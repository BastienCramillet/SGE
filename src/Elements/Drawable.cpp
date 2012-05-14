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
        return *m_currentSprite;
    }

    void Drawable::setCurrentSprite (const std::string &id)
    {
        m_currentSprite = m_mSprite[id];
    }

    void Drawable::setPosition(sf::Vector2f position)
    {
        m_currentSprite->setPosition(position);
    }


    void Drawable::addSprite(const std::string &url, sf::Sprite* sprite)
    {
        m_mSprite[url] = sprite;
    }


    int Drawable::getZIndex() const {
        return zIndex;
    }

    void Drawable::setZIndex(int z) {
        zIndex = z;
    }

} // namespace sg
