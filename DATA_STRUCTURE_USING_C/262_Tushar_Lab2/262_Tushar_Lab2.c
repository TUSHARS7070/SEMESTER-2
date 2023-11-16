#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a Perfume in a singly linked list
struct PerfumeSingly {
    char name[50];
    int year;
    struct PerfumeSingly* next;
};

// Structure for a Perfume in a doubly linked list
struct PerfumeDoubly {
    char name[50];
    int year;
    struct PerfumeDoubly* prev;
    struct PerfumeDoubly* next;
};

// Structure for a Perfume in a circular linked list
struct PerfumeCircular {
    char name[50];
    int year;
    struct PerfumeCircular* next;
};

// Function to create a new Perfume node for the singly linked list
struct PerfumeSingly* createSingly(char name[], int year) {
    struct PerfumeSingly* newP = (struct PerfumeSingly*)malloc(sizeof(struct PerfumeSingly));
    if (newP != NULL) {
        strcpy(newP->name, name);
        newP->year = year;
        newP->next = NULL;
    }
    return newP;
}

// Function to create a new Perfume node for the doubly linked list
struct PerfumeDoubly* createDoubly(char name[], int year) {
    struct PerfumeDoubly* newP = (struct PerfumeDoubly*)malloc(sizeof(struct PerfumeDoubly));
    if (newP != NULL) {
        strcpy(newP->name, name);
        newP->year = year;
        newP->prev = NULL;
        newP->next = NULL;
    }
    return newP;
}

// Function to create a new Perfume node for the circular linked list
struct PerfumeCircular* createCircular(char name[], int year) {
    struct PerfumeCircular* newP = (struct PerfumeCircular*)malloc(sizeof(struct PerfumeCircular));
    if (newP != NULL) {
        strcpy(newP->name, name);
        newP->year = year;
        newP->next = NULL;
    }
    return newP;
}

// Function to insert a Perfume at the front of the singly linked list
void insertSingly(struct PerfumeSingly** head, char name[], int year) {
    struct PerfumeSingly* newP = createSingly(name, year);
    if (newP != NULL) {
        newP->next = *head;
        *head = newP;
    } else {
        printf("Memory allocation failed. Perfume not inserted.\n");
    }
}

// Function to print all Perfumes in the singly linked list
void printSingly(struct PerfumeSingly* head) {
    printf("Singly Linked List Perfumes:\n");
    while (head != NULL) {
        printf("Name: %s, Year: %d\n", head->name, head->year);
        head = head->next;
    }
}

// Function to delete a Perfume by name from the singly linked list
void deleteSingly(struct PerfumeSingly** head, char name[]) {
    struct PerfumeSingly* current = *head;
    struct PerfumeSingly* prev = NULL;

    if (current != NULL && strcmp(current->name, name) == 0) {
        *head = current->next;
        free(current);
        return;
    }

    while (current != NULL && strcmp(current->name, name) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Perfume '%s' not found.\n", name);
        return;
    }

    prev->next = current->next;
    free(current);
}

// Function to insert a Perfume at the front of the doubly linked list
void insertDoubly(struct PerfumeDoubly** head, char name[], int year) {
    struct PerfumeDoubly* newP = createDoubly(name, year);
    if (newP != NULL) {
        newP->next = *head;
        if (*head != NULL) {
            (*head)->prev = newP;
        }
        *head = newP;
    } else {
        printf("Memory allocation failed. Perfume not inserted.\n");
    }
}

// Function to print all Perfumes in the doubly linked list
void printDoubly(struct PerfumeDoubly* head) {
    printf("Doubly Linked List Perfumes:\n");
    while (head != NULL) {
        printf("Name: %s, Year: %d\n", head->name, head->year);
        head = head->next;
    }
}

// Function to delete a Perfume by name from the doubly linked list
void deleteDoubly(struct PerfumeDoubly** head, char name[]) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct PerfumeDoubly* current = *head;

    if (strcmp(current->name, name) == 0) {
        *head = current->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(current);
        return;
    }

    while (current != NULL && strcmp(current->name, name) != 0) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Perfume '%s' not found.\n", name);
        return;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    current->prev->next = current->next;
    free(current);
}

// Function to insert a Perfume at the front of the circular linked list
void insertCircular(struct PerfumeCircular** head, char name[], int year) {
    struct PerfumeCircular* newP = createCircular(name, year);
    if (newP != NULL) {
        if (*head == NULL) {
            newP->next = newP;  // Point to itself to form a circle
            *head = newP;       // Assign the new node as the head
        } else {
            newP->next = (*head)->next; // Insert at the beginning by adjusting pointers
            (*head)->next = newP;
        }
    } else {
        printf("Memory allocation failed. Perfume not inserted.\n");
    }
}

// Function to print all Perfumes in the circular linked list
void printCircular(struct PerfumeCircular* head) {
    struct PerfumeCircular* current = head;
    printf("Circular Linked List Perfumes:\n");
    if (head != NULL) {
        do {
            printf("Name: %s, Year: %d\n", current->name, current->year);
            current = current->next;
        } while (current != head);
    }
}

// Function to delete a Perfume by name from the circular linked list
void deleteCircular(struct PerfumeCircular** head, char name[]) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct PerfumeCircular* current = *head;
    struct PerfumeCircular* temp = NULL;

    while (strcmp(current->name, name) != 0) {
        if (current->next == *head) {
            printf("Perfume '%s' not found.\n", name);
            return;
        }
        temp = current;
        current = current->next;
    }

    if (current->next == *head) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
        *head = NULL;
        return;
    }

    temp->next = current->next;
    free(current);
}

// Main function
int main() {
    struct PerfumeSingly* singlyList = NULL;
    struct PerfumeDoubly* doublyList = NULL;
    struct PerfumeCircular* circularList = NULL;

    // Inserting perfumes into different types of linked lists
    insertSingly(&singlyList, "Chanel No. 5", 1921);
    insertSingly(&singlyList, "Dior Sauvage", 2015);
    insertSingly(&singlyList, "Armani Code", 2004);

    insertDoubly(&doublyList, "Givenchy L'Interdit", 2020);
    insertDoubly(&doublyList, "Tom Ford Black Orchid", 2006);
    insertDoubly(&doublyList, "Versace Eros", 2012);

    insertCircular(&circularList, "Paco Rabanne 1 Million", 2008);
    insertCircular(&circularList, "Yves Saint Laurent Black Opium", 2014);
    insertCircular(&circularList, "Calvin Klein Eternity", 1988);

    // Printing perfumes in different types of linked lists
    printSingly(singlyList);
    printf("\n");

    printDoubly(doublyList);
    printf("\n");

    printCircular(circularList);
    printf("\n");

    // Deleting perfumes from different types of linked lists
    deleteSingly(&singlyList, "Dior Sauvage");
    printf("\nAfter deleting 'Dior Sauvage' from Singly Linked List:\n");
    printSingly(singlyList);
    printf("\n");

    deleteDoubly(&doublyList, "Chanel No. 5");
    printf("\nAfter deleting 'Chanel No. 5' from Doubly Linked List:\n");
    printDoubly(doublyList);
    printf("\n");

    deleteCircular(&circularList, "Armani Code");
    printf("\nAfter deleting 'Armani Code' from Circular Linked List:\n");
    printCircular(circularList);

    return 0;
}
