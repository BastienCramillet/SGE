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
*   \file SoundsXmlLoader.hpp
*   \version 1.0
*/



#ifndef SOUNDS_XML_LOADER_HPP
#define SOUNDS_XML_LOADER_HPP


#include <string>
#include <map>

#include <Core/Singleton.hpp>

namespace sg {


    /**
        \struct SoundData
        \brief Data which compose a sound
    */
    struct SoundData {
        std::string soundID;                //!< sound ID
        std::string url;                    //!< file url
    };


    /**
        \brief The SoundXmlLoader is a manager based on sounds.xml
    */
    class SoundXmlLoader : public Singleton<SoundXmlLoader> {

        friend class Singleton<SoundXmlLoader>;

    public :

        /**
            \brief Get images datas from image ID
        */
        const SoundData* getSoundData(const std::string &soundID);


    private :

        SoundXmlLoader();

        ~SoundXmlLoader();

        std::map<std::string, SoundData*> m_datas; // datas, loaded once from sounds.xml

    };

}



#endif // SOUNDS_XML_LOADER_HPP

