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

#ifndef DRAWABLE_HPP_INCLUDED
#define DRAWABLE_HPP_INCLUDED

/*!
*   \file Drawable.cpp
*   \brief The drawable object header
*   \version 0.1
*   \author Bastien (Bigz) Cramillet
*/

#include <SFML/Graphics.hpp>

namespace sg
{
    class Drawable
    {
        public :

            /*!
            *   \brief Constructor
            */
            Drawable ();

            /*!
            *   \brief Destructor
            */
            ~Drawable ();

            /*!
            *   \brief Get the current showed sprite of the drawable
            */
            const sf::Sprite& getCurrentSprite() const;

            /*!
            *   \brief Set the current showed sprite of the drawable
            *
            *   \param id The id of the desired sprite
            */
            void setCurrentSprite (const std::string& id);

            /*!
            *   \brief Set the position of the current sprite
            *
            *   \param position The new position of the drawable
            */
            void setPosition(const sf::Vector2f& position);

            /*!
            *   \brief Add a sprite loaded by the graphic engine to the drawable object
            *
            *   \param id The refered id of the image
            *   \param drawable The sf::Sprite to add
            */
            void addSprite (const std::string& id, sf::Sprite* drawable);

            /*!
            *   \brief Add a sprite loaded by the graphic engine to the drawable object
            *           and set the origin of the sprite to correctly manage transformations
            *
            *   \param id The refered id of the image
            *   \param drawable The sf::Sprite to add
            *   \param width The width of the image
            *   \param height The height of the image
            */
            void addSprite (const std::string& id, sf::Sprite* drawable, int width, int height);


        protected :

            std::map<std::string, sf::Sprite*>  m_mSprite;          //!< All the different sprites of the drawable and their id
            sf::Sprite*                         m_currentSprite;    //!< The current sprite of the drawable
    };

    /*
    struct ZIndexSort {
        bool operator() (const Drawable *d1, const Drawable *d2) const {
            return d1->getZIndex() < d2->getZIndex();
        }
    };
    //std::sort(m_vDrawable.begin(), m_vDrawable.end(), ZIndexSort());
    */


}

#endif // DRAWABLE_HPP_INCLUDED
