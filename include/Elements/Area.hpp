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
*   \file Area.hpp
*   \brief Area header
*   \version 0.1
*   \author Xavier
*/

#ifndef AREA_HPP_INCLUDED
#define AREA_HPP_INCLUDED

#include <SFML/Graphics/Rect.hpp>

#include <Elements/Element.hpp>

namespace sg
{
    /*!
    *   \class Area
    *   \brief An area is a zone of the map
    */
    class Area : public Element, public sf::FloatRect
    {
        public :

            /*!
            *   \brief Create an area
            */
            explicit Area(const sf::FloatRect &rect);


            /*!
            *   \brief Update the area (does nothing)
            */
            inline void update() {
            }

            /*!
            *   \brief Get the area position
            */
            sf::Vector2f getPosition() const;

    };
}


#endif // AREA_HPP_INCLUDED
