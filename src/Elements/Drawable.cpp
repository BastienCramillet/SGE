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

#include <Elements/Drawable.hpp>
#include <Engines/GraphicEngine.hpp>

#include <Core/DebugNew.hpp>

namespace sg
{
    Drawable::Drawable()
    {
        m_currentSprite = 0;
    }

    Drawable::~Drawable ()
    {
        m_currentSprite = 0;
        for(std::map<std::string, sf::Sprite*>::iterator it = m_mSprite.begin(); it != m_mSprite.end(); ++it)
        {
            it->second = 0;
        }
        m_mSprite.clear();
    }

    const sf::Sprite& Drawable::getCurrentSprite() const
    {
        if (! m_currentSprite) {
            Log::w("Drawable") << "No sprite selected";
        }
        return *m_currentSprite;
    }

    void Drawable::setCurrentSprite (const std::string &id)
    {
        m_currentSprite = m_mSprite[id];
    }

    void Drawable::setPosition(const sf::Vector2f& position)
    {
        m_currentSprite->setPosition(position);
    }

    void Drawable::addSprite(const std::string &url, sf::Sprite* sprite)
    {
        m_mSprite[url] = sprite;
    }


    void Drawable::addSprite(const std::string &url, sf::Sprite* sprite, int width, int height)
    {
        sprite->setOrigin(sf::Vector2f(width / 2.f, height / 2.f));
        m_mSprite[url] = sprite;
    }

} // namespace sg
