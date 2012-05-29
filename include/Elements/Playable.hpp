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
*   \file Playable.hpp
*   \brief Playable object header
*   \version 0.1
*   \author Bastien (Bigz) Cramillet
*/

#ifndef PLAYABLE_HPP_INCLUDED
#define PLAYABLE_HPP_INCLUDED

#include <SFML/Audio.hpp>
#include <map>

namespace sg
{
    /*!
    *   \class Playable
    *   \brief Represent a playable object which can be played as different sounds
    */
    class Playable
    {
        public :

            /*!
            *   \brief Constructor
            */
            Playable ();

            /*!
            *   \brief Destructor
            */
            ~Playable ();

            /*!
            *   \brief Play the sound of the given id
            *
            *   \param id The id of the sound
            */
            void play(std::string& id);

            /*!
            *   \brief Add a sound to the playable object
            */
            void addSound(const std::string& id, sf::Sound* sound);

            /*!
            *   \brief Set the position of the object
            *
            *   \param position The new 3D position of the object
            */
            void setPosition(const sf::Vector3f& position);

        protected :

            std::map<std::string, sf::Sound*> m_mSound;     //!< All the different sounds of the playable and their id
    };
}

#endif // PLAYABLE_HPP_INCLUDED
