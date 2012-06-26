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
*   \file Animatable.hpp
*   \version 0.1
*   \author Bastien (Bigz) Cramillet
*/

#ifndef ANIMATABLE_HPP_INCLUDED
#define ANIMATABLE_HPP_INCLUDED

#include <Elements/Drawable.hpp>
#include <Animations/AnimatedSprite.hpp>

namespace sg
{
    /*!
    *   \class Animatable
    *   \brief A animatable object is composed of animated sprites
    */
    class Animatable : public sg::Drawable
    {
        public :

            /*!
            *   \brief Constructor
            */
            Animatable();

            /*!
            *   \brief Destructor
            */
            ~Animatable();

            /*!
            *   \brief Add a new animated sprite
            *
            *   \param id The id of the animation
            *   \param sprite The sprite composed b the frames of the animation
            *   \param frameCount The number of frame in the animation
            *   \param frequency The number of frames per seconds
            *   \param gridSize The matrix of the animation
            *   \param frameSize The size of a unique frame
            *   \param isLooping Should the animation loop ?
            */
            void addAnimatedSprite(const std::string& id, sf::Sprite* sprite, int frameCount, int frequency,
                            sf::Vector2i gridSize, sf::Vector2i frameSize, bool isLooping);

            /*!
            *   \brief Set the current animated sprite
            *
            *   \param id The id of the whished animation
            */
            void setSprite(std::string& id);

        protected :

            sg::AnimatedSprite* m_currentAnimatedSprite;

            std::map<std::string, sg::AnimatedSprite*> m_mAnimatedSprite;

    };

} // namespace

#endif // ANIMATABLE_HPP_INCLUDED
