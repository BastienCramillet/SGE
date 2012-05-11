/*------------------------------------------------------------------------------
*
* SGE - Simple Game Engine
*
* Copyright (c) 2010-2011 Bastien Cramillet (Bigz)(bastien.cramillet@gmail.com)
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
*   \file Engine.hpp
*   \brief Engines mother class header
*   \version 0.1
*/

#ifndef MEMORYMANAGER_HPP_INCLUDED
#define MEMORYMANAGER_HPP_INCLUDED

#include "Core/File.hpp"
#include <cstddef>
#include <map>
#include <stack>
#include <deque>
#include <fstream>

namespace sg
{
    /*!
    *   \class MemoryManager
    *   \brief Class used in debug mode to control the memory using
    */
    class MemoryManager
    {
        public :

            static MemoryManager& getInstance();

            static void kill ();

            /*!
            *   \brief Add a memory allocation
            *
            *   \param size Size allocated
            *   \param file File with the allocation within
            *   \param line Line of the allocation in the file
            *   \param array Is the object a simple object or an array
            */
            void* allocate(std::size_t size, const File& file, int line, bool array);

            /*!
            *   \brief Free a memory allocation
            *
            *   \param ptr The pointer to free
            *   \param array Specify if the pointer point to an array or not
            */
            void free(void* ptr, bool array);

            /*!
            *   \brief Save information on the current deallocation
            *
            *   \param file File with the allocation within
            *   \param line Line of the allocation in the file
            */
            void nextDelete(const File& File, int Line);

        private :

            /*!
            *   \brief Constructor
            */
            MemoryManager();

            /*!
            *   \brief Destructor
            */
            ~MemoryManager ();

            /*!
            *   \brief Write a report about memory leaks
            */
            void reportLeaks();

            /*!
            *   \brief Information about a memory block
            */
            struct TBlock
            {
                std::size_t size;  //!< Allocated size
                File        file;  //!< File from the allocation comes
                int         line;  //!< Ligne de l'allocation
                bool        array; //!< Est-ce un objet ou un tableau ?
            };
            typedef std::map<void*, TBlock> TBlockMap;

            static MemoryManager* instance;     //!< The only one instance

            TBlockMap          m_blocks;        //!< Memory blocks allocated
            std::ofstream      m_file;          //!< Output file
            std::deque<TBlock> m_deleteDeque;   //!< Collection of memory blocks
    };

} // namespace se

#endif // MEMORYMANAGER_HPP_INCLUDED
