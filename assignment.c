// assignment
// DS LAB ASSIGNMENT FOR NEXT DAY
// write a menu based program on Linked list performing 
// 1. CREATION
// 2. INSERTION
// 3. DELETION
// 4. PRINT
// 5. REVERSE
// 6. CONCATENATION OF LIST
// 7. CIRCULAR LINKED LIST

#include<stdio.h>
#include<stdlib.h>

//structure of a linked list
struct Node{
        int data;
        struct Node *next;
};


/* ========================================================================================
                                Printing of a linked list
===========================================================================================*/
void displayLL(struct Node *ptr){
    system("clear");
    printf("\n=========================================================\n");
    if(ptr==NULL){
        printf("\t\t(empty)");
    }
    else{
        while(ptr!=NULL)
        {
            printf("%d -> ",ptr->data);
            ptr = ptr->next;
        }
    }
}
//============================================================================================



/* ========================================================================================
                                Insertion of a node
===========================================================================================*/
struct Node* insertBeg(struct Node *head){
    struct Node *elem;
    elem = (struct Node*) malloc (sizeof(struct Node));
    printf("\nEnter the value to insert at beginning : ");
    scanf("%d",&(elem->data));
    elem->next = head;
    head = elem;
    return elem;
}

void insertEnd(struct Node *ptr){
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    struct Node *elem;
    elem = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter the value to insert at the end : ");
    scanf("%d",&(elem->data));
    ptr->next = elem;
    elem->next = NULL;
}

void insertn(struct Node *ptr){
    printf("Enter the index(starts from 1): ");
    int i;
    scanf("%d",&i);
    i=i-1;
    while(--i)
    {
        ptr = ptr->next;
    }
    struct Node *elem;
    elem = (struct Node*)malloc(sizeof(struct Node)); 
    printf("Enter the value to insert : ",i);
    scanf("%d",&(elem->data));
    elem->next = ptr->next;
    ptr->next = elem;
}

struct Node* insert(struct Node *head){
    system("clear");
    printf("\n===========Insertion of a Node==========\n\n");
    printf("Where you want to insert a node? \n");
    printf("1. At beginning\n");
    printf("2. In the end\n");
    printf("3. At 'nth' index\n");
    printf("4. Main Menu\n");
    printf("Enter your choice : ");
    int ch;
    scanf("%d", &ch);
    switch(ch){
        case 1: head = insertBeg(head);
                break;
                
        case 2: insertEnd(head);
                break;
                
        case 3: insertn(head);
                break;
                
        case 4: exit;
                break;
        
        default: printf("Wrong choice entered!!!\n\n");
                system("clear");
                exit;
    }
    return head;
}

//=============================================================================================




/* ========================================================================================
                                Deletion of a node
===========================================================================================*/

struct Node* deleteByValue(struct Node *ptr){
    printf("Enter the value to delete : ");
    int val;
    scanf("%d",&val);
    while(ptr->data != val || ptr->next!=NULL)
    {
        ptr = ptr->next;   
    }
    if(ptr==NULL)
    {
        printf("Entered value not found!!!\n");
    }
    else if(ptr->data == val){
        
    }
}

struct Node* delete(struct node *head){
    printf("\n===========Deletion of a Node==========\n\n");
    printf("How you want to delete a node \n");
    printf("1. By value\n");
    printf("2. By index\n");
    printf("3. Main Menu\n");
    printf("Enter your choice : ");
    int ch;
    scanf("%d", &ch);
    switch (ch)
    {
    case 1: deleteByValue(head);
            break;

    case 2: deleteByIndex(head);
            break;

    case 3: exit;
    
    default: printf("Wrong choice entered!!!\n\n");
            system("clear");
            exit; 
    }
    return head;
}

//=============================================================================================




int main(){

        struct Node *head;
        head = NULL;
        while(1){
        displayLL(head);
        printf("\n======================[Linked List]======================\n\n");
        printf(" 1. Create a new Linked List\n");
        printf(" 2. Insert element in a Linked List\n");
        printf(" 3. Delete element in a Linked List\n");
        printf(" 4. Reverse a Linked List\n");
        printf(" 5. Concatenate two Linked list\n");
        printf(" 6. Circular Linked List\n");
        printf(" 7. Exit\n");
        printf("Enter the choice you want to perform : ");
        int ch;
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: head=(struct Node*)malloc(sizeof(struct Node));
                    printf("Enter head elem : ");
                    scanf("%d",&(head->data));
                    head->next = NULL;
                    break;

            case 2: head = insert(head);
                    break;

            case 3: head = delete(head);
                    break;

            // case 4: reverse();
            //         break;

            // case 5: concatenate();
            //         break;

            // case 6: circularLL();
            //         break;

            case 7: return 0;

            default: printf("No choice choosen");

        }
    }
    return 1;
}