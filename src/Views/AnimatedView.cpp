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
        : sg::View(center, size), m_timer(0)
    {
    }

    AnimatedView::~AnimatedView()
    {
        delete m_timer;

        for (std::vector<AnimatedViewStep *>::iterator it = m_steps.begin(); it != m_steps.end(); ++it) {
            delete *it;
        }
        m_steps.clear();
    }


    AnimatedViewStep& AnimatedView::createStep(const sf::Time& start, const sf::Time& duration) {
        addStep(new AnimatedViewStep(start, duration));
        return *m_steps.back();
    }


    void AnimatedView::addStep(AnimatedViewStep *step)
    {
        step->computeAnimation();
        m_steps.push_back(step);
    }


    void AnimatedView::update()
    {
        if (m_steps.size() == 0) {
            return;
        }

        if (! m_timer) {
            m_timer = new sf::Clock();
        }

        // finished views
        for (std::vector<AnimatedViewStep *>::iterator it = m_steps.begin(); it != m_steps.end(); ) {
            if ((*it)->m_end <= m_timer->getElapsedTime()) {

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
            if ((*it)->m_start <= m_timer->getElapsedTime()) {

                // t is the current pourcent accomplish
                float t = (m_timer->getElapsedTime() - (*it)->m_start).asSeconds() / (*it)->m_duration.asSeconds();

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

                // calcule acceleration
                float acceleration = currentPoint.y - lastVisitedPoint.y;
/*
                // interpolation if currentPoint == lastPoint
                if (! pointDefined) {

                    const sf::Vector2f start = sf::Vector2f(0, 0);
                    const sf::Vector2f diff  = sf::Vector2f(1, 1);

                    currentPoint = start + t * diff;
                    acceleration = currentPoint.y - lastVisitedPoint.y;
                }
*/                //else {
                    //(*it)->m_lastAcceleration   = acceleration;
                    //(*it)->m_lastUpdateTime     = sf::seconds(t);
                    (*it)->m_lastVisitedPoint   = currentPoint;
                    //Log::v() << acceleration;
                //}


                //Log::d() << acceleration;

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

        if (v->m_size) {
            this->reset(sf::FloatRect(this->getCenter().x, this->getCenter().y, this->getSize().x * factor, this->getSize().y * factor));
        }

        if (v->m_rotation) {
            this->rotate(*v->m_rotation * factor);
        }
    }

}

