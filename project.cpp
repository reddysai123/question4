#include<stdio.h>
#include<pthread.h>
#include<time.h>
#include<string.h>
int i=0;
void *fun()
{
char a[6]={'i','j','k','m'};
printf("character is %c",a[i]);
i++	;
if(i==strlen(a)-1)
{
	i=0;
}
}
main()
{
int size=0,size_l=0,i=0,m;
clock_t r,t;
double exetime;
while(1)
{
printf("\nEnter 1 to create process and 2 to exit:");
scanf("%d",&m);
if(m==2)
{
break;
}
else
{
pthread_t p[10],lower[10],higher[10];
pthread_create(&p[i],NULL,fun,NULL);
t=clock();
pthread_join(p[i],NULL);
r=clock()-t;
exetime=(double)r/CLOCKS_PER_SEC;//to get in seconds
printf("\nThe time taken by the process is=%f",exetime);
if(exetime<1)
{
printf("\nEntered to the higher priority");
higher[size]=p[i];
size++;
}
else
{
printf("\nEntered to the low priority");
lower[size_l]=p[i];
size_l++;
}
i++;
}
}
}

