#include <stdio.h>
#include <stdlib.h>
#include "queue_list.h"

Node *list_front = NULL;
Node *list_rear = NULL;
int size = 0;


/**
 * @brief Enqueues the data into the queue.
 *
 * @param data The data to enqueue.
 */
void enqueueList(int data)
{
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Error allocating memory!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (size == 0)
        list_front = list_rear = newNode;
    else
    {
        list_rear->next = newNode;
        list_rear = newNode;
    }
    size++;
}


/**
 * @brief Dequeues the data from the queue.
 *
 * @return The dequeued data.
 */
int dequeueList()
{
    if (size == 0)
    {
        printf("Queue is empty!\n");
        return 0;
    }
    Node *temp = list_front;
    int data = temp->data;
    list_front = list_front->next;
    free(temp);
    size--;
    if (size == 0)
        list_rear = NULL;
    return data;
}


/**
 * @brief Prints the queue.
 */
void printList()
{
    if (size == 0)
    {
        printf("Queue is empty!\n");
        return;
    }
    Node *temp = list_front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


/**
 * @brief Returns the list_front of the queue.
 *
 * @return The list_front of the queue.
 */
int frontList()
{
    if (size == 0)
    {
        printf("Queue is empty!\n");
        return 0;
    }
    return list_front->data;
}


/**
 * @brief Clears the queue.
 */
void clearList()
{
    while (size != 0)
        dequeueList();
}


/**
 * @brief Checks if the queue is empty.
 *
 * @return True if the queue is empty, false otherwise.
 */
int isEmptyList()
{
    return size == 0;
}
