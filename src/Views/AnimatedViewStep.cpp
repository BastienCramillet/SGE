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

#include "Tools/Log.hpp"


namespace sg {


    AnimatedViewStep::AnimatedViewStep(const sf::Time& start, const sf::Time& duration)
        : m_start(start), m_duration(duration), m_center(0), m_size(0), m_rotation(0), m_animationPointCount(10000)
    {
        m_end = m_start + m_duration;
    }


    AnimatedViewStep::~AnimatedViewStep() {
        delete m_center;
        delete m_size;
        delete m_rotation;
    }


    AnimatedViewStep& AnimatedViewStep::moveCenter(const sf::Vector2f& center) {
        m_center = new sf::Vector2f(center);
        return *this;
    }


    AnimatedViewStep& AnimatedViewStep::moveSize(const sf::Vector2f& size) {
        m_size = new sf::Vector2f(size);
        return *this;
    }


    AnimatedViewStep& AnimatedViewStep::rotate(float rotation) {
        m_rotation = new float(rotation);
        return *this;
    }


    AnimatedViewStep& AnimatedViewStep::setPointCount(int pointCount) {
        m_animationPointCount = pointCount;
        return *this;
    }



    void AnimatedViewStep::computeAnimation(const sf::Vector2f &start)
    {
        //sf::Vector2f p0(0, 0);
        //sf::Vector2f p1(0, 1);
        //sf::Vector2f p2(1, 0);
        //sf::Vector2f p1(0.25, 0.1);
        //sf::Vector2f p2(0.25, 1);
        sf::Vector2f p3(1, 1);

        std::vector<sf::Vector2f> l;
        l.push_back(start);
        //l.push_back(p1);
        //l.push_back(p2);
        l.push_back(p3);

        m_computedPoints = BezierCurve::computeBezierCurve(l, m_animationPointCount);
    }

}

