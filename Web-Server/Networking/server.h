#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#ifndef SERVER_H
#define SERVER_H

struct Server {
  int domain;
  int service;
  int protocol;
  u_long interface;
  int port;
  int backlog;
  int socket;

  struct sockaddr_in address;

  void (*launch)(struct Server *server);
};

struct Server server_constructor(int domain, int service, int protocol,
                                 u_long interface, int port, int backlog,
                                 void (*launch)(struct Server *server));

#endif // !SERVER_H
