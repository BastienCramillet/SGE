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
*   \file NetworkMachine.hpp
*   \version 0.1
*   \author Bastien (Bigz) Cramillet
*/

#ifndef NETWORKMACHINE_HPP_INCLUDED
#define NETWORKMACHINE_HPP_INCLUDED

#include <Core/Thread.hpp>
#include <SFML/Network.hpp>

namespace sg
{
    /*!
    *   \class NetworkMachine
    *   \brief This class represent a basic machine on a network
    */
    class NetworkMachine : public sg::Thread
    {
        public :

            /*!
            *   \brief Constructor
            */
            NetworkMachine() {}

            /*!
            *   \brief Destructor
            */
            ~NetworkMachine()
            {
                if (m_running) forceStop();
            }

            bool isRunning();

            /*!
            *   \brief Mandatory - See sg::Thread::run()
            */
            virtual void run() = 0;

            /*!
            *   \brief Start the network machine
            */
            void start()
            {
                if (!m_running)
                {
                    m_running = true;
                    run();
                }
            }

            /*!
            *   \brief Stop the network machine
            */
            void shutdown()
            {
                m_running = false;
                wait();
            }

            /*!
            *   \brief Restart the network machine by shuting it down and starting it again
            */
            void restart()
            {
                shutdown();
                start();

            }


        protected :

            bool            m_running; //!< A boolean used to let the main loop of the machine process or not
            sf::IpAddress   m_address; //!< The IP address of the machine

    };
} // namespace sg

#endif // NETWORKMACHINE_HPP_INCLUDED
