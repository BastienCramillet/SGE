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
*   \file
*   \version 0.1
*   \author Bastien (Bigz) Cramillet
*/

#include <Animations/Bone.hpp>
#include <Animations/Node.hpp>
#include <Tools/TrigoUtil.hpp>

namespace sg
{
    Bone::Bone()
    {
        m_angle = 0;
        m_length = 1;
        m_pParent = 0;
        m_pChild = new sg::Node();
    }

    Bone::Bone(sg::Node* parentNode, float angle, float length) :
        m_pParent(parentNode), m_angle(angle), m_length(length)
    {
        m_pChild = new sg::Node();
    }

    Bone::~Bone()
    {
        m_pParent = 0;
        delete m_pChild;
    }

    void Bone::computeChildPosition()
    {
        sf::Vector2f position = TrigoUtil::computeVector(m_angle, m_length);
        m_pChild->setPosition(position.x + m_pParent->getPosition().x,
                             position.y + m_pParent->getPosition().y);

    }


    void Bone::rotate(float angle)
    {
        m_angle += angle;
        computeChildPosition();
        m_pChild->rotate(angle);
    }
}
