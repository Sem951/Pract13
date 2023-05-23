#include <stdio.h>
#include <stdlib.h>
#include "queue_array.h"


int *queue = NULL;
int array_front = -1;
int array_rear = -1;
int size = 0;
int capacity = INITIAL_SIZE;


/**
 * @brief Initializes the queue.
 */
void initArray()
{
    queue = malloc(capacity * sizeof(int));
    if (queue == NULL)
    {
        printf("Не вдалось виділити пам'ять!\n");
        exit(1);
    }
}


/**
 * @brief Enqueues the data into the queue.
 *
 * @param data The data to enqueue.
 */
void enqueueArray(int data)
{
    if ((array_rear + 1) % capacity == array_front)
    {  // Очередь полна
        capacity *= 2;
        queue = realloc(queue, capacity * sizeof(int));
        if (queue == NULL)
        {
            printf("Не вдалось виділити пам'ять!\n");
            exit(1);
        }
    }
    if (size == 0)
        array_front = array_rear = 0;
    else
        array_rear = (array_rear + 1) % capacity;

    queue[array_rear] = data;
    size++;
}


/**
 * @brief Dequeues the data from the queue.
 *
 * @return The dequeued data.
 */
int dequeueArray()
{
    if (size == 0)
    {
        printf("Очередь пуста!\n");
        return 0;
    }
    int data = queue[array_front];
    queue[array_front] = 0;
    array_front = (array_front + 1) % capacity;
    size--;
    return data;
}


/**
 * @brief Prints the queue.
 */
void printArray()
{
    if (size == 0)
    {
        printf("Очередь пуста!\n");
        return;
    }
    for (int i = 0; i < capacity; i++)
        printf("%d ", queue[i]);
    printf("\n");
}


/**
 * @brief Returns the list_front of the queue.
 *
 * @return The list_front of the queue.
 */
int frontArray()
{
    if (size == 0)
    {
        printf("Очередь пуста!\n");
        return 0;
    }
    return queue[array_front];
}


/**
 * @brief Clears the queue.
 */
void clearArray()
{
    free(queue);
    array_front = -1;
    array_rear = -1;
    size = 0;
    capacity = INITIAL_SIZE;
    initArray();
}


/**
 * @brief Checks if the queue is empty.
 *
 * @return True if the queue is empty, false otherwise.
 */
int isEmptyArray()
{
    return size == 0;
}


/**
 * @brief Frees the queue.
 */
void freeArray()
{
    free(queue);
}
