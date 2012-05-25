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
*   \file NetworkEngine.hpp
*   \version 0.1
*/

#ifndef NETWORKENGINE_HPP_INCLUDED
#define NETWORKENGINE_HPP_INCLUDED

#include <Core/Singleton.hpp>
#include <SFML/Network.hpp>

#include <string>

enum NETWORK_TYPE
{
    NONE,
    CLIENT,
    SERVER,
    BOTH
};

namespace sg
{
    class Server;
    class Client;

    class NetworkEngine : public Singleton<NetworkEngine>
    {
        friend class Singleton<NetworkEngine>;

        public :

            /*!
            *   \brief Get the local IP address of the machine
            */
            const sf::IpAddress getLocalAddress() const;

            /*!
            *   \brief Get the public IP address of the machine
            */
            const sf::IpAddress getPublicAddress() const;

            void createServer(const std::string& address, int port);
            void createClient(const std::string& address, int port);

            NETWORK_TYPE getType();

            void clean();

        private :



            NetworkEngine ();
            ~NetworkEngine ();

            NETWORK_TYPE m_type;

            sg::Server* m_server;
            sg::Client* m_client;
    };
}

#endif // NETWORKENGINE_HPP_INCLUDED
