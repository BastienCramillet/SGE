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

    void Drawable::setPosition(sf::Vector2f position)
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
