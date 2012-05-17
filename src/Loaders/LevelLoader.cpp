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
*   \file MapLoader.cpp
*   \version 1.0
*/

#include <set>
#include <map>

#include <tinyxml.h>

#include "Loaders/LevelLoader.hpp"

#include "Level.hpp"

#include "Tools/Log.hpp"

#include "Engines/PhysicEngine.hpp"
#include "Engines/GraphicEngine.hpp"
#include "Engines/AudioEngine.hpp"

#include "Loaders/ObjectXmlLoader.hpp"
#include "Loaders/ImageXmlLoader.hpp"

#include "Elements/Decor.hpp"
#include "Elements/StaticObject.hpp"
#include "Elements/DynamicObject.hpp"


namespace sg {


    void LevelLoader::loadLevel(const std::string &filePath, Level *level) {

        TiXmlDocument doc(filePath.c_str());
        if ( ! doc.LoadFile() ) {
            Log::e("LevelLoader") << "Cannot load map (" << filePath << ") ! "
                          << "error #" << doc.ErrorId() << " : " << doc.ErrorDesc();
            return;
        }

        TiXmlHandle hdl(&doc);
        TiXmlElement *root = hdl.FirstChildElement().Element();

        level->m_name = std::string(root->Attribute("name"));
        level->m_height = atof(root->Attribute("height"));
        level->m_width = atof(root->Attribute("width"));

        Log::i("LevelLoader") << "Loading map : " << level->m_name << " (" << level->m_width << " x " << level->m_height << ")";

        /*
            Looking for items to load
        */


        // 1. Object(s)
        TiXmlElement *objectToLoad = hdl.FirstChildElement().
                                         FirstChildElement("load").
                                         FirstChildElement("objects").
                                         Element()->
                                         FirstChildElement();

        std::set<std::string> objectToLoadIds;

        while (objectToLoad) {
            Log::v("LevelLoader") << "Object to load : " << objectToLoad->Attribute("id");
            objectToLoadIds.insert(std::string(objectToLoad->Attribute("id")));
            objectToLoad = objectToLoad->NextSiblingElement();
        }


        // 2. Music(s)
        TiXmlElement *musicToLoad = hdl.FirstChildElement().
                                        FirstChildElement("load").
                                        FirstChildElement("musics").
                                        Element()->
                                        FirstChildElement();

        while (musicToLoad) {
            Log::v("LevelLoader") << "Music to load : " << musicToLoad->Attribute("id");
            musicToLoad  = musicToLoad->NextSiblingElement();
        }


        /*
            Now we're looking for items which will fill the map
        */

        // 1. Objects
        Log::d("LevelLoader") << "Chargement des objets...";
        TiXmlElement *objectOnMap = hdl.FirstChildElement().
                                        FirstChildElement("items").
                                        FirstChildElement("objects").
                                        Element()->
                                        FirstChildElement();

        while (objectOnMap) {
            Log::v("LevelLoader") << "Object on map : " << objectOnMap->Attribute("id")
                          << " (" << objectOnMap->Attribute("x") << "," << objectOnMap->Attribute("y") << ")";

            const ImageData *imageData   = ImageXmlLoader::getInstance().getImageData(objectOnMap->Attribute("imageOnCreateID"));
            const ObjectData *objectData = ObjectXmlLoader::getInstance().getObjectData(objectOnMap->Attribute("id"));

            if (objectOnMap->Attribute("isOnBackground") == std::string("false")) { // this is a dynamic object

                if (objectOnMap->Attribute("isMovable") == std::string("true")) {

                    sg::DynamicObject* obj = new sg::DynamicObject(objectData->objectID);
                    obj->addSprite(
                                imageData->url,
                                GraphicEngine::getInstance().getSprite("data/images/" + imageData->url)
                               );
                    obj->setCurrentSprite(imageData->url);

                    for (std::multimap<std::string, std::string>::const_iterator it = objectData->sounds.begin(); it != objectData->sounds.end(); ++it) {
                        obj->addSound(it->first, AudioEngine::getInstance().getSound(it->second));
                    }

                    obj->addBody(sg::PhysicEngine::getInstance().createDynamicBox(
                                     atoi(objectOnMap->Attribute("x")),
                                     atoi(objectOnMap->Attribute("y")),
                                     objectData->width,
                                     objectData->height,
                                     atoi(objectOnMap->Attribute("density")),
                                     atoi(objectOnMap->Attribute("friction"))
                                     ));

                    level->m_vDynamics.push_back(obj);

                }
                else { // non movable

                    sg::StaticObject * obj = new sg::StaticObject(objectData->objectID);
                    obj->addSprite(
                                imageData->url,
                                GraphicEngine::getInstance().getSprite("data/images/" + imageData->url)
                                );
                    obj->setCurrentSprite(imageData->url);

                    for (std::multimap<std::string, std::string>::const_iterator it = objectData->sounds.begin(); it != objectData->sounds.end(); ++it) {
                        obj->addSound(it->first, AudioEngine::getInstance().getSound(it->second));
                    }

                    obj->addBody(sg::PhysicEngine::getInstance().createStaticBox(
                                     atoi(objectOnMap->Attribute("x")),
                                     atoi(objectOnMap->Attribute("y")),
                                     objectData->width,
                                     objectData->height
                                     ));

                    level->m_staticObjects.push_back(obj);
                }
            }
            else { // non dynamic object (decor)

                sg::Decor *decor = new sg::Decor(objectData->objectID);

                decor->addSprite(
                            imageData->url,
                            GraphicEngine::getInstance().getSprite("data/images/" + imageData->url)
                    );

                decor->setCurrentSprite(imageData->url);

                decor->setPosition(sf::Vector2f(
                                        atof(objectOnMap->Attribute("x")),
                                        atof(objectOnMap->Attribute("y"))
                                   )
                            );
            }

            objectOnMap  = objectOnMap->NextSiblingElement();
        }


        // 2. Areas
        Log::d("LevelLoader") << "Chargement des zones...";
        TiXmlElement *areaOnMap = hdl.FirstChildElement().
                                       FirstChildElement("items").
                                       FirstChildElement("areas").
                                       Element()->
                                       FirstChildElement();

        while (areaOnMap) {
            Log::v("LevelLoader") << "Area on map : " << areaOnMap->Attribute("description")
                          << " (" << areaOnMap->Attribute("x") << "," << areaOnMap->Attribute("y") << ")";
            Log::w("LevelLoader") << "This loading is not implemented yet !";
            areaOnMap = areaOnMap->NextSiblingElement();
        }


    }

}
