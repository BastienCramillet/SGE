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

/*!
*   \file Element.hpp
*   \brief Element header
*   \version 0.1
*   \author Bastien (Bigz) Cramillet
*/

#ifndef ELEMENT_HPP_INCLUDED
#define ELEMENT_HPP_INCLUDED

#include <string>

#include <SFML/System/Vector2.hpp>

namespace sg
{
    /*!
    *   \class Element
    *   \brief Base class of all the different elements which compose a level
    */
    class Element
    {
        public :

            /*!
            *   \brief Constructor
            *
            *   \param id The element id
            */
            Element(const std::string& id)
            {
                m_elementID = id;
            }

            /*!
            *   \brief Destructor
            */
            virtual ~Element() {
            }

            /*!
            *   \brief Get the element id
            */
            const std::string& getElementID() const
            {
                return m_elementID;
            }

            /*!
            *   \brief Pure virtual method to get the element position
            */
            virtual sf::Vector2f getPosition() const = 0;

    private :

        std::string m_elementID;    //!< The element id

    };
} // namespace sg

#endif // ELEMENT_HPP_INCLUDED
