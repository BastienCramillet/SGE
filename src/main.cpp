#include <Engines/WindowEngine.hpp>
#include <Engines/GraphicEngine.hpp>
#include <Engines/AudioEngine.hpp>
#include <Tools/Log.hpp>
#include <fstream>


#include <Core/MemoryManager.hpp>
#include <Managers/Settings.hpp>
int main()
{
    std::ofstream file("logs.txt");
    Log::setOutput(file);   // écrire les messages de log dans un fichier

    sg::WindowEngine::getInstance().createWindow();
    sg::GraphicEngine::getInstance().createView(sf::Vector2f(sg::Settings::getInstance().getAppWidth() / 2,sg::Settings::getInstance().getAppHeight() / 2),
                                         sf::Vector2f(sg::Settings::getInstance().getAppWidth(),sg::Settings::getInstance().getAppHeight()));
    sg::AudioEngine::getInstance().init();

    sg::WindowEngine::getInstance().run();

    sg::GraphicEngine::getInstance().kill();
    sg::WindowEngine::getInstance().kill();
    #ifdef D_DEBUG
        sg::MemoryManager::getInstance().kill();
    #endif // _DEBUG

    return 0;
}
