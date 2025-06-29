#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct HashTable {
    int key;
    int value;
    int status; // 0: empty, 1: occupied, -1: deleted
};

struct HashTable hashTable[SIZE];

void initializeTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i].status = 0;
    }
}

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key, int value) {
    int index = hashFunction(key);
    int originalIndex = index;
    
    while (hashTable[index].status == 1) {
        index = (index + 1) % SIZE;
        if (index == originalIndex) {
            printf("Hash table is full!\n");
            return;
        }
    }
    
    hashTable[index].key = key;
    hashTable[index].value = value;
    hashTable[index].status = 1;
    printf("Inserted (%d, %d) at index %d\n", key, value, index);
}

int search(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    
    while (hashTable[index].status != 0) {
        if (hashTable[index].status == 1 && hashTable[index].key == key) {
            return index;
        }
        index = (index + 1) % SIZE;
        if (index == originalIndex) break;
    }
    
    return -1;
}

void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i].status == 1) {
            printf("Index %d: (%d, %d)\n", i, hashTable[i].key, hashTable[i].value);
        } else {
            printf("Index %d: Empty\n", i);
        }
    }
}

int main() {
    initializeTable();
    
    int choice, key, value, result;
    
    while (1) {
        printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter key and value: ");
                scanf("%d %d", &key, &value);
                insert(key, value);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                result = search(key);
                if (result != -1)
                    printf("Key found at index %d\n", result);
                else
                    printf("Key not found\n");
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}
