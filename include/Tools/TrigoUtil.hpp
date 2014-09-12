/*------------------------------------------------------------------------------
*
* SE - Simple Engine
*
* Copyright (c) 2010-2011 Bastien Cramillet (Bigz)(bastien.cramillet@gmail.com)
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

#ifndef TRIGOUTIL_HPP_INCLUDED
#define TRIGOUTIL_HPP_INCLUDED

#include <SFML/System/Vector2.hpp>

namespace sg
{
    class TrigoUtil
    {
        public :

            /** \brief Compute and return the position of a point to another
             *         from the angle and the distance between those two.
             *
             * \param angle The angle between the two points
             * \param ditance The distance between the two points
             * \return The position (a vector) of a point in the referential of the other
             */
            static sf::Vector2f computeVector(float angle, float distance);
    };
}



#endif // TRIGOUTIL_HPP_INCLUDED
