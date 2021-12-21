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

