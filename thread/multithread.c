#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<sys/time.h>

#define MAX 10

pthread_t thread[2];
pthread_mutex_t mut;
int number = 0,i;

void *thread1(){
   printf("thread1 :I'm thread 1\n");
   for(i = 0;i < MAX;i++){
      pthread_mutex_lock(&mut);
      printf("thread1:number = %d\n",number);
      number++;
      pthread_mutex_unlock(&mut);
      sleep(2);
   }
   printf("thread1:mian thread is waiting me to finish task?\n");
   pthread_exit(NULL);
}

void * thread2(){
   printf("thread2 :I'm thread 2\n");
   for(i = 0;i < MAX;i++){
      pthread_mutex_lock(&mut);
      printf("thread2:number = %d\n",number);
      number++;
      pthread_mutex_unlock(&mut);
      sleep(3);
   }
   printf("thread2:main thread is waiting me to finish task?\n");
   pthread_exit(NULL);
}
void thread_create(void){
   int temp;
   memset(&thread,0,sizeof(thread));
   if((temp = pthread_create(&thread[0],NULL,thread1,NULL)) != 0){
      printf("create thread1 fail!\n");
   }else{
      printf("thread1 has been created!\n");
   }
   if((temp = pthread_create(&thread[1],NULL,thread2,NULL)) != 0){
      printf("create thread2 fail!\n");
   }else{
      printf("thread2 has been created!\n");
   }
}

void thread_wait(void){
   if(thread[0] != 0){
      pthread_join(thread[0],NULL);
      printf("thread1 has end!\n");
   }
   if(thread[1] != 0){
      pthread_join(thread[1],NULL);
      printf("thread2 has end!\n");
   }
}
int main(int argc,char *argv[]){
   pthread_mutex_init(&mut,NULL);
   printf("I'm main thread,I'm creating thread ... \n");
   thread_create();
   printf("I'm main thread,I'm waiting thread finish task!\n");
   thread_wait();
   return 0;
}
