#include <Engines/GraphicEngine.hpp>
#include <Core/DebugNew.hpp>

namespace sg
{

    GraphicEngine::GraphicEngine()
    {
    }

    GraphicEngine::~GraphicEngine ()
    {
        clear();
    }

    void GraphicEngine::treatMessage (EngineMessage* message)
    {

        delete message;
    }

    void GraphicEngine::init()
    {

    }

    void GraphicEngine::clear()
    {
        if (!m_vDrawable.empty())
        {
            int size = m_vDrawable.size();
            for (int i = 0; i < size; ++i)
            {
                delete m_vDrawable[i];
                m_vDrawable[i] = 0;
            }
        }
    }

    void GraphicEngine::update ()
    {

    }



    void GraphicEngine::draw (sf::RenderTarget& target)
    {
        int size = m_vDrawable.size();
        for (int i = 0; i < size; ++i)
        {
            target.draw(*m_vDrawable[i]);
        }
    }

    /******************************************************
    *                     Draw Part                       *
    ******************************************************/

    void GraphicEngine::draw(sf::RenderTarget& target, sf::Sprite& sprite)
    {
        target.draw(sprite);
    }

    sf::Sprite* GraphicEngine::getSprite(const std::string &url)
    {
        //const sf::Texture* img = m_resourceManager.getResource(url);

        sf::Sprite* sprite = new sf::Sprite(*(m_resourceManager.getResource(url)));
        m_vDrawable.push_back(sprite);

        sprite->setPosition(sf::Vector2f(50,50));

        return sprite;
    }

}
