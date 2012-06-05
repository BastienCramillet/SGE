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


/**
    \author Xavier
*/

#include "Views/AnimatedViewStep.hpp"

#include "Views/AnimatedView.hpp"

#include "Tools/Log.hpp"

#include "Views/TransitionTiming.hpp"

namespace sg {


    AnimatedViewStep::AnimatedViewStep(const sf::Time& start, const sf::Time& duration,  float baseZoom, const sf::Vector2f &baseCenter, AnimatedView *parent)
        : m_start(start), m_duration(duration), m_center(0), m_size(0), m_rotation(0), m_animationPointCount(10000),
          m_zoomFactor(0), m_baseZoom(baseZoom), m_parent(parent), m_animationTiming(&sg::TransitionTiming::DEFAULT),
          m_initialCenter(baseCenter)
    {
        m_end = m_start + m_duration;
    }


    AnimatedViewStep::~AnimatedViewStep() {
        delete m_center;
        delete m_zoomFactor;
        delete m_rotation;
    }


    AnimatedViewStep& AnimatedViewStep::moveCenter(const sf::Vector2f& center) {
        if (m_center) {
            Log::w("AnimatedViewStep") << "Re-define target center";
            delete m_center;
        }
        m_parent->addToBaseCenter(center);
        m_center = new sf::Vector2f(center);
        return *this;
    }


    AnimatedViewStep& AnimatedViewStep::rotate(float rotation) {
        if (m_rotation) {
            Log::w("AnimatedViewStep") << "Re-define target rotation";
            delete m_rotation;
        }
        m_rotation = new float(rotation);
        return *this;
    }


    AnimatedViewStep& AnimatedViewStep::zoom(float factor) {
        if (m_zoomFactor) {
            Log::w("AnimatedViewStep") << "Re-define target zoom";
            m_parent->addToBaseZoom(-*m_zoomFactor);
            delete m_zoomFactor;
        }
        m_parent->addToBaseZoom(factor);
        m_zoomFactor = new float(factor);
        return *this;
    }

    AnimatedViewStep& AnimatedViewStep::setPointCount(int pointCount) {
        m_animationPointCount = pointCount;
        return *this;
    }


    AnimatedViewStep& AnimatedViewStep::backToBaseZoom() {
        return zoom(-m_baseZoom);
    }


    AnimatedViewStep& AnimatedViewStep::backToInitialCenter() {
        return moveCenter(-m_initialCenter);
    }


    AnimatedViewStep& AnimatedViewStep::setTransitionTiming(TransitionTiming::AbstractTransitionTiming &timing) {
        m_animationTiming = &timing;
        return *this;
    }


    void AnimatedViewStep::computeTransition(const sf::Vector2f &start)
    {
        std::vector<sf::Vector2f> l;
        l.push_back(start);

        for (std::vector<sf::Vector2f>::const_iterator it = m_animationTiming->getPointsOnCurve().begin(); it != m_animationTiming->getPointsOnCurve().end(); ++it) {
            l.push_back(*it);
        }
        l.push_back(sf::Vector2f(1.f, 1.f));

        m_computedPoints = BezierCurve::computeBezierCurve(l, m_animationPointCount);
    }

}

