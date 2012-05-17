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

#ifndef DRUNKER_VIEW_HPP_INCLUDED
#define DRUNKER_VIEW_HPP_INCLUDED

#include "Views/View.hpp"

#include <SFML/System/Vector2.hpp>

namespace sg {

    /*!
    *   \class SimpleView
    *   \brief A drunker view is a view... drink vodka, you'll see
    */
    class DrunkerView : public sg::View {

    public :


        DrunkerView(const sf::Vector2f &center, const sf::Vector2f &size);


        /**
            Override sg::View::update

            Update the view (automatics randomizedmoves)
        */
        void update();


        /**
            Fix the min & max rotation speed

            Default values are 0 .. 0.05
        */
        void setOffsetRotationLimit(const sf::Vector2f &limits);

        /**
          Fix the min & max rotation (in degrees)

          Default values are -5 .. 4
        */
        void setRotationLimits(const sf::Vector2f &limits);

        /**
            Fix the min & max x growing speed

            Default values are 1 .. 4.5
        */
        void setOffsetGrowX(const sf::Vector2f &limits);

        /**
            Fix the min & max y growing speed

            Default values are 1 .. 2.5
        */
        void setOffsetGrowY(const sf::Vector2f &limits);

        /**
          Fix the min & max x growing

          Default values are -150 .. 150
        */
        void setXGrowingLimits(const sf::Vector2f &limits);

        /**
          Fix the min & max x growing

          Default values are -200 .. 200
        */
        void setYGrowingLimits(const sf::Vector2f &limits);


    private :

        bool m_viewRotatePositif;

        bool m_viewXGrowing;

        bool m_viewYGrowing;

        sf::Vector2f m_saveViewInitialSize;


        sf::Vector2f m_offsetRotationLimits;    //!< min and max rotation offset

        sf::Vector2f m_rotationLimits;          //!< min and max rotation (degres)

        sf::Vector2f m_offsetGrowX;             //!< limits for x growing speed

        sf::Vector2f m_offsetGrowY;             //!< limits for y growing speed

        sf::Vector2f m_growXLimits;             //!< limits for x growing

        sf::Vector2f m_growYLimits;             //!< limits for y growing
    };

}

#endif
