/*------------------------------------------------------------------------------
*
* SGE - Simple Game Engine
*
* Copyright (c) 2012 Bastien Cramillet (Bigz)(bastien.cramillet@gmail.com)
*                    Xavier Michel (Saffir)(xavier.michel.mx440@gmail.com)
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

#ifndef CURVE_FACTORY_HPP
#define CURVE_FACTORY_HPP

#include <SFML/System/Vector2.hpp>

#include <vector>

namespace sg
{
    class BezierCurve;
    class CurveFactory
    {
        public:
            /** Default constructor */
            CurveFactory();
            /** Default destructor */
            virtual ~CurveFactory();

            sg::BezierCurve* createCurve(const std::vector<sf::Vector2f> points);

            sg::BezierCurve* createLinearCurve();

            sg::BezierCurve* createEaseInCurve();

            sg::BezierCurve* createEaseOutCurve();

            sg::BezierCurve* createEaseInEaseOutCurve();

            void clear();


        protected:
        private:
            std::vector<sg::BezierCurve*> m_vCurve; //!< All the curves created by the factory
    };
} // namespace
#endif // CURVE_FACTORY_HPP
