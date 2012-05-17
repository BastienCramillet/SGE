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
*   \file MapObjectLoader.hpp
*   \version 1.0
*/

#ifndef MAPOBJECTLOADER_HPP
#define MAPOBJECTLOADER_HPP


#include <string>
#include <map>

#include <Core/Singleton.hpp>


namespace sg {

    /**
      Datas which compose an object
    */
    struct ObjectData {
        std::string objectID;                                       //!< Object ID
        int width;                                                  //!< image width
        int height;                                                 //!< image height
        std::multimap<std::string, std::string> sounds;             //!< object sounds (trigger / sound id)
        std::multimap<std::string, std::string> images;             //!< object images (trigger/ image id)
        std::multimap<std::string, std::string> ephemerals;         //!< object ephemerals (trigger / ephemeral id)
    };


    class ObjectXmlLoader : public Singleton<ObjectXmlLoader> {

        friend class Singleton<ObjectXmlLoader>;

    public :

        const ObjectData* getObjectData(const std::string& objectID);

        /**
            return a possible sound for the given trigger
        */
        std::string getSoundID(const std::string &objectID, const std::string &trigger);


        /**
            return a possible image for the given trigger
        */
        std::string getImageID(const std::string &objectID, const std::string &trigger);


        /**
            return a possible ephemeral for the given trigger
        */
        std::string getEphemeralID(const std::string &objectID, const std::string &trigger);


    private :

        ObjectXmlLoader();

        ~ObjectXmlLoader();

        std::map<std::string, ObjectData*> m_datas; // datas, loaded once from objects.xml
    };

}



#endif // MAPOBJECTLOADER_HPP
