#include"header.h"
void sort_data(SLL *ptr)
{
  if(ptr==0){
   printf("\033[34m No records found\033[0m\n");
   return ;
  }
  
  
   int c=count_node(ptr); // finding node count
   SLL *p1,*p2,t;
   p1=ptr; //holding first node addr
   
   int i,j;
   for(i=0;i<c-1;i++)
   {
     p2=p1->next; //always starts from p1->next
    for(j=0;j<c-1-i;j++){
     if(p1->rollno > p2->rollno){ //swapping logic
      t.rollno=p1->rollno;
      p1->rollno=p2->rollno;
      p2->rollno=t.rollno;
      
      strcpy(t.name,p1->name);
      strcpy(p1->name,p2->name);
      strcpy(p2->name,t.name);
     
      t.marks=p1->marks;
      p1->marks=p2->marks;
      p2->marks=t.marks;
     }
     p2=p2->next; // visit next node   
    }
    p1=p1->next; //alwways starts from p1->next
   }   
  }



void search_node(SLL *ptr){
    if(ptr==0){
     printf("No records found\n");
     return ;
    }
     int f=0;
	char name[20];
	printf("enter name to search\n");
	scanf("%s",name); //scaaning 
	while(ptr){
     if(strcmp(ptr->name,name)==0){ // comaprsing 
      printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks); // prinintg
       f=1;
      }
      ptr=ptr->next;// visit next node 	
	
	}
	if(f==0)
	printf("name not found\n");
}



int count_node(SLL *ptr)
{
   int c=0;
   while(ptr){ // till last record
     c++; // count increment
     ptr=ptr->next; //visit next record
   }
   return c; //return final count
}
