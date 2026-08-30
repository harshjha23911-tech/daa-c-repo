#include <stdio.h>
#define SIZE 10
int hashTable[SIZE];
void initialize() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}
void insert(int key) {
    int index = key % SIZE;
    int i = 0;
    while (i < SIZE) {
        int pos = (index + i * i) % SIZE;
        if (hashTable[pos] == -1) {
            hashTable[pos] = key;
            printf("%d inserted at index %d\n", key, pos);
            return;
        }
        i++;
    }
    printf("Hash table is full.\n");
}
void search(int key) {
    int index = key % SIZE;
    int i = 0;
    while (i < SIZE) {
        int pos = (index + i * i) % SIZE;
        if (hashTable[pos] == key) {
            printf("%d found at index %d\n", key, pos);
            return;
        }
        if (hashTable[pos] == -1)
            break;
        i++;
    }
    printf("%d not found\n", key);
}
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1)
            printf("[%d] -> EMPTY\n", i);
        else
            printf("[%d] -> %d\n", i, hashTable[i]);
    }
}
int main() {
    int choice, key;
    initialize();
    while (1) {
        printf("\n1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}