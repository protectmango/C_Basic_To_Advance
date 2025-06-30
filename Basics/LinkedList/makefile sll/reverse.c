#include"header.h"
void reverse_links(SLL **ptr){
 if(*ptr==0){
   printf("\033[35m No records found\033[0m\n");
   return ;
 }

  int c=count_node(*ptr); // finding node count
  if(c>1){
  SLL **arr,*t=*ptr;;
  arr=malloc(sizeof(SLL*)*c);
  int i=0;
   while(t){ // till last node 
    arr[i]=t; //holding all node addr
    i++;
    t=t->next;//visit next node
   }  

////////////////// change the link 
  for(i=1;i<c;i++)
    arr[i]->next=arr[i-1];
    
  arr[0]->next=0;
  *ptr=arr[c-1];  
 }
}

