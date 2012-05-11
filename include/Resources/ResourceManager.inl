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

/*!
*   \file ResourceManager.cpp
*   \brief Resources manager template class
*   \version 0.1
*/




    template<class T>
    inline ResourceManager<T>::ResourceManager()
    {
    }

    template<class T>
    inline ResourceManager<T>::~ResourceManager()
    {
        forceDeleteAllRessouces();
        Log::i("ResourceManager") << "Bye !";
    }


    //    virtual const Resource_type* getResource(const std::string &url) { ?
    //      implemented in header

    template<class T>
    inline void ResourceManager<T>::releaseResource(const std::string &url)
    {
        if ( isLoaded(url) ) {
            m_mResources[url]->removeRef();
            if ( m_mResources[url]->isToDelete() ) {
                deleteResource(url);
            }
        } else {
            Log::w("ResourceManager") << "Releasing an unload resource : " << url;
        }
    }

    template<class T>
    inline void ResourceManager<T>::loadResource(const std::string &url, DELETE_TYPE deleteType)
    {
        Log::v("ResourceManager") << "Loading resource : " << url;
        m_mResources[url] = new T(url, deleteType);
    }

    template<class T>
    inline void ResourceManager<T>::deleteAllResources()
    {
        Log::d("ResourceManager") << "All resource are being deleted";
        for (typename std::map<std::string, T*>::iterator it = m_mResources.begin(); it != m_mResources.end();)
        {
            it->second->release(true);
            if (it->second->isToDelete()) {
                m_mResources.erase(it++);
            } else {
                ++it;
            }
        }

    }

    template<class T>
    inline void ResourceManager<T>::forceDeleteAllRessouces()
    {
        Log::d("ResourceManager") << "All resources are being deleted (without exception)";
        for (typename std::map<std::string, T*>::iterator it = m_mResources.begin(); it != m_mResources.end();)
        {
            delete m_mResources[it->first];
            m_mResources[it->first] = 0;
            m_mResources.erase(it++);
        }
        m_mResources.clear();
    }

    template<class T>
    inline void ResourceManager<T>::deleteResource(const std::string &url)
    {
        Log::v("ResourceManager") << "deleting resource : " << url;
        if ( isLoaded(url) ) {
            delete m_mResources[url];
            m_mResources[url] = 0;
            m_mResources.erase(url);
        }
    }

    template<class T>
    inline bool ResourceManager<T>::isLoaded(const std::string &url) const
    {
        return (m_mResources.find(url) != m_mResources.end());
    }
