#include"header.h"
void read_file(SLL **ptr){
  SLL *new,*last;
  
  FILE *fp;
  fp=fopen("std.txt","r");
  if(fp==0)
  {
   printf("file not present\n");
   return ;
  }
  
  while(1){
  new=malloc(sizeof(SLL)); // creat a node 
   if(fscanf(fp,"%d%s%f",&new->rollno,new->name,&new->marks)==-1)
   break;
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
}

void save_file(SLL *ptr)
{
  printf("\033[34m ***********************\n");
   if(ptr==0)
  {
   printf("No records found\n");
   return;
  }
  FILE *fp;
  fp=fopen("std.txt","w");
   while(ptr){ // till last
     fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->marks); // prinintg
    ptr=ptr->next; //visit next node
   }
   printf("Data saved in file \n");
printf("**********************\033[0m\n");
 fclose(fp);
}


