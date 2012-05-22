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

#ifndef ANIMATED_VIEW_STEP_HPP_INCLUDED
#define ANIMATED_VIEW_STEP_HPP_INCLUDED

#include <vector>
#include <queue>

#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

#include "Tools/BezierCurve.hpp"

/**
  \author Xavier
*/

namespace sg {

    /**
        \class ViewStep
        \brief A view step, a state at a moment
    */
    class AnimatedViewStep {

        friend class AnimatedView;

    public :

        /**
            \brief Set the target center
        */
        AnimatedViewStep& moveCenter(const sf::Vector2f& center);

        /**
            \brief Set the target size
        */
        AnimatedViewStep& moveSize(const sf::Vector2f& size);

        /**
            \brief Set the target rotation
        */
        AnimatedViewStep& rotate(float rotation);

        /**
            \brief Set the animation point count

            The default value is 100

            More point there is, more precise will be the animation but this will take more time to calculate
        */
        AnimatedViewStep& setPointCount(int pointCount);


        /**
            \brief Destroy view step
        */
        ~AnimatedViewStep();


    private :

        AnimatedViewStep(const sf::Time& start, const sf::Time& duration);

        /**
            \brief Compute the animation points
        */
        void computeAnimation();


        sf::Time m_start;                           //!< Start of the animation

        sf::Time m_duration;                        //!< Duration of the animation

        sf::Time m_end;                             //!< End of the animation computed

        sf::Vector2f *m_center;                     //!< Target center of the animation (null if undefined)

        sf::Vector2f *m_size;                       //!< Target size of the animation (null if undefined)

        float *m_rotation;                          //!< Target rotation of the animation (null if undefined)

        int m_animationPointCount;                  //!< Number of point for calculating animation

        std::queue<sf::Vector2f> m_computedPoints;  //!< Points on animation curve

        float m_lastAcceleration;                   //!< Last

        sf::Time m_lastUpdateTime;
    };

}


#endif
