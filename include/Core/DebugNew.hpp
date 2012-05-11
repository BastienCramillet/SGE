/*------------------------------------------------------------------------------
*
* SGE - Simple Game Engine
*
* Copyright (c) 2012 Bastien Cramillet (Bigz)(bastien.cramillet@gmail.com)
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

#ifdef D_DEBUG

#ifndef DEBUGNEW_HPP_INCLUDED
#define DEBUGNEW_HPP_INCLUDED

/*!
*   \file DebugNew.hpp
*   \brief Overload of the memory allocation and deallocation
*           operators and functions in order to see the memory leaks
*   \version 0.1
*/

#include <Core/MemoryManager.hpp>


/*!
*   \brief Overload of the new operator
*
*   \param size Size to allocate
*   \param file Source file
*   \param line Refered line in the source code
*
*   \return A pointer to the allocated zone
*/
inline void* operator new(std::size_t size, const char* file, int line)
{
    return sg::MemoryManager::getInstance().allocate(size, file, line, false);
}


/*!
*   \brief Overload of the new[] operator
*
*   \param size Size to allocate
*   \param file Source file
*   \param line Refered line in the source code
*
*   \return A pointer to the allocated zone
*/
inline void* operator new[](std::size_t size, const char* file, int line)
{
    return sg::MemoryManager::getInstance().allocate(size, file, line, true);
}


/*!
*   \brief Overload of the delete operator
*
*   \param ptr pointer to free
*/
inline void operator delete(void* ptr)
{
    sg::MemoryManager::getInstance().free(ptr, false);
}

/*!
*   \brief Overload of the delete operator
*
*   \param ptr pointer to free
*   \param file Source file
*   \param line Refered line in the source code
*/
inline void operator delete(void* ptr, const char* file, int line)
{
    sg::MemoryManager::getInstance().nextDelete(file, line);
    sg::MemoryManager::getInstance().free(ptr, false);
}


/*!
*   \brief Overload of the delete[] operator
*
*   \param ptr pointer to free
*/
inline void operator delete[](void* ptr)
{
    sg::MemoryManager::getInstance().free(ptr, true);
}


/*!
*   \brief Overload of the delete[] operator
*
*   \param ptr pointer to free
*   \param file Source file
*   \param line Refered line in the source code
*/
inline void operator delete[](void* ptr, const char* file, int line)
{
    sg::MemoryManager::getInstance().nextDelete(file, line);
    sg::MemoryManager::getInstance().free(ptr, true);
}
#endif // DEBUGNEW_HPP_INCLUDED

//******************************************************
// Macros used for automated tracking
//******************************************************
#ifndef new
    #define new    new(__FILE__, __LINE__)
    #define delete sg::MemoryManager::getInstance().nextDelete(__FILE__, __LINE__), delete
#endif

#endif // D_DEBUG




