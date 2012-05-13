/*------------------------------------------------------------------------------
*
* SE - Simple Engine
*
* Copyright (c) 2010-2011 Bastien Cramillet (Bigz)(bastien.cramillet@gmail.com)
*                         Xavier Michel (Saffir)(xavier.michel.mx440@gmail.com)
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
*   \file Level.cpp
*   \brief Level implementation
*   \version 1.0
*/

#include <tinyxml.h>

#include "LevelLoader.hpp"
#include "Level.hpp"

#include "DynamicObject.hpp"

#include "Tools/Log.hpp"

namespace sg {


    Level::Level()
    {
        clear();
    }

    Level::~Level() {
        clear();
    }

    Level::Level(const std::string &filePath)
    {
        load(filePath);
    }


    void Level::load(const std::string &filePath)
    {
        clear();

        Log::i("Level") << "start loading (" << filePath << ")";

        LevelLoader::loadLevel(filePath, this);

        m_isLoaded = true;

        Log::i("Level") << "Loading is over (" << filePath << ")";
    }


    void Level::clear()
    {
        Log::d("Level") << "is clearing Level content";
        m_isLoaded = false;
        m_name = "";
        m_height = 0;
        m_width = 0;
        for (std::vector<DynamicObject *>::iterator it = m_vDynamics.begin(); it != m_vDynamics.end(); ++it) {
            delete *it;
        }
        m_vDynamics.clear();
    }


    void Level::update()
    {
        for (std::vector<DynamicObject *>::iterator it = m_vDynamics.begin(); it != m_vDynamics.end(); ++it) {
            (*it)->update();
        }
    }


    // getters

    const std::string& Level::getName() const {
        return m_name;
    }

    int Level::getHeight() const {
        return m_height;
    }

    int Level::getWidth() const {
        return m_width;
    }

    bool Level::isLoaded() const {
        return m_isLoaded;
    }

}
