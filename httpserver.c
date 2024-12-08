#include <sys/socket.h>
#include <string.h>
#include <fcntl.h>
#include <sys/sendfile.h>
#include <netinet/in.h>
#include <unistd.h>
void main()
{
    // Creating a socket

    // AF_INET: This specifies the address family. AF_INET means you're using IPv4 addresses (e.g., 192.168.0.1).
    // SOCK_STREAM: This specifies the socket type. SOCK_STREAM is used for TCP connections.
    // 0: This is typically reserved for the protocol. For SOCK_STREAM, the system automatically selects the correct protocol, which is TCP.

    // The socket() function creates a socket and returns an integer file descriptor (s) that you can use to reference the socket in future operations
    //  like binding, listening, or sending data.
    int s = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr = {
        AF_INET,
        0x901f,
        {INADDR_ANY}};

    bind(s, (struct sockaddr *)&addr, sizeof(addr));

    listen(s, 5);
    int client_fd = accept(s, 0, 0);
    char buffer[256] = {0};
    recv(client_fd, buffer, 256, 0);

    // Extracting file name from GET /file.html ....
    char *fileName = buffer + 5;
    *strchr(fileName, ' ') = 0;
    int opened_fd = open(fileName, O_RDONLY);
    sendfile(client_fd, opened_fd, 0, 256);
    close(opened_fd);
    close(client_fd);
    close(s);
}