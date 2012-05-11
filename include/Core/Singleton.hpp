/*------------------------------------------------------------------------------
*
* SGE - Simple Game Engine
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
*   \file Singleton.hpp
*   \brief Reusable singleton class model
*   \version 1.0
*   \author Bastien (Bigz) Cramillet
*/

#ifndef SINGLETON_HPP_INCLUDED
#define SINGLETON_HPP_INCLUDED

#include <Core/DebugNew.hpp>

namespace sg
{
    /*!
    *   \class Singleton
    *   \brief Reusable singleton class model
    */
    template <typename T>
    class Singleton
    {
        protected :

            /*!
            *   \brief Constructor
            */
            Singleton ();

            /*!
            *   \brief Destructor
            */
            ~Singleton ();

        public :

            /*!
            *   \brief Public interface
            *
            *   \return A reference to the singleton object
            */
            static T& getInstance ();

            /*!
            *   \brief Singleton killer
            */
            static void kill ();

        private :

            static T *m_singleton;  //!< The only one instance
    };

    #include "Singleton.inl"

    #include <Core/DebugNewOff.hpp>


} // namespace se

#endif // SINGLETON_HPP_INCLUDED
