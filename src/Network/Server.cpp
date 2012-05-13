#include <Network/Server.hpp>
#include <iostream>

namespace sg
{
    Server::Server() : sg::Thread(), m_address("localhost"), m_port(25220), m_pwd("")
    {
    }

    Server::Server(std::string address, int port, std::string pwd) :
                    sg::Thread(), m_address(address), m_port(port), m_pwd(pwd)
    {
    }

    void Server::run ()
    {
        // Create a listener to wait for incoming connections on port 55001
         sf::TcpListener listener;
         listener.listen(m_port);

         // Wait for a connection
         sf::TcpSocket socket;
         listener.accept(socket);
         std::cout << "New client connected: " << socket.getRemoteAddress() << std::endl;

         // Receive a message from the client
         char buffer[1024];
         std::size_t received = 0;
         socket.receive(buffer, sizeof(buffer), received);
         std::cout << "The client said: " << buffer << std::endl;

         // Send an answer
         std::string message = "Welcome, client";
         socket.send(message.c_str(), message.size() + 1);




//            std::cout << "Server message : " << i << std::endl;
//            boost::xtime xt;
//            boost::xtime_get(&xt, boost::TIME_UTC);
//            xt.sec += 1;
//            boost::thread::sleep(xt);
    }
}
