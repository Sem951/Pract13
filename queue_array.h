#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#define INITIAL_SIZE 5

extern int *queue;
extern int array_front;
extern int array_rear;
extern int size;
extern int capacity;

void initArray();
void enqueueArray(int data);
int dequeueArray();
void printArray();
int frontArray();
void clearArray();
int isEmptyArray();
void freeArray();

#endif
