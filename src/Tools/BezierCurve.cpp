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
    \version 1.0
*/


#include "Tools/BezierCurve.hpp"

/**
    \brief This is square implementation
*/
#define SGE_POW_2(X) ((X)*(X))

/**
    \brief This is cube implementation
*/
#define SGE_POW_3(X) ((X)*(X)*(X))


namespace sg {


    std::queue<sf::Vector2f> BezierCurve::computeBezierCurveDegree1(const std::vector<sf::Vector2f> &points, float nb_points)
    {
        std::queue<sf::Vector2f> computedPoints;
        for (float i = 0.0f; i < 1.0f; i+=1.f / nb_points)
        {
            computedPoints.push(sf::Vector2f(i, i));
        }
        return computedPoints;
    }


    std::queue<sf::Vector2f> BezierCurve::computeBezierCurveDegree3(const std::vector<sf::Vector2f> &points, float nb_points)
    {
        const sf::Vector2f p0 = points[0];
        const sf::Vector2f p1 = points[1];
        const sf::Vector2f p2 = points[2];
        const sf::Vector2f p3 = points[3];

        std::queue<sf::Vector2f> computedPoints;
        for (float i = 0.0f; i < 1.0f; i += 1.f / nb_points)
        {
            float t = i;
            float x = SGE_POW_3(1-t)*p0.x + 3*t*SGE_POW_2(1-t)*p1.x + 3*SGE_POW_2(t)*(1-t)*p2.x + SGE_POW_3(t)*p3.x;
            float y = SGE_POW_3(1-t)*p0.y + 3*t*SGE_POW_2(1-t)*p1.y + 3*SGE_POW_2(t)*(1-t)*p2.y + SGE_POW_3(t)*p3.y;
            computedPoints.push(sf::Vector2f(x, y));
        }
        return computedPoints;
    }



    std::queue<sf::Vector2f> BezierCurve::computeBezierCurveDegreeN(const std::vector<sf::Vector2f> &points, float nb_points)
    {
        std::queue<sf::Vector2f> computedPoints;
        for(float i = 0.0f; i < 1.0f; i += 1.f / nb_points)
        {
            computedPoints.push(casteljau(points, i));
        }
        return computedPoints;
    }



    sf::Vector2f BezierCurve::casteljau(const std::vector<sf::Vector2f> &points, float param)
    {
        if (points.size() == 1) {
            return points[0];
        }

        std::vector<sf::Vector2f> newPoints;
        newPoints.resize(points.size()-1);

        for(int i=0; i<points.size()-1; i++) {
            newPoints[i] = points[i] * (1-param) + points[i+1] * param;
        }

        return casteljau(newPoints, param);
    }

}
