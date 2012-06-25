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
*   \file Client.hpp
*   \brief Client class header
*   \version 0.1
*/

#ifndef CLIENT_HPP_INCLUDED
#define CLIENT_HPP_INCLUDED

#include <Network/NetworkMachine.hpp>
#include <SFML/Network.hpp>

namespace sg
{
    /*!
    *   \class Client
    *   \brief Represent a network client
    */
    class Client : public sg::NetworkMachine
    {
        public :

            /*!
            *   \brief Default constructor
            *
            *   \param name The name of the client
            */
            Client(std::string name);

            /*!
            *   \brief Default destructor
            */
            ~Client();

            /*!
            *   \brief Get the name of the client
            */
            const std::string& getName() const;

            /*!
            *   \brief Mandatory - See sg::Thread::run()
            */
            void run ();

            /*!
            *   \brief Try to connect the client to a server at the given address and port
            *
            *   \param ipAddress The IP address of the server
            *   \param port The port listened by the server
            */
            void connectTo(sf::IpAddress ipAddress, int port);

            /*!
            *   \brief Send a packet to the connected TCP Socket
            *
            *   \param packet The sf::Packet to send
            */
            void send(sf::Packet packet);

        private :

            std::string m_name;         //!< The name of the client
            sf::TcpSocket m_tcpSocket;
            sf::UdpSocket m_udpSocket;

            std::vector<std::string> m_vClients;
    };
}

#endif // CLIENT_HPP_INCLUDED
