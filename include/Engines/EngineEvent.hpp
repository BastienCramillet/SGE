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

#ifndef ENGINEEVENT_HPP_INCLUDED
#define ENGINEEVENT_HPP_INCLUDED

/*!
 * \file EngineEvent.hpp
 * \version 1.0
 */

namespace sg
{
    /*!
    *   \class EngineEvent
    *   \brief EngineEvent class
    *   \version 1.0
    */

    class EngineEvent
    {
        public :

            /*!
            *   \brief EngineEvent class constructor
            *
            *   \param command The event command
            *   \param args The command arguments
            */
            EngineEvent(std::string command, std::vector<std::string> args);

            std::string                 m_engine;
            std::string                 m_command; //!< The event command
            std::vector<std::string>    m_vArgs;    //!< The command arguments
    };
}
#endif // ENGINEEVENT_HPP_INCLUDED
