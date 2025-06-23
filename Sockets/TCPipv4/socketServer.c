#include "socket/utils.h"

int main(void) {
  int server_socket_FD = create_TCPipv4_socket();
  struct sockaddr_in *serveraddress = create_TCPipv4_address("", 2000);

  int result = bind(server_socket_FD, serveraddress, sizeof(*serveraddress));

  if (result == 0) {
    printf("socket was bound succesfully\n");
  }

  int listen_result = listen(server_socket_FD, 10);

  struct sockaddr_in client_address;
  int client_address_size = sizeof(client_address);
  int client_socket_FD =
      accept(server_socket_FD, &client_address, &client_address_size);

  char buffer[1024];
  recv(client_socket_FD, buffer, 1024, 0);

  printf("Response was %s\n", buffer);

  return 0;
}
