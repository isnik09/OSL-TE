Implement the C program in which main program accepts the integers to be sorted. Main program uses the FORK system call to create a new process called a child process. Parent process the integers using sorting algorithm and waits for child process using WAIT system call to sort the integers using any sorting algorithm. Also demonstrate zombie and orphan states. 
#include<unistd.h> #include<sys/types.h> #include<stdio.h>
void asc(int*, int sz); void dsc(int*, int sz); int main()
{
pid_t pid; int *a,sz,i;
printf("enter the size of the array\n"); scanf("%d",&sz); a=(int*)malloc(sz*sizeof(int));
printf("enter element of %d size array\n",sz); for(i=0;i<sz;i++)
{
printf("a[%d]:",i);
scanf("%d",&a[i]);
}
pid=fork();
switch(pid)
{
case -1:
printf("Error in fork\n"); exit(-1);
case 0:
printf("child process\n"); asc(a,sz);
exit(0); default:
wait (NULL);
printf("Parent process\n"); dsc(a,sz);
exit(0);
}
return 0;
}
void asc(int *a, int sz)
{
int i,j,temp; for(i=0;i<sz;i++)
{
for(j=i+1;j<sz;j++)
{
if(a[i]>a[j])
{
temp=a[i]; a[i]=a[j]; a[j]=temp;
}

}
}
printf("sorted array elements in ascending order are\n"); for(i=0;i<sz;i++)
{
printf("%d\t",a[i]);
}
printf("\n");
}

void dsc(int *a, int sz)
{
int i,j,temp; for(i=0;i<sz;i++)
{
for(j=i+1;j<sz;j++)
{
if(a[i]<a[j])
{
temp=a[i]; a[i]=a[j]; a[j]=temp;
}
}
}
printf("sorted array elements in descending order are\n"); for(i=0;i<sz;i++)
{
printf("%d\t",a[i]);
}
printf("\n");
}


Output:
enter the size of the array 5
enter element of 5 size array a[0]:4
3a[1]:2
a[2]:5
a[3]:6
a[4]:7
child process

sorted array elements in ascending order are 2 4 5 6 7
Parent process
sorted array elements in descending order are 7 6 5 4 2

Implement the C program in which main program accepts an array. Main program uses the FORK system call to create a new process called a child process. Parent process sorts an array and passes the sorted array to child process through the command line arguments of EXECVE system call. The child process uses EXECVE system call to load new program which display array in reverse order. 


#include<stdio.h> #include<stdlib.h> #include<unistd.h> #include<string.h>
int main(int argc,char *argv[])
{

int val[10],ele; pid_t pid;
char *cval[10]; int i,j,n,temp;
printf("\n Enter the size of array\n"); scanf("%d",&n);
printf("\n Enter the numbers\n"); for(i=0;i<n;i++)
{
scanf("%d",&val[i]);
}
printf("\n Elements entered are\n"); for(i=0;i<n;i++) printf("%d",val[i]);
{


for(i=1;i<n;i++)
{
for(j=0;j<n-1;j++)
{
if(val[j]>val[j+1])
{
temp=val[j]; val[j]=val[j+1]; val[j+1]=temp;
}
}
}

printf("\n Sorted elements are\n:"); for(i=0;i<n;i++)
{
printf("%d",val[i]);
}

printf("\n Enter element to search:"); scanf("%d",&ele);
val[i]=ele;

for(i=0;i<n+1;i++)
{

char a[sizeof(int)]; snprintf(a,sizeof(int),"%d",val[i]); cval[i]=malloc(sizeof(a)); strcpy(cval[i],a);
}
cval[i]=NULL; pid=fork(); if(pid==0)
{
execv(argv[1],cval);
perror("\n Error in execv call");
}

}
}

Output:

Enter the size of array 6

Enter the numbers 6
8
4
9
6
0

Elements entered are 684960
Sorted elements are
:046689
Enter element to search:6

2B-b
#include<stdio.h> #include<stdlib.h> #include<string.h>
int main(int argc,char *argv[],char *en[])
{
int i,j,c,arr[argc],ele;

for(j=0;j<argc-1;j++)
{
int n=atoi(argv[j]); arr[j]=n;
}

ele=atoi(argv[j]); i=0;j=argc-1; c=(i+j)/2;
while(arr[c]!=ele && i<=j)
{
if(ele>arr[c]) i=c+1;
else j=c-1;
c=(i+j)/2;
}
if(i<=j)
printf("\n Element found in given array"); else
printf("\n Elements not found in given array"); return 0;
}


Output:
Element found in given array9

Implement the C program for CPU Scheduling Algorithms: Shortest Job First (Preemptive) and Round Robin with different arrival time. 
#include <stdio.h> #include<conio.h> int main()
{

int arrival_time[10], burst_time[10], temp[10]; int i, smallest, count = 0, time, limit;
double wait_time = 0, turnaround_time = 0, end; float average_waiting_time, average_turnaround_time; clrscr();
printf("\nEnter the Total Number of Processes:\t"); scanf("%d", &limit);
printf("\nEnter Details of %d Processes", limit); for(i = 0; i < limit; i++)
{
printf("\nEnter Arrival Time:\t"); scanf("%d", &arrival_time[i]); printf("Enter Burst Time:t"); scanf("%d", &burst_time[i]); temp[i] = burst_time[i];
}
burst_time[9] = 9999;
for(time = 0; count != limit; time++)
{
smallest = 9;
for(i = 0; i < limit; i++)
{
if(arrival_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0)
{
smallest = i;
}
}
burst_time[smallest]--; if(burst_time[smallest] == 0)
{
count++;
end = time + 1;
wait_time = wait_time + end - arrival_time[smallest] - temp[smallest];
turnaround_time = turnaround_time + end - arrival_time[smallest];
}
}
average_waiting_time = wait_time / limit; average_turnaround_time = turnaround_time / limit; printf("\nnAverage Waiting Time:t%lf", average_waiting_time); printf("Average Turnaround Time:t%lf\n",
average_turnaround_time); return 0;
getch();
}

Output:
Enter the Total Number of Processes: 4


Enter Details of 4 Processes Enter Arrival Time: 2 Enter Burst Time:t21

Enter Arrival Time: 1 Enter Burst Time:t3

Enter Arrival Time: 4 Enter Burst Time:t6

Enter Arrival Time: 2 Enter Burst Time:t3

nAverage Waiting Time:t4.000000Average Turnaround Time:t12.250000

Implement the C program for CPU Scheduling Algorithms: Shortest Job First (Preemptive) and Round Robin with different arrival time. 
#include<stdio.h>

int main()
{
int i, limit, total = 0, x, counter = 0, time_quantum; int wait_time = 0, turnaround_time = 0, arrival_time[10],
burst_time[10], temp[10];
float average_wait_time, average_turnaround_time; printf("Enter Total Number of Processes:\n\t"); scanf("%d", &limit);
x = limit;
for(i = 0; i < limit; i++)
{
printf("Enter Details of Process[%d]\n", i + 1); printf("Arrival Time:\t");
scanf("%d", &arrival_time[i]); printf("Burst Time:t"); scanf("%d", &burst_time[i]);
temp[i] = burst_time[i];
}

printf("Enter Time Quantum:\n\t"); scanf("%d", &time_quantum);
printf("\nProcess IDttBurst Timet Turnaround Timet Waiting Timen");
for(total = 0, i = 0; x != 0;)
{
if(temp[i] <= time_quantum && temp[i] > 0)
{
total = total + temp[i]; temp[i] = 0;
counter = 1;
}
else if(temp[i] > 0)
{
temp[i] = temp[i] - time_quantum; total = total + time_quantum;
}
if(temp[i] == 0 && counter == 1)
{
x--;
printf("\nProcess[%d]\t%d\t %d\t %d", i + 1, burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);


burst_time[i]; arrival_time[i];
wait_time = wait_time + total - arrival_time[i] - turnaround_time = turnaround_time + total -

counter = 0;
}
if(i == limit - 1)
{
i = 0;
}
else if(arrival_time[i + 1] <= total)
{


}
else
{

}
}
i++;


i = 0;


average_wait_time = wait_time * 1.0 / limit; average_turnaround_time = turnaround_time * 1.0 / limit; printf("\nAverage Waiting Time:t%f", average_wait_time); printf("\nAvg Turnaround Time:t%f", average_turnaround_time); return 0;
}
Output:
Enter Total Number of Processes: 4
Enter Details of Process[1] Arrival Time: 2
Burst Time:t3
Enter Details of Process[2] Arrival Time: 3
Burst Time:t5
Enter Details of Process[3] Arrival Time: 0
Burst Time:t6
Enter Details of Process[4] Arrival Time: 1
Burst Time:t5
Enter Time Quantum: 2

Process IDttBurst Timet Turnaround Timet Waiting Timen

Process[1]	3	1	-2
Process[2]	5	13	8
Process[3]	6	18	12
Process[4]	5	18	13
Average Waiting Time:t7.750000 Avg Turnaround Time:t12.500000

Thread synchronization using counting semaphores. Application to demonstrate: producer- consumer problem with counting semaphores and mutex. 

#include <stdlib.h> #include <stdio.h> #include <pthread.h> #include <semaphore.h>
//#include "buffer.h" # define BUFFER_SIZE 5
#define RAND_DIVISOR 100000000
#define TRUE 1

/* The mutex lock */ pthread_mutex_t mutex;

/* the semaphores */ sem_t full, empty;

/* the buffer */
buffer_item buffer[BUFFER_SIZE];

/* buffer counter */ int counter;

pthread_t tid1, tid2; //Thread ID pthread_attr_t attr; //Set of thread attributes

void *producer(void *param); /* the producer thread */ void *consumer(void *param); /* the consumer thread */

void initializeData() {

/* Create the mutex lock */ pthread_mutex_init(&mutex, NULL);

/* Create the full semaphore and initialize to 0 */ sem_init(&full, 0, 0);

/* Create the empty semaphore and initialize to BUFFER_SIZE */ sem_init(&empty, 0, BUFFER_SIZE);

/* Get the default attributes */ pthread_attr_init(&attr);

/* init buffer */ counter = 0;
}

/* Producer Thread */
void *producer(void *param) { buffer_item item;

while(TRUE) {
/* sleep for a random period of time */ int rNum = rand() / RAND_DIVISOR; sleep(rNum);

/* generate a random number */ item = rand();

/* acquire the empty lock */ sem_wait(&empty);
/* acquire the mutex lock */ pthread_mutex_lock(&mutex);

if(insert_item(item)) {
fprintf(stderr, " Producer report error condition\n");
}
else {
printf("producer produced %d\n", item);
}
/* release the mutex lock */ pthread_mutex_unlock(&mutex);
/* signal full */ sem_post(&full);
}
}

/* Consumer Thread */
void *consumer(void *param) { buffer_item item;

while(TRUE) {
/* sleep for a random period of time */ int rNum = rand() / RAND_DIVISOR; sleep(rNum);

/* aquire the full lock */ sem_wait(&full);
/* aquire the mutex lock */ pthread_mutex_lock(&mutex); if(remove_item(&item)) {
fprintf(stderr, "Consumer report error condition\n");
}
else {
printf("consumer consumed %d\n", item);
}
/* release the mutex lock */ pthread_mutex_unlock(&mutex);
/* signal empty */ sem_post(&empty);
}
}

/* Add an item to the buffer */
int insert_item(buffer_item item) {
/* When the buffer is not full add the item and increment the counter*/
if(counter < BUFFER_SIZE) { buffer[counter] = item; counter++;
return 0;

}
else { /* Error the buffer is full */ return -1;
}
}

/* Remove an item from the buffer */ int remove_item(buffer_item *item) {
/* When the buffer is not empty remove the item and decrement the counter */
if(counter > 0) {
*item = buffer[(counter-1)]; counter--;
return 0;
}
else { /* Error buffer empty */ return -1;
}
}

int main(int argc, char *argv[]) {
/* Loop counter */ int i;

/* Verify the correct number of arguments were passed in */ if(argc != 4) {
fprintf(stderr, "USAGE:./main.out <INT> <INT> <INT>\n");
}
int mainSleepTime = atoi(argv[1]); /* Time in seconds for main to sleep */
int numProd = atoi(argv[2]); /* Number of producer threads */ int numCons = atoi(argv[3]); /* Number of consumer threads */

/* Initialize the app */ initializeData();

/* Create the producer threads */ for(i = 0; i < numProd; i++) {
/* Create the thread */ pthread_create(&tid1,&attr,producer,NULL);
}

/* Create the consumer threads */ for(i = 0; i < numCons; i++) {
/* Create the thread */ pthread_create(&tid2,&attr,consumer,NULL);
}
/* Sleep for the specified amount of time in milliseconds */
//sleep(mainSleepTime);

pthread_join(tid1, NULL); pthread_join(tid2, NULL);

/* Exit the program */ printf("Exit the program\n"); exit(0);

}


Output:
enter the number of readers:3


enter the number of writers:4


reader is trying to enter
1	reader is  inside reader is trying to enter
2	reader is  inside reader is trying to enter
3	reader is  inside writer is trying to enter writer is trying to enter writer is trying to enter reader is leaving
reader is leaving reader is leaving writer has entered Writer is leaving writer has entered writer is leaving writer has entered writer is leaving

Thread synchronization and mutual exclusion using mutex. Application to demonstrate: Reader- Writer problem with reader priority. 
#include<pthread.h>
//#include<semaphore.h> #include<stdlib.h> #include<stdio.h>
pthread_mutex_t x, wsem;// x is for reader count, wsem is formutual exclusion
pthread_t tid; int readcount; void initialize()
{
pthread_mutex_init(&x,NULL); pthread_mutex_init(&wsem,NULL); readcount=0;
}
void * reader(void * param)
{
int waittime; waittime=rand()%5;
printf("\n reader is trying to enter"); pthread_mutex_lock(&x);
readcount++; if(readcount==1) pthread_mutex_lock(&wsem);
printf("\n %d reader is inside",readcount); pthread_mutex_unlock(&x);
sleep(waittime); pthread_mutex_lock(&x); readcount--; if(readcount==0) pthread_mutex_unlock(&wsem); pthread_mutex_unlock(&x);
printf("\n reader is leaving ");
}
void *writer(void * param)
{
int waittime; waittime=rand()%3;
printf("\n writer is trying to enter"); pthread_mutex_lock(&wsem);
printf("\n writer has entered"); sleep(waittime); pthread_mutex_unlock(&wsem); printf("\n writer is leaving "); sleep(30);
exit(0);
}
int main()
{
int n1,n2,i;
printf("\n enter the number of readers:"); scanf("%d",&n1);
printf("\n enter the number of writers:"); scanf("%d",&n2);

for(i=0;i<n1;i++) pthread_create(&tid,NULL,reader,NULL); for(i=0;i<n1;i++) pthread_create(&tid,NULL,writer,NULL); sleep(30);
exit(0);
}


Output:
enter the number of readers:2


enter the number of writers:3


reader is trying to enter
1	reader is  inside reader is trying to enter
2	reader is  inside writer is trying to enter writer is trying to enter reader is leaving
reader is leaving writer has entered writer is leaving writer has entered writer is leaving

Implement the C program for Deadlock Avoidance Algorithm: Bankers Algorithm. 

// Banker's Algorithm #include <stdio.h> int main()
{

// P0, P1, P2, P3, P4 are the Process names here



int n, m, i, j, k;

n = 5; // Number of processes m = 3; // Number of resources
int alloc[5][3] = { { 0, 1, 0 }, // P0 // Allocation Matrix

{ 2, 0, 0 }, // P1

{ 3, 0, 2 }, // P2

{ 2, 1, 1 }, // P3

{ 0, 0, 2 } }; // P4



int max[5][3] = { { 7, 5, 3 }, // P0 // MAX Matrix

{ 3, 2, 2 }, // P1

{ 9, 0, 2 }, // P2

{ 2, 2, 2 }, // P3

{ 4, 3, 3 } }; // P4



int avail[3] = { 3, 3, 2 }; // Available Resources



int f[n], ans[n], ind = 0; for (k = 0; k < n; k++) {
f[k] = 0;

}

int need[n][m];

for (i = 0; i < n; i++) { for (j = 0; j < m; j++)
need[i][j] = max[i][j] - alloc[i][j];

}

int y = 0;

for (k = 0; k < 5; k++) { for (i = 0; i < n; i++) {
if (f[i] == 0) {



int flag = 0;

for (j = 0; j < m; j++) {

if (need[i][j] > avail[j]){ flag = 1;
break;

}

}



if (flag == 0) { ans[ind++] = i;
for (y = 0; y < m; y++) avail[y] += alloc[i][y];
f[i] = 1;

}

}

}

}



printf("Following is the SAFE Sequence\n"); for (i = 0; i < n - 1; i++)
printf(" P%d ->", ans[i]);

printf(" P%d", ans[n - 1]);



return (0);



// This code is contributed by Deep Baldha (CandyZack)

}




Output:
Following is the SAFE Sequence P1 -> P3 -> P4 -> P0 -> P2

Implement the C program for Page Replacement Algorithms: FCFS, LRU, and Optimal for frame size as minimum three. 


#include<stdio.h> int n,nf;
int in[100]; int p[50]; int hit=0; int i,j,k;
int pgfaultcnt=0; void getData()
{
printf("\nEnter length of page reference sequence:"); scanf("%d",&n);
printf("\nEnter the page reference sequence:"); for(i=0; i<n; i++)
scanf("%d",&in[i]); printf("\nEnter no of frames:"); scanf("%d",&nf);
}
void initialize()
{
pgfaultcnt=0; for(i=0; i<nf; i++)
p[i]=9999;
}
int isHit(int data)
{
hit=0;
for(j=0; j<nf; j++)

{

if(p[j]==data

{

hit=1; break;
}

}
return hit;

}
int getHitIndex(int data)
{
int hitind;
for(k=0; k<nf; k++)
{
if(p[k]==data)
{
hitind=k; break;
}
}
return hitind;
}
void dispPages()
{
for (k=0; k<nf; k++)
{
if(p[k]!=9999)
printf(" %d",p[k]);
}
}
void dispPgFaultCnt()

{

printf("\nTotal no of page faults:%d",pgfaultcnt);

}
void fifo()
{  initialize(); for(i=0; i<n; i++)
{
printf("\nFor %d :",in[i]); if(isHit(in[i])==0)
{
for(k=0; k<nf-1; k++) p[k]=p[k+1];
p[k]=in[i]; pgfaultcnt++; dispPages();
}
else
printf("No page fault");
}
dispPgFaultCnt();
}
void optimal()
{
initialize(); int near[50];
for(i=0; i<n; i++)
{
printf("\nFor %d :",in[i]); if(isHit(in[i])==0)
{
for(j=0; j<nf; j++)

{

int pg=p[j] int found=0;
for(k=i; k<n; k++)
{
if(pg==in[k])
{
near[j]=k; found=1; break;
}
else
found=0;
}
if(!found) near[j]=9999;
}
int max=-9999; int repindex; for(j=0; j<nf; j++)
{
if(near[j]>max)
{
max=near[j]; repindex=j;
}
}
p[repindex]=in[i]; pgfaultcnt++; dispPages();
}

else
printf("No page fault");

}
dispPgFaultCnt();

}
void lru()
{
initialize(); int least[50];
for(i=0; i<n; i++)
{
printf("\nFor %d :",in[i]); if(isHit(in[i])==0)
{
for(j=0; j<nf; j++)
{
int pg=p[j]; int found=0;
for(k=i-1; k>=0; k--)
{
if(pg==in[k])
{
least[j]=k; found=1; break;
}
else
found=0;
}
if(!found) least[j]=-9999;

}
int min=9999; int repindex; for(j=0; j<nf; j++)
{
if(least[j]<min)
{
min=least[j]; repindex=j;
}
}
p[repindex]=in[i]; pgfaultcnt++; dispPages();
}
else
printf("No page fault!");

}
dispPgFaultCnt();

}
void lfu()
{
int usedcnt[100];
int least,repin,sofarcnt=0,bn; initialize();
for(i=0; i<nf; i++) usedcnt[i]=0; for(i=0; i<n; i++)
{
printf("\n For %d :",in[i]); if(isHit(in[i]))

{

int hitind=getHitIndex(in[i]); usedcnt[hitind]++; printf("No page fault!");
}
else
{
pgfaultcnt++; if(bn<nf)
{
p[bn]=in[i]; usedcnt[bn]=usedcnt[bn]+1; bn++;
}
else
{
least=9999; for(k=0; k<nf; k++)
if(usedcnt[k]<least)
{
least=usedcnt[k]; repin=k;
}
p[repin]=in[i]; sofarcnt=0; for(k=0; k<=i; k++)
if(in[i]==in[k]) sofarcnt=sofarcnt+1;
usedcnt[repin]=sofarcnt;
}

dispPages();

}


}
dispPgFaultCnt();

}
void secondchance()
{
int usedbit[50]; int victimptr=0; initialize(); for(i=0; i<nf; i++)
usedbit[i]=0; for(i=0; i<n; i++)
{
printf("\nFor %d:",in[i]); if(isHit(in[i]))
{
printf("No page fault!");
int hitindex=getHitIndex(in[i]); if(usedbit[hitindex]==0)
usedbit[hitindex]=1;
}
else
{
pgfaultcnt++; if(usedbit[victimptr]==1)
{
do
{
usedbit[victimptr]=0;

victimptr++; if(victimptr==nf)
victimptr=0;

}
while(usedbit[victimptr]!=0);

}
if(usedbit[victimptr]==0)
{
p[victimptr]=in[i]; usedbit[victimptr]=1; victimptr++;
}
dispPages();


}
if(victimptr==nf) victimptr=0;
}
dispPgFaultCnt();

}
int main()
{
int choice; while(1)
{
printf("\nPage Replacement Algorithms\n1.Enter data\n2.FIFO\n3.Optimal\n4.LRU\n5.LFU\n6.Second Chance\n7.Exit\nEnter your choice:");
scanf("%d",&choice); switch(choice)
{
case 1:

getData(); break;
case 2:
fifo(); break;
case 3:
optimal(); break;
case 4:
lru(); break;
case 5:
lfu(); break;
case 6:
secondchance(); break;
default: return 0; break;
}

}

}






Output:
Page Replacement Algorithms 1.Enter data
2.	FIFO

3.	Optimal 4.LRU
5.	LFU
6.	Second Chance 7.Exit
Enter your choice:1


Enter length of page reference sequence:8


Enter the page reference sequence:2 3
4
2
3
5
6
2


Enter no of frames:3


Page Replacement Algorithms 1.Enter data
2.	FIFO
3.	Optimal 4.LRU
5.	LFU
6.	Second Chance 7.Exit
Enter your choice:2


For 2 : 2

For 3 : 2 3
For 4 : 2 3 4
For 2 :No page fault For 3 :No page fault For 5 : 3 4 5
For 6 : 4 5 6
For 2 : 5 6 2
Total no of page faults:6
Page Replacement Algorithms 1.Enter data
2.	FIFO
3.	Optimal 4.LRU
5.	LFU
6.	Second Chance 7.Exit
Enter your choice:3


For 2 : 2
For 3 : 2 3
For 4 : 2 3 4
For 2 :No page fault For 3 :No page fault For 5 : 2 5 4
For 6 : 2 6 4
For 2 :No page fault Total no of page faults:5
Page Replacement Algorithms 1.Enter data
2.	FIFO
3.	Optimal

4.	LRU
5.	LFU
6.	Second Chance 7.Exit
Enter your choice:4


For 2 : 2
For 3 : 2 3
For 4 : 2 3 4
For 2 :No page fault! For 3 :No page fault! For 5 : 2 3 5
For 6 : 6 3 5
For 2 : 6 2 5
Total no of page faults:6
Page Replacement Algorithms 1.Enter data
2.	FIFO
3.	Optimal 4.LRU
5.	LFU
6.	Second Chance 7.Exit
Enter your choice:5


For 2 : 2
For 3 : 2 3
For 4 : 2 3 4
For 2 :No page fault! For 3 :No page fault! For 5 : 2 3 5

For 6 : 2 3 6
For 2 :No page fault!
Total no of page faults:5
Page Replacement Algorithms 1.Enter data
2.	FIFO
3.	Optimal 4.LRU
5.	LFU
6.	Second Chance 7.Exit
Enter your choice:7

Pipes: Full duplex communication between parent and child processes. Parent process writes a pathname of a file (the contents of the file are desired) on one pipe to be read by child process and child process writes the contents of the file on second pipe to be read by parent process and 
displays on standard output. 


#include<stdio.h> #include<stdlib.h> #include<sys/types.h> #include<sys/stat.h> #include<unistd.h> #include<fcntl.h> #include<string.h>

int main()
{
puts("\n\tClient -  Listening\n"); int code6 = mkfifo("fifo6.txt",0666); int code7 = mkfifo("fifo7.txt",0666); char strMessage[5000];
if(code6 == -1)
perror("\n\tmkfifo6 returned an error-file any already
exist\n");
if(code7 == -1)
perror("\n\tmkfifo7 returned an error-file any already
exist\n");

int fd = open("fifo6.txt", O_RDONLY); int fd2 = open("fifo7.txt", O_WRONLY); if(fd == -1)
{
perror("Cannot open FIFO6 for read"); return EXIT_FAILURE;
}
if(fd2 == -1)
{
perror("Cannot open FIFO7 for write"); return EXIT_FAILURE;
}
puts("FIFO OPEN");
//read string up to(5000 characters) char stringBuffer[5000]; memset(stringBuffer, 0, 5000);

int res; char Len;
//while(1)
{
res = read(fd, &Len, 1);
//if(Len == 1)//since null counts 1
//break;

read(fd, stringBuffer, Len); //Read String Characters stringBuffer[(int)Len] = 0;
printf("\nClient Received: %s\n", stringBuffer); int j = 0,w=0, line = 0; while(stringBuffer[j]!='\0'){
char ch = stringBuffer[j]; if((ch==' ')||(ch=='\n')){




} j++;
}
w++;
if(ch=='\n')
line++;

char LC = (char) strlen(strMessage); char str1[256];
char str2[256]; char str3[256];
sprintf(str1," No.of Words : %d:::", w); strcat(strMessage,str1);
sprintf(str2," No.of Charecters: %d:::",(j-1)); strcat(strMessage,str2);
sprintf(str3," No.of Lines: %d",line); strcat(strMessage,str3);
strcat(strMessage,"\0"); printf("\n\tString: %s",strMessage);
write(fd2, &LC, 1);
write(fd2, strMessage, strlen(strMessage)); fflush(stdin);
strMessage[0] = 0;//reseting the character array
//if(LC==1)
//break;

}
printf("\n"); puts("CLIENT CLOSED"); puts("SERVER CLOSED");
close(fd); close(fd2); return 0;
}
Output:
Client - Listening


mkfifo6 returned an error-file any already exist
: Permission denied


mkfifo7 returned an error-file any already exist
: Permission denied
Cannot open FIFO6 for read: No such file or directory

Inter-process Communication using Shared Memory using System V. Application to demonstrate: Client and Server Programs in which server process creates a shared memory segment and writes the message to the shared memory segment. Client process reads the message from the shared memory segment and displays it to the screen. 

/*
* shm-client - client program to demonstrate shared memory.
*/
#include <sys/types.h> #include <sys/ipc.h> #include <sys/shm.h> #include <stdio.h>
#define SHMSZ 27
main()
{
int shmid; key_t key; char *shm, *s;

/*
*	We need to get the segment named
*	"5678", created by the server.
*/
key = 5678;

/*
*	Locate the segment.
*/
if ((shmid = shmget(key, SHMSZ, 0666)) < 0) { perror("shmget");
exit(1);
}

/*
*	Now we attach the segment to our data space.
*/
if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) { perror("shmat");
exit(1);
}

/*
*	Now read what the server put in the memory.
*/
for (s = shm; *s != NULL; s++) putchar(*s);
putchar('\n');

/*
*	Finally, change the first character of the
*	segment to '*', indicating we have read
*	the segment.
*/
*shm = '*';

exit(0);
}

7B-2
#include <sys/types.h> #include <sys/ipc.h> #include <sys/shm.h> #include <stdio.h>
#define SHMSZ 27
main()
{
char c; int shmid; key_t key;
char *shm, *s;

/*
*	We'll name our shared memory segment
* "5678".
*/
key = 5678;

/*
*	Create the segment.
*/
if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) { perror("shmget");
exit(1);
}

/*
*	Now we attach the segment to our data space.
*/
if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) { perror("shmat");
exit(1);
}

/*
*	Now put some things into the memory for the
*	other process to read.
*/
s = shm;

for (c = 'a'; c <= 'z'; c++)
*s++ = c;
*s = NULL;

/*
*	Finally, we wait until the other process
*	changes the first character of our memory

*	to '*', indicating that it has read what
*	we put there.
*/
while (*shm != '*') sleep(1);

exit(0);
}

Implement the C program for Disk Scheduling Algorithms: SSTF, SCAN, C-Look considering the initial head position moving away from the spindle. 

#include<stdio.h> #include<stdlib.h> int main()
{
int RQ[100],i,j,n,TotalHeadMoment=0,initial,size,move; printf("Enter the number of Requests\n"); scanf("%d",&n);
printf("Enter the Requests sequence\n"); for(i=0;i<n;i++)
scanf("%d",&RQ[i]);
printf("Enter initial head position\n"); scanf("%d",&initial);
printf("Enter total disk size\n"); scanf("%d",&size);
printf("Enter the head movement direction for high 1 and for low 0\n"); scanf("%d",&move);
// logic for C-look disk scheduling
/*logic for sort the request array */ for(i=0;i<n;i++)
{
for( j=0;j<n-i-1;j++)
{
if(RQ[j]>RQ[j+1])
{
int temp; temp=RQ[j]; RQ[j]=RQ[j+1];
RQ[j+1]=temp;
} }

}
int index; for(i=0;i<n;i++)
{
if(initial<RQ[i])
{
index=i; break;
}
}
// if movement is towards high value if(move==1)
{
for(i=index;i<n;i++)
{
TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial); initial=RQ[i];
}
for( i=0;i<index;i++)
{
TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial); initial=RQ[i];
}
}
// if movement is towards low value else
{
for(i=index-1;i>=0;i--)
{
TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial); initial=RQ[i];

}
for(i=n-1;i>=index;i--)
{
TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial); initial=RQ[i];
}

}
printf("Total head movement is %d",TotalHeadMoment); return 0;
}






Output:
Enter the number of Request 8
Enter the Requests Sequence 95 180 34 119 11 123 62 64
Enter initial head position 50
Enter the head movement direction for high 1 and for low 0 1
Total head movement is 322

8B
#include<stdio.h> #include<stdlib.h> int main()
{
int RQ[100],i,j,n,TotalHeadMoment=0,initial,size,move; printf("Enter the number of Requests\n"); scanf("%d",&n);
printf("Enter the Requests sequence\n"); for(i=0;i<n;i++)
scanf("%d",&RQ[i]);
printf("Enter initial head position\n"); scanf("%d",&initial);
printf("Enter total disk size\n"); scanf("%d",&size);
printf("Enter the head movement direction for high 1 and for low 0\n"); scanf("%d",&move);

// logic for Scan disk scheduling


/*logic for sort the request array */ for(i=0;i<n;i++)
{
for(j=0;j<n-i-1;j++)
{
if(RQ[j]>RQ[j+1])
{
int temp; temp=RQ[j]; RQ[j]=RQ[j+1];

RQ[j+1]=temp;

}
}

}
int index; for(i=0;i<n;i++)
{
if(initial<RQ[i])
{
index=i; break;
}
}
// if movement is towards high value if(move==1)
{
for(i=index;i<n;i++)
{
TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial); initial=RQ[i];
}
// last movement for max size TotalHeadMoment=TotalHeadMoment+abs(size-RQ[i-1]-1); initial = size-1;
for(i=index-1;i>=0;i--)
{
TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial); initial=RQ[i];
}
}
// if movement is towards low value

else
{
for(i=index-1;i>=0;i--)
{
TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial); initial=RQ[i];
}
// last movement for min size TotalHeadMoment=TotalHeadMoment+abs(RQ[i+1]-0); initial =0;
for(i=index;i<n;i++)
{
TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial); initial=RQ[i];
}
}
printf("Total head movement is %d",TotalHeadMoment); return 0;}
Output:
Enter the number of Request 8
Enter the Requests Sequence 95 180 34 119 11 123 62 64
Enter initial head position 50
Enter total disk size
200 Enter the head movement direction for high 1 and for low 0 1
Total head movement is 337


8C
#include<stdio.h> #include<stdlib.h> int main()
{
int RQ[100],i,n,TotalHeadMoment=0,initial,count=0; printf("Enter the number of Requests\n"); scanf("%d",&n);
printf("Enter the Requests sequence\n"); for(i=0;i<n;i++)
scanf("%d",&RQ[i]);
printf("Enter initial head position\n"); scanf("%d",&initial);

// logic for sstf disk scheduling


/* loop will execute until all process is completed*/ while(count!=n)
{
int min=1000,d,index; for(i=0;i<n;i++)
{
d=abs(RQ[i]-initial); if(min>d)
{
min=d; index=i;
}

}
TotalHeadMoment=TotalHeadMoment+min; initial=RQ[index];
// 1000 is for max
// you can use any number RQ[index]=1000;
count++;

}


printf("Total head movement is %d",TotalHeadMoment); return 0;
}



Output:
Enter the number of Request 8
Enter Request Sequence
95 180 34 119 11 123 62 64
Enter initial head Position 50
Total head movement is 236
