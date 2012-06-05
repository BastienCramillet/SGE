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


#include "Frame/Frame.hpp"

#include "Views/View.hpp"

#include "Tools/Log.hpp"

namespace sg {

    Frame::Frame()
        : m_view(0)
    {
    }

    Frame::~Frame() {
        Log::d("Frame") << "Deleting frame";
        for (std::map<std::string, View *>::iterator it = m_views.begin(); it != m_views.end(); ++it) {
            delete it->second;
        }
        m_views.clear();
    }


    View* Frame::getCurrentView() {
        if (!m_view) {
            Log::w("Frame") << "No view selected";
        }
        return m_view;
    }


    void Frame::addView(const std::string &key, View *v) {
        if (! v->isInitialized() ) { // call once
            v->initialize();
            v->markAsInitialized();
        }
        m_views[key] = v;
    }


    void Frame::setCurrentView(const std::string &key) {
        if (! m_views[key]) {
            Log::e("Frame") << "This view doesn't exists : " << key;
        }
        m_view = m_views[key];
    }

    void Frame::update() {
        m_view->update();
    }
}
