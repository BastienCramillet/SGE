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

#ifndef AUDIOENGINE_HPP_INCLUDED
#define AUDIOENGINE_HPP_INCLUDED

#include <Core/Singleton.hpp>
#include <Engines/Engine.hpp>
#include <Resources/ResourceManager.hpp>
#include <Resources/AudioResource.hpp>
#include <SFML/Audio.hpp>

namespace sg
{


    class AudioEngine : public Singleton<AudioEngine>, public Engine
    {
        friend class Singleton<AudioEngine>;

        public :

            void init();

            void clear();

            sf::Sound* getSound(const std::string &url);

            void playSound (sf::Sound sound);

        private :

            AudioEngine();
            ~AudioEngine();
            void treatMessage (EngineMessage* message);

            std::vector<sf::Sound*> m_vSound;
            std::vector<sf::Music*> m_vMusic;

            ResourceManager<AudioResource> m_resourceManager;
    };
} // namespace sg

#endif // AUDIOENGINE_HPP_INCLUDED
