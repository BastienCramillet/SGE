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

/*!
*   \file Settings.hpp
*   \brief Settings source file
*   \version 0.1
*   \author Bastien (Bigz) Cramillet
*/

#include <Managers/Settings.hpp>

#include <Tools/Log.hpp>
#include <tinyxml.h>

namespace sg
{

    Settings::Settings() {

        //Chargement du fichier config.xml contenant les informations d'options du jeu.
        TiXmlDocument doc("data/config.xml");
        if( ! doc.LoadFile() ){
            Log::e("Settings.cpp") << "Error while loading config.xml";
            Log::e("Settings.cpp") << "error #" << doc.ErrorId() << " : " << doc.ErrorDesc();
            exit(0);
        }

        TiXmlHandle hdl(&doc);
        TiXmlElement *elem = hdl.FirstChildElement().FirstChildElement().Element();

        while( elem ){

            if ( elem->Attribute("name") == std::string("resolution") ) {
                if (atoi(elem->Attribute("width")))
                {
                    app_width = atoi(elem->Attribute("width"));
                    Log::i("Settings.cpp") << "Application window width : " << app_width;
                    app_height = atoi(elem->Attribute("height"));
                    Log::i("Settings.cpp") << "Application window height : " << app_height;
                } // sinon on garde les valeurs par défaut définies plus haut
            }


            else if ( elem->Attribute("name") == std::string("musique") ) {
                if (atoi(elem->Attribute("volume"))) {
                    musicVolume = atoi(elem->Attribute("volume"));
                }
            }

            elem = elem->NextSiblingElement();
        }

    }


    // get

    int Settings::getAppHeight() {
        return app_height;
    }

    int Settings::getAppWidth() {
        return app_width;
    }
    // set

    void Settings::setAppHeight(int h) {
        app_height = h;
    }

    void Settings::setAppWidth(int w) {
        app_width = w;
    }

} // namespace
