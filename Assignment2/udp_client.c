#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    int clientSocket;

    char clientMessage[] = "Hello Server";
    char serverReply[256];

    struct sockaddr_in serverAddress;
    socklen_t addrSize = sizeof(serverAddress);

    // Create UDP socket
    clientSocket = socket(AF_INET, SOCK_DGRAM, 0);

    if(clientSocket < 0)
    {
        printf("Socket creation failed\n");
        return 0;
    }

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(9000);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // Send message to server
    sendto(clientSocket,
           clientMessage,
           sizeof(clientMessage),
           0,
           (struct sockaddr*)&serverAddress,
           addrSize);

    // Receive reply
    recvfrom(clientSocket,
             serverReply,
             sizeof(serverReply),
             0,
             (struct sockaddr*)&serverAddress,
             &addrSize);

    printf("Reply from Server: %s\n", serverReply);

    close(clientSocket);

    return 0;
}