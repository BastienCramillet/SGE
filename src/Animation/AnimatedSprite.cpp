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
*   \file AnimatedSprite.cpp
*   \version 0.1
*   \author Bastien (Bigz) Cramillet
*/

#include <Animations/AnimatedSprite.hpp>

namespace sg
{
    AnimatedSprite::AnimatedSprite ()
    {
        m_sprite = 0;
    }

    AnimatedSprite::AnimatedSprite (sf::Sprite* sprite, int frameCount, int frequency,
                            sf::Vector2i gridSize, sf::Vector2i frameSize, bool isLooping)
                            : m_sprite(sprite), m_frameCount(frameCount), m_frequency(frequency),
                            m_gridSize(gridSize), m_frameSize(frameSize), m_isLooping(isLooping)
    {
        m_isPlaying = false;
        m_delay = (1.f/(float)m_frequency);
    }

    void AnimatedSprite::play ()
    {
        m_isPlaying = true;
        m_stopWatch.restart();
    }

    void AnimatedSprite::update ()
    {
        if (m_isPlaying)
        {
            if (m_stopWatch.getElapsedTime().asSeconds() >= m_delay)
            {
                nextFrame();
                if (m_currentFrame == m_frameCount && m_isLooping)
                    m_stopWatch.restart();
                else
                    m_stopWatch.stop();
            }
        }
    }

    void AnimatedSprite::stop ()
    {
        m_isPlaying = false;
        m_stopWatch.stop();
    }

    void AnimatedSprite::pause ()
    {
        m_isPlaying = false;
        m_stopWatch.stop();
    }

    void AnimatedSprite::reset ()
    {
        m_currentFrame = 0;
        m_stopWatch.restart();
    }

    void AnimatedSprite::nextFrame ()
    {

    }
}