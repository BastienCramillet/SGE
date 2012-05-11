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
    DynamicObject::DynamicObject ()
    {

    }

    DynamicObject::~DynamicObject ()
    {

    }

    void DynamicObject::update()
    {
        float x = getBodyPosition().x * 100.f;
        float y = getBodyPosition().y * 100.f;

        if (m_currentSprite!=0)
            m_currentSprite->setPosition(sf::Vector2f(x,y));
    }

    void DynamicObject::play(std::string& id)
    {
        float x = getBodyPosition().x;
        float y = getBodyPosition().y;

        m_mSound[id]->setPosition(sf::Vector3f(x,y,1));
        m_mSound[id]->play();
    }
}
