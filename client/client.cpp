#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

#define PORT 5555

using namespace std;

int main() {

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "172.17.0.2", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connect failed");
        exit(EXIT_FAILURE);
    }

    char buffer[1024] = {0};
    int valread = read(sockfd, buffer, 1024);

    cout << buffer << endl;

    close(sockfd);
    
    return 0;
}

