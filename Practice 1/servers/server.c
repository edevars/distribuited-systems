#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 5000
#define BUFFER_LEN 1024
int main(int argc, char const *argv[])
{
    int socket_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_LEN] = {0};
    char *message = "Hello from server";

    // Creating socket file descriptor
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_fd == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Server connected at port: ", PORT);
    }

    // Socket options (socket file descriptro, level)
    int socket_options = setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                    &opt, sizeof(opt));
    if (socket_options)
    {
        perror("Error setting the socket options");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 5000
    int binding = bind(socket_fd, (struct sockaddr *)&address, sizeof(address));
    if (binding < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    int backlog_queue = 3;

    if (listen(socket_fd, backlog_queue) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    new_socket = accept(socket_fd, (struct sockaddr *)&address,(socklen_t *)&addrlen);
    if (new_socket  < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Reading the value from the client
    valread = read(new_socket, buffer, BUFFER_LEN);
    printf("%s\n", buffer);
    // Sending message 
    send(new_socket, message, strlen(message), 0);
    printf("Hello message sent\n");
    return 0;
}