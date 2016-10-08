#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>
#include<stddef.h>

void print_msg(char *ptr);


int main(int argc,char *argv[]){
  pthread_t thread1,thread2;
  int i,j;
  char *msg1 = "do msg1\n";
  char *msg2 = "do msg2\n";
  pthread_create(&thread1,NULL,(void*)(&print_msg),(void*)msg1);
  pthread_create(&thread2,NULL,(void*)(&print_msg),(void*)msg2);
  sleep(1);

  return 0;
}

void print_msg(char *ptr){
   int retval;
   int id = pthread_self();
   printf("Thread ID:%x\n",id);
   printf("%s",ptr);
   pthread_exit(&retval);
}
