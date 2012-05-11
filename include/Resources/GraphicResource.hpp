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

#ifndef GRAPHICRESOURCE_HPP_INCLUDED
#define GRAPHICRESOURCE_HPP_INCLUDED

/*!
*   \file GraphicResource.hpp
*   \brief A graphic resource
*   \version 1.0
*/

#include "ResourceSettings.hpp"

#include <SFML/Graphics/Texture.hpp>

#include "Resource.hpp"


namespace sg
{

    /*!
    *   \class GraphicResource
    *   \brief A graphic resource made with a SFML Texture
    */

    class GraphicResource : public Resource<sf::Texture>
    {
        public :

            GraphicResource(const std::string &url, DELETE_TYPE del) : Resource<sf::Texture>(del)
            {
                m_data = new sf::Texture();
                if (!m_data->loadFromFile(url))
                    Log::e("GraphicResource") << "Couldn't load the file : " << url;

            }

    };

} // namespace sg


#endif // GRAPHICRESOURCE_HPP_INCLUDED
