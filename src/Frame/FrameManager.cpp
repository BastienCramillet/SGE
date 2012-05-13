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

#include "../../include/Frame/Frame.hpp"
#include "../../include/Frame/FrameManager.hpp"

#include "../../include/Tools/Log.hpp"

#include "ObjectXmlLoader.hpp"
#include "ImageXmlLoader.hpp"


namespace sg {


    FrameManager::FrameManager() {

    }


    FrameManager::~FrameManager() {
        Log::i("FrameManager") << "Deleting all frames...";
        for (unsigned int i = 0; i < m_frames.size(); ++i)
        {
            unloadFrame(i);
        }
        m_frames.clear();

        ImageXmlLoader::kill();
        ObjectXmlLoader::kill();
    }


    int FrameManager::addFrame(Frame *frame) {
        Log::i("FrameManager") << "Adding a new frame";
        m_frames.push_back(frame);
        return m_frames.size() - 1;
    }


    void FrameManager::unloadFrame(int frameID) {
        Log::v("FrameManager") << "Unloading frame #" << frameID;
        if (m_frames[frameID] != 0) {
            delete m_frames[frameID];
            m_frames[frameID] = 0;
        }
    }

}
