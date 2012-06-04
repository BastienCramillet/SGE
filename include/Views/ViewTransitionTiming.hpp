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
    \brief This file contains default view animation timings
    \version 1.0
*/

#ifndef VIEW_TRANSITION_TIMING_HPP
#define VIEW_TRANSITION_TIMING_HPP

#include <vector>
#include <SFML/System/Vector2.hpp>

#include "Tools/Log.hpp"

namespace sg
{
    /**
        \namespace AnimationTiming
        \brief Contains default animations timing
    */
    namespace AnimationTiming {

        /**
            \struct AbstractAnimationTiming
            \brief Define the base for animation timing
        */
        struct AbstractAnimationTiming {

            /**
                \brief Get points which compose the bezier curve
                \warning Point at (0,0) and (1,1) souldn't be in the returned list
            */
            const std::vector<sf::Vector2f>& getPointsOnCurve() const {
                return m_points;
            }


            /**
                \brief Add a point on the curve (x, y)
            */
            void addPoint(int x, int y) {
                if (x<0 || x>1 || y<0 || y>1) {
                    Log::w("AbstractAnimationTiming") << "Point ignored, incorrect values : " << x << "," << y;
                }
                m_points.push_back(sf::Vector2f(x, y));
            }


            void addPoints(int lenght, int tab[][2]) {
                for (int i = 0; i<lenght; ++i) {
                    addPoint(tab[i][0], tab[i][1]);
                }
            }


            private :
                /**
                    \brief The vector is used to keep a cache of points
                */
                std::vector<sf::Vector2f> m_points;
        };





        /**
            \struct DefaultTiming
            \brief Default animation timing
        */
        struct DefaultTiming : public AbstractAnimationTiming {
            DefaultTiming() {
                addPoint(0.25, 0.1);
                addPoint(0.25, 1);
            }
        };
        // is declared in .cpp
        extern DefaultTiming DEFAULT_TIMING;



        /**
            \struct LinearTiming
            \brief Linear timing
        */
        struct LinearTiming : public AbstractAnimationTiming {
            LinearTiming() {
            }
        };
        // is declared in .cpp
        extern LinearTiming LINEAR_TIMING;


        /**
            \struct EaseInTiming
            \brief Ease-in function
        */
        struct EaseInTiming : public AbstractAnimationTiming {
            EaseInTiming() {
                addPoint(0.42, 0.f);
                addPoint(1.f, 1.f);
            }
        };
        // is declared in .cpp
        extern EaseInTiming EASE_IN_TIMING;



        /**
            \struct EaseOutTiming
            \brief Ease-out function
        */
        struct EaseOutTiming : public AbstractAnimationTiming {
            EaseOutTiming() {
                addPoint(0.f, 0.f);
                addPoint(0.58, 1.f);
            }
        };
        // is declared in .cpp
        extern EaseOutTiming EASE_OUT_TIMING;



        /**
            \struct EaseInOutTiming
            \brief Ease-in-out function
        */
        struct EaseInOutTiming : public AbstractAnimationTiming {
            EaseInOutTiming() {
                addPoint(0.42, 0.f);
                addPoint(0.58, 1.f);
            }
        };
        // is declared in .cpp
        extern EaseInOutTiming EASE_IN_OUT_TIMING;



        /**
            \struct CubicBezierTiming
            \brief Bezier cubic timing
        */
        struct CubicBezierTiming : public AbstractAnimationTiming {
            CubicBezierTiming() {
                addPoint(0.f, 1.f);
                addPoint(1.f, 0.f);
            }
        };
        // is declared in .cpp
        extern CubicBezierTiming CUBIC_BEZIER_TIMING;


    }

}


#endif
