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
*   \file Timer.cpp
*   \version 0.1
*   \author Bastien (Bigz) Cramillet
*/

#include <Core/Timer.hpp>
#include <assert.h>

namespace sg
{
    Timer::Timer() : m_clock(), m_timeLimit(sf::Time::Zero)
    {

    }

    Timer::Timer(sf::Time timeLimit, bool initRunning) : m_clock(initRunning), m_timeLimit(timeLimit)
    {
        assert(timeLimit > sf::Time::Zero);
    }

    Timer::~Timer()
    {

    }

    sf::Time Timer::getRemainingTime() const
    {
        // Le temps restant est soit zéro, soit le temps limite - le temps écoulé.
        // Si la soustraction donne un résultat négatif, zéro sera plus grand, sinon on renvoie le résultat de cette soustraction
        return std::max((m_timeLimit - m_clock.getElapsedTime()), sf::Time::Zero);
    }

    bool Timer::isRunning() const
    {
        return (m_clock.isRunning() && !isExpired());
    }

    bool Timer::isExpired() const
    {
        return (m_clock.getElapsedTime() > m_timeLimit);
    }

    void Timer::start()
    {
        m_clock.start();
    }

    void Timer::stop()
    {
        m_clock.stop();
    }

    void Timer::restart(sf::Time timeLimit, bool continueRunning)
    {
        assert(timeLimit > sf::Time::Zero);

        m_timeLimit = timeLimit;
        m_clock.restart(continueRunning);
    }

    void Timer::restart(bool continueRunning)
    {
        m_clock.restart(continueRunning);
    }
}
