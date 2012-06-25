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
*   \file NetworkEngine.cpp
*   \brief Network engine source code
*   \version 0.1
*/

#include <Engines/NetworkEngine.hpp>

#include <Network/Server.hpp>
#include <Network/Client.hpp>

namespace sg {

    NetworkEngine::NetworkEngine ()
    {
        m_server = 0;
        m_client = 0;
    }

    NetworkEngine::~NetworkEngine ()
    {
        clean();
    }

    void NetworkEngine::clean ()
    {
        if (m_server) delete m_server;
        if (m_server) delete m_client;
        if (!m_vPacket.empty())
        {
            int size = m_vPacket.size();
            for (int i = 0; i < size; ++i)
            {
                delete m_vPacket[i];
                m_vPacket[i] = 0;
            }
        }
    }

    void NetworkEngine::addPacket(sf::Packet* packet)
    {
        m_vPacket.push_back(packet);
    }

    void NetworkEngine::treatMessage (EngineMessage* message)
    {

        delete message;
    }

    NETWORK_TYPE NetworkEngine::getType()
    {
        return m_type;
    }

    void NetworkEngine::createServer(const std::string& address, int port)
    {
        m_server = new Server(address, port);
    }

    void NetworkEngine::createClient(const std::string& address, int port)
    {
        //m_client = new Client(address, port);
    }

}
