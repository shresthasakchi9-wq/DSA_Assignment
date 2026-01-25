#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}


void addNode(struct Node** head, int data) {
    struct Node* node = createNode(data);
    if (*head == NULL) {
        *head = node; 
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = node; 
    }
}


void printReverse(struct Node* head) {
    if (head == NULL) return;  
    printReverse(head->next);   
    printf("%d ", head->data);  
}

int main() {
    struct Node* head = NULL;

    // Add nodes
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);


    printf("Reverse list: ");
    printReverse(head);  
    printf("\n");

    return 0;
}
