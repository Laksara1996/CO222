#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char word[100];
    int len;
    struct node*next;
    
}Node;

int text(Node*head, int len);
int len(Node *head);

int main(int argc, char *argv[]){

	if(argc!=2){
		printf("Number of arguments are wrong\n");
		return 0;
	}

	char array[100];
	FILE*ifile;
	ifile= fopen(argv[1],"r");

	Node head;
	Node * itr= &head;

	while(fscanf(ifile, "%s",array) != EOF){
	    Node *temp =NULL;
	    temp=(Node*)malloc(sizeof(Node));
	    itr->next=temp;
	    strcpy(temp->word,array);
	    temp->len = strlen(array);
	    itr= temp;
	        
	}  

	fclose(ifile);
	text(&head,len(&head));
	   
	return 0;
}

int len(Node * head){
  int l=0;
  Node *crnt = head;
     while(crnt != NULL){
         if(crnt-> len > l){
           l=crnt->len;
         }
         crnt = crnt-> next;
     }
     return l;
}

int text(Node *head, int len){
	while(len>0){
	   while(head != NULL){
	        if(head->len == len){
	           printf("%s\n", head->word);
	           return 0;
	        }
	        head = head-> next;
	   }
	   len--;
	}
}
    

