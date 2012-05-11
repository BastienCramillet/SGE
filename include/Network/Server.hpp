#ifndef SERVER_HPP_INCLUDED
#define SERVER_HPP_INCLUDED

#include <Core/Thread.hpp>
#include <SFML/Network.hpp>

namespace sg
{

    class Server : public sg::Thread
    {
        public :

            Server();

            Server(std::string address, int port, std::string pwd);

            void run();

        private :

            std::string m_address;
            int m_port;
            std::string m_pwd;
    };

}

#endif // SERVER_HPP_INCLUDED
