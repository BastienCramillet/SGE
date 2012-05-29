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
*   \file Physical.hpp
*   \brief Physical object header
*   \version 0.1
*   \author Bastien (Bigz) Cramillet
*/

#ifndef PHYSICAL_HPP_INCLUDED
#define PHYSICAL_HPP_INCLUDED

class b2Body;
class b2Vec2;

namespace sg
{
    /*!
    *   \class Physical
    *   \brief Represent a Box2D physical object
    */
    class Physical
    {
        public :

            /*!
            *   \brief Constructor
            */
            Physical ();

            /*!
            *   \brief Destructor
            */
            ~Physical ();

            /*!
            *   \brief Get the body position
            */
            const b2Vec2& getBodyPosition() const;

            /*!
            *   \brief Get the body rotation
            */
            const float getBodyAngle() const;

            /*!
            *   \brief Set the Box2D body of the physical object
            *
            *   \param body The Box2D body
            */
            void addBody(b2Body* body);

        protected :

            b2Body* m_body;     //!< The Box2D body of the physical object
    };
} // namespace sg

#endif // PHYSICAL_HPP_INCLUDED
