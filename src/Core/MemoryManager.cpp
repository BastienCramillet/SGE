/*------------------------------------------------------------------------------
*
* SE - Simple Engine
*
* Copyright (c) 2010-2011 Bastien Cramillet (Bigz)(bastien.cramillet@gmail.com)
*                         Xavier Michel (Saffir)(xavier.michel.mx440@gmail.com)
*
* This software is provided 'as-is', without any express or implied
* warranty. In no event will the authors be held liable for any damages
* arising from the use of this software.
*
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
*
*    1. The origin of this software must not be misrepresented; you must not
*    claim that you wrote the original software. If you use this software
*    in a product, an acknowledgment in the product documentation would be
*    appreciated but is not required.
*
*    2. Altered source versions must be plainly marked as such, and must not be
*    misrepresented as being the original software.
*
*    3. This notice may not be removed or altered from any source
*   distribution.
*
*-----------------------------------------------------------------------------*/

/*!
*   \file MemoryManager.hpp
*   \brief The memory manager source code
*   \version 0.1
*   \author Bastien (Bigz) Cramillet
*/

#include <Core/MemoryManager.hpp>
#include <Tools/Log.hpp>
#include <iomanip>
#include <sstream>
#include <stdlib.h>

namespace sg
{
    MemoryManager* MemoryManager::instance = 0;

    MemoryManager::MemoryManager() : m_file("Memory leaks.log")
    {
        // Checking that the file is open
        if (!m_file)
            Log::d("MemoryManager") << "Memory leaks.log, Impossible d'accéder en écriture";

        // Write a header in the file
        m_file << "  ========================================" << std::endl;
        m_file << "   sg::Engine v0.1 - Memory leak tracker " << std::endl;
        m_file << "  ========================================" << std::endl << std::endl;
    }

    MemoryManager::~MemoryManager()
    {
        if (m_blocks.empty())
        {
            // There is no leak
            m_file << std::endl;
            m_file << "  ========================================" << std::endl;
            m_file << "     No leak detected, congratulations !  " << std::endl;
            m_file << "  ========================================" << std::endl;
        }
        else
        {
            // There are leaks
            m_file << std::endl;
            m_file << "  ========================================" << std::endl;
            m_file << "   Oops... Some leaks have been detected  " << std::endl;
            m_file << "  ========================================" << std::endl;
            m_file << std::endl;

            reportLeaks();
        }

    }

    MemoryManager& MemoryManager::getInstance()
    {
        if (!instance)
        {
            instance = new MemoryManager();
        }

        return *instance;
    }

    void MemoryManager::kill ()
    {
        if ( instance )
        {
            delete instance;
            instance = 0;
        }
    }

    void MemoryManager::reportLeaks()
    {
        // Detail of the leaks
        std::size_t totalSize = 0;
        for (TBlockMap::iterator i = m_blocks.begin(); i != m_blocks.end(); ++i)
        {
            // Add the size of the block to the total size
            totalSize += i->second.size;

            // Add information about the current block in the file
            m_file << "-> 0x" << i->first
                   << " | "   << std::setw(7) << std::setfill(' ') << static_cast<int>(i->second.size) << " octets"
                   << " | "   << i->second.file.filename() << " (" << i->second.line << ")" << std::endl;

            // Free the memory
            ::free(i->first);
        }

        // Show the total of the leaks
        m_file << std::endl << std::endl << "-- "
               << static_cast<int>(m_blocks.size()) << " blocs non-libéré(s), "
               << static_cast<int>(totalSize)       << " octets --"
               << std::endl;
    }


    void* MemoryManager::allocate(std::size_t size, const File& file, int line, bool array)
    {
        // Memory allocation
        void* ptr = malloc(size);

        // Add the block to the allocated block list
        TBlock newBlock;
        newBlock.size  = size;
        newBlock.file  = file;
        newBlock.line  = line;
        newBlock.array = array;
        m_blocks[ptr]  = newBlock;

        // Log
        m_file << "++ Allocation    | 0x" << ptr
               << " | " << std::setw(7) << std::setfill(' ') << static_cast<int>(newBlock.size) << " octets"
               << " | " << newBlock.file.filename() << " (" << newBlock.line << ")" << std::endl;

        return ptr;
    }

    void MemoryManager::free(void* ptr, bool array)
    {
        // Search for the address within the allocated blocks
        TBlockMap::iterator it = m_blocks.find(ptr);

        // If the block wasn't allocated, we generate an error
        if (it == m_blocks.end())
        {
            ::free(ptr);
            return;
        }

        // If the allocation type doesn't match, we generate an error
        if (it->second.array != array)
        {
            Log::d("MemoryManager") << ptr << " " << it->second.file.filename() << " " << it->second.line << " " << !array;
        }

        // If everything is ok, we delete the block and log
        m_file << "-- Désallocation | 0x" << ptr
               << " | " << std::setw(7) << std::setfill(' ') << static_cast<int>(it->second.size) << " octets"
               << " | " << m_deleteDeque.back().file.filename() << " (" << m_deleteDeque.back().line << ")" << std::endl;
        m_blocks.erase(it);
        m_deleteDeque.pop_back();

        // Free the memory
        ::free(ptr);
    }

    void MemoryManager::nextDelete(const File& file, int line)
    {
        TBlock Delete;
        Delete.file = file;
        Delete.line = line;

        m_deleteDeque.push_back(Delete);
    }

} // namespace sg
