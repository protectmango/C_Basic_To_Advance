#include"header.h"
int main(){
	int op,c;
	SLL *headptr=0;
repeat : 
		printf("\033[32mEnter your choice\n");
		printf("1)add_begin \n2)add_end \n3)add_middle \n4)print_node \n5)count_node \n6)save_file \n7)read_file \n8)reverse_print \n9)delete_all \n10)delete_node \n11)search_node \n12)sort_data \n13)reverse_links \n14)exit\n\033[0m");
		scanf("%d",&op); 
		switch(op){
			case 1: add_begin(&headptr);break;
			case 2: add_end(&headptr);break;
			case 3: add_middle(&headptr);break;
			case 4:print_node(headptr);break; 
			case 5:c=count_node(headptr);
					printf("\033[31m Total count:%d\n\033[0m",c);break;
			case 6: save_file(headptr);break;
			case 7: read_file(&headptr);break;
			case 8: reverse_print(headptr);break;
			case 9:delete_all(&headptr);break;
			case 10: delete_node(&headptr);break;
			case 11: search_node(headptr);break;
			case 12: sort_data(headptr);break;
			case 13: reverse_links(&headptr);break;
			case 0 : goto repeat ;
			case 14:exit(0);
			default:printf("\033[31;4;5;1;44m wrong choice selected\033[0m\n");
		}
	
}

