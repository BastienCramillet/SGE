#include <Engines/WindowEngine.hpp>
//provisoire
#include <Engines/GraphicEngine.hpp>

#include <Core/DebugNew.hpp>

#include <Engines/AudioEngine.hpp>

#include <Engines/PhysicEngine.hpp>

#include <Managers/Settings.hpp>

#include <Elements/DynamicObject.hpp>
#include <Elements/Decor.hpp>

#include <Tools/Randomizer.hpp>

namespace sg
{
    WindowEngine::WindowEngine ()
    {
        m_window = 0;
        init();
    }

    WindowEngine::~WindowEngine ()
    {
        if (m_window != 0)
        {
            delete m_window;
        }
    }

    void WindowEngine::init()
    {
        Log::i("WindowEngine.cpp") << sg::Settings::getInstance().getAppWidth();
    }

    void WindowEngine::createWindow ()
    {
        m_window = new sf::RenderWindow(sf::VideoMode(sg::Settings::getInstance().getAppWidth(),
                                                      sg::Settings::getInstance().getAppHeight()),
                                        "Simple Game Engine",
                                        sf::Style::Close, sf::ContextSettings(0, 0, 4, 2, 0) );
        m_window->setFramerateLimit(100);
        Log::i("WindowEngine.cpp") << "Creation of the window";
    }

    void WindowEngine::run ()
    {
        // too old, just update and run with frame

        /*
        std::string url = "data/bouche_incendie.png";

        std::string urls = "data/Aterrissage.wav";


        sg::DynamicObject* dobj = new sg::DynamicObject();
        dobj->addBody(sg::PhysicEngine::getInstance().createStaticBox(500, 500, 500, 100));

        sg::DynamicObject* obj = new sg::DynamicObject();
        obj->addSprite(url, sg::GraphicEngine::getInstance().getSprite(url));
        obj->setCurrentSprite(url);
        obj->addSound(urls, sg::AudioEngine::getInstance().getSound(urls));
        obj->addBody(sg::PhysicEngine::getInstance().createDynamicBox(500, 100, 57, 87));

        //sg::PhysicEngine::getInstance().start();

        sf::Event event;
        while (m_window->isOpen())
        {
            sf::Vector3f pos = sf::Vector3f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y,0);
            // Get the keyboard and mouse events
            while (m_window->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    m_window->close();
                }
                if (event.key.code == sf::Keyboard::Up)     GraphicEngine::getInstance().moveView(sf::Vector2f(0,-50));
                if (event.key.code == sf::Keyboard::Down)   GraphicEngine::getInstance().moveView(sf::Vector2f(0,50));
                if (event.key.code == sf::Keyboard::Left)   GraphicEngine::getInstance().moveView(sf::Vector2f(-50,0));
                if (event.key.code == sf::Keyboard::Right)  GraphicEngine::getInstance().moveView(sf::Vector2f(50,0));
            }

            m_window->clear();
            //m_window->setView(GraphicEngine::getInstance().getView());

            dobj->update();
            obj->update();
            GraphicEngine::getInstance().draw(*m_window);

            m_window->display();
        }
        delete dobj;
        delete obj;
        */
    }



    void WindowEngine::run(GameFrame *gf) {

        sg::PhysicEngine::getInstance().start();


        sf::Event event;
        while (m_window->isOpen())
        {
            sf::Vector3f pos = sf::Vector3f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y,0);
            // Get the keyboard and mouse events
            while (m_window->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    m_window->close();
                }
                if (event.key.code == sf::Keyboard::Up)     gf->getCurrentView()->move(sf::Vector2f(0,-50));
                if (event.key.code == sf::Keyboard::Down)   gf->getCurrentView()->move(sf::Vector2f(0,50));
                if (event.key.code == sf::Keyboard::Left)   gf->getCurrentView()->move(sf::Vector2f(-50,0));
                if (event.key.code == sf::Keyboard::Right)  gf->getCurrentView()->move(sf::Vector2f(50,0));
            }

            m_window->clear();
            m_window->setView(*gf->getCurrentView());
            Log::v() << gf->getCurrentView()->getCenter().x << " ," << gf->getCurrentView()->getCenter().y;
            gf->update();

            GraphicEngine::getInstance().draw(*m_window);

            m_window->display();
        }
    }


}
