/*------------------------------------------------------------------------------
*
* SGE - Simple Game Engine
*
* Copyright (c) 2012 Bastien Cramillet (Bigz)(bastien.cramillet@gmail.com)
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
*   \file Client.hpp
*   \brief Client class header
*   \version 0.1
*/

#ifndef CLIENT_HPP_INCLUDED
#define CLIENT_HPP_INCLUDED

#include <Core/Thread.hpp>
#include <SFML/Network.hpp>

namespace sg
{

    class Client : public sg::Thread
    {
        public :

            Client() : sg::Thread() {};

            void run ()
            {
                 // Create a socket and connect it to 192.168.1.50 on port 55001
                 sf::TcpSocket socket;
                 socket.connect("127.0.0.1", 55001);

                 // Send a message to the connected host
                 std::string message = "Hi, I am a client";
                 socket.send(message.c_str(), message.size() + 1);

                 // Receive an answer from the server
                 char buffer[1024];
                 std::size_t received = 0;
                 socket.receive(buffer, sizeof(buffer), received);
            }

        private :

            std::string m_name;
    };
}

#endif // CLIENT_HPP_INCLUDED
