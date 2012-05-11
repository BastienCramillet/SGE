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

/*!
*   \file Drawable.cpp
*   \brief The File utility header
*   \version 0.1
*/

#ifndef FILE_HPP_INCLUDED
#define FILE_HPP_INCLUDED

#include <string>

namespace sg
{
    /*!
    *   \class File
    *   \brief Class which allow an easy way to manipulate files
    */
    class File
    {
        public :

            /*!
            *   \brief Constructor
            *
            *   \param name Name of the file
            */
            File(const std::string& name = "unknown");

            /*!
            *   \brief Constructor
            *
            *   \param name Name of the file
            */
            File(const char* name);

            /*!
            *   \brief Check if the file exists
            *
            *   \return True if the file exists, false if not
            */
            bool exists() const;

            /*!
            *   \brief Return the name of the file with its full path
            *
            *   \return The full name of the file in a string
            */
            const std::string& fullname() const;

            /*!
            *   \brief Return the name of the file without its path
            *
            *   \return The short name of the file, with extension, in a string
            */
            std::string filename() const;

            /*!
            *   \brief Return the name of the file without its path nor extension
            *
            *   \return The short name of the file, without extension, in a string
            */
            std::string shortFilename() const;

            /*!
            *   \brief Return the extension of the file
            *
            *   \return The extension of the file in a string
            */
            std::string extension() const;

        private :

            std::string m_name; //!< File path
    };

} // namespace se

#endif // FILE_HPP_INCLUDED
