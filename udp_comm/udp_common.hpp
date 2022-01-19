#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>

void socket_create(int* sock) {
    *sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (*sock == -1) {
        printf("Failed to create socket!\n");
        exit(1);
    }
}

void socket_bind(int* result_bind, int* sock, struct sockaddr* addr) {
    *result_bind = bind(*sock, addr, sizeof(*addr));
}
