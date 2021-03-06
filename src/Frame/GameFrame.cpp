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

#include "../../include/Frame/GameFrame.hpp"

#include "../../include/Level.hpp"

#include "../../include/Tools/Log.hpp"

namespace sg {


    GameFrame::GameFrame() : Frame(), m_level(0) {
        Log::d("GameFrame") << "Creation of an empty game frame";
    }


    GameFrame::~GameFrame() {
        Log::d("GameFrame") << "Deleting game frame";
        if (m_level) {
            delete m_level;
        }
    }


    void GameFrame::loadLevel(const std::string &levelFile) {
        Log::d("GameFrame") << "Loading some level...";
        m_level = new Level();
        m_level->load(levelFile);
    }


    void GameFrame::update() {
        Frame::update();
        m_level->update();
    }

}
