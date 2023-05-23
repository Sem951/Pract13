#ifndef QUEUE_LIST_H
#define QUEUE_LIST_H

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

extern Node *list_front;
extern Node *list_rear;
extern int size;

void enqueueList(int data);
int dequeueList();
void printList();
int frontList();
void clearList();
int isEmptyList();

#endif
