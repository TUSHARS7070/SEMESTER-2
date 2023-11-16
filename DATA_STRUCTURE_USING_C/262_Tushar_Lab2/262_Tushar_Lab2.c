#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a Perfume
struct Perfume {
    char name[50];
    int year;
    struct Perfume* next;
};

// Function to create a new Perfume node
struct Perfume* createPerfume(char name[], int year) {
    struct Perfume* newPerfume = (struct Perfume*)malloc(sizeof(struct Perfume));
    if (newPerfume != NULL) {
        strcpy(newPerfume->name, name);
        newPerfume->year = year;
        newPerfume->next = NULL;
    }
    return newPerfume;
}

// Function to insert a Perfume at the front of the list
void insertPerfumeAtFront(struct Perfume** head, char name[], int year) {
    struct Perfume* newPerfume = createPerfume(name, year);
    if (newPerfume != NULL) {
        newPerfume->next = *head;
        *head = newPerfume;
    } else {
        printf("Memory allocation failed. Perfume not inserted.\n");
    }
}

// Function to print all Perfumes in the list
void printPerfumes(struct Perfume* head) {
    printf("Perfumes:\n");
    while (head != NULL) {
        printf("Name: %s, Year: %d\n", head->name, head->year);
        head = head->next;
    }
}

// Function to delete a Perfume by name
void deletePerfume(struct Perfume** head, char name[]) {
    struct Perfume* temp = *head;
    struct Perfume* prev = NULL;

    if (temp != NULL && strcmp(temp->name, name) == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Perfume '%s' not found.\n", name);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to delete Perfumes by year
void deletePerfumeByYear(struct Perfume** head, int year) {
    struct Perfume* temp = *head;
    struct Perfume* prev = NULL;

    while (temp != NULL && temp->year != year) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("No perfume found with year %d.\n", year);
        return;
    }

    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

// Function to insert a Perfume at a specific position in the list
void insertPerfumeAtPosition(struct Perfume** head, char name[], int year, int position) {
    struct Perfume* newPerfume = createPerfume(name, year);
    if (newPerfume != NULL) {
        if (position <= 1) {
            newPerfume->next = *head;
            *head = newPerfume;
        } else {
            struct Perfume* temp = *head;
            int currentPosition = 1;
            while (temp != NULL && currentPosition < position - 1) {
                temp = temp->next;
                currentPosition++;
            }
            if (temp == NULL) {
                printf("Position exceeds the length of the list. Perfume not inserted.\n");
            } else {
                newPerfume->next = temp->next;
                temp->next = newPerfume;
            }
        }
    } else {
        printf("Memory allocation failed. Perfume not inserted.\n");
    }
}

// Main function
int main() {
    struct Perfume* perfumeList = NULL;

    // Inserting perfumes at the front
    insertPerfumeAtFront(&perfumeList, "Chanel No. 5", 1921);
    insertPerfumeAtFront(&perfumeList, "Dior Sauvage", 2015);
    insertPerfumeAtFront(&perfumeList, "Armani Code", 2004);

    // Printing perfumes
    printf("Initial perfume list:\n");
    printPerfumes(perfumeList);

    // Deleting a perfume
    deletePerfume(&perfumeList, "Dior Sauvage");
    printf("\nAfter deleting 'Dior Sauvage':\n");
    printPerfumes(perfumeList);

    // Deleting perfumes by year
    deletePerfumeByYear(&perfumeList, 2004);
    printf("\nAfter deleting perfumes from the year 2004:\n");
    printPerfumes(perfumeList);

    // Inserting a perfume at a specific position
    insertPerfumeAtPosition(&perfumeList, "Gucci Guilty", 2020, 2);
    printf("\nAfter inserting 'Gucci Guilty' at position 2:\n");
    printPerfumes(perfumeList);

    return 0;
}
