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
*   \file StaticObject.hpp
*   \brief Static object header
*   \version 0.1
*   \author Xavier
*/

#ifndef STATIC_OBJECT_HPP_INCLUDED
#define STATIC_OBJECT_HPP_INCLUDED

#include <Elements/DynamicObject.hpp>

namespace sg
{
    /*!
    *   \class StaticObject
    *   \brief Represent a physical but static object.
    *           Its position is just never updated and its body is set as static
    */
    class StaticObject : public DynamicObject
    {
        public :

            /*!
            *   \brief Constructor
            *
            *   \param elementID The id of the element
            */
            StaticObject(const std::string& elementID);

            /*!
            *   \brief The never used update of the object
            */
            inline void update() {
            }
    };
}


#endif // STATIC_OBJECT_HPP_INCLUDED
