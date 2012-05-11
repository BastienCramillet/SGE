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
*   \file Map.cpp
*   \brief Map implementation
*   \version 1.0
*/

#include <tinyxml.h>

#include "Map.hpp"

#include "Tools/Log.hpp"

namespace sg {


    Map::Map()
    {
        clear();
    }


    Map::Map(const std::string &filePath)
    {
        load(filePath);
    }


    void Map::load(const std::string &filePath)
    {
        clear();

        Log::i("Map") << "start loading (" << filePath << ")";

        TiXmlDocument doc(filePath.c_str());
        if ( ! doc.LoadFile() ) {
            Log::e("Map") << "Cannot load map (" << filePath << ") ! "
                          << "error #" << doc.ErrorId() << " : " << doc.ErrorDesc();
            return;
        }

        TiXmlHandle hdl(&doc);
        TiXmlElement *root = hdl.FirstChildElement().Element();

        m_name = std::string(root->Attribute("name"));
        m_height = atof(root->Attribute("height"));
        m_width = atof(root->Attribute("width"));

        /*
            Looking for items to load
        */

        // 1. Object(s)
        TiXmlElement *objectToLoad = hdl.FirstChildElement().
                                         FirstChildElement("load").
                                         FirstChildElement("objects").
                                         Element()->
                                         FirstChildElement();

        while (objectToLoad) {
            Log::v("Map") << "Object to load : " << objectToLoad->Attribute("id");
            objectToLoad  = objectToLoad->NextSiblingElement();
        }

        // 2. Music(s)
        TiXmlElement *musicToLoad = hdl.FirstChildElement().
                                        FirstChildElement("load").
                                        FirstChildElement("musics").
                                        Element()->
                                        FirstChildElement();

        while (musicToLoad) {
            Log::v("Map") << "Music to load : " << musicToLoad->Attribute("id");
            musicToLoad  = musicToLoad->NextSiblingElement();
        }


        /*
            Now we're looking for items which will fill the map
        */

        // 1. Objects
        TiXmlElement *objectOnMap = hdl.FirstChildElement().
                                        FirstChildElement("items").
                                        FirstChildElement("objects").
                                        Element()->
                                        FirstChildElement();

        while (objectOnMap) {
            Log::v("Map") << "Object on map : " << objectOnMap->Attribute("id")
                          << " (" << objectOnMap->Attribute("x") << "," << objectOnMap->Attribute("y") << ")";
            objectOnMap  = objectOnMap->NextSiblingElement();
        }

        // 2. Areas
        TiXmlElement *areasOnMap = hdl.FirstChildElement().
                                       FirstChildElement("items").
                                       FirstChildElement("areas").
                                       Element()->
                                       FirstChildElement();

        while (areasOnMap) {
            Log::v("Map") << "Area on map : " << objectOnMap->Attribute("id")
                          << " (" << objectOnMap->Attribute("x") << "," << objectOnMap->Attribute("y") << ")";
            areasOnMap  = areasOnMap->NextSiblingElement();
        }


        /*
            Finished !
        */

        m_isLoaded = true;

        Log::i("Map") << "Loading is over (" << filePath << ")";
    }


    void Map::clear()
    {
        Log::d("Map") << "is clearing map content";
        m_isLoaded = false;
        m_name = "";
        m_height = 0;
        m_width = 0;
    }


    // getters

    const std::string& Map::getName() const {
        return m_name;
    }

    int Map::getHeight() const {
        return m_height;
    }

    int Map::getWidth() const {
        return m_width;
    }

    bool Map::isLoaded() const {
        return m_isLoaded;
    }

}
