#include<stdio.h>
#include<stdlib.h>
struct node {
    int info;
    struct node *link;
};
struct node *first=NULL;
void insertAtFirst(int x){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->info=x;
    newNode->link=first;
    first=newNode;
}
int GCD(int a, int b){
    int min;
    if(a<=b){
        min=a;
    }
    else{
        min=b;
    }
    int i;
    for( i=min;i>=1;i--){
        if(a%i==0 && b%i==0){
            min=i;
            break;
        }
    }
    return min;
}
void display(){
    struct node *save=first;
    if(first==NULL){
        printf("Linklist Is Empty");
        return;
    }
    else {
        struct node* save = first;

        while (save != NULL)
        {
            printf("%d -> ",save->info);
            save = save->link;
        }
        printf("null\n");
    }
}
void insertGcd(){
    if(first==NULL){
        printf("Linklist Is Empty");
        return;
    }
    struct node *current=first;
    struct node *next=first->link;
    
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    
    while(current!=NULL){
        newNode=(struct node*)malloc(sizeof(struct node));
        newNode->info=GCD(current->info,next->info);
        current=current->link;
        next=next->link;
    }
}

void main()
{
	int choice,a;
	while(1){
		printf("1. enter a new node\n2.check Gcd and display\n3. display\n4. EXIT\nENTER YOUR CHOICE:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("ENTER ELEMENT:");
				scanf("%d",&a);
				insertAtFirst(a);
				display();
				break;
				
			case 2:
				insertGcd();
				display();
				break;
				
			case 3:
				display();
				
			case 4:
                exit(0);
                break;

            default:printf("")
		}
	}
}
