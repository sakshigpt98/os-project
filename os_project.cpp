#include<stdio.h>
#include<pthread.h>
int readcount=0;
int shared=1;
pthread_mutex_t wrt,red;
void *reader(void *arv)
{
	printf("reader is trying to enter....\n");
	pthread_mutex_lock(&red);
   	readcount++;
	if(readcount==1)
	 pthread_mutex_lock(&wrt);
	printf("reader inside the reader function =%d\n",readcount);
	printf("value of shared in reader=%d",shared);
	pthread_mutex_unlock(&red);
	//sleep(2);
	pthread_mutex_lock(&red);
	readcount--;
	if(readcount=0)
	 pthread_mutex_unlock(&wrt);
	printf("reader trying to leaving...\n");
	pthread_mutex_unlock(&red);

	
}
void *writer(void *a)
{
	printf("writer are trying to enter...\n");
	pthread_mutex_lock(&wrt);
	printf("writer entered...\n");
	shared++;
	printf("value of shared in writer=%d",shared);
	//sleep(2);
	printf("reader inside writerfunctionn=%d\n",readcount);
	printf("writer leaving...\n");
	pthread_mutex_unlock(&wrt);
	//sleep(2);	
}
int main()
{
	    void* result;
		pthread_t t1[50],t2[50];
		int n1,n2,i;
	        pthread_mutex_init(&wrt,NULL);
		pthread_mutex_init(&red,NULL);
		printf("enter reader=");
		scanf("%d",&n1);
	    printf("enter  writer");
		scanf("%d",&n2);
		for(i=0;i<n1;i++)
		pthread_create(&t1[i],NULL,reader,NULL);
		for(i=0;i<n2;i++)
		pthread_create(&t1[i],NULL,writer,NULL);
		for(i=0;i<n2;i++)
		pthread_join(t1[i],&result);
		for(i=0;i<n1;i++)
		pthread_join(t2[i],&result);
		return 0;

}
