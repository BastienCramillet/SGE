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

#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED

#include <vector>
#include <SFML/System/Vector2.hpp>

namespace sg
{
    class Bone;
    class Node
    {
        public :

            Node();

            Node(sf::Vector2f position);

            ~Node();

            const sf::Vector2f& getPosition() const;
            void setPosition(sf::Vector2f position);
            void setPosition(float x, float y);

            void rotate(float angle);

            void move(sf::Vector2f offset);

            void addBone(float angle, float size);





        private :

            sf::Vector2f m_position;
            std::vector<Bone*> m_vBones;
    };
}



#endif // NODE_HPP_INCLUDED
