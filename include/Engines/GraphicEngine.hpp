/*------------------------------------------------------------------------------
*
* SGE - Simple Game Engine
*
* Copyright (c) 2012 Bastien Cramillet (Bigz)(bastien.cramillet@gmail.com)
*                    Xavier Michel (Saffir)(xavier.michel.mx440@gmail.com)
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
*   \file GraphicEngine.hpp
*   \brief Graphic Engine class header
*   \version 0.1
*   \author Bastien (Bigz) Cramillet
*/

#ifndef GRAPHICENGINE_HPP_INCLUDED
#define GRAPHICENGINE_HPP_INCLUDED

#include <Core/Singleton.hpp>
#include <Engines/Engine.hpp>
#include <SFML/Graphics.hpp>

#include <Resources/ResourceManager.hpp>
#include <Resources/GraphicResource.hpp>


namespace sg
{
    class Drawable;

    class GraphicEngine : public Singleton<GraphicEngine>, public Engine
    {
        friend class Singleton<GraphicEngine>;

        public :

            void init();

            void clear();

            void update ();


            void draw (sf::RenderTarget& target);

            void draw (sf::RenderTarget& target, sf::Sprite& sprite);

            sf::Sprite* getSprite(const std::string& url);

        private :

            GraphicEngine ();

            ~GraphicEngine ();

            void treatMessage (EngineMessage* message);

            std::vector<sf::Drawable *> m_vDrawable;

            ResourceManager<GraphicResource> m_resourceManager;



    };
} // namespace sg

#endif // GRAPHICENGINE_HPP_INCLUDED
