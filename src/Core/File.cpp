/*------------------------------------------------------------------------------
*
* SE - Simple Engine
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
*   \file File.cpp
*   \brief The File class source
*   \version 0.1
*/

#include <Core/File.hpp>
#include <algorithm>
#include <fstream>

namespace sg
{
    /*************************************
    *     Constructors / Destructors     *
    *************************************/

    File::File(const std::string& name) : m_name(name)
    {
        std::replace(m_name.begin(), m_name.end(), '/', '\\');
    }

    File::File(const char* Name) : m_name(Name)
    {
        std::replace(m_name.begin(), m_name.end(), '/', '\\');
    }


    /*************************
    *     Public methods     *
    *************************/

    bool File::exists() const
    {
        std::ifstream file(m_name.c_str());
        return file.is_open();
    }

    const std::string& File::fullname() const
    {
        return m_name;
    }

    std::string File::filename() const
    {
        std::string::size_type pos = m_name.find_last_of("\\/");

        if (pos != std::string::npos)
            return m_name.substr(pos + 1, std::string::npos);
        else
            return m_name;
    }

    std::string File::shortFilename() const
    {
        return filename().substr(0, filename().find_last_of("."));
    }

    std::string File::extension() const
    {
        std::string::size_type pos = m_name.find_last_of(".");
        if (pos != std::string::npos)
            return m_name.substr(pos + 1, std::string::npos);
        else
            return "";
    }

} // namespace sg
