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

#ifndef AUDIORESOURCE_HPP_INCLUDED
#define AUDIORESOURCE_HPP_INCLUDED

/*!
*   \file AudioResource.hpp
*   \brief An audio resource
*   \version 1.0
*/

#include "ResourceSettings.hpp"

#include <SFML/Audio.hpp>

#include "Resource.hpp"

#include <Core/DebugNew.hpp>

namespace sg
{

    /*!
    *   \class AudioResource
    *   \brief An audio resource made with a SFML Music or Sound
    */

    class AudioResource : public Resource<sf::SoundBuffer>
    {
        public :

            AudioResource(const std::string &url, DELETE_TYPE del) : Resource<sf::SoundBuffer>(del)
            {

                    m_data = new sf::SoundBuffer;
                    if (!m_data->loadFromFile(url))
                        Log::e("SoundResource") << "Couldn't load the file : " << url;



            }

    };

} // namespace sg

#include <Core/DebugNewOff.hpp>


#endif // AUDIORESOURCE_HPP_INCLUDED
