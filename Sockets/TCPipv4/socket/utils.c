#include "utils.h"
#include "netinet/in.h"
#include <string.h>

int create_TCPipv4_socket() { return socket(AF_INET, SOCK_STREAM, 0); }

struct sockaddr_in *create_TCPipv4_address(char *ip, int port) {

  struct sockaddr_in *address = malloc(sizeof(struct sockaddr_in));
  address->sin_port = htons(port);
  address->sin_family = AF_INET;

  if (strlen(ip) == 0) {
    (*address).sin_addr.s_addr = INADDR_ANY;
  }
  inet_pton(AF_INET, ip, &address->sin_addr.s_addr);
  return address;
};
