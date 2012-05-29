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
*   \file StopWatch.cpp
*   \version 0.1
*   \author Bastien (Bigz) Cramillet
*/

#include <Core/StopWatch.hpp>

namespace sg
{
    StopWatch::StopWatch(bool initRunning) : m_buffer(sf::Time::Zero), m_running(initRunning)
    {
    }

    StopWatch::~StopWatch()
    {
    }

    sf::Time StopWatch::getElapsedTime() const
    {
        if(m_running)
            return (m_buffer + m_clock.getElapsedTime());

        return m_buffer;
    }

    bool StopWatch::isRunning() const
    {
        return m_running;
    }

    void StopWatch::start()
    {
        if(!m_running)
        {
            m_running = true;
            m_clock.restart();
        }
    }

    void StopWatch::stop()
    {
        if(m_running)
        {
            m_buffer += m_clock.getElapsedTime();
            m_running = false;
        }
    }

    void StopWatch::restart(bool stillRunning)
    {
        m_buffer = sf::Time::Zero;
        m_running = stillRunning;
        m_clock.restart();
    }
}
