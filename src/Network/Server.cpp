#include <Network/Server.hpp>
#include <iostream>

namespace sg
{
    Server::Server() : m_address("localhost"), m_port(25220), m_pwd("")
    {
        // Automaticly listen to new connections
        m_listener.listen(m_port);
    }

    Server::Server(const std::string& address, int port, std::string pwd) :
                    m_address(address), m_port(port), m_pwd(pwd)
    {
        // Automaticly listen to new connections
        m_listener.listen(m_port);
    }

    Server::~Server() {}

    void Server::run ()
    {
        // Add the listener to the selector
        m_selector.add(m_listener);

        // Endless loop that waits for new connections
        while (m_running)
        {
            // Make the selector wait for data on any socket
            if (m_selector.wait())
            {
                // Test the listener
                if (m_selector.isReady(m_listener))
                {
                    // The listener is ready: there is a pending connection
                    sf::TcpSocket* client = new sf::TcpSocket;
                    if (m_listener.accept(*client) == sf::Socket::Done)
                    {
                        // Add the new client to the clients list
                        m_vClients.push_back(client);

                        // Add the new client to the selector so that we will
                        // be notified when he sends something
                        m_selector.add(*client);
                    }
                }
                else
                {
                    // The listener socket is not ready, test all other sockets (the clients)
                    for (std::vector<sf::TcpSocket*>::iterator it = m_vClients.begin(); it != m_vClients.end(); ++it)
                    {
                        sf::TcpSocket& client = **it;
                        if (m_selector.isReady(client))
                        {
                            // The client has sent some data, we can receive it
                            sf::Packet packet;
                            if (client.receive(packet) == sf::Socket::Done)
                            {
                                std::cout << packet.getData() << std::endl;
                            }
                        }
                    }
                }
            }
        }





        // Create a listener to wait for incoming connections on port 55001
//         sf::TcpListener listener;
//         listener.listen(m_port);
//
//         // Wait for a connection
//         sf::TcpSocket socket;
//         listener.accept(socket);
//         std::cout << "New client connected: " << socket.getRemoteAddress() << std::endl;
//
//         // Receive a message from the client
//         char buffer[1024];
//         std::size_t received = 0;
//         socket.receive(buffer, sizeof(buffer), received);
//         std::cout << "The client said: " << buffer << std::endl;
//
//         // Send an answer
//         std::string message = "Welcome, client";
//         socket.send(message.c_str(), message.size() + 1);




//            std::cout << "Server message : " << i << std::endl;
//            boost::xtime xt;
//            boost::xtime_get(&xt, boost::TIME_UTC);
//            xt.sec += 1;
//            boost::thread::sleep(xt);
    }
}
