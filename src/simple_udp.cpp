#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include "simple_udp.h"

SIMPLE_UDP::SIMPLE_UDP(std::string address, int port)
{
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1)
    {
        perror("Error creating socket");
        // Handle error
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(address.c_str());
    addr.sin_port = htons(port);
}

SIMPLE_UDP::~SIMPLE_UDP()
{
    close(sock);
}

void SIMPLE_UDP::udp_send(std::string word)
{
    ssize_t sent_bytes = sendto(sock, word.c_str(), word.length(), 0, (struct sockaddr *)&addr, sizeof(addr));
    if (sent_bytes == -1)
    {
        perror("Error sending data");
        // Handle error
    }
}

void SIMPLE_UDP::udp_bind()
{
    if (bind(sock, (const struct sockaddr *)&addr, sizeof(addr)) == -1)
    {
        perror("Error binding socket");
        // Handle error
    }
}

std::string SIMPLE_UDP::udp_recv()
{
    #define BUFFER_MAX 400
    char buf[BUFFER_MAX];
    memset(buf, 0, sizeof(buf));
    
    ssize_t received_bytes = recv(sock, buf, sizeof(buf) - 1, 0);
    if (received_bytes == -1)
    {
        perror("Error receiving data");
        // Handle error
    }

    return std::string(buf, received_bytes);
}

void SIMPLE_UDP::udp_recv(char *buf, int size)
{
    memset(buf, 0, size);

    ssize_t received_bytes = recv(sock, buf, size - 1, 0);
    if (received_bytes == -1)
    {
        perror("Error receiving data");
        // Handle error
    }
}

