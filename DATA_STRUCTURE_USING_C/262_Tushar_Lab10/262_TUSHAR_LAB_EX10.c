#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define MAX_PERFUMES 5

struct PerfumeNode {
    int perfumeID;
    char brand[50];
    int quantity;
    float price;
    int visited;
};

struct Edge {
    int src, dest;
    float weight;
};

struct PerfumeNode* newPerfumeNode(int id, const char* brand, int quantity, float price) {
    struct PerfumeNode* node = (struct PerfumeNode*)malloc(sizeof(struct PerfumeNode));
    node->perfumeID = id;
    strncpy(node->brand, brand, sizeof(node->brand) - 1);
    node->brand[sizeof(node->brand) - 1] = '\0';
    node->quantity = quantity;
    node->price = price;
    node->visited = 0;  // Initialize visited to 0 here
    return node;
}

float minPrice(struct PerfumeNode* inventory) {
    float min = INFINITY;

    for (int i = 0; i < MAX_PERFUMES; i++) {
        if (inventory[i].brand[0] != '\0' && inventory[i].price < min) {  // Check for non-empty nodes
            min = inventory[i].price;
        }
    }

    return min;
}

void printAllPerfumes(struct PerfumeNode* inventory, int numPerfumes) {
  for (int i = 0; i < numPerfumes; i++) {
    printf("Perfume ID:%d Brand:%s Quantity:%d Price:%.2f\n",
           inventory[i].perfumeID, inventory[i].brand, inventory[i].quantity, inventory[i].price);
  }
}


void primMST(struct PerfumeNode* inventory) {
    struct Edge* edges = (struct Edge*)malloc((MAX_PERFUMES - 1) * sizeof(struct Edge));

    for (int i = 1; i < MAX_PERFUMES; i++) {
        edges[i - 1].src = 0;
        edges[i - 1].dest = i;
        edges[i - 1].weight = fabs(inventory[0].price - inventory[i].price);
    }

    inventory[0].visited = 1;

    printf("Edges in the Minimum Spanning Tree (Prim's algorithm):\n");




for (int count = 1; count < MAX_PERFUMES; count++) {
    int minIndex = -1;
    float minValue = INFINITY;

    for (int i = 0; i < MAX_PERFUMES - 1; i++) {
        if (!inventory[edges[i].dest].visited && edges[i].weight < minValue) {
            minIndex = i;
            minValue = edges[i].weight;
        }
    }

    if (minIndex != -1) {
        inventory[edges[minIndex].dest].visited = 1;

        printf("Brand:%s - Brand:%s, Weight:%.2f\n",
            inventory[edges[minIndex].src].brand, inventory[edges[minIndex].dest].brand, edges[minIndex].weight);

        for (int i = 0; i < MAX_PERFUMES - 1; i++) {
            if (!inventory[edges[i].dest].visited) {
                float newWeight = fabs(inventory[edges[minIndex].dest].price - inventory[edges[i].dest].price);
                if (newWeight < edges[i].weight) {
                    edges[i].src = edges[minIndex].dest;
                    edges[i].weight = newWeight;
                }
            }
        }
    }
}

}


int compareEdges(const void* a, const void* b) {
    return (*(struct Edge*)a).weight > (*(struct Edge*)b).weight ? 1 : -1;
}

void kruskalMST(struct PerfumeNode* inventory) {
    int numEdges = MAX_PERFUMES * (MAX_PERFUMES - 1) / 2;
    struct Edge* edges = (struct Edge*)malloc(numEdges * sizeof(struct Edge));

    int edgeCount = 0;
    for (int i = 0; i < MAX_PERFUMES; i++) {
        for (int j = i + 1; j < MAX_PERFUMES; j++) {
            edges[edgeCount].src = i;
            edges[edgeCount].dest = j;
            edges[edgeCount].weight = fabs(inventory[i].price - inventory[j].price);
            edgeCount++;
        }
    }

    qsort(edges, numEdges, sizeof(struct Edge), compareEdges);

    int* parent = (int*)malloc(MAX_PERFUMES * sizeof(int));
    for (int i = 0; i < MAX_PERFUMES; i++) {
        parent[i] = i;
    }

    printf("\nEdges in the Minimum Spanning Tree (Kruskal's algorithm):\n");
    for (int i = 0; i < numEdges; i++) {
        int root1 = inventory[edges[i].src].perfumeID;
        int root2 = inventory[edges[i].dest].perfumeID;

        if (root1 != root2 && inventory[edges[i].src].visited && inventory[edges[i].dest].visited) {
            printf("Brand:%s - Brand:%s, Weight:%.2f\n",
                   inventory[edges[i].src].brand, inventory[edges[i].dest].brand, edges[i].weight);

            for (int j = 0; j < MAX_PERFUMES; j++) {
                if (parent[j] == root2) {
                    parent[j] = root1;
                }
            }
        }
    }

    free(parent);
    free(edges);
}

int main() {
    struct PerfumeNode inventory[MAX_PERFUMES] = {{0}};  // Initialize all elements to zero
    int numPerfumes = 0;

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add Perfume\n");
        printf("2. Display Inventory\n");
        printf("3. Find Minimum Price\n");
        printf("4. Create MST using Prim's Algorithm\n");
        printf("5. Create MST using Kruskal's Algorithm\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int id, quantity;
                char brand[50];
                float price;

                printf("Enter Perfume ID: ");
                scanf("%d", &id);

                while (getchar() != '\n');  // Clear the input buffer

                printf("Enter Brand: ");
                fgets(brand, sizeof(brand), stdin);
                // Remove trailing newline from brand
                brand[strcspn(brand, "\n")] = '\0';

                printf("Enter Quantity: ");
                scanf("%d", &quantity);
                printf("Enter Price: ");
                scanf("%f", &price);
                if (id < 0 || quantity < 0 || price < 0) {
                    printf("Invalid input. Please enter positive values for ID, quantity, and price.\n");
                    break;
                }

                // Add the new perfume to the inventory
                    for (int i = 0; i < MAX_PERFUMES; i++) {
                        if (inventory[i].brand[0] == '\0') {
                        inventory[i] = *newPerfumeNode(id, brand, quantity, price);
                        numPerfumes++;  // Increment the count of perfumes
                        printf("Perfume added to the inventory.\n");
                        break;
                        }
                    }
                break;
                }
            case 2:
                printf("\nAll Perfumes in the Inventory:\n");
                printAllPerfumes(inventory, numPerfumes);
                break;
            case 3: {
                float minimumPrice = minPrice(inventory);
                printf("\nMinimum Price in the Inventory: %.2f\n", minimumPrice);
                break;
            }
            case 4:
                printf("\nCreating MST using Prim's Algorithm:\n");
                primMST(inventory);
                break;
            case 5:
                printf("\nCreating MST using Kruskal's Algorithm:\n");
                kruskalMST(inventory);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 0);

    return 0;
}
