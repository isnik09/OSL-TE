#include<pthread.h>
//#include<semaphore.h>
#include<stdlib.h>
#include<stdio.h>
pthread_mutex_t x, wsem;// x is for reader count, wsem is formutual exclusion
pthread_t tid;
int readcount;
void initialize()
{
pthread_mutex_init(&x,NULL);
pthread_mutex_init(&wsem,NULL);
readcount=0;
}
void * reader(void * param)
{
int waittime;
waittime=rand()%5;
printf("\n reader is trying to enter");
pthread_mutex_lock(&x);
readcount++;
if(readcount==1)
pthread_mutex_lock(&wsem);
printf("\n %d reader is inside",readcount);
pthread_mutex_unlock(&x);
sleep(waittime);
pthread_mutex_lock(&x);
readcount--;
if(readcount==0)
pthread_mutex_unlock(&wsem);
pthread_mutex_unlock(&x);
printf("\n reader is leaving ");
}
void *writer(void * param)
{
int waittime;
waittime=rand()%3;
printf("\n writer is trying to enter");
pthread_mutex_lock(&wsem);
printf("\n writer has entered");
sleep(waittime);
pthread_mutex_unlock(&wsem);
printf("\n writer is leaving ");
sleep(30);
exit(0);
}
int main()
{
int n1,n2,i;
printf("\n enter the number of readers:");
scanf("%d",&n1);
printf("\n enter the number of writers:");
scanf("%d",&n2);
for(i=0;i<n1;i++)
pthread_create(&tid,NULL,reader,NULL);
for(i=0;i<n1;i++)
pthread_create(&tid,NULL,writer,NULL);
sleep(30);
exit(0);
}
