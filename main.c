#include <stdio.h>
#include "queue_array.h"
#include "queue_list.h"
#include "HelperFuncs.h"

void menu(int queueType) {
    while (1) {
        printf("%s\n", queueType == 1 ? "Array\n" : "List\n");
        printf("1. Insert\n"
               "2. Delete\n"
               "3. Print\n"
               "4. Show first\n"
               "5. Clear\n"
               "6. Check if empty\n"
               "0. Exit the menu\n");

        int option;
        option = range_scan(0, 6);

        if (option == 0)
            break;

        int data;
        switch (option) {
            case 1:
                system("cls");
                printf("Insert data\n\n"
                       "Enter data: ");
                data = scan_safe_func_int();
                if (queueType == 1)
                    enqueueArray(data);
                else
                    enqueueList(data);
                break;
            case 2:
                system("cls");
                printf("Delete data\n\n"
                       "Enter data: ");
                if (queueType == 1)
                    dequeueArray();
                else
                    dequeueList();
                break;
            case 3:
                system("cls");
                printf("Print\n\n");
                if (queueType == 1)
                    printArray();
                else
                    printList();
                break;
            case 4:
                system("cls");
                printf("Show first\n\n");
                if (queueType == 1)
                    printf("%d\n", frontArray());
                else
                    printf("%d\n", frontList());
                break;
            case 5:
                system("cls");
                if (queueType == 1)
                    clearArray();
                else
                    clearList();
                printf("Clear complete\n\n");
                break;
            case 6:
                system("cls");
                if (queueType == 1)
                    printf("%s\n", isEmptyArray() ? "Queue is empty" : "Queue is not empty");
                else
                    printf("%s\n", isEmptyList() ? "Queue is empty" : "Queue is not empty");
                break;
        }
        system("pause");
    }
}

int main() {
    initArray();

    while (1) {
        system("cls");
        printf("\n1. Queue through array\n");
        printf("2. Queue via singly linked linear list\n");
        printf("0. Exit\n");

        int option;
        option = range_scan(0, 2);

        if (option == 0)
            break;

        menu(option);
    }

    freeArray();
    clearList();

    return 0;
}
