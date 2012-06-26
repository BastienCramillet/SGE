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
*   \file Animatable.cpp
*   \version 0.1
*   \author Bastien (Bigz) Cramillet
*/

#include <Elements/Animatable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>

namespace sg
{
    Animatable::Animatable() : Drawable()
    {
        m_currentAnimatedSprite = 0;
    }

    Animatable::~Animatable()
    {

        m_currentAnimatedSprite = 0;
        for(std::map<std::string, sg::AnimatedSprite*>::iterator it = m_mAnimatedSprite.begin(); it != m_mAnimatedSprite.end(); ++it)
        {
            delete it->second;
            it->second = 0;
        }
        m_mAnimatedSprite.clear();
    }

    void Animatable::addAnimatedSprite(const std::string& id, sf::Sprite* sprite, int frameCount, int frequency,
                            sf::Vector2i gridSize, sf::Vector2i frameSize, bool isLooping)
    {
        m_mAnimatedSprite[id] = new sg::AnimatedSprite(sprite, frameCount, frequency,
                                                                    gridSize, frameSize, isLooping);
        addSprite(id, sprite, frameSize.x, frameSize.y);
        m_currentAnimatedSprite = m_mAnimatedSprite[id];
        m_currentSprite = m_currentAnimatedSprite->getAnimatedSprite();
        //m_currentSprite->setScale(1 / ((gridSize.x * frameSize.x) / frameCount), 1 / ((gridSize.x * frameSize.x) / frameCount));

        m_currentAnimatedSprite->play();

    }

    void Animatable::setSprite(std::string& id)
    {
        m_currentAnimatedSprite->stop();
        m_currentAnimatedSprite = m_mAnimatedSprite[id];
        m_currentAnimatedSprite->restart();
        m_currentSprite = m_currentAnimatedSprite->getAnimatedSprite();
    }
}
