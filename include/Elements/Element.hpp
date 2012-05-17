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

#ifndef ELEMENT_HPP_INCLUDED
#define ELEMENT_HPP_INCLUDED

#include <string>

#include <SFML/System/Vector2.hpp>

namespace sg
{
    class Element
    {
        public :

            Element(const std::string &id) {
                m_elementID = id;
            }

            virtual ~Element() {
            }

            std::string getElementID() {
                return m_elementID;
            }

            virtual sf::Vector2f getPosition() const = 0;

    private :

        std::string m_elementID;

    };
} // namespace sg

#endif // ELEMENT_HPP_INCLUDED
