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

/*!
*   \file StopWatch.hpp
*   \version 0.1
*   \author Bastien (Bigz) Cramillet
*/

#ifndef STOPWATCH_HPP_INCLUDED
#define STOPWATCH_HPP_INCLUDED

#include <SFML/System.hpp>

namespace sg
{
    /*!
    *   \class StopWatch
    *   \brief Represent a pausable clock
    */
    class StopWatch
    {
        public:
            /*!
            *   \brief Constructor
            *
            *   \param initRunning True if the Stop Watch has to start at its creation
            */
            StopWatch(bool initRunning = false);

            /*!
            *   \brief Destructor
            */
            virtual ~StopWatch();

            /*!
            *   \brief Return the elapsed time since the start or last reset
            */
            sf::Time getElapsedTime() const;

            /*!
            *   \brief Return if the StopWatch is running
            */
            bool isRunning() const;

            /*!
            *   \brief Start the StopWatch
            */
            void start();

            /*!
            *   \brief Stop the StopWatch
            */
            void stop();

            /*!
            *   \brief Reset the StopWatch
            *
            *   \param stillrunning If true, the StopWatch will keep running, by default it stops !
            */
            void restart(bool stillrunning = false);

        private:
            sf::Clock   m_clock;    //!< The clock used by the StopWatch
            sf::Time    m_buffer;   //!< A buffer used to keep the elapsed time
            bool        m_running;  //!< Represent if the StopWatch is running or stoped
    };
}
#endif // STOPWATCH_HPP_INCLUDED
