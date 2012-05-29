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
*   \file Decor.hpp
*   \brief Decor header
*   \version 0.1
*   \author Xavier
*/

#ifndef DECOR_HPP_INCLUDED
#define DECOR_HPP_INCLUDED

#include <Elements/Element.hpp>
#include <Elements/Drawable.hpp>

namespace sg
{
    /*!
    *   \class Decor
    *   \brief Represent a simple visual decorative element
    */
    class Decor : public Element, public Drawable
    {
        public :

            /*!
            *   \brief Constructor
            *
            *   \param elementID The id of the decor
            */
            Decor(const std::string& elementID);

            /*!
            *   \brief Destructor
            */
            ~Decor();

            /*!
            *   \brief Update the decor
            */
            inline void update() {}


            /*!
            *   \brief Override Element::getPostion
            */
            sf::Vector2f getPosition() const;

            /*!
            *   \brief Get the rotation of the decor by the sprite
            */
            float getRotation() const;

    };
}


#endif // DYNAMICOBJECT_HPP_INCLUDED
