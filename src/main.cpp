#include <Engines/WindowEngine.hpp>
#include <Engines/GraphicEngine.hpp>
#include <Engines/AudioEngine.hpp>
#include <Tools/Log.hpp>
#include <fstream>


#include <Core/MemoryManager.hpp>
#include <Managers/Settings.hpp>

#include <Frame/FrameManager.hpp>
#include <Frame/GameFrame.hpp>

int main()
{
    //std::ofstream file("logs.txt");
    //Log::setOutput(file);   // écrire les messages de log dans un fichier
    //Log::setLogLevel(DEBUG);

    Log::i("main") << "SGE stared !";

    sg::WindowEngine::getInstance().createWindow();
    sg::GraphicEngine::getInstance().createView(sf::Vector2f(sg::Settings::getInstance().getAppWidth() / 2,sg::Settings::getInstance().getAppHeight() / 2),
                                         sf::Vector2f(sg::Settings::getInstance().getAppWidth(),sg::Settings::getInstance().getAppHeight()));
    sg::AudioEngine::getInstance().init();

    // Frame tests
    sg::FrameManager frameManager;

    sg::GameFrame *gameFrame = new sg::GameFrame();
    gameFrame->loadLevel("data/maps/demo_map.xml");

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
