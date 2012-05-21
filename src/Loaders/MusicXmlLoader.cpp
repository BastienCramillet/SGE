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
*   \file MusicXmlLoader.cpp
*   \version 1.0
*/

#include <tinyxml.h>

#include "Loaders/MusicXmlLoader.hpp"

#include "Tools/Log.hpp"

namespace sg {

    MusicXmlLoader::MusicXmlLoader() {
        Log::i("MusicXmlLoader") << "Loading musics data from musics.xml";

        // return in case of error
        m_datas["default"] = new MusicData;

        TiXmlDocument doc("data/musics.xml");
        if ( ! doc.LoadFile() ) {
            Log::e("ImageXmlLoader") << "Cannot load file (" << "data/musics.xml" << ") ! "
                          << "error #" << doc.ErrorId() << " : " << doc.ErrorDesc();
            return;
        }

        TiXmlHandle hdl(&doc);


        /*
            Looking for items to load
        */

        TiXmlElement *music = hdl.FirstChildElement("musics").
                                         Element()->
                                         FirstChildElement();

        while (music) {

            Log::v("MusicXmlLoader") << "Music found : " << music->Attribute("id");

            MusicData *md = new MusicData;

            md->musicID        = std::string(music->Attribute("id"));
            md->url            = std::string(music->Attribute("url"));

            m_datas[md->musicID] = md;

            music = music->NextSiblingElement();
        }


        Log::i("MusicXmlLoader") << "Loading musics resources... Over !";
    }



    MusicXmlLoader::~MusicXmlLoader() {
        Log::i("MusicXmlLoader") << "unloading datas...";
        for (std::map<std::string, MusicData *>::iterator it = m_datas.begin(); it != m_datas.end(); ++it) {
            delete it->second;
        }
        m_datas.clear();
    }


    const MusicData* MusicXmlLoader::getMusicData(const std::string &musicID) {
        if ( ! m_datas[musicID] ) {
            Log::e("MusicXmlLoader") << "No music datas for ID : " << musicID;
            return m_datas["default"];
        }
        return m_datas[musicID];
    }

}


