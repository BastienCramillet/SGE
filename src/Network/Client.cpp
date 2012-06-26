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
*   \file Client.cpp
*   \brief Client class source code
*   \version 0.1
*   \author Bastien (Bigz) Cramillet
*/

#include <Network/Client.hpp>
#include <Engines/NetworkEngine.hpp>

#include <Tools/Log.hpp>

namespace sg
{
    Client::Client(std::string name) : m_name(name)
    {
    }

    Client::~Client() {}

    void Client::run()
    {
        while(m_running)
        {
            sf::Packet* packet = new sf::Packet();
            m_tcpSocket.receive(*packet);
            sg::NetworkEngine::getInstance().addPacket(packet);
        }
    }

    void Client::connectTo(sf::IpAddress ipAddress, int port)
    {
        m_tcpSocket.connect(ipAddress, port);
    }

    void Client::send(sf::Packet packet)
    {
        if (m_tcpSocket.send(packet) != sf::Socket::Done)
        {
            Log::w("Client") << "The TCP socket has not sent the data : " << packet.getData();
        }
    }
}
