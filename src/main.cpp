#include <Engines/WindowEngine.hpp>
#include <Engines/GraphicEngine.hpp>
#include <Engines/AudioEngine.hpp>
#include <Tools/Log.hpp>
#include <fstream>


#include "Core/MemoryManager.hpp"
#include "Managers/Settings.hpp"

#include "Frame/FrameManager.hpp"
#include "Frame/GameFrame.hpp"

#include "Elements/Decor.hpp"

#include "Views/DrunkerView.hpp"
#include "Views/AnimatedView.hpp"

int main()
{
    //std::ofstream file("logs.txt");
    //Log::setOutput(file);   // écrire les messages de log dans un fichier
    Log::setLogLevel(DEBUG);

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
    gameFrame->loadLevel("data/maps/map_animation.xml");

    gameFrame->addView(
                "simple view demo",
                 new sg::View(
                           sf::Vector2f(sg::Settings::getInstance().getAppWidth() / 2,sg::Settings::getInstance().getAppHeight() / 2),
                           sf::Vector2f(sg::Settings::getInstance().getAppWidth(),sg::Settings::getInstance().getAppHeight())
                    )
            );

//    gameFrame->addView
//            ("drunker view demo",
//             new sg::DrunkerView(
//                           sf::Vector2f(sg::Settings::getInstance().getAppWidth() / 2,sg::Settings::getInstance().getAppHeight() / 2),
//                           sf::Vector2f(sg::Settings::getInstance().getAppWidth(),sg::Settings::getInstance().getAppHeight())
//                    )
//            );
//
//    sg::AnimatedView *animatedView = new sg::AnimatedView(
//                sf::Vector2f(sg::Settings::getInstance().getAppWidth() / 2,sg::Settings::getInstance().getAppHeight() / 2),
//                sf::Vector2f(sg::Settings::getInstance().getAppWidth(),sg::Settings::getInstance().getAppHeight())
//            );
//
//    // move left
//    animatedView->createStep(sf::seconds(3), sf::seconds(10)).moveCenter(sf::Vector2f(2000, 0)).setTransitionTiming(sg::TransitionTiming::EASE_OUT);
//
//    // zoom at the end
//    animatedView->createStep(sf::seconds(10), sf::seconds(3)).zoom(0.5).setTransitionTiming(sg::TransitionTiming::EASE_IN);
//
//    // unzoom
//    animatedView->createStep(sf::seconds(15), sf::seconds(2)).zoom(-1).setTransitionTiming(sg::TransitionTiming::CUBIC_BEZIER);
//
//    // rotate
//    animatedView->createStep(sf::seconds(15), sf::seconds(2)).rotate(360);  // default timing
//
//    // come back to normal zoom
//    animatedView->createStep(sf::seconds(17), sf::seconds(2)).backToBaseZoom().setTransitionTiming(sg::TransitionTiming::LINEAR);
//
//    // back to initial position
//    animatedView->createStep(sf::seconds(20), sf::seconds(3)).backToInitialCenter().setTransitionTiming(sg::TransitionTiming::EASE_IN_OUT);
//
//
//    gameFrame->addView("animated view demo", animatedView);
//
//    gameFrame->setCurrentView("animated view demo");

    gameFrame->setCurrentView("simple view demo");

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
