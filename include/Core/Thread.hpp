/*------------------------------------------------------------------------------
*
* SGE - Simple Game Engine
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
*   \file Thread.hpp
*   \brief Thread class header
*   \version 1.0
*   \author Bastien (Bigz) Cramillet
*/

#ifndef THREAD_HPP_INCLUDED
#define THREAD_HPP_INCLUDED

#include <SFML/System.hpp>

namespace sg
{
    /*!
    *   \class Thread
    *   \brief A simple thread based on SFML threads
    */
    class Thread
    {
        public :

            /*!
            *   \brief Constructor
            */
            Thread ()
            {
                m_thread = new sf::Thread(&sg::Thread::run, this);
            };

            /*!
            *   \brief Destructor
            */
            ~Thread()
            {
                delete m_thread;
                m_thread = 0;
            }

            /*!
            *   \brief Mandatory function to overload for all thread subclass
            *           The real content of the subclass is here
            */
            virtual void run() = 0;

            /*!
            *   \brief Start the run function of the Thread subclass
            */
            void start()
            {
                m_thread->launch();
            };

        protected :

            sf::Thread*    m_thread;    //!< The SFML thread
    };

}
#endif // THREAD_HPP_INCLUDED
