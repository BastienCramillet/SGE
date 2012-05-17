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
*   \file LevelImageLoader.cpp
*   \version 1.0
*/

#include <tinyxml.h>

#include <Loaders/ImageXmlLoader.hpp>

#include <Engines/GraphicEngine.hpp>

#include <Tools/Log.hpp>


namespace sg {

    ImageXmlLoader::ImageXmlLoader() {
        Log::i("ImageXmlLoader") << "Loading images data from images.xml";

        TiXmlDocument doc("data/images.xml");
        if ( ! doc.LoadFile() ) {
            Log::e("ImageXmlLoader") << "Cannot load file (" << "data/images.xml" << ") ! "
                          << "error #" << doc.ErrorId() << " : " << doc.ErrorDesc();
            return;
        }

        TiXmlHandle hdl(&doc);


        /*
            Looking for items to load
        */

        TiXmlElement *image = hdl.FirstChildElement("images").
                                         Element()->
                                         FirstChildElement();

        while (image) {

            Log::v("ImageXmlLoader") << "Image found : " << image->Attribute("id");

            ImageData *lid = new ImageData;

            lid->imageID        = std::string(image->Attribute("id"));
            lid->width          = atoi(image->Attribute("width"));
            lid->height         = atoi(image->Attribute("height"));
            lid->rowCount       = atoi(image->Attribute("rowCount"));
            lid->columnCount    = atoi(image->Attribute("columnCount"));
            lid->isOneShotAnim  = (image->Attribute("isOneShotAnim") == std::string("true"));
            lid->url            = std::string(image->Attribute("url"));
            lid->isRectangular  = (image->Attribute("isRectangular") == std::string("true"));

            if ( ! lid->isRectangular ) { // load points

                TiXmlElement *point = image->FirstChildElement();
                while (point) {
                    lid->points.push_back(sf::Vector2f(
                                              atof(point->Attribute("x")),
                                              atof(point->Attribute("y"))));
                    point = point->NextSiblingElement();
                }
            }


            m_datas[lid->imageID] = lid;

            image = image->NextSiblingElement();
        }


        Log::i("ImageXmlLoader") << "Loading map resources... Over !";
    }



    ImageXmlLoader::~ImageXmlLoader() {
        Log::i("ImageXmlLoader") << "unloading datas...";
        for (std::map<std::string, ImageData *>::iterator it = m_datas.begin(); it != m_datas.end(); ++it) {
            delete it->second;
        }
        m_datas.clear();
    }


    const ImageData* ImageXmlLoader::getImageData(const std::string &imageID) {
        if ( ! m_datas[imageID] ) {
            Log::w("ImageXmlLoader") << "No images datas for ID : " << imageID;
        }
        return m_datas[imageID];
    }

}


