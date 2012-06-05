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

#include "Core/StopWatch.hpp"

#include "Views/View.hpp"
#include "Views/AnimatedViewStep.hpp"
#include "Views/TransitionTiming.hpp"

namespace sg {

    /*!
        \class AnimatedView
        \brief The animated view is a view which is really customizable, by using view steps

        The first call to update will lauch view timer

        Animated steps positions are computed when step is added in this view

        \b TIMES ARE DEFINED IN SECONDS

        \sa AnimatedViewStep

        Usage example :
        \code
            sg::GameFrame *gameFrame = new sg::GameFrame();
            gameFrame->loadLevel("data/maps/demo_map.xml");

            sg::AnimatedView *animatedView = new sg::AnimatedView(400, 300, 800, 600));

            // move left
            animatedView->createStep(sf::seconds(3), sf::seconds(10)).moveCenter(sf::Vector2f(2000, 0)).setAnimationTiming(sg::TransitionTiming::EASE_OUT);

            // zoom at the end
            animatedView->createStep(sf::seconds(10), sf::seconds(3)).zoom(0.5).setAnimationTiming(sg::TransitionTiming::EASE_IN);

            // unzoom
            animatedView->createStep(sf::seconds(15), sf::seconds(2)).zoom(-1).setAnimationTiming(sg::TransitionTiming::CUBIC_BEZIER);

            // rotate
            animatedView->createStep(sf::seconds(15), sf::seconds(2)).rotate(360);  // default timing

            // come back to normal zoom
            animatedView->createStep(sf::seconds(17), sf::seconds(2)).backToBaseZoom().setAnimationTiming(sg::TransitionTiming::LINEAR);

            gameFrame->setCurrentView("animated view demo");
        \endcode

    */
    class AnimatedView : public sg::View {

    public :

        /**
            \brief Build some view, with initial values
        */
        AnimatedView(const sf::Vector2f &center, const sf::Vector2f &size);

        /**
            \brief Destroy the view and steps
        */
        ~AnimatedView();

        /**
            \brief Create a view step
        */
        AnimatedViewStep& createStep(const sf::Time& start, const sf::Time& duration);


        /**
           \brief Update the view

           Override sg::View::update
        */
        void update();


    private :

        /**
            \brief Apply the view transformation, with the given factor as mulitplicator

            The final factor is 1, to complete animation
        */
        void applyView(AnimatedViewStep *v, float factor = 1.f);


        /**
            \brief View steps

            Initialy, all steps are stored in the vector
            When a step is over, it's removed from this vector and deleted
            So, only non achieved steps are in vector
        */
        std::vector<AnimatedViewStep*> m_steps;



        // ------------------------------------------
        // functions defined to back to initial state

        /**
            \brief Is used to compute base zoom
        */
        void addToBaseZoom(float factor);

        friend AnimatedViewStep& AnimatedViewStep::zoom(float);
        // ------------------------------------------



        StopWatch m_watch;       //!< internal timer to know where we are in animation. This timer starts at the first call to method update

        float m_zoomSum;         //!< This sum corresponds to the sum of applied zooms (to come back to base zoom)
    };

}

#endif // ANIMATED_VIEW_HPP_INCLUDED
