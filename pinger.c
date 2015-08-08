/*    
 *    taken from  - http://cboard.cprogramming.com/networking-device-communication/41635-ping-program.html
 *    pinger.c 
 *    This is a ping imitation program 
 *    It will send an ICMP ECHO packet to the server of 
 *    your choice and listen for an ICMP REPLY packet
 *    Have fun!
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <linux/ip.h>
#include <linux/icmp.h>
#include <string.h>
#include <unistd.h>
 
 
char dst_addr[20];
char src_addr[20];
 
unsigned short in_cksum(unsigned short *, int);
void parse_argvs(char**, char*, char* );
void usage();
char* getip();
char* toip(char*);
 
int main(int argc, char* argv[])
{
    struct iphdr* ip;
    struct iphdr* ip_reply;
    struct icmphdr* icmp;
    struct sockaddr_in connection;
    char* packet;
    char* buffer;
    int sockfd;
    int optval;
    int addrlen;
    int siz;
 
     
    if (getuid() != 0)
    {
    fprintf(stderr, "%s: root privelidges needed\n", *(argv + 0));
    exit(EXIT_FAILURE);
    }
 
    parse_argvs(argv, dst_addr, src_addr);
    strncpy(dst_addr, toip(dst_addr), 20);
    strncpy(src_addr, toip(src_addr), 20);
    printf("Source address: %s\n", src_addr);
    printf("Destination address: %s\n", dst_addr);
     
    /*
     * allocate all necessary memory
    */
    packet = malloc(sizeof(struct iphdr) + sizeof(struct icmphdr));
    buffer = malloc(sizeof(struct iphdr) + sizeof(struct icmphdr));
    /****************************************************************/
     
    ip = (struct iphdr*) packet;
    icmp = (struct icmphdr*) (packet + sizeof(struct iphdr));
     
    /*  
     *  here the ip packet is set up
     */
    ip->ihl          = 5;
    ip->version          = 4;
    ip->tos          = 0;
    ip->tot_len          = sizeof(struct iphdr) + sizeof(struct icmphdr);
    ip->id           = htons(0);
    ip->frag_off     = 0;
    ip->ttl          = 64;
    ip->protocol     = IPPROTO_ICMP;
    ip->saddr            = inet_addr(src_addr);
    ip->daddr            = inet_addr(dst_addr);
    ip->check            = in_cksum((unsigned short *)ip, sizeof(struct iphdr));
     
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) == -1)
    {
    perror("socket");
    exit(EXIT_FAILURE);
    }
     
    /* 
     *  IP_HDRINCL must be set on the socket so that
     *  the kernel does not attempt to automatically add
     *  a default ip header to the packet
     */
     
    setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &optval, sizeof(int));
     
    /*
     *  here the icmp packet is created
     *  also the ip checksum is generated
     */
    icmp->type           = ICMP_ECHO;
    icmp->code           = 0;
    icmp->un.echo.id     = random();
    icmp->un.echo.sequence   = 0;
    icmp-> checksum      = in_cksum((unsigned short *)icmp, sizeof(struct icmphdr));
     
     
    connection.sin_family = AF_INET;
    connection.sin_addr.s_addr = inet_addr(dst_addr);
     
    /*
     *  now the packet is sent
     */
     
    sendto(sockfd, packet, ip->tot_len, 0, (struct sockaddr *)&connection, sizeof(struct sockaddr));
    printf("Sent %d byte packet to %s\n", ip->tot_len, dst_addr);
     
    /*
     *  now we listen for responses
     */
    addrlen = sizeof(connection);
    if (( siz = recvfrom(sockfd, buffer, sizeof(struct iphdr) + sizeof(struct icmphdr), 0, (struct sockaddr *)&connection, &addrlen)) == -1)
    {
    perror("recv");
    }
    else
    {
    printf("Received %d byte reply from %s:\n", siz , dst_addr);
        ip_reply = (struct iphdr*) buffer;
    printf("ID: %d\n", ntohs(ip_reply->id));
    printf("TTL: %d\n", ip_reply->ttl);
    }
 
    free(packet);
    free(buffer);
    close(sockfd);
    return 0;
}
void parse_argvs(char** argv, char* dst, char* src)
{
    int i;
    if(!(*(argv + 1))) 
    {
    /* there are no options on the command line */
    usage();
    exit(EXIT_FAILURE); 
    }
    if (*(argv + 1) && (!(*(argv + 2)))) 
    {
    /* 
     *   only one argument provided
     *   assume it is the destination server
     *   source address is local host
     */
    strncpy(dst, *(argv + 1), 15);
    strncpy(src, getip(), 15);
    return;
    }
    else if ((*(argv + 1) && (*(argv + 2))))
    {
    /* 
     *    both the destination and source address are defined
     *    for now only implemented is a source address and 
     *    destination address
     */
    strncpy(dst, *(argv + 1), 15);
    i = 2;
    while(*(argv + i + 1))
    {
        if (strncmp(*(argv + i), "-s", 2) == 0)
        {
        strncpy(src, *(argv + i + 1), 15);
        break;
        }
        i++;
    }
    }
 
}
 
void usage()
{
    fprintf(stderr, "\nUsage: pinger [destination] <-s [source]>\n");
    fprintf(stderr, "Destination must be provided\n");
    fprintf(stderr, "Source is optional\n\n");
}
 
char* getip()
{
    char buffer[256];
    struct hostent* h;
     
    gethostname(buffer, 256);
    h = gethostbyname(buffer);
     
    return inet_ntoa(*(struct in_addr *)h->h_addr);
     
}
 
/*
 * return the ip address if host provided by DNS name
 */
char* toip(char* address)
{
    struct hostent* h;
    h = gethostbyname(address);
    return inet_ntoa(*(struct in_addr *)h->h_addr);
}
 
/*
 * in_cksum --
 * Checksum routine for Internet Protocol
 * family headers (C Version)
 */
unsigned short in_cksum(unsigned short *addr, int len)
{
    register int sum = 0;
    u_short answer = 0;
    register u_short *w = addr;
    register int nleft = len;
    /*
     * Our algorithm is simple, using a 32 bit accumulator (sum), we add
     * sequential 16 bit words to it, and at the end, fold back all the
     * carry bits from the top 16 bits into the lower 16 bits.
     */
    while (nleft > 1)
    {
      sum += *w++;
      nleft -= 2;
    }
    /* mop up an odd byte, if necessary */
    if (nleft == 1)
    {
      *(u_char *) (&answer) = *(u_char *) w;
      sum += answer;
    }
    /* add back carry outs from top 16 bits to low 16 bits */
    sum = (sum >> 16) + (sum & 0xffff);       /* add hi 16 to low 16 */
    sum += (sum >> 16);               /* add carry */
    answer = ~sum;              /* truncate to 16 bits */
    return (answer);
}
