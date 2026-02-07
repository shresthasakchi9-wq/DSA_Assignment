#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAfter(Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }

    Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if (prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    }

    prevNode->next = newNode;
}

void deleteNode(Node** head, Node* delNode) {
    if (*head == NULL || delNode == NULL)
        return;

    if (*head == delNode)
        *head = delNode->next;

    if (delNode->next != NULL)
        delNode->next->prev = delNode->prev;

    if (delNode->prev != NULL)
        delNode->prev->next = delNode->next;

    free(delNode);
}

void printList(Node* node) {
    printf("List: ");
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    Node* head = createNode(10);
    Node* second = createNode(20);
    Node* third = createNode(30);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    printf("Original List:\n");
    printList(head);

    insertAfter(second, 25);
    printf("After insertion:\n");
    printList(head);

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    insertAfter(temp, 40);
    printf("After insertion:\n");
    printList(head);

    deleteNode(&head, second);
    printf("After deletion:\n");
    printList(head);

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    deleteNode(&head, temp);
    printf("After deletion:\n");
    printList(head);

    return 0;
}