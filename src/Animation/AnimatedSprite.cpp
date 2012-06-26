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
*   \file AnimatedSprite.cpp
*   \version 0.1
*   \author Bastien (Bigz) Cramillet
*/

#include <Animations/AnimatedSprite.hpp>
#include <iostream>

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
        m_currentFrame = 0;
        m_isPlaying = false;
        m_delay = (1.f/(float)m_frequency);
        m_sprite->setTextureRect(sf::IntRect(0, 0, m_frameSize.x, m_frameSize.y));
    }

    AnimatedSprite::~AnimatedSprite ()
    {
        m_sprite = 0;
    }

    sf::Sprite* AnimatedSprite::getAnimatedSprite()
    {
        return m_sprite;
    }

    void AnimatedSprite::play ()
    {
        m_isPlaying = true;
        m_stopWatch.start();
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
                else if (m_currentFrame == m_frameCount && !m_isLooping)
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

    void AnimatedSprite::restart ()
    {
        m_currentFrame = 0;
        m_stopWatch.restart();
        play();
    }

    void AnimatedSprite::reset ()
    {
        m_currentFrame = 0;
        stop();
    }

    void AnimatedSprite::nextFrame ()
    {
        ++m_currentFrame;

        unsigned int xOffset;
        unsigned int yOffset;


        if (m_currentFrame != m_frameCount)
        {
            xOffset = (m_currentFrame) % m_gridSize.x;
            yOffset = (int)((m_currentFrame) / m_gridSize.x) + 1;
        }
        else
        {
            if (m_currentFrame == m_frameCount && m_isLooping)
            {
                m_currentFrame = 0;
                xOffset = 0;
                yOffset = 0;
            }
            else if (m_currentFrame == m_frameCount && !m_isLooping)
            {
                --m_currentFrame;
                return;
            }
        }

        m_sprite->setTextureRect(sf::IntRect(xOffset * m_frameSize.x,
                                             yOffset * m_frameSize.y,
                                             m_frameSize.x,
                                             m_frameSize.y));
    }
}
