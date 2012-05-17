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
*   \file AudioEngine.cpp
*   \brief AudioEngine source code
*   \version 0.1
*   \author Bastien (Bigz) Cramillet
*/

#include <Engines/AudioEngine.hpp>
#include <Core/DebugNew.hpp>
#include <Managers/Settings.hpp>

namespace sg
{
    AudioEngine::AudioEngine()
    {

    }

    AudioEngine::~AudioEngine()
    {
        clear();
    }

    void AudioEngine::init()
    {
        sf::Listener::setPosition(sf::Vector3f(sg::Settings::getInstance().getAppWidth() / 2.f, sg::Settings::getInstance().getAppHeight() / 2.f, 0.f));

         // Make it face the right axis (1, 0, 0)
        sf::Listener::setDirection(0, 0, 1);
    }

    void AudioEngine::clear()
    {
        if (!m_vSound.empty())
        {
            int size = m_vSound.size();
            for (int i = 0; i < size; ++i)
            {
                delete m_vSound[i];
                m_vSound[i] = 0;
            }
        }

        if (!m_vMusic.empty())
        {
            int size = m_vMusic.size();
            for (int i = 0; i < size; ++i)
            {
                delete m_vMusic[i];
                m_vMusic[i] = 0;
            }
        }
    }

    sf::Sound* AudioEngine::getSound(const std::string& url)
    {
        sf::Sound* sound = new sf::Sound(*(m_resourceManager.getResource(url)));
        sound->setMinDistance(480.f);
        m_vSound.push_back(sound);
        return sound;
    }


}
