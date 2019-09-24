#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// returns the local host name for computer

void check_host_name(int hostname) {

    if (hostname == -1) {
        perror("gethostname");
        exit(1);
    }
}

/*
int main() {
    char hostbuffer[256];
    char *IPBuffer;
    struct hostent *host_entry;

    int hostname;


    // retrieve hostname
    hostname = gethostname(hostbuffer, sizeof(hostbuffer));

    check_host_name(hostname);

    host_entry = gethostbyname(hostbuffer);

    // To convert an Internet network
    // address into ASCII string
    IPBuffer = inet_ntoa(*((struct in_addr *) host_entry->h_addr_list[0]));

    printf("Hostname: %s\n", hostbuffer);
    printf("Host IP: %s", IPBuffer);


}*/
