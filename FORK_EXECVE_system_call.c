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
