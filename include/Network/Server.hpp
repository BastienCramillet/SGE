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
*   \file Server.hpp
*   \brief Server class header
*   \version 0.1
*/

#ifndef SERVER_HPP_INCLUDED
#define SERVER_HPP_INCLUDED

#include <Core/Thread.hpp>
#include <SFML/Network.hpp>
#include <Network/NetworkMachine.hpp>

namespace sg
{

    class Server : public sg::NetworkMachine
    {
        public :

            Server();
            ~Server();

            Server(const std::string& address, int port, std::string pwd = "");

            void run();

        private :

            std::string m_name;
            std::string m_address;
            int m_port;
            std::string m_pwd;

            sf::TcpListener m_listener;
            sf::SocketSelector m_selector;

            //std::vector<std::string> m_vClients;
            std::vector<sf::TcpSocket*> m_vClients;
    };

}

#endif // SERVER_HPP_INCLUDED
