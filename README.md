#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
pthread_mutex_t wrt,red;
int readcount=0;
void *reader(void *arv)
{
 printf("readers trying to enter..\n");
 pthread_mutex_lock(&red);
 readcount++;
 if(readcount==1)
    {
    	 pthread_mutex_lock(&wrt);
    }
 printf("readers inside is=%d\n",readcount);
 pthread_mutex_unlock(&red);
 //sleep(2);
 pthread_mutex_lock(&red);
 readcount--;
 if(readcount==0)
    {
    	 pthread_mutex_unlock(&wrt);
    }
 pthread_mutex_unlock(&red);
 printf("readers trying to leaving...\n");
 	 
}
void *writer(void *a)
{
  printf("writers trying to enter..\n");
  pthread_mutex_lock(&wrt);
  printf("writers to entered..");
  printf("number of readers here= %d\n",readcount);
  //sleep(2);
  pthread_mutex_unlock(&wrt);
  printf("writers are leaving..\n");
  //sleep(2);
  pthread_exit(NULL);	 
}
int main()
{
	pthread_mutex_init(&wrt,NULL);
	pthread_mutex_init(&red,NULL);
	int n1,n2,i;
	pthread_t tid1,tid2;
	printf("Enter number of readers=");
	scanf("%d",&n1);
	printf("Enter number of writers=");
	scanf("%d",&n2);
	for(i=0;i<n1;i++)
	{
		 pthread_create(&tid1,NULL,reader,NULL);
	}
	for(i=0;i<n2;i++)
	{
		 pthread_create(&tid2,NULL,writer,NULL);
	}
	return 0;
}
