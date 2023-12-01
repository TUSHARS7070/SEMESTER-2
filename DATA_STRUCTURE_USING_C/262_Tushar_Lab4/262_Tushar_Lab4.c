#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Perfume {
    char brand[30];
    char name[50];
    float price;
    int quantity;
    struct Perfume* next;
};

struct Customer {
    char name[50];
    int age;
    float totalAmount;
    struct Customer* next;
};

// Function to add a new perfume to the inventory
struct Perfume* addPerfume(struct Perfume* rear, char name[], char brand[], float price, int quantity) {
    struct Perfume* newPerfume = (struct Perfume*)malloc(sizeof(struct Perfume));

    if (newPerfume == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    strcpy(newPerfume->brand, brand);
    strcpy(newPerfume->name, name);
    newPerfume->price = price;
    newPerfume->quantity = quantity;
    newPerfume->next = NULL;

    if (rear == NULL) {
        newPerfume->next = newPerfume;
        return newPerfume;
    }

    newPerfume->next = rear->next;
    rear->next = newPerfume;

    return newPerfume;
}

// Function to display the perfume inventory
void displayInventory(struct Perfume* head) {
    printf("Perfumes in the inventory:\n");
    if (head == NULL) {
        printf("Inventory is empty.\n");
        printf("\n==============================================================\n\n\n");
        return;
    }

    struct Perfume* current = head;

    do {
        printf("%s %s | Rs. %.2f | %d pcs\n",  current->brand, current->name, current->price, current->quantity);
        current = current->next;
    } while (current != head);
    
    printf("\n==============================================================\n\n\n");
}

// Function to find a perfume in the inventory by name
struct Perfume* findPerfume(struct Perfume* head, char name[]) {
    if (head == NULL) {
        return NULL;
    }

    struct Perfume* current = head;

    do {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    } while (current != head);

    return NULL;
}

// Function to process buying perfumes
void buyPerfume(struct Perfume* inventory, struct Customer** customerList) {
    char customerName[50], perfumeName[50];
    int customerAge, quantity;

    printf("Available Perfumes for Purchase:\n");
    displayInventory(inventory);

    printf("Enter the name of the perfume you want to buy: ");
    scanf("%s", perfumeName);

    struct Perfume* selectedPerfume = findPerfume(inventory, perfumeName);

    if (selectedPerfume == NULL) {
        printf("Perfume not found in the inventory.\n");
        printf("\n==============================================================\n\n\n");
        return;
    }

    printf("Enter the quantity you want to buy: ");
    scanf("%d", &quantity);

    if (quantity > selectedPerfume->quantity) {
        printf("Insufficient quantity in stock.\n");
        printf("\n==============================================================\n\n\n");
        return;
    }

    printf("Enter customer details:\n");
    printf("Name: ");
    scanf("%s", customerName);
    printf("Age: ");
    scanf("%d", &customerAge);
    printf("\n==============================================================\n\n\n");

    // Create a new customer and add to the list
    struct Customer* newCustomer = (struct Customer*)malloc(sizeof(struct Customer));
    if (newCustomer == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newCustomer->name, customerName);
    newCustomer->age = customerAge;
    newCustomer->totalAmount = 0.0;
    newCustomer->next = NULL;

    if (*customerList == NULL) {
        *customerList = newCustomer;
    } else {
        struct Customer* temp = *customerList;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newCustomer;
    }

    float totalAmount = quantity * selectedPerfume->price;
    selectedPerfume->quantity -= quantity;

    // Update the customer's total amount spent
    struct Customer* currentCustomer = *customerList;
    while (currentCustomer != NULL) {
        if (strcmp(currentCustomer->name, customerName) == 0) {
            currentCustomer->totalAmount += totalAmount;
            break;
        }
        currentCustomer = currentCustomer->next;
    }

    printf("  Bill for %s:\n", customerName);
    printf("\t\t\tPerfumeShop\n\t\t\t===========\n\n %s \t\t %d \t\t Rs. %.2f\n\n\t\t\t\tTotal Amount: Rs. %.2f\n\n\t\t\tThank you", selectedPerfume->name, quantity, selectedPerfume->price, totalAmount);
    printf("\n==============================================================\n\n\n");
}

// Function to add a new customer
struct Customer* addCustomer(struct Customer* rear, char name[], int age) {
    struct Customer* newCustomer = (struct Customer*)malloc(sizeof(struct Customer));

    if (newCustomer == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    strcpy(newCustomer->name, name);
    newCustomer->age = age;
    newCustomer->totalAmount = 0.0;
    newCustomer->next = NULL;

    if (rear == NULL) {
        return newCustomer;
    }

    rear->next = newCustomer;
    rear = newCustomer;
    return rear;
}

// Function to display customer details
void displayCustomers(struct Customer* head) {
    printf("Customer details:\n");
    if (head == NULL) {
        printf("Customer list is empty.\n");
        printf("\n==============================================================\n\n\n");
        return;
    }

    struct Customer* current = head;

    while (current != NULL) {
        printf(" %s | %d  years old | Rs. %.2f\n", current->name, current->age, current->totalAmount);
        current = current->next;
    }

    printf("\n==============================================================\n\n\n");
}

// Function to free perfume inventory
void freeInventory(struct Perfume* head) {
    if (head == NULL) {
        return;
    }

    struct Perfume* current = head;
    struct Perfume* next;

    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != head);
}

// Function to free customer list
void freeCustomers(struct Customer* head) {
    struct Customer* current = head;
    struct Customer* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

// Main Function
int main() {
    struct Perfume* inventory = NULL; 
    struct Customer* customerList = NULL;

    char name[50], brand[30];
    int quantity, age;
    float price;

    int choice;

    do {
        printf("\nMain Menu:\n");
        printf("1. Add Perfume to Inventory\n");
        printf("2. Display Perfume Inventory\n");
        printf("3. Buy a Perfume\n");
        printf("4. Add Customer\n");
        printf("5. Display Customer Details\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n==============================================================\n\n\n");

        switch (choice) {
            case 1:
                printf("Enter Perfume details:\n");
                printf("Brand: ");
                scanf("%s", brand);
                printf("Name: ");
                scanf("%s", name);
                printf("Price: ");
                scanf("%f", &price);
                printf("Quantity: ");
                scanf("%d", &quantity);
                printf("\n==============================================================\n\n\n");
                if (inventory == NULL) {
                    inventory = addPerfume(inventory, name, brand, price, quantity);
                } else {
                    inventory = addPerfume(inventory, name, brand, price, quantity);
                }
                break;

            case 2:
                displayInventory(inventory);
                break;

            case 3:
                buyPerfume(inventory, &customerList);
                break;

            case 4:
                printf("Enter Customer details:\n");
                printf("Name: ");
                scanf("%s", name);
                printf("Age: ");
                scanf("%d", &age);
                printf("\n==============================================================\n\n\n");
                if (customerList == NULL) {
                    customerList = addCustomer(customerList, name, age);
                } else {
                    customerList = addCustomer(customerList, name, age);
                }
                break;

            case 5:
                displayCustomers(customerList);
                break;

            case 6:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 6);

    freeInventory(inventory);
    freeCustomers(customerList);

    return 0;
}
