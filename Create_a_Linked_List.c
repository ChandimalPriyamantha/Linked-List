#include<stdio.h>
#include<stdlib.h>

struct node{
	
	int data;
	struct node *next;
	
};

struct node *p, *q, *head;

void createNode(){
	
	int i, n, item;

	
	printf("Enter the nuber of nodes");
	scanf("%d",&n);
	
	printf("Enter the vale of the head node:");
	scanf("%d",&item);
	
	q = (struct node*)malloc(sizeof(struct node));
	
	q->data = item;
	q->next = NULL;
	
	head = q;
	p = head;
	
	for(i=1; i<n; i++){
		
	    printf("Enter the vale of the next node:");
	    scanf("%d",&item);
	
	    q = (struct node*)malloc(sizeof(struct node));
	
	    q->data = item;
	    q->next = NULL;
	    
	    p->next = q; //Link the nodes
	    p = p->next; //Jump to the current node
	    
	}
	
	
return 0;
	
}

void printValue(){
	
	p = head;
	while(p!=NULL){
		printf("%d",p->data);
		p = p->next;
	}
}

void insert_begin(){
	
	struct node *p;
	int value;
	p = (struct node*)malloc(sizeof(struct node*));
	if(p==NULL){
		printf("\nOVERFLOW");
	}else{
		printf("\nEnter value\n");
		scanf("%d",&value);
		
		p->data = value;
		p->next = head;
		head=p;
	}
}

void insert_middle(){
	
	int i,loc,value;
	struct node *new_node, *temp;
	new_node=(struct node*)malloc(sizeof(struct node));
	
	if(new_node==NULL){
		printf("\nOVERFLOW");
	}else{
		printf("\nEnter element value");
		scanf("%d",&value);
		new_node->data = value;
		printf("\nEnter the location after which you want to insert");
		scanf("\n%d",&loc);
		temp=head;
		
		for(i=1; i<loc; i++){
			temp = temp->next;
			
			if(temp==NULL){
				printf("\n Can't insert\n'");
				return 0;
			}
		}
		
		new_node->next = temp->next;
		temp->next=new_node;
	}
	
}

void insertEnd(){
	
	struct node *p, *temp;
	int value;
	p=(struct node*)malloc(sizeof(struct node));
	if(p==NULL){
		printf("\nOVERFLOW");
	}else{
	  printf("\nEnter value\n");
	  scanf("%d",&value);
	  p->data=value;
	  if(head==NULL){
	  	p->next = NULL;
	  	head = p;
	  }else{
	  	temp=head;
	  	while(temp->next!=NULL){
	  		temp= temp->next;
		  }
		  temp->next=p;
		  p->next = NULL;
	  }
	}
}

void delete_begin(){
	
	struct node *temp;
	if(head==NULL){
		printf("\nList is empty\n");
	}else{
		
		temp=head;
		head=temp->next;
		free(temp);
	}
}

void delete_end(){
	struct node *temp, *prev_node;
	if(head==NULL){
		printf("\nlist is empty");
	}else if(head->next == NULL){
	    head=NULL;
	    free(head);
	    printf("\nOnly node of the list deleted..\n");
	    
	    }else{
	    	temp=head;
	    	while(temp->next!=NULL){
	    		prev_node = temp;
	    		temp=temp->next;
			}
			
			prev_node->next=NULL;
			free(temp);
		}
	}
	
void delete_middle(){
	
	struct node *temp, *prev_node;
	int loc,i;
	
	printf("\nEnter the location of the node after which you want to perform deletion \n");
	scanf("%d",&loc);
	
	temp=head;
	for(i=0; i<loc; i++){
		
		prev_node=temp;
		temp=temp->next;
		
		if(temp==NULL){
			printf("\nCan't delete'");
			return 0;
		}
	}
	
	prev_node->next=temp->next;
	free(temp);
	printf("\nDelete node %d",loc+1);
	
}


int main(){
	
createNode();
printValue();
printf("\n");
delete_middle();
printf("\n");
//delete_end();
//delete_begin();
printValue();
//insert_begin();	
//printValue();
//insert_middle();
//printValue();
//insertEnd();
//printValue();
	
}
