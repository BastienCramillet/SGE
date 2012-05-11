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

#ifndef RESSOURCEMANAGER_HPP_INCLUDED
#define RESSOURCEMANAGER_HPP_INCLUDED

/*!
*   \file ResourceManager.hpp
*   \brief Resource manager template class
*   \version 1.0
*/


#include <cstring>
#include <map>


#include "ResourceSettings.hpp"
#include "Tools/Log.hpp"

namespace sg
{

    /*!
    *   \class ResourceManager
    *   \brief Resource manager template class
    */

    template<typename T>
    class ResourceManager
    {

        public :

            /*!
            *   \typedef Resource_type
            *   \brief The resource type of T
            */
            typedef typename T::Resource_type Resource_type;

            /*!
            *   \brief Resource manager constructor
            */
            ResourceManager();

            /*!
            *   \brief Return a pointer on the resource
            *   If the resource is not loaded, we load it at this time with the order to delete it when his ref count is null
            */
            virtual const Resource_type* getResource(const std::string &url) {
                if ( ! isLoaded(url) ) {
                    loadResource(url);
                }
                m_mResources[url]->addRef();
                return m_mResources[url]->data();
            }

            /*!
            *   \brief Send that the resource is not usefull anymore
            *   If the resource have to be delete, it will be now
            */
            virtual void releaseResource(const std::string &url);

            /*!
            *   \brief Order the loading of a resource
            *
            *   \param url Resource url
            *   \param deleteType The delete condition for delete the resource
            */
            virtual void loadResource(const std::string &url, DELETE_TYPE deleteType = AUTO_DELETE);

            /*!
            *   \brief Delete all resources except thoses with the delete type NEVER_DELETE
            */
            virtual void deleteAllResources();

            /*!
            *   \brief Delete all resources without exception. Do not take care of the delete type.
            */
            virtual void forceDeleteAllRessouces();

            /*!
            *   \brief Delete the resource if loaded. Do not take care of the delete type.
            */
            virtual void deleteResource(const std::string &url);

            /*!
            *   \brief Virtual destructor
            */
            virtual ~ResourceManager();

            /*!
            *   \brief Return if the resource is loaded, false otherwise
            */
            virtual bool isLoaded(const std::string &url) const;


        protected :

            std::map<std::string, T*> m_mResources;      //!< Map of loaded resources <url, resource>
    };


#include "ResourceManager.inl"

} // namespace sg



#endif // RESSOURCEMANAGER_HPP_INCLUDED
