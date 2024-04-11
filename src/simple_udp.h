#ifndef SIMPLE_UDP_H
#define SIMPLE_UDP_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <iostream>

class SIMPLE_UDP
{
private:
    int sock;
    struct sockaddr_in addr;
    
public:
    SIMPLE_UDP(std::string address, int port);
    
    ~SIMPLE_UDP();
    
    void udp_send(std::string word);

    void udp_bind();
    
    std::string udp_recv();
    
    void udp_recv(char *buf, int size);
};

#endif
