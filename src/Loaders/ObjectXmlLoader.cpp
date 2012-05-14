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
*   \file MapObjectLoader.cpp
*   \version 1.0
*/

#include <tinyxml.h>

#include "ObjectXmlLoader.hpp"
#include "ImageXmlLoader.hpp"

#include "Tools/Randomizer.hpp"
#include "Tools/Log.hpp"


namespace sg {


    ObjectXmlLoader::ObjectXmlLoader() {

        Log::i("ObjectXmlLoader") << "Loading objects resources...";

        TiXmlDocument doc("data/objects.xml");
        if ( ! doc.LoadFile() ) {
            Log::e("ObjectXmlLoader") << "Cannot load file (" << "data/objects.xml" << ") ! "
                          << "error #" << doc.ErrorId() << " : " << doc.ErrorDesc();
            return;
        }

        TiXmlHandle hdl(&doc);


        /*
            Looking for items to load
        */

        TiXmlElement *object = hdl.FirstChildElement("objects").
                                         Element()->
                                         FirstChildElement();

        while (object) {

            Log::v("ObjectXmlLoader") << "Object found : " << object->Attribute("id");


            ObjectData *od = new ObjectData;
            od->objectID = std::string(object->Attribute("id"));
            od->width    = atoi(object->Attribute("width"));
            od->height   = atoi(object->Attribute("height"));


            // loading object images
            TiXmlElement *image = object->FirstChildElement("images")->FirstChildElement();
            while (image) {
                od->images.insert(std::pair<std::string, std::string>(image->Attribute("triggered"), image->Attribute("id")));
                image = image->NextSiblingElement();
            }

            // loading object sounds
            TiXmlElement *sound = object->FirstChildElement("sounds")->FirstChildElement();
            while (sound) {
                od->sounds.insert(std::pair<std::string, std::string>(sound->Attribute("triggered"), sound->Attribute("id")));
                sound = sound->NextSiblingElement();
            }

            // loading object ephemerals
            TiXmlElement *ephemeral = object->FirstChildElement("ephemerals")->FirstChildElement();
            while (ephemeral) {
                od->ephemerals.insert(std::pair<std::string, std::string>(ephemeral->Attribute("triggered"), ephemeral->Attribute("id")));
                ephemeral = ephemeral->NextSiblingElement();
            }

            m_datas[od->objectID] = od;

            object  = object->NextSiblingElement();
        }

        Log::i("ObjectXmlLoader") << "Loading objects resources... Over !";
    }


    ObjectXmlLoader::~ObjectXmlLoader() {
        Log::i("ObjectXmlLoader") << "unloading datas...";
        for (std::map<std::string, ObjectData*>::iterator it = m_datas.begin(); it != m_datas.end(); ++it) {
            delete it->second;
        }
        m_datas.clear();
    }


    const ObjectData* ObjectXmlLoader::getObjectData(const std::string &objectID) {
        if ( ! m_datas[objectID] ) {
            Log::w("ObjectXmlLoader") << "No object datas for ID : " << objectID;
        }
        return m_datas[objectID];
    }


    std::string ObjectXmlLoader::getSoundID(const std::string &objectID, const std::string &trigger) {

        if ( ! m_datas[objectID] ) {
            Log::w("ObjectXmlLoader") << "No object datas for ID : " << objectID;
        }
        ObjectData *od = m_datas[objectID];

        if ( od->sounds.count(trigger) > 0 ) {

            std::pair< std::multimap< std::string, std::string>::iterator, std::multimap<std::string, std::string>::iterator> it;
            it = od->sounds.equal_range(trigger);

            std::vector<std::string> soundsPossible;
            for (std::multimap<std::string, std::string>::iterator it2 = it.first; it2 != it.second; ++it2) {
                   soundsPossible.push_back( (*it2).second );
            }

            return soundsPossible[sg::Randomizer::random(0, soundsPossible.size() - 1)];
        }
        else {
            Log::e("ObjectXmlLoader") << "No sounds for trigger" << trigger << " on object " << objectID;
        }

        return "";
    }


    std::string ObjectXmlLoader::getImageID(const std::string &objectID, const std::string &trigger) {

        if ( ! m_datas[objectID] ) {
            Log::w("ObjectXmlLoader") << "No object datas for ID : " << objectID;
        }
        ObjectData *od = m_datas[objectID];

        if ( od->images.count(trigger) > 0 ) {

            std::pair< std::multimap< std::string, std::string>::iterator, std::multimap<std::string, std::string>::iterator> it;
            it = od->images.equal_range(trigger);

            std::vector<std::string> imagesPossible;
            for (std::multimap<std::string, std::string>::iterator it2 = it.first; it2 != it.second; ++it2) {
                   imagesPossible.push_back( (*it2).second );
            }

            return imagesPossible[sg::Randomizer::random(0, imagesPossible.size() - 1)];
        }
        else {
            Log::e("ObjectXmlLoader") << "No image for trigger" << trigger << " on object " << objectID;
        }

        return "";
    }


    std::string ObjectXmlLoader::getEphemeralID(const std::string &objectID, const std::string &trigger) {

        if ( ! m_datas[objectID] ) {
            Log::w("ObjectXmlLoader") << "No object datas for ID : " << objectID;
        }
        ObjectData *od = m_datas[objectID];

        if ( od->ephemerals.count(trigger) > 0 ) {

            std::pair< std::multimap< std::string, std::string>::iterator, std::multimap<std::string, std::string>::iterator> it;
            it = od->ephemerals.equal_range(trigger);

            std::vector<std::string> ephemeralsPossible;
            for (std::multimap<std::string, std::string>::iterator it2 = it.first; it2 != it.second; ++it2) {
                   ephemeralsPossible.push_back( (*it2).second );
            }

            return ephemeralsPossible[sg::Randomizer::random(0, ephemeralsPossible.size() - 1)];
        }
        else {
            Log::e("ObjectXmlLoader") << "No ephemeral for trigger" << trigger << " on object " << objectID;
        }

        return "";
    }


}

