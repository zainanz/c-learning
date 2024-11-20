#include <sys/socket.h>
#include <string.h>
#include <fcntl.h>
#include <sys/sendfile.h>
#include <netinet/in.h>
#include <unistd.h>
void main()
{
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