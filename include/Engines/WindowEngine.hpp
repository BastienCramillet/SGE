/*------------------------------------------------------------------------------
*
* SGE - Simple Game Engine
*
* Copyright (c) 2012 Bastien Cramillet (Bigz)(bastien.cramillet@gmail.com)
*                    Xavier Michel (Saffir)(xavier.michel.mx440@gmail.com)
*
* This software is provided 'as-is', without any express or implied
* warranty. In no event will the authors be held liable for any damages
* arising from the use of this software.
*
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
*
*    1. The origin of this software must not be misrepresented; you must not
*    claim that you wrote the original software. If you use this software
*    in a product, an acknowledgment in the product documentation would be
*    appreciated but is not required.
*
*    2. Altered source versions must be plainly marked as such, and must not be
*    misrepresented as being the original software.
*
*    3. This notice may not be removed or altered from any source
*   distribution.
*
*-----------------------------------------------------------------------------*/

/*!
*   \file WindowEngine.hpp
*   \version 0.1
*/

#ifndef WINDOWENGINE_HPP_INCLUDED
#define WINDOWENGINE_HPP_INCLUDED

#include <Core/Singleton.hpp>
#include <Engines/Engine.hpp>
#include <SFML/Graphics.hpp>

#include <Frame/GameFrame.hpp>

namespace sg
{
    class WindowEngine : public Singleton<WindowEngine>, public Engine
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

            void treatMessage (EngineMessage* message);

            sf::RenderWindow* m_window;
    };
} // namespace sg

#endif // WINDOWENGINE_HPP_INCLUDED
