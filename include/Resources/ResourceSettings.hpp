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

#ifndef RESSOURCESETTINGS_HPP_INCLUDED
#define RESSOURCESETTINGS_HPP_INCLUDED

/*!
*   \file ResourceSettings.hpp
*   \brief Contain some settings and configuration usefull for resources
*   \version 1.0
*/


namespace sg {

    /*!
    *   \enum DELETE_TYPE
    *   \brief Define how the resource will be delete
    */
    enum DELETE_TYPE
    {
        AUTO_DELETE,    //!< Auto delete the resource when not used anymore
        DO_NOT_DELETE,  //!< Not AUTO_DELETE, but the resource will be deleted when all the resources will be delete
        NEVER_DELETE    //!< Never delete unless it's forced
    };

} // namespace sg

#endif // RESSOURCESETTINGS_HPP_INCLUDED
