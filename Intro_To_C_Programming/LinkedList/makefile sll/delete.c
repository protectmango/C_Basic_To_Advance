#include"header.h"
/* 1. if records not present
   2. if records present ,but data not found
   3. if records present and data found at first place
   4.found at middle position
   5.found at last position
   6.if node count is 1  

*/

void delete_node(SLL **ptr){
 if(*ptr==0){
  printf("No records found\n");
  return ;
 }
 int n;
 printf("enter rollno to delete\n");
 scanf("%d",&n);
 
 SLL *del=*ptr,*prev; // starts from  first node addr
 while(del){ // till last node 
    if(n == del->rollno){ // if rollno present then
     if(del == *ptr) // check if it is first node then
        *ptr=del->next; // update headpointer
     else // if it is middle/last position
        prev->next=del->next; //update previous node next addr
     free(del); //delete a node 
     return ;
    }
    prev=del; //follow the del pointer one step back
    del=del->next; //visit next node
  }
   printf("Rollno not found\n");
}


void delete_all(SLL **ptr){
 if(*ptr==0)
 {
  printf("No records found\n");
  return ;
 }
 int c=1;
  SLL *del= *ptr; // holding first node addr
 while(del){  // till last node 
 *ptr= del->next; //update headptr to next node 
 printf("Node %d deleted\n",c++);
 sleep(1); //generate delay 1 sec
 free(del); //delete a node
 del=*ptr; //update del to first node
 
 }
 printf("all the nodes deleted\n");
}

