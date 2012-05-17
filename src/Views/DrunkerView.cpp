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

#include "Views/DrunkerView.hpp"

#include "Tools/Randomizer.hpp"


namespace sg {

    DrunkerView::DrunkerView(const sf::Vector2f &center, const sf::Vector2f &size)
        : sg::View(center, size), m_viewRotatePositif(true), m_viewXGrowing(true), m_viewYGrowing(true)
    {
        m_saveViewInitialSize = size;

        m_offsetRotationLimits  = sf::Vector2f(0.0f, 0.05f);
        m_rotationLimits        = sf::Vector2f(-5.f, 4.f);
        m_offsetGrowX           = sf::Vector2f(1.0f, 4.5f);
        m_offsetGrowY           = sf::Vector2f(1.0f, 2.5f);
        m_growXLimits           = sf::Vector2f(-150.f, 150.f);
        m_growYLimits           = sf::Vector2f(-200.f, 200.f);
    }


    void DrunkerView::setOffsetRotationLimit(const sf::Vector2f &limits) {
        m_offsetRotationLimits = limits;
    }

    void DrunkerView::setOffsetGrowX(const sf::Vector2f &limits) {
        m_offsetGrowX = limits;
    }

    void DrunkerView::setOffsetGrowY(const sf::Vector2f &limits) {
        m_offsetGrowY = limits;
    }

    void DrunkerView::setXGrowingLimits(const sf::Vector2f &limits) {
        m_growXLimits = limits;
    }

    void DrunkerView::setYGrowingLimits(const sf::Vector2f &limits) {
        m_growYLimits = limits;
    }


    void DrunkerView::update()
    {
        float offsetRotationView = 0;
        float offsetSizeViewX    = 0;
        float offsetSizeViewY    = 0;

        offsetRotationView = Randomizer::random(m_offsetRotationLimits.x, m_offsetRotationLimits.y);
        if (m_viewRotatePositif && getRotation() < 180 && getRotation() > m_rotationLimits.y) {
            m_viewRotatePositif = false;
        }
        if (!m_viewRotatePositif && getRotation() > 180 && getRotation() <  (360 + m_rotationLimits.x)) {
            m_viewRotatePositif = true;
        }
        if (!m_viewRotatePositif) {
            offsetRotationView = -offsetRotationView;
        }

        offsetSizeViewX = Randomizer::random(m_offsetGrowX.x, m_offsetGrowX.y);
        offsetSizeViewY = Randomizer::random(m_offsetGrowY.x, m_offsetGrowY.y);

        if (m_viewXGrowing && getSize().x > m_saveViewInitialSize.x + m_growXLimits.y) {
            m_viewXGrowing = false;
        }
        if (!m_viewXGrowing && getSize().x < m_saveViewInitialSize.x + m_growXLimits.x) {
            m_viewXGrowing = true;
        }

        if (m_viewYGrowing && getSize().y > m_saveViewInitialSize.y + m_growYLimits.y) {
            m_viewYGrowing = false;
        }
        if (!m_viewYGrowing && getSize().y < m_saveViewInitialSize.y + m_growYLimits.x) {
            m_viewYGrowing = true;
        }


        if (!m_viewXGrowing) {
            offsetSizeViewX = - offsetSizeViewX;
        }
        if (!m_viewYGrowing) {
            offsetSizeViewY = - offsetSizeViewY;
        }

        setRotation(getRotation() + offsetRotationView);
        setSize(getSize().x + offsetSizeViewX, getSize().y + offsetSizeViewY);
    }

}

