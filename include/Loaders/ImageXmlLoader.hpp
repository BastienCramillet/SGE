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
*   \file ImageXmlLoader.hpp
*   \version 1.0
*/



#ifndef IMAGE_XML_LOADER_HPP
#define IMAGE_XML_LOADER_HPP


#include <string>
#include <set>
#include <map>
#include <vector>

#include <SFML/System/Vector2.hpp>

#include <Core/Singleton.hpp>


namespace sg {


    /**
        \struct ImageData
        \brief Data which compose an image
    */
    struct ImageData {
        std::string imageID;                //!< image ID
        int width;                          //!< image width
        int height;                         //!< image height
        int rowCount;                       //!< row count (tileset)
        int columnCount;                    //!< column count (tileset)
        int frameCount;                     //!< Number of frame which compose the tile
        bool isOneShotAnim;                 //!< This image should be played only one time (explosion for example)
        int fps;                            //!< Image FPS
        std::string url;                    //!< Image url
        bool isRectangular;                 //!< For collision, if false, it's polygonal
        std::vector<sf::Vector2f> points;   //!< Points for collision
    };


    /**
        \class ImageXmlLoader
        \brief The LevelImageManger is a manager based on images.xml
    */
    class ImageXmlLoader : public Singleton<ImageXmlLoader> {

        friend class Singleton<ImageXmlLoader>;

    public :

        /**
            \brief Get images datas from image ID
        */
        const ImageData* getImageData(const std::string &imageID);


    private :

        ImageXmlLoader();

        ~ImageXmlLoader();

        std::map<std::string, ImageData*> m_datas; // datas, loaded once from images.xml

    };

}



#endif // MAPOBJECTLOADER_HPP

