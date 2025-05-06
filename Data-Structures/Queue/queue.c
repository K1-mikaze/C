#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned int PIB;
  char name;
  unsigned int position;
  unsigned int size;
  struct Node *next;
} Node;

typedef struct {
  Node *first_Node;
} Queue;

void initQueue(Queue *q) { q->first_Node = NULL; }

bool isEmpty(Queue *q) { return q->first_Node == NULL; }

void getIn(Queue *q, char name) {
  Node *node = (Node *)malloc(sizeof(Node));
  if (node == NULL) {
    return;
  }
  node->size = sizeof(Node);
  node->name = name;
  node->next = NULL;

  if (isEmpty(q)) {
    node->PIB = 0;
    node->position = 0;
    q->first_Node = node;
  } else {
    Node *last_Node = q->first_Node;
    while (last_Node->next != NULL) {
      last_Node = last_Node->next;
    }
    node->PIB = last_Node->PIB + 1;
    node->position = last_Node->position + last_Node->size + 1;
    last_Node->next = node; // Fixed this line - removed the &
  }
}
void printQueue(Queue *q) {
  if (q->first_Node == NULL) {
    printf("Queue is empty.\n");
    return;
  }

  Node *node = q->first_Node;
  printf("--------------------------------\n");
  printf("Queue Contents:\n");
  printf("--------------------------------\n");

  while (node != NULL) {
    printf("PIB: %d\n", node->PIB);
    printf("Name: %c\n", node->name);
    printf("Position: %d\n", node->position);
    printf("Size: %d bytes\n", node->size);
    printf("--------------------------------\n");
    node = node->next;
  }
}
int main() {

  Queue q;
  initQueue(&q);

  getIn(&q, 'A');
  getIn(&q, 'B');
  printQueue(&q);

  return 0;
}
