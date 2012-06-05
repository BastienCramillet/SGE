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

            AnimatedSprite ();

            AnimatedSprite (sf::Sprite* sprite, int frameCount, int frequency,
                            sf::Vector2i gridSize, sf::Vector2i frameSize, bool isLooping);

            void play ();

            void update ();

            void stop ();

            void pause ();

            void reset ();

            void nextFrame ();

        private :

            sf::Sprite* m_sprite;

            int m_frameCount;
            int m_frequency;

            sf::Vector2i m_gridSize;
            sf::Vector2i m_frameSize;

            bool m_isLooping;
            bool m_isPlaying;

            sg::StopWatch m_stopWatch;
            int m_currentFrame;
            float m_delay;

    };
} // namespace sg

#endif // ANIMATEDSPRITE_HPP_INCLUDED
