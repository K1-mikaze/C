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
  Node *top;
} Stack;

Node *NodeAllocate() { return (Node *)malloc(sizeof(Node)); }

void initStack(Stack *s) { s->top = NULL; }

bool isEmpty(Stack *s) { return s->top == NULL; }

void printStack(Stack *s) {
  Node *node = s->top;
  while (node != NULL) {
    printf("PIB : %d   Name : %c\nPosition : %d\nSize : %d\n\n", node->PIB,
           node->name, node->position, node->size);
    node = (Node *)node->next;
  }
  free(node);
}

void push(Stack *s, char name) {
  Node *node = NodeAllocate();
  if (node == NULL) {
    printf("Memory allocation failed\n");
  } else {
    if (!isEmpty(s)) {
      node->next = s->top;
      node->PIB = s->top->PIB + 1;
      node->position = s->top->position + sizeof(Node) + 1;
    } else {
      node->PIB = 0;
      node->position = 0;
    }
    node->size = sizeof(Node);
    node->name = name;
    s->top = node;
    free(node);
  }
}

void pop(Stack *s) {
  Node *node = s->top;
  s->top = (Node *)s->top->next;
  printf("-------------------\nPROCESS DELETED\nPIB : %d   Name : "
         "%c\nPosition : %d\nSize : "
         "%d\n------------------\n\n",
         node->PIB, node->name, node->position, node->size);
  free(node);
  node = NULL;
}

int main() {

  Stack stack;
  initStack(&stack);

  push(&stack, 'A');
  push(&stack, 'B');
  push(&stack, 'C');
  printStack(&stack);
  pop(&stack);
  printStack(&stack);

  return 0;
}
