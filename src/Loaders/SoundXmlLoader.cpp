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
*   \file SoundXmlLoader.cpp
*   \version 1.0
*/

#include <tinyxml.h>

#include "Loaders/SoundXmlLoader.hpp"

#include "Tools/Log.hpp"

namespace sg {

    SoundXmlLoader::SoundXmlLoader() {
        Log::i("SoundXmlLoader") << "Loading musics data from musics.xml";

        // return in case of error
        m_datas["default"] = new SoundData;

        TiXmlDocument doc("data/musics.xml");
        if ( ! doc.LoadFile() ) {
            Log::e("SoundXmlLoader") << "Cannot load file (" << "data/musics.xml" << ") ! "
                          << "error #" << doc.ErrorId() << " : " << doc.ErrorDesc();
            return;
        }

        TiXmlHandle hdl(&doc);


        /*
            Looking for items to load
        */

        TiXmlElement *sound = hdl.FirstChildElement("musics").
                                         Element()->
                                         FirstChildElement();

        while (sound) {

            Log::v("SoundXmlLoader") << "Music found : " << sound->Attribute("id");

            SoundData *sd = new SoundData;

            sd->soundID        = std::string(sound->Attribute("id"));
            sd->url            = std::string(sound->Attribute("url"));

            m_datas[sd->soundID] = sd;

            sound = sound->NextSiblingElement();
        }


        Log::i("SoundXmlLoader") << "Loading sounds resources... Over !";
    }



    SoundXmlLoader::~SoundXmlLoader() {
        Log::i("SoundXmlLoader") << "unloading datas...";
        for (std::map<std::string, SoundData *>::iterator it = m_datas.begin(); it != m_datas.end(); ++it) {
            delete it->second;
        }
        m_datas.clear();
    }


    const SoundData* SoundXmlLoader::getSoundData(const std::string &soundID) {
        if ( ! m_datas[soundID] ) {
            Log::e("SoundXmlLoader") << "No sound datas for ID : " << soundID;
            return m_datas["default"];
        }
        return m_datas[soundID];
    }

}


