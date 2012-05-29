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
*   \file DynamicObject.cpp
*   \brief Dynamic object source code
*   \version 0.1
*   \author Bastien (Bigz) Cramillet
*/

#include <Elements/DynamicObject.hpp>
#include <Box2D.h>

#include <Tools/Log.hpp>

namespace sg
{
    DynamicObject::DynamicObject(const std::string& elementID)
        : Element(elementID)
    {
    }

    DynamicObject::~DynamicObject ()
    {

    }

    sf::Vector2f DynamicObject::getPosition() const
    {
        return sf::Vector2f(getBodyPosition().x * 100, getBodyPosition().y * 100);
    }

    float DynamicObject::getRotation() const
    {
        return getBodyAngle() * 180.f / acos(-1.0);
    }

    void DynamicObject::update()
    {
        sf::Vector2f pos = getPosition();
        float rot = getRotation();

        if (m_currentSprite!=0)
        {
            m_currentSprite->setPosition(sf::Vector2f(pos.x, pos.y));
            m_currentSprite->setRotation(rot);
        }
    }

    void DynamicObject::play(std::string& id)
    {
        sf::Vector2f pos = getPosition();

        m_mSound[id]->setPosition(sf::Vector3f(pos.x, pos.y, 1));
        m_mSound[id]->play();
    }
}
