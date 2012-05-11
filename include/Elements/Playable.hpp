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

#ifndef PLAYABLE_HPP_INCLUDED
#define PLAYABLE_HPP_INCLUDED

#include <SFML/Audio.hpp>
#include <map>

namespace sg
{
    class Playable
    {
        public :

            Playable ();
            ~Playable ();

            void play(std::string& id);

            void addSound (std::string& id, sf::Sound* sound);

            void setPosition(sf::Vector3f position);

        protected :

            std::map<std::string, sf::Sound*> m_mSound;
    };
}

#endif // PLAYABLE_HPP_INCLUDED
