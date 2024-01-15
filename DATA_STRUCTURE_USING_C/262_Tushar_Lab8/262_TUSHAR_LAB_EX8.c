#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a perfume
typedef struct TreeNode {
    int productId;
    char perfumeName[50];
    float price;
    int quantity;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Structure to represent a Binary Search Tree
typedef struct {
    TreeNode *root;
} BinaryTree;

// Function to create a new node with given details
TreeNode *createNode(int productId, const char *perfumeName, float price, int quantity) {
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    if (newNode != NULL) {
        newNode->productId = productId;
        strcpy(newNode->perfumeName, perfumeName);
        newNode->price = price;
        newNode->quantity = quantity;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

// Function to insert a new node into the BST
TreeNode *insertNode(TreeNode *root, int productId, const char *perfumeName, float price, int quantity) {
    if (root == NULL) {
        return createNode(productId, perfumeName, price, quantity);
    }

    if (productId < root->productId) {
        root->left = insertNode(root->left, productId, perfumeName, price, quantity);
    } else if (productId > root->productId) {
        root->right = insertNode(root->right, productId, perfumeName, price, quantity);
    }

    return root;
}

// Function to search for a perfume by productId
TreeNode *search(TreeNode *root, int productId) {
    if (root == NULL || root->productId == productId) {
        return root;
    }

    if (productId < root->productId) {
        return search(root->left, productId);
    } else {
        return search(root->right, productId);
    }
}

// Function to find the minimum value node in a BST
TreeNode *findMin(TreeNode *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node with given productId from the BST
TreeNode *deleteNode(TreeNode *root, int productId) {
    if (root == NULL) {
        return root;
    }

    if (productId < root->productId) {
        root->left = deleteNode(root->left, productId);
    } else if (productId > root->productId) {
        root->right = deleteNode(root->right, productId);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children, get the inorder successor (smallest in the right subtree)
        TreeNode *temp = findMin(root->right);

        // Copy the inorder successor's data to this node
        root->productId = temp->productId;
        strcpy(root->perfumeName, temp->perfumeName);
        root->price = temp->price;
        root->quantity = temp->quantity;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->productId);
    }

    return root;
}

// Function to calculate the height of the BST
int calculateHeight(TreeNode *root) {
    if (root == NULL) {
        return -1;
    } else {
        int leftHeight = calculateHeight(root->left);
        int rightHeight = calculateHeight(root->right);

        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        } else {
            return rightHeight + 1;
        }
    }
}

// Function to perform in-order traversal of the BST
void inOrderTraversal(TreeNode *root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%-11d%-15s%-8.2f%-9d\n", root->productId, root->perfumeName, root->price, root->quantity);
        inOrderTraversal(root->right);
    }
}

// Function to perform pre-order traversal of the BST
void preOrderTraversal(TreeNode *root) {
    if (root != NULL) {
        printf("%-11d%-15s%-8.2f%-9d\n", root->productId, root->perfumeName, root->price, root->quantity);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Function to perform post-order traversal of the BST
void postOrderTraversal(TreeNode *root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%-11d%-15s%-8.2f%-9d\n", root->productId, root->perfumeName, root->price, root->quantity);
    }
}

int main() {
    int menu = 0;
    BinaryTree perfumeTree;
    perfumeTree.root = NULL;

    while (menu != 7) {
        printf("\n\nMenu:\n1. Insert Perfume\n2. Search Perfume\n");
        printf("3. Delete Perfume\n4. Calculate Height\n");
        printf("5. In-Order Traversal\n6. Pre-Order Traversal\n");
        printf("7. Post-Order Traversal\n8. Exit\n--------------\nEnter your choice: ");

        if (scanf("%d", &menu) != 1) {
            // Handle invalid input
            printf("Invalid input. Please enter a number.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);  // Clear input buffer
            continue;
        }

        switch (menu) {
            case 1: {
                int productId;
                char perfumeName[50];
                float price;
                int quantity;

                printf("Enter details for the new perfume:\n");
                printf("Product ID: ");
                scanf("%d", &productId);

                // Consume the newline character
                getchar();

                printf("Perfume Name: ");
                scanf("%s", perfumeName);
                printf("Price: ");
                scanf("%f", &price);
                printf("Quantity: ");
                scanf("%d", &quantity);

                perfumeTree.root = insertNode(perfumeTree.root, productId, perfumeName, price, quantity);
                break;
            }

            case 2: {
                int searchId;
                printf("Enter the Product ID to search: ");
                scanf("%d", &searchId);
                TreeNode *result = search(perfumeTree.root, searchId);
                if (result != NULL) {
                    printf("Perfume Found:\n");
                    printf("Product ID | Perfume Name | Price | Quantity\n");
                    printf("--------------------------------------------------\n");
                    printf("%-11d%-15s%-8.2f%-9d\n", result->productId, result->perfumeName, result->price, result->quantity);
                    printf("--------------------------------------------------\n");
                } else {
                    printf("Perfume not found with Product ID: %d\n", searchId);
                }
                break;
            }

            case 3: {
                int deleteId;
                printf("Enter the Product ID to delete: ");
                scanf("%d", &deleteId);
                perfumeTree.root = deleteNode(perfumeTree.root, deleteId);
                printf("Perfume with Product ID %d deleted, if exists.\n", deleteId);
                break;
            }

            case 4:
                printf("Height of the BST: %d\n", calculateHeight(perfumeTree.root));
                break;

            case 5:
                printf("\nIn-Order Traversal:\n");
                printf("Product ID | Perfume Name | Price | Quantity\n");
                printf("--------------------------------------------------\n");
                inOrderTraversal(perfumeTree.root);
                printf("--------------------------------------------------\n");
                break;

            case 6:
                printf("\nPre-Order Traversal:\n");
                printf("Product ID | Perfume Name | Price | Quantity\n");
                printf("--------------------------------------------------\n");
                preOrderTraversal(perfumeTree.root);
                printf("--------------------------------------------------\n");
                break;

            case 7:
                printf("\nPost-Order Traversal:\n");
                printf("Product ID | Perfume Name | Price | Quantity\n");
                printf("--------------------------------------------------\n");
                postOrderTraversal(perfumeTree.root);
                printf("--------------------------------------------------\n");
                break;

            case 8:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice, make a valid choice.\n");
                break;
        }
    }

    return 0;
}
