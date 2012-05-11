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
*   \file Resource.cpp
*   \brief Resources template class
*   \version 1.0
*/

namespace sg
{

    template<class T>
    inline Resource<T>::Resource(DELETE_TYPE deleteType)
                : m_data(0), m_deleteType(deleteType), m_nRefCount(0)
    {
    }

    template<class T>
    inline Resource<T>::~Resource()
    {
        delete m_data;
    }

    template<class T>
    inline void Resource<T>::addRef()
    {
        ++m_nRefCount;
    }

    template<class T>
    inline void Resource<T>::removeRef()
    {
        if (m_nRefCount > 0)
            --m_nRefCount;

        if ( m_nRefCount == 0 )
            release();
    }

    template<class T>
    inline void Resource<T>::release(bool forceDelete)
    {
        if (m_deleteType == NEVER_DELETE)
            return;

        if (forceDelete)
        {
            delete m_data;
            m_data = 0;
        }
        else if (m_deleteType == AUTO_DELETE && m_nRefCount == 0)
        {
            delete m_data;
            m_data = 0;
        }
    }

    template<class T>
    inline const T* Resource<T>::data() const
    {
        return m_data;
    }

    template<class T>
    inline bool Resource<T>::isToDelete() const
    {
        return (m_data == 0);
    }

} // namespace sg
