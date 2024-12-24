#include <cstddef>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int node_data;
    struct Node *next; 
} node_t;

void printList(node_t *head) {
    node_t *current = head;
    while(current != NULL)
    {
        printf("%d--", current->node_data);
        current = current->next;
    }
    printf("END\n");
}

void freeList(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        node_t *free_this = current;
        current = current->next;
        free(free_this);
    }
    printf("List successfully freed.\n");
}
int main()
{
    node_t *head = (node_t *)malloc(sizeof(node_t));
    node_t *n1 = (node_t *)malloc(sizeof(node_t));
    node_t *n2 = (node_t *)malloc(sizeof(node_t));
    node_t *n3 = (node_t *)malloc(sizeof(node_t));
    node_t *n4 = (node_t *)malloc(sizeof(node_t));

    head->node_data = 100;
    n1->node_data = 200;
    n2->node_data = 300;
    n3->node_data = 400;
    n4->node_data = 500;

    head->next = n1;
    n1->next = n2; n2->next = n3; n3->next = n4;
    n4->next = NULL;
    
    printList(head);
    freeList(head);
    return 0;
}
