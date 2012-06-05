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

#include "Views/AnimatedView.hpp"

#include <cmath>

#include "Tools/Log.hpp"


namespace sg {

    AnimatedView::AnimatedView(const sf::Vector2f &center, const sf::Vector2f &size)
        : sg::View(center, size), m_zoomSum(0)
    {
    }

    AnimatedView::~AnimatedView()
    {
        for (std::vector<AnimatedViewStep *>::iterator it = m_steps.begin(); it != m_steps.end(); ++it) {
            delete *it;
        }
        m_steps.clear();
    }


    void AnimatedView::initialize() {
        computeTransitions();
    }


    AnimatedViewStep& AnimatedView::createStep(const sf::Time& start, const sf::Time& duration) {
        AnimatedViewStep *step = new AnimatedViewStep(start, duration, m_zoomSum, m_centerMovesSum, this);
        m_steps.push_back(step);
        return *step;
    }


    void AnimatedView::computeTransitions() {
        for (std::vector<AnimatedViewStep *>::iterator it = m_steps.begin(); it != m_steps.end(); ++it) {
            (*it)->computeTransition();
        }
    }


    void AnimatedView::update()
    {
        if (m_steps.size() == 0) {
            return;
        }

        if (! m_watch.isRunning()) {
            m_watch.start();
        }

        // finished views
        for (std::vector<AnimatedViewStep *>::iterator it = m_steps.begin(); it != m_steps.end(); ) {
            if ((*it)->m_end <= m_watch.getElapsedTime()) {

                // correcting delta, see bellow for more explications
                sf::Vector2f lastVisitedPoint   = (*it)->m_computedPoints.front();
                sf::Vector2f currentPoint       = (*it)->m_computedPoints.back();
                applyView(*it, currentPoint.y - lastVisitedPoint.y);

                it =  m_steps.erase(it++);
            }
            else {
                ++it;
            }
        }


        // non finished but current played views
        for (std::vector<AnimatedViewStep *>::iterator it = m_steps.begin(); it != m_steps.end(); ++it) {
            if ((*it)->m_start <= m_watch.getElapsedTime()) {

                if ( (*it)->m_computedPoints.size() == 0 ) {
                    Log::w("AnimatedView") << "It seems like you're transition have not initially compute point positions "
                                           << "This mistake can lead to very low performances"
                                           << "I'm going to do it but you should make it when you create AnimatedView, by calling computeTransitions()"
                                           << "when you're creating the animation (loading screen)";
                    (*it)->computeTransition();
                }

                // t is the current pourcent accomplish
                float t = (m_watch.getElapsedTime() - (*it)->m_start).asSeconds() / (*it)->m_duration.asSeconds();

                // we're going to compute delta beetween last visited point and current point
                sf::Vector2f lastVisitedPoint   = (*it)->m_lastVisitedPoint;
                sf::Vector2f currentPoint       = (*it)->m_computedPoints.front();

                // find current point
                bool pointDefined = false;          // current point is different from lastVisitedPoint
                while (currentPoint.x < t)
                {
                    pointDefined = true;

                    // next !
                    (*it)->m_computedPoints.pop();
                    currentPoint = (*it)->m_computedPoints.front();
                }

                // compute more points if currentPoint == lastPoint
                if (! pointDefined) {

                    Log::w("AnimatedView") << "It seems like you're animation need more points to be fluid. I've currently "
                                           << (*it)->m_animationPointCount
                                           << " and I'm going to recompute position. It can lead to verry bad performances."
                                           << "You should give me more pointCount (see AnimatedViewStep::setPointCount(int pointCount)";

                    (*it)->m_animationPointCount *= 2;  // 2x more points on the curve !
                    (*it)->computeTransition(lastVisitedPoint);

                    // ignore the first (our position)
                    (*it)->m_computedPoints.pop();
                    currentPoint = (*it)->m_computedPoints.front();
                    (*it)->m_computedPoints.pop();
                }

                // calcule acceleration
                float acceleration = currentPoint.y - lastVisitedPoint.y;

                // save last visited point
                (*it)->m_lastVisitedPoint = currentPoint;

                // apply the move
                applyView(*it, acceleration);
            }
        }

    }


    void AnimatedView::applyView(AnimatedViewStep *v, float factor)
    {

        if (v->m_center) {
            this->move(*v->m_center * factor);
        }

        if (v->m_zoomFactor) {
            this->zoom(1-(*v->m_zoomFactor * factor));
        }

        if (v->m_rotation) {
            this->rotate(*v->m_rotation * factor);
        }
    }


    void AnimatedView::addToBaseZoom(float factor) {
        m_zoomSum += factor;
    }


    void AnimatedView::addToBaseCenter(const sf::Vector2f &center) {
        m_centerMovesSum += center;
    }

}

