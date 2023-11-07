#include <stdio.h>
#include <string.h>

#define MAX_PERFUMES 50

// Define the Perfume structure
struct Perfume {
    char name[50];
    float price;
    int quantity;
};

// Function to display the list of available perfumes
void displayPerfumes(struct Perfume perfumes[], int numPerfumes) {
    printf("List of Available Perfumes:\n");
    printf("ID\tName\tPrice\tQuantity\n");
    for (int i = 0; i < numPerfumes; i++) {
        printf("%d\t%s\t%.2f\t%d\n", i + 1, perfumes[i].name, perfumes[i].price, perfumes[i].quantity);
    }
    printf("\n");
}

// Function to add a new perfume to the inventory
void addPerfume(struct Perfume perfumes[], int *numPerfumes) {
    if (*numPerfumes < MAX_PERFUMES) {
        struct Perfume newPerfume;
        printf("Enter perfume name: ");
        scanf("%s", newPerfume.name);
        printf("Enter perfume price: ");
        scanf("%f", &newPerfume.price);
        printf("Enter quantity: ");
        scanf("%d", &newPerfume.quantity);
        perfumes[*numPerfumes] = newPerfume;
        (*numPerfumes)++;
        printf("Perfume added to the inventory.\n");
    } else {
        printf("Inventory is full. Cannot add more perfumes.\n");
    }
}

// Function to sell a perfume
void sellPerfume(struct Perfume perfumes[], int *numPerfumes) {
    int perfumeId;
    printf("Enter the ID of the perfume to sell: ");
    scanf("%d", &perfumeId);

    if (perfumeId >= 1 && perfumeId <= *numPerfumes) {
        int quantity;
        printf("Enter the quantity to sell: ");
        scanf("%d", &quantity);

        if (perfumes[perfumeId - 1].quantity >= quantity) {
            perfumes[perfumeId - 1].quantity -= quantity;
            printf("Sold %d units of %s.\n", quantity, perfumes[perfumeId - 1].name);
        } else {
            printf("Not enough stock for %s.\n", perfumes[perfumeId - 1].name);
        }
    } else {
        printf("Invalid perfume ID.\n");
    }
}

// Function to display the total value of the perfume inventory
void displayInventoryValue(struct Perfume perfumes[], int numPerfumes) {
    float totalValue = 0.0;
    for (int i = 0; i < numPerfumes; i++) {
        totalValue += perfumes[i].price * perfumes[i].quantity;
    }
    printf("Total Inventory Value: %.2f\n", totalValue);
}

int main() {
    struct Perfume perfumes[MAX_PERFUMES];
    int numPerfumes = 0;

    int option;

    while (1) {
        printf("\nPerfume Retail Store Management:\n");
        printf("1. Add a new perfume\n");
        printf("2. Sell a perfume\n");
        printf("3. Display list of available perfumes\n");
        printf("4. Display inventory value\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addPerfume(perfumes, &numPerfumes);
                break;
            case 2:
                sellPerfume(perfumes, &numPerfumes);
                break;
            case 3:
                displayPerfumes(perfumes, numPerfumes);
                break;
            case 4:
                displayInventoryValue(perfumes, numPerfumes);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
