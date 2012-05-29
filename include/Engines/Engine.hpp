/*------------------------------------------------------------------------------
*
* SGE - Simple Game Engine
*
* Copyright (c) 2012 Bastien Cramillet (Bigz)(bastien.cramillet@gmail.com)
*                    Xavier Michel (Saffir)(xavier.michel.mx440@gmail.com)
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

#ifndef ENGINE_HPP_INCLUDED
#define ENGINE_HPP_INCLUDED

/*!
*   \file Engine.hpp
*   \version 1.0
*/

#include <queue>
#include <string>
#include <map>

namespace sg
{
    /*!
    *   \class Engine
    *   \brief Engine mother class with the engine messages managment
    */
    class Engine
    {
        public :

            struct EngineMessage
            {
                std::string                 command;    //!< The desired command
                std::map<int, int>          i_data;     //!< The integer arguments
                std::map<int, float>        f_data;     //!< The floating arguments
                std::map<int, std::string>  s_data;     //!< The string arguments
            };

            /*!
            *   \brief Engine class constructor
            */
            Engine ();

            /*!
            *   \brief Engine class destructor
            */
            virtual ~Engine ();

            /*!
            *   \brief Update the engine
            */
            virtual void update ()
            {
                processQueue();
            }

            /*!
            *   \brief Add a message to the engine message queue
            *
            *   \param message The engine message to add
            */
            void addMessage (EngineMessage* message)
            {
                m_qEngineMessage.push(message);
            }

            /*!
            *   \brief Send a message to another engine
            *
            *   \param engine The receiver engine
            *   \param message The message to send
            */
            void sendMessage (std::string engine, EngineMessage* message);

        protected:

            /*!
            *   \brief Treat the message queue
            */
            void processQueue ()
            {
                while(!m_qEngineMessage.empty())
                {
                    treatMessage(m_qEngineMessage.front());
                    m_qEngineMessage.pop();
                }
            }

            /*!
            *   \brief Treat the given message
            *
            *   \param message The message to treat
            */
            virtual void treatMessage (EngineMessage* message) = 0;

            std::queue<EngineMessage*> m_qEngineMessage;  //!< The message queue to treat


    };

} // namespace sg

#endif // ENGINE_HPP_INCLUDED
