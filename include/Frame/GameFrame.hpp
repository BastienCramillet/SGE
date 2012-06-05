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

#ifndef GAME_FRAME_HPP_INCLUDED
#define GAME_FRAME_HPP_INCLUDED

/*!
*   \file
*   \brief
*   \version 0.1
*/

#include <string>
#include <functional>

#include "Frame.hpp"

namespace sg
{
    class Level;

    /**
        \class GameFrame
        \brief A game frame is a frame which contains a level
    */
    class GameFrame : public Frame
    {
        public :

            GameFrame();

            ~GameFrame();

            /**
                \brief Load the given level
            */
            void loadLevel(const std::string &levelFile);

            /**
                \brief Update the game frame (refresh object positions...)
            */
            void update();


        private :

            Level *m_level;

    };
} // namespace sg
#endif // GAME_FRAME_HPP_INCLUDED
