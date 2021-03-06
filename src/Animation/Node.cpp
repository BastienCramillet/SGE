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

#include <Animations/Node.hpp>
#include <Animations/Bone.hpp>
#include <Constants.hpp>
#include <algorithm>

namespace sg
{

    Node::Node()
    {

    }

    Node::Node(sf::Vector2f position) : m_position(position)
    {

    }

    Node::~Node()
    {
        std::for_each(m_vBones.begin(), m_vBones.end(), Delete());
        m_vBones.clear();
    }

    /**********
    * getters *
    **********/

    const sf::Vector2f& Node::getPosition() const
    {
        return m_position;
    }

    /**********
    * Setters *
    **********/

    void Node::setPosition(float x, float y)
    {
        m_position.x = x;
        m_position.y = y;
    }

    void Node::setPosition(sf::Vector2f position)
    {
        m_position = position;
    }


    /**********
    * Methods *
    **********/

    void Node::rotate(float angle)
    {
        for (unsigned short int i = 0; i < m_vBones.size(); ++i)
        {
            m_vBones[i]->rotate(angle);
        }
    }

    void Node::move(sf::Vector2f offset)
    {
        m_position.x += offset.x;
        m_position.y += offset.y;

    }

    void Node::addBone(float angle, float scale)
    {
        m_vBones.push_back(new Bone(this, angle, scale));
    }

}
