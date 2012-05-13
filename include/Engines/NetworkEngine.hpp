#ifndef NETWORKENGINE_HPP_INCLUDED
#define NETWORKENGINE_HPP_INCLUDED

#include <Core/Singleton.hpp>

#include <string>

namespace sg
{
    class NetworkEngine : public Singleton<NetworkEngine>
    {
        friend class Singleton<NetworkEngine>;

        public :

            void createServer(std::string address, int port);
            void createClient(std::string address, int port);

        private :

            NetworkEngine ();
            ~NetworkEngine ();
    };
}

#endif // NETWORKENGINE_HPP_INCLUDED
