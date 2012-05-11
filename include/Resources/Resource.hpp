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

#ifndef RESOURCE_HPP_INCLUDED
#define RESOURCE_HPP_INCLUDED

/*!
*   \file Resource.hpp
*   \brief Resources template class
*   \version 1.0
*/

#include "ResourceSettings.hpp"

#include "Tools/Log.hpp"

namespace sg
{

    /*!
    *   \class Resource
    *   \brief Resources template class
    */

    template<typename T>
    class Resource
    {
        public :

            /*!
            *   \brief Constructor
            *
            *   \param deleteType An enumerate type describing the way to delete the resource
            */
            Resource(DELETE_TYPE deleteType);

            /*!
            *   \brief Add a reference on the resource
            */
            void addRef();

            /*!
            *   \brief Drop a reference on the resource
            */
            void removeRef();

            /*!
            *   \brief Free the resource
            */
            void release(bool forceDelete = false);

            /*!
            *   \brief Return a data pointer
            */
            const T* data() const;

            /*!
            *   \brief Return if the resource has to be deleted or not
            */
            bool isToDelete() const;

            /*!
            *   \typedef resource_type
            *   \brief Store the type of T inside the class for using it within the manager
            */
            typedef T Resource_type;

            /*!
            *   \brief Virtual destructor
            */
            virtual ~Resource();

        protected :

            T*              m_data;             //!< The stored data (image, sound, ...)
            DELETE_TYPE     m_deleteType;       //!< How will this resource been released ?
            int             m_nRefCount;        //!< References counter
    };


} // namespace sg

#include "Resource.inl"

#endif // RESSOURCE_HPP_INCLUDED
