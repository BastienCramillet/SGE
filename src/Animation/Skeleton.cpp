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

#include <Animations/Skeleton.hpp>
#include <Animations/Node.hpp>

namespace sg
{
    Skeleton::Skeleton()
    {
        m_mainNode = 0;
    }

    Skeleton::Skeleton(sf::Vector2f position)
    {
        m_mainNode = new Node(position);
    }

    Skeleton::~Skeleton()
    {
        delete m_mainNode;
    }

}
