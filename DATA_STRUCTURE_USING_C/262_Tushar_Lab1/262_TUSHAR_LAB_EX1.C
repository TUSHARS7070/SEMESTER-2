#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

struct Perfume {
    int id;
    char brand[50];
    char name[100];
    float price;
    int quantity;
};

struct Perfume perfumeInventory[SIZE];

void displayPerfumeInventory(struct Perfume* inventory, int size) {
    if (size == 0) {
        printf("\n\nPerfume inventory is empty, nothing to display.\n\n");
    } else {
        printf("\n\nPerfume Inventory:\n");
        for (int i = 0; i < size; i++) {
            if (inventory[i].id > 0) {
                printf("ID: %d\n", inventory[i].id);
                printf("Brand: %s\n", inventory[i].brand);
                printf("Name: %s\n", inventory[i].name);
                printf("Price: $%.2f\n", inventory[i].price);
                printf("Quantity: %d\n", inventory[i].quantity);
                printf("\n");
            }
        }
    }
}

int findPerfumeIndex(struct Perfume* inventory, int size, int id) {
    for (int i = 0; i < size; i++) {
        if (inventory[i].id == id) {
            return i;
        }
    }
    return -1;
}

void addNewPerfume(struct Perfume* inventory, int* size) {
    int id = 0;
    printf("\n\nPerfume Id: ");
    scanf("%d", &id);

    int index = findPerfumeIndex(inventory, *size, id);

    if (index != -1) {
        int quantity = 0;
        printf("Quantity to add: ");
        scanf("%d", &quantity);
        inventory[index].quantity += quantity;
        printf("\nQuantity added to existing perfume.\n\n\n");
    } else {
        inventory[*size].id = id;

        printf("Brand: ");
        fflush(stdin);
        gets(inventory[*size].brand);

        printf("Name: ");
        fflush(stdin);
        gets(inventory[*size].name);

        printf("Price: ");
        scanf("%f", &inventory[*size].price);

        printf("Quantity: ");
        scanf("%d", &inventory[*size].quantity);

        printf("\nPerfume added to the inventory.\n\n");
        (*size)++;
    }
}

void sellPerfume(struct Perfume* inventory, int* size) {
    int id, quantity;
    printf("\n\nEnter Perfume ID to sell: ");
    scanf("%d", &id);

    int index = findPerfumeIndex(inventory, *size, id);

    if (index != -1) {
        printf("Enter quantity to sell: ");
        scanf("%d", &quantity);

        if (quantity <= inventory[index].quantity) {
            inventory[index].quantity -= quantity;
            printf("\nSold %d units of %s.\n", quantity, inventory[index].name);
        } else {
            printf("\nInsufficient quantity in stock.\n");
        }
    } else {
        printf("\nPerfume not found in inventory.\n");
    }
}

void displaySalesReport(struct Perfume* inventory, int size) {
    printf("\n\nSales Report:\n");
    printf("ID\tBrand\tName\tPrice\tSold Quantity\n");

    for (int i = 0; i < size; i++) {
        if (inventory[i].id > 0) {
            int soldQuantity = inventory[i].quantity; // Corrected line
            printf("%d\t%s\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].brand, inventory[i].name, inventory[i].price,
                   soldQuantity);
        }
    }
}





void matrixAddition(struct Perfume* inventory, int* size) {
    if (*size < 2) {
        printf("\nInsufficient number of perfumes to perform matrix addition.\n");
        return;
    }

    printf("\n\nMatrix Addition:\n");

    for (int i = 0; i < *size - 1; i++) {
        printf("Perfume %d + Perfume %d =\n", inventory[i].id, inventory[i + 1].id);
        printf("Brand: %s\n", inventory[i].brand);
        printf("Name: %s\n", inventory[i].name);
        printf("Price: $%.2f\n", inventory[i].price + inventory[i + 1].price);
        printf("Quantity: %d\n", inventory[i].quantity + inventory[i + 1].quantity);
        printf("\n");
    }
}

void matrixMultiplication(struct Perfume* inventory, int* size) {
    if (*size < 2) {
        printf("\nInsufficient number of perfumes to perform matrix multiplication.\n");
        return;
    }

    printf("\n\nMatrix Multiplication:\n");

    for (int i = 0; i < *size - 1; i++) {
        printf("Perfume %d * Perfume %d =\n", inventory[i].id, inventory[i + 1].id);
        printf("Brand: %s\n", inventory[i].brand);
        printf("Name: %s\n", inventory[i].name);
        printf("Price: $%.2f\n", inventory[i].price * inventory[i + 1].price);
        printf("Quantity: %d\n", inventory[i].quantity * inventory[i + 1].quantity);
        printf("\n");
    }
}

int main() {
    int choice, currSize = 0;
    int* currentSizePointer = &currSize;

    while (1) {
        printf("Menu:\n");
        printf("1. Display Perfume Inventory\n");
        printf("2. Add New Perfume\n");
        printf("3. Sell Perfume\n");
        printf("4. Display Sales Report\n");
        printf("5. Matrix Addition\n");
        printf("6. Matrix Multiplication\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("======================================================");

        switch (choice) {
        case 1:
            displayPerfumeInventory(perfumeInventory, currSize);
            printf("======================================================\n");
            break;
        case 2:
            addNewPerfume(perfumeInventory, currentSizePointer);
            printf("======================================================\n");
            break;
        case 3:
            sellPerfume(perfumeInventory, currentSizePointer);
            printf("======================================================\n");
            break;
        case 4:
            displaySalesReport(perfumeInventory, currSize);
            printf("======================================================\n");
            break;
        case 5:
            matrixAddition(perfumeInventory, currentSizePointer);
            printf("======================================================\n");
            break;
        case 6:
            matrixMultiplication(perfumeInventory, currentSizePointer);
            printf("======================================================\n");
            break;
        case 7:
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
            printf("======================================================\n");
        }
    }
}
