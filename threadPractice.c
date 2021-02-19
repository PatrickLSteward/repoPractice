#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct ID_struct{
    int num;
    char c;
};

void* task_body1(void* pv)
{
   struct ID_struct *ID = pv; 
   
   printf("%d  -- %c\n",ID -> num+1,ID -> c);
   //pthread_exit(NULL);
  
}

int main(){
   int len = 26;
   pthread_t pt1[len]; //thread handle
   struct ID_struct ID[len];
   for(int i=0; i <len; ++i){
   	ID[i].num = i;
   	ID[i].c = 'A' + i;
   }
   //c +=1;
   for(int i=0; i <len; ++i){
      pthread_create(&pt1[i], NULL,task_body1,&ID[i]);
   }
   
   
   printf("here-----.\n");
    
   for(int i=0; i <len; ++i){
   	pthread_join(pt1[i],NULL);
   }
   printf("Finished executing all threads.\n");
   return 0;
}
