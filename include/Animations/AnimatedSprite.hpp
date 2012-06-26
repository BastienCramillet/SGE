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
*   \file AnimatedSprite
*   \version 0.1
*   \author Bastien (Bigz) Cramillet
*/

#ifndef ANIMATEDSPRITE_HPP_INCLUDED
#define ANIMATEDSPRITE_HPP_INCLUDED

#include <Core/StopWatch.hpp>
#include <SFML/Graphics.hpp>

namespace sg
{
    /*!
    *   \class AnimatedSprite
    *   \brief Represent a complex sprite composed of many other subsprites
    *           The drew sub sprite change over the time to simulate an animation
    */
    class AnimatedSprite
    {
        public :

            /*!
            *   \brief Default constructor
            */
            AnimatedSprite ();

            /*!
            *   \brief Full constructor
            *
            *   \param sprite The sprite composed b the frames of the animation
            *   \param frameCount The number of frame in the animation
            *   \param frequency The number of frames per seconds
            *   \param gridSize The matrix of the animation
            *   \param frameSize The size of a unique frame
            *   \param isLooping Should the animation loop ?
            */
            AnimatedSprite (sf::Sprite* sprite, int frameCount, int frequency,
                            sf::Vector2i gridSize, sf::Vector2i frameSize, bool isLooping);

            /*!
            *   \brief Destructor
            */
            ~AnimatedSprite();

            /*!
            *   \brief Get the animated sprite
            *
            *   \return sf::Sprite
            */
            sf::Sprite* getAnimatedSprite();

            /*!
            *   \brief Play the animation
            */
            void play ();

            /*!
            *   \brief Update the animation
            */
            void update ();

            /*!
            *   \brief Stop the animation
            */
            void stop ();

            /*!
            *   \brief Pause the animation
            */
            void pause ();

            /*!
            *   \brief Restart the animation
            */
            void restart ();

            /*!
            *   \brief Reset the animation
            */
            void reset ();

            /*!
            *   \brief Change the current frame of the animation to the next one
            */
            void nextFrame ();

        private :

            sf::Sprite* m_sprite;

            bool            m_isLooping;    //!< Should the animation loop ?
            bool            m_isPlaying;    //!< Is the animation currently playing ?

            int             m_frameCount;   //!< The amount of frames which compose the animation
            int             m_frequency;    //!< FPS of the animation
            int             m_currentFrame; //!< The index of the current frame

            float           m_delay;        //!< Duration in seconds between two frames

            sf::Vector2i    m_gridSize;     //!< The matrix of the animation
            sf::Vector2i    m_frameSize;    //!< The size of a unique frame

            sg::StopWatch   m_stopWatch;    //!< A stop watch used for the timing of the animation

    };
} // namespace sg

#endif // ANIMATEDSPRITE_HPP_INCLUDED
