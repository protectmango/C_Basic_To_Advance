#include"header.h"

void reverse_print(SLL *ptr)
{
  if(ptr==0){
   printf("No records found\n");
    return ;
  }

  SLL *temp;
  int i,j,c=count_node(ptr); // finding node count
  for(i=0;i<c;i++){
   temp=ptr; // always starts from first node
   for(j=0;j<c-1-i;j++)
    temp=temp->next;
    
    printf("%d %s %f\n",temp->rollno,temp->name,temp->marks);
  
  }
}


void print_node(SLL *ptr)
{
  printf("\033[34m***********************\n");
   if(ptr==0)
  {
   printf("No records found\n");
   return;
  }
   while(ptr){ // till last
     printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks); // prinintg
    ptr=ptr->next; //visit next node
   }
printf("**********************\033[0m\n");

}
