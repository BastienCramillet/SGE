#include <Engines/GraphicEngine.hpp>
#include <Core/DebugNew.hpp>

#include "Elements/Drawable.hpp"

namespace sg
{

    GraphicEngine::GraphicEngine()
    {
    }

    GraphicEngine::~GraphicEngine ()
    {
        clear();
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

    /******************************************************
    *                     View Part                       *
    ******************************************************/

    void GraphicEngine::createView (sf::Vector2f center, sf::Vector2f size)
    {
        m_view = sf::View(center, size);
    }

    const sf::View& GraphicEngine::getView() const
    {
        return m_view;
    }

    void GraphicEngine::setViewPosition (sf::Vector2f position)
    {
        m_view.setCenter(position);
    }

    void GraphicEngine::setViewSize (sf::Vector2f size)
    {
        m_view.setSize(size);
    }

    void GraphicEngine::zoomView (float factor)
    {
        m_view.zoom(factor);
    }

    void GraphicEngine::rotateView (float angle)
    {
        m_view.rotate(angle);
    }

    void GraphicEngine::moveView (sf::Vector2f offset)
    {
        m_view.move(offset);
    }

    void GraphicEngine::draw (sf::RenderTarget& target)
    {
        int size = m_vDrawable.size();
        for (int i = 0; i < size; ++i)
        {
            target.draw(m_vDrawable[i]->getCurrentSprite());
        }
    }

    /******************************************************
    *                     Draw Part                       *
    ******************************************************/

    void GraphicEngine::draw (sf::RenderTarget& target, sf::Sprite& sprite)
    {
        target.draw(sprite);
    }

    sf::Sprite* GraphicEngine::getSprite(const std::string &url, int zIndex)
    {
        //const sf::Texture* img = m_resourceManager.getResource(url);
        sg::Drawable *d = new sg::Drawable();

        sf::Sprite* sprite = new sf::Sprite(*(m_resourceManager.getResource(url)));
        sprite->setPosition(sf::Vector2f(50,50));

        d->addSprite(url, sprite);
        d->setCurrentSprite(url);

        d->setZIndex(zIndex);

        m_vDrawable.push_back(d);

        // drawable has been added, sort according to ZValue
        std::sort(m_vDrawable.begin(), m_vDrawable.end(), ZIndexSort());

        return sprite;
    }

}
