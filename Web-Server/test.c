#include "Networking/server.h"
#include "sys/socket.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void launch(struct Server *server) {

  int address_lenght = sizeof(server->address);
  int new_socket = accept(server->socket, (struct sockaddr *)&server->address,
                          (socklen_t *)&address_lenght);
  char buffer[30000];
  char *hello =
      "HTTP/1.1 200 OK\nDate: Mon, 27 Jul 2009 12:28:53 GMT\nServer: "
      "Apache/2.2.14 (Win32)\nLast-Modified: Wed, 22 Jul 2009 19:15:56 "
      "GMT\nContent-Type: text/html\nConnection: "
      "Closed\n\n<html><body><h1>Hello, World!</h1></body></html>";
  while (1) {
    printf("===== WAITING FOR CONNECTION ====\n");
    read(new_socket, buffer, 30000);
    printf("%s\n", buffer);
    write(new_socket, hello, strlen(hello));
    close(new_socket);
  }
}

int main(int argc, char *argv[]) {
  struct Server server =
      server_constructor(AF_INET, SOCK_STREAM, 0, INADDR_ANY, 80, 10, launch);
  server.launch(&server);
  return 0;
}
