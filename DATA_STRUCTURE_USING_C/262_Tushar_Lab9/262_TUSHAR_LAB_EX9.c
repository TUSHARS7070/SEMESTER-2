#include <stdio.h>
#include <stdlib.h>

// Definition of a perfume node
struct PerfumeNode {
    int perfumeID;  // Unique identifier for each perfume
    char brand[50];
    int quantity;
    float price;
    struct PerfumeNode* left;
    struct PerfumeNode* right;
};

// Function to create a new perfume node
struct PerfumeNode* newPerfumeNode(int id, const char* brand, int quantity, float price) {
    struct PerfumeNode* node = (struct PerfumeNode*)malloc(sizeof(struct PerfumeNode));
    node->perfumeID = id;
    snprintf(node->brand, sizeof(node->brand), "%s", brand);
    node->quantity = quantity;
    node->price = price;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Breadth-First Traversal (Level Order Traversal) for Perfume Inventory
void BFT(struct PerfumeNode* root) {
    if (root == NULL)
        return;

    // Create a queue for BFT
    struct PerfumeNode* queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while (front != rear) {
        struct PerfumeNode* current = queue[++front];
        printf("ID:%d Brand:%s Quantity:%d Price:%.2f\n", current->perfumeID, current->brand, current->quantity, current->price);

        if (current->left != NULL)
            queue[++rear] = current->left;

        if (current->right != NULL)
            queue[++rear] = current->right;
    }
}

// Depth-First Traversal (Inorder) for Perfume Inventory
void DFT(struct PerfumeNode* root) {
    if (root == NULL)
        return;

    DFT(root->left);
    printf("ID:%d Brand:%s Quantity:%d Price:%.2f\n", root->perfumeID, root->brand, root->quantity, root->price);
    DFT(root->right);
}

// Function to search for a perfume by ID using Breadth-First Traversal (BFT)
struct PerfumeNode* searchPerfumeBFT(struct PerfumeNode* root, int perfumeID) {
    if (root == NULL)
        return NULL;

    // Create a queue for BFT search
    struct PerfumeNode* queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while (front != rear) {
        struct PerfumeNode* current = queue[++front];

        if (current->perfumeID == perfumeID)
            return current;

        if (current->left != NULL)
            queue[++rear] = current->left;

        if (current->right != NULL)
            queue[++rear] = current->right;
    }

    return NULL;
}

// Function to search for a perfume by ID using Depth-First Traversal (DFT)
struct PerfumeNode* searchPerfumeDFT(struct PerfumeNode* root, int perfumeID) {
    if (root == NULL || root->perfumeID == perfumeID)
        return root;

    // Check the left subtree
    struct PerfumeNode* leftResult = searchPerfumeDFT(root->left, perfumeID);
    if (leftResult != NULL)
        return leftResult;

    // Check the right subtree
    return searchPerfumeDFT(root->right, perfumeID);
}

// Function to display all perfumes in the inventory
void displayAllPerfumes(struct PerfumeNode* root) {
    if (root == NULL)
        return;

    printf("All Perfumes in the Inventory:\n");
    DFT(root);
    printf("\n");
}

// Function to display menu and handle user input
void displayMenu() {
    printf("\nPerfume Store Management Menu:\n");
    printf("1. Add Perfume to Inventory\n");
    printf("2. Display Perfume Inventory (BFT)\n");
    printf("3. Display Perfume Inventory (DFT)\n");
    printf("4. Display All Perfumes\n");
    printf("5. Search Perfume by ID (BFT)\n");
    printf("6. Search Perfume by ID (DFT)\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct PerfumeNode* inventoryRoot = NULL;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add Perfume to Inventory (customize as needed)
                {
                    int id, quantity;
                    char brand[50];
                    float price;
                    printf("Enter Perfume ID: ");
                    scanf("%d", &id);
                    printf("Enter Brand: ");
                    scanf("%s", brand);
                    printf("Enter Quantity: ");
                    scanf("%d", &quantity);
                    printf("Enter Price: ");
                    scanf("%f", &price);

                    struct PerfumeNode* newPerfume = newPerfumeNode(id, brand, quantity, price);

                    // Add the new perfume to the inventory
                    if (inventoryRoot == NULL)
                        inventoryRoot = newPerfume;
                    else {
                        struct PerfumeNode* current = inventoryRoot;
                        struct PerfumeNode* parent;

                        while (current != NULL) {
                            parent = current;
                            if (id < current->perfumeID)
                                current = current->left;
                            else
                                current = current->right;
                        }

                        if (id < parent->perfumeID)
                            parent->left = newPerfume;
                        else
                            parent->right = newPerfume;
                    }

                    printf("Perfume added to inventory.\n");
                }
                break;

            case 2:
                printf("Perfume Inventory (Breadth-First Traversal):\n");
                BFT(inventoryRoot);
                printf("\n");
                break;

            case 3:
                printf("Perfume Inventory (Depth-First Traversal):\n");
                DFT(inventoryRoot);
                printf("\n");
                break;

            case 4:
                displayAllPerfumes(inventoryRoot);
                break;

            case 5:
                {
                    int searchID;
                    printf("Enter Perfume ID to search using BFT: ");
                    scanf("%d", &searchID);
                    struct PerfumeNode* result = searchPerfumeBFT(inventoryRoot, searchID);
                    if (result != NULL)
                        printf("Perfume found in inventory - ID:%d Brand:%s Quantity:%d Price:%.2f\n", result->perfumeID, result->brand, result->quantity, result->price);
                    else
                        printf("Perfume with ID %d not found in the inventory.\n", searchID);
                }
                break;

            case 6:
                {
                    int searchID;
                    printf("Enter Perfume ID to search using DFT: ");
                    scanf("%d", &searchID);
                    struct PerfumeNode* result = searchPerfumeDFT(inventoryRoot, searchID);
                    if (result != NULL)
                        printf("Perfume found in inventory - ID:%d Brand:%s Quantity:%d Price:%.2f\n", result->perfumeID, result->brand, result->quantity, result->price);
                    else
                        printf("Perfume with ID %d not found in the inventory.\n", searchID);
                }
                break;

            case 7:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 7);

    return 0;
}
