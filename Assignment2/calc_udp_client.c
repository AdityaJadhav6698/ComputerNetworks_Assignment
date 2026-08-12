#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

struct Data {
    int num1;
    int num2;
    char op;
};

int main() {

    int clientSocket;
    struct sockaddr_in serverAddr;
    socklen_t len = sizeof(serverAddr);

    struct Data d;
    int result;

    clientSocket = socket(AF_INET, SOCK_DGRAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(9000);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    printf("Enter first number: ");
    scanf("%d", &d.num1);

    printf("Enter operator (+ - * /): ");
    scanf(" %c", &d.op);

    printf("Enter second number: ");
    scanf("%d", &d.num2);

    sendto(clientSocket, &d, sizeof(d), 0,
           (struct sockaddr*)&serverAddr, len);

    recvfrom(clientSocket, &result, sizeof(result), 0,
             (struct sockaddr*)&serverAddr, &len);

    printf("Result = %d\n", result);

    close(clientSocket);
    return 0;
}