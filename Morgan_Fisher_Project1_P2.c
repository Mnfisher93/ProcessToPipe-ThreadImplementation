//** Morgan Fisher **//
//** Operating Sytems Project 1  **//
//** Part 2 **//
//** Refrences: Slides, Textbook **//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

//** threads call each function   **//
void* addarray1(void*arg);
void* addarray2(void*arg);

//** In the main function, create 2 threads. **//
int main() {

//** thread identifier **//
pthread_t tid1;
//** set of thread attributes r **//
pthread_attr_t attr;
//** set the default attributes of the thread **//
pthread_attr_init(&attr);

//** Create thread 1 **//
pthread_create(&tid1,NULL,addarray1,NULL);
pthread_join(tid1,NULL);

//** 2nd thread identifier **//
pthread_t tid2;

//** Create thread 2 **//
pthread_create(&tid2,NULL,addarray2,NULL);
pthread_join(tid2,NULL);


return 0;
}

//First Function
void* addarray1(void* arg)
{
  //declare array
    int arr1[]={3,8,12,21,1};
    int sum=0;
//** Length of Array **//
    int length  = sizeof(arr1)/sizeof(int);
//** Sum values of the array **// 
    for(int i=0; i<length; i++)
    {
        sum=sum+arr1[i];
    }
    printf("\nSum of Value from first function:%d\t",sum);
//** Exit thread **//
    pthread_exit(NULL);
}

//** Second Function
void* addarray2(void* arg)
{
  //declare array
    int arr2[]={7,23,18,15,10};
    int sum=0;
//** Length of Array **//
    int length  = sizeof(arr2)/sizeof(int);
//** Sum values of the array **//
    for(int i=0; i<length; i++)
    {
        sum=sum+arr2[i];
    }
    printf("\nSum of Value from second function:%d\t",sum);
//** Exit thread **//
    pthread_exit(NULL);
}