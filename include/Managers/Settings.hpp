/*------------------------------------------------------------------------------
*
* SGE - Simple Game Engine
*
* Copyright (c) 2012 Bastien Cramillet (Bigz)(bastien.cramillet@gmail.com)
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

#ifndef SETTINGS_HPP_INCLUDED
#define SETTINGS_HPP_INCLUDED

/*!
*   \file
*   \brief
*   \version 0.1
*   \author Bastien (Bigz) Cramillet
*/

#include <Core/Singleton.hpp>

namespace sg
{
    /**
        \class Settings
        \brief Get and set application settings
    */
    class Settings : public Singleton<Settings>
    {
        friend class Singleton<Settings>;

        public :

            // get/set application
            int getAppHeight();
            int getAppWidth();

            void setAppHeight(int h);
            void setAppWidth(int w);


        protected :

            /*!
            *   \brief Constructeur de la classe
            */
            Settings();

            int app_width;      //!< Résolution en largeur de l'application
            int app_height;     //!< Résolution en hauteur de l'application

            int musicVolume;    //!< Volume de la musique en jeu
    };
} // namespace sg
#endif // SETTINGS_HPP_INCLUDED
