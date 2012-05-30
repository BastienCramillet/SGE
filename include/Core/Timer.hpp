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
*   \file Timer.hpp
*   \version 0.1
*   \author Bastien (Bigz) Cramillet
*/

#ifndef TIMER_HPP_INCLUDED
#define TIMER_HPP_INCLUDED

#include <SFML/System.hpp>
#include <Core/StopWatch.hpp>

namespace sg
{
    class Timer
    {
        public:

            /*!
            *   \brief Default Constructor.
            *       To use the Timer you will need to use restart(sf::Time timeLimit, bool continueRunning).
            */
            Timer();

            /*!
            *   \brief Recommended constructor.
            *
            *   \param timeLimit The starting time of the Timer. It will decrease to zero.
            *   \param initRunning Set it true if you want to start the timer at construction
            */
            Timer(sf::Time timeLimit, bool initRunning = false);

            /*!
            *   \brief Default destructor.
            */
            virtual ~Timer();

            /*!
            *   \brief Return the time remaining to reach zero, or zero if the reamining timer is over
            */
            sf::Time getRemainingTime() const;

            /*!
            *   \brief Return if the Timer is running or not
            */
            bool isRunning() const;

            /*!
            *   \brief Return if the Timer is expired or not
            */
            bool isExpired() const;

            /*!
            *   \brief Start the Timer
            */
            void start();

            /*!
            *   \brief Stop the Timer
            */
            void stop();

            /*!
            *   \brief Reset the Timer
            *
            *   \param timeLimit The starting time of the Timer. It will decrease to zero.
            *   \param continueRunning Set it true if you want to restart the timer right now
            */
            void restart(sf::Time timeLimit, bool continueRunning = false);

            /*!
            *   \brief To reset the Timer, the old time limit will be kept
            *
            *   \param continueRunning Set it true if you want to restart the timer
            */
            void restart(bool continueRunning = false);

        private:
            StopWatch   m_clock;        //!< The clock used by the Timer
            sf::Time    m_timeLimit;    //!< The time limit of the Timer
    };
}

#endif // TIMER_HPP_INCLUDED
