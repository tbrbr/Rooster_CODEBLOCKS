#ifndef SERAQUESERVER_H_INCLUDED
#define SERAQUESERVER_H_INCLUDED

#include <SFML/Network.hpp>
#include <iostream>
#include <string.h>
using namespace sf;


#define FISRT_PLAYER_PORT 2001
#define SCND_PLAYER_PORT 2002
#define SERVER_PORT 2000

typedef unsigned short us16;

void ConnectUDPSocket(UdpSocket & socket, us16 port){
    if (socket.bind(port) != sf::Socket::Done)
    {
        std::cout << "Failz\n";
    }
}

unsigned short recieveData(UdpSocket & socket, IpAddress & ip, char data[], unsigned short port){
    
    sf::IpAddress sender;
    size_t received;
    socket.receive(data, 100, received, sender, port);
    return port;

}

void SendData(UdpSocket & socket, const char * message, IpAddress & ip, us16 port){
    socket.send(message, strlen(message) + 1, ip, port);
}


#endif // SERAQUESERVER_H_INCLUDED
