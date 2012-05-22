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

#ifndef ANIMATED_VIEW_HPP_INCLUDED
#define ANIMATED_VIEW_HPP_INCLUDED

/**
  \author Xavier
*/

#include <vector>
#include <queue>

#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

#include "Views/View.hpp"
#include "Views/AnimatedViewStep.hpp"


namespace sg {



    /*!
    *   \class AnimatedView
    *   \brief The animated view is a view which is really customizable, by using view steps
    *
    *   The first call to update will lauch view timer
    *
    *   Animated steps positions are computed when step is added in this view
    *
    *   TIMES ARE DEFINED IN SECONDS
    *
    *   \sa AnimatedViewStep
    */
    class AnimatedView : public sg::View {

    public :

        /**
            Build some view, with initial values
        */
        AnimatedView(const sf::Vector2f &center, const sf::Vector2f &size);

        /**
            Destroy the view and steps
        */
        ~AnimatedView();

        /**
            Create a view step
        */
        AnimatedViewStep& createStep(const sf::Time& start, const sf::Time& duration);


        /**
            Override sg::View::update

            Update the view
        */
        void update();


    private :

        /**
            Apply the view transformation, with the given factor as mulitplicator
        */
        void applyView(AnimatedViewStep *v, float factor = 1.f);


        /**
            \brief Add some step in the animated view

            The step will be automaticly managed by this view, you don't need to worry about memory management
        */
        void addStep(AnimatedViewStep *step);


        /**
            \brief View steps

            Initialy, all steps are stored in the vector
            When a step is over, it's removed from this vector and deleted
            So, only non achieved steps are in vector
        */
        std::vector<AnimatedViewStep*> m_steps;

        sf::Clock *m_timer;                 //!< internal timer to know where we are in animation. This timer starts at the first call to method update
    };

}

#endif // ANIMATED_VIEW_HPP_INCLUDED
