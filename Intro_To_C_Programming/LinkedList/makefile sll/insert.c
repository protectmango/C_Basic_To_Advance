#include"header.h"
void add_middle(SLL **ptr)
{
  SLL *new,*pos;
  new=malloc(sizeof(SLL));
  printf("My dear ! enter rollno name and marks\n");
   scanf("%d%s%f",&new->rollno,new->name,&new->marks);
                                // scan the data 
                                 	
  if((*ptr==0) ||(new->rollno < (*ptr)->rollno))
  { // if no records / new ->rollno < first rollno
     new->next=*ptr; //update new next addr
     *ptr=new; // update headptr
  } 
  else // if middle node /last node 
  {
   pos=*ptr; 
   while((pos->next!=0) &&(new->rollno > pos->next->rollno)) // finding exact position to add 
   pos=pos->next; //visit next node 
   
   
   new->next=pos->next; // update new next addr
   pos->next=new;     // update the position next addr
  
  }
}

void add_begin(SLL **ptr){
  SLL *new;
  new=malloc(sizeof(SLL)); // creat a node 
   printf("My dear ! enter rollno name and marks\n");
   scanf("%d%s%f",&new->rollno,new->name,&new->marks);
                                // scan the data 
   new->next=*ptr; // update new record next 
   *ptr=new; // update headptr
}

void add_end(SLL **ptr){
  SLL *new,*last;
  new=malloc(sizeof(SLL)); // creat a node 
   printf("My dear ! enter rollno name and marks\n");
   scanf("%d%s%f",&new->rollno,new->name,&new->marks);
                                // scan the data 

   new->next=0; //always update zero 
   if(*ptr==0) // if no records present then
      *ptr=new; // update headptr
   else
   {
     last=*ptr; // started from first node 
     while(last->next) //finding the last node
     last=last->next; //visit next node 
     
     last->next=new; // update last node next addr as new
   }  
}
