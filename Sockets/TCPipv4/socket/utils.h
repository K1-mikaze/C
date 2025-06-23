#ifndef SOCKET_UTILS_H
#define SOCKET_UTILS_H

#include <arpa/inet.h>
#include <malloc.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>

int create_TCPipv4_socket();

struct sockaddr_in *create_TCPipv4_address(char *ip, int port);

#endif // SOCKET_UTILS
