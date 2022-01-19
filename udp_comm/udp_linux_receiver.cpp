#include <netinet/in.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    int sock;
    sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        printf("Failed to create a socket!\n"); 
        return -1;
    }
    printf("Succeeded to create a socket.\n");

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family	= PF_INET; // IPv4
    server_addr.sin_port	= htons(6699); // Port number
    server_addr.sin_addr.s_addr	= htonl(INADDR_ANY); // 32bit IP address (or inet_addr("0.0.0.0"))

    if (bind(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Failed to bind socket!\n");
        return -1;
    }
    printf("Succeeded to bind socket.\n");

    // declare client struct to get client information
    struct sockaddr_in client_addr;
    unsigned int client_addr_size = sizeof(client_addr);

    // receive message
    while(true) {
        const int BUFF_SIZE = 1248;
        char buff_rcv[BUFF_SIZE];
        recvfrom(sock, buff_rcv, BUFF_SIZE, 0, (struct sockaddr*)&client_addr, &client_addr_size); 

		printf("Buffer:");
		for (int i=0 ; i<8 ; i++) { printf(" %02x", buff_rcv[i]); }
		printf("\n");
    }

    return 0;
}
