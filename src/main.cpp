#include <Engines/WindowEngine.hpp>
#include <Engines/GraphicEngine.hpp>
#include <Engines/AudioEngine.hpp>
#include <Tools/Log.hpp>
#include <fstream>


#include <Core/MemoryManager.hpp>
#include <Managers/Settings.hpp>

#include <Frame/FrameManager.hpp>
#include <Frame/GameFrame.hpp>

#include <Elements/Decor.hpp>

#include <Views/DrunkerView.hpp>

int main()
{
    //std::ofstream file("logs.txt");
    //Log::setOutput(file);   // écrire les messages de log dans un fichier
    //Log::setLogLevel(DEBUG);

    Log::i("main") << "SGE started !";

    sg::WindowEngine::getInstance().createWindow();
    sg::AudioEngine::getInstance().init();

    // Frame tests
    sg::FrameManager frameManager;

    std::string url = "data/images/fonds/fond.png";
    sg::Decor* obj = new sg::Decor("");
    obj->addSprite(url, sg::GraphicEngine::getInstance().getSprite(url));
    obj->setCurrentSprite(url);
    obj->setPosition(sf::Vector2f(-200, -1170));

    std::string url2 = "data/images/fonds/decor.png";
    sg::Decor* obj2 = new sg::Decor("");
    obj2->addSprite(url2, sg::GraphicEngine::getInstance().getSprite(url2));
    obj2->setCurrentSprite(url2);
    obj2->setPosition(sf::Vector2f(-200, -1170));

    sg::GameFrame *gameFrame = new sg::GameFrame();
    gameFrame->loadLevel("data/maps/demo_map.xml");

    gameFrame->addView(
                "simple view",
                 new sg::View(
                           sf::Vector2f(sg::Settings::getInstance().getAppWidth() / 2,sg::Settings::getInstance().getAppHeight() / 2),
                           sf::Vector2f(sg::Settings::getInstance().getAppWidth(),sg::Settings::getInstance().getAppHeight())
                    )
            );

    gameFrame->addView
            ("drunker view",
             new sg::DrunkerView(
                           sf::Vector2f(sg::Settings::getInstance().getAppWidth() / 2,sg::Settings::getInstance().getAppHeight() / 2),
                           sf::Vector2f(sg::Settings::getInstance().getAppWidth(),sg::Settings::getInstance().getAppHeight())
                    )
            );

    gameFrame->setCurrentView("drunker view");

    int gameFrameID = frameManager.addFrame(gameFrame);

    sg::WindowEngine::getInstance().run(gameFrame);

    // ---

//  sg::WindowEngine::getInstance().run();

    sg::GraphicEngine::getInstance().kill();
    sg::WindowEngine::getInstance().kill();

    #ifdef D_DEBUG
        sg::MemoryManager::getInstance().kill();
    #endif // _DEBUG


    return 0;
}
