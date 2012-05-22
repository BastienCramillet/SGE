/*------------------------------------------------------------------------------
*
* SGE - Simple Game Engine
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

/*!
*   \file BezierCurve.hpp
*   \version 0.1
*   \author Xavier
*/

#ifndef BEZIER_CURVE_HPP_INCLUDED
#define BEZIER_CURVE_HPP_INCLUDED

#include <vector>
#include <queue>

#include <SFML/System/Vector2.hpp>

namespace sg
{

    /**
        \class BezierCurve
        \brief This class provides tools for computing bezier *2D* curve
    */
    class BezierCurve
    {

        public :

            /**
                \brief Compute point position for the given parameters

                \param points
                                points which defined the curve
                \param nb_point
                               number of point required in the returned list

                More point you wan't, and more computing points will take time

                This method delegate work, according to the inputted array size
            */
            inline static std::queue<sf::Vector2f> computeBezierCurve(const std::vector<sf::Vector2f> &points, float nb_points = 100.f)
            {
                // degree 1
                if (points.size() == 2) {
                    return computeBezierCurveDegree1(points, nb_points);
                }

                // degree 3
                if (points.size() == 4) {
                    return computeBezierCurveDegree3(points, nb_points);
                }

                // degree n
                return computeBezierCurveDegreeN(points, nb_points);
            }


    private :

            /**
                \brief Compute bezier curve of degree 1 (2 points)
            */
            static std::queue<sf::Vector2f> computeBezierCurveDegree1(const std::vector<sf::Vector2f> &points, float nb_points);

            /**
                \brief Compute bezier curve of degree 3 (4 points)
            */
            static std::queue<sf::Vector2f> computeBezierCurveDegree3(const std::vector<sf::Vector2f> &points, float nb_points);


            /**
                \brief Compute bezier curve of degree n (n-1 points)
            */
            static std::queue<sf::Vector2f> computeBezierCurveDegreeN(const std::vector<sf::Vector2f> &points, float nb_points);



            /**
                \brief An recursive implementation of the castlejau algorithm (not optimal)

                \see http://www.siteduzero.com/forum-83-475063-p1-afficher-une-courbe-de-bezier.html
            */
            static sf::Vector2f casteljau(const std::vector<sf::Vector2f> &points, float param);


    };
} // namespace sg

#endif // BEZIER_CURVE_HPP_INCLUDED
