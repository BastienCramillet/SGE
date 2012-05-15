#ifndef WINDOWENGINE_HPP_INCLUDED
#define WINDOWENGINE_HPP_INCLUDED

#include <Core/Singleton.hpp>
#include <SFML/Graphics.hpp>

#include <Frame/GameFrame.hpp>

namespace sg
{
    class WindowEngine : public Singleton<WindowEngine>
    {
        friend class Singleton<WindowEngine>;

        public :

            void init();

            void createWindow ();

            void run ();

            // test
            void run(GameFrame *gf);

        private :

            WindowEngine ();
            ~WindowEngine ();

            sf::RenderWindow* m_window;
    };
} // namespace sg

#endif // WINDOWENGINE_HPP_INCLUDED
