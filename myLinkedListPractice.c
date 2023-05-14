#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *p, *q, *head;

void createNode(){
	
	int i,n,item;
	
	printf("Enter the number of nodes");
	scanf("%d",&n);
	
	printf("Enter the valu of the head node:");
	scanf("%d",&item);
	
	q = (struct node*)malloc(sizeof(struct node));
	
	q->data = item;
	q->next = NULL;
	
    head = q;
    p = head;
    
    for(i=1; i<n; i++){
    	printf("Enter the valu of the next node:");
    	scanf("%d",&item);
    	
    	q = (struct node*)malloc(sizeof(struct node));
    	
    	q->data = item;
    	q->next = NULL;
    	
    	p->next = q;
    	p = p->next;
	}
	
	p = head;
	while(p!=NULL){
		printf("%d",p->data);
		p = p->next;
	}
return 0;
}

int main(){
	createNode();
}
