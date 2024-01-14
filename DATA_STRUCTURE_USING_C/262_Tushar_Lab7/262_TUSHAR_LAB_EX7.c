#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
    int productId;
    char perfumeName[50];
    float price;
    int quantity;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct {
    TreeNode *root;
} BinaryTree;

typedef struct QueueNode {
    TreeNode *data;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
} Queue;

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

Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (queue != NULL) {
        queue->front = NULL;
        queue->rear = NULL;
    }
    return queue;
}

void enqueue(Queue *queue, TreeNode *data) {
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = NULL;
        if (queue->rear == NULL) {
            queue->front = newNode;
            queue->rear = newNode;
        } else {
            queue->rear->next = newNode;
            queue->rear = newNode;
        }
    }
}

TreeNode *dequeue(Queue *queue) {
    if (queue->front == NULL) {
        return NULL; // Queue is empty
    }

    QueueNode *temp = queue->front;
    TreeNode *data = temp->data;

    queue->front = temp->next;
    free(temp);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return data;
}

void levelOrderInsertion(BinaryTree *tree, int productId, const char *perfumeName, float price, int quantity) {
    TreeNode *newNode = createNode(productId, perfumeName, price, quantity);
    if (tree->root == NULL) {
        tree->root = newNode;
        return;
    }

    Queue *queue = createQueue();
    enqueue(queue, tree->root);

    while (queue->front != NULL) {
        TreeNode *current = dequeue(queue);

        if (current->left == NULL) {
            current->left = newNode;
            break;
        } else {
            enqueue(queue, current->left);
        }

        if (current->right == NULL) {
            current->right = newNode;
            break;
        } else {
            enqueue(queue, current->right);
        }
    }

    free(queue);
}

BinaryTree createBinaryTree() {
    BinaryTree tree;
    tree.root = NULL;
    int numProducts;
    printf("Enter the number of products: ");
    scanf("%d", &numProducts);

    // Perform level order insertion
    for (int i = 0; i < numProducts; i++) {
        int productId;
        char perfumeName[50];
        float price;
        int quantity;
        printf("Enter details for product %d:\n", i + 1);
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

        levelOrderInsertion(&tree, productId, perfumeName, price, quantity);
    }

    return tree;
}

void inOrderTraversal(TreeNode *root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%-11d%-15s%-8.2f%-9d\n", root->productId, root->perfumeName, root->price, root->quantity);
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(TreeNode *root) {
    if (root != NULL) {
        printf("%-11d%-15s%-8.2f%-9d\n", root->productId, root->perfumeName, root->price, root->quantity);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(TreeNode *root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%-11d%-15s%-8.2f%-9d\n", root->productId, root->perfumeName, root->price, root->quantity);
    }
}

int main() {
    int menu = 0;
    BinaryTree perfumeTree = createBinaryTree();

    while (menu != 5) {
        printf("\n\nMenu:\n1. In-Order Traversal\n2. Pre-Order Traversal\n");
        printf("3. Post-Order Traversal\n4. Display Perfumes\n5. Exit\n--------------\nEnter your choice: ");

        if (scanf("%d", &menu) != 1) {
            // Handle invalid input
            printf("Invalid input. Please enter a number.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);  // Clear input buffer
            continue;
        }

        switch (menu) {
            case 1:
                printf("\nIn-Order Traversal:\n");
                printf("Product ID | Perfume Name | Price | Quantity\n");
                printf("--------------------------------------------------\n");
                inOrderTraversal(perfumeTree.root);
                printf("--------------------------------------------------\n");
                break;

            case 2:
                printf("\nPre-Order Traversal:\n");
                printf("Product ID | Perfume Name | Price | Quantity\n");
                printf("--------------------------------------------------\n");
                preOrderTraversal(perfumeTree.root);
                printf("--------------------------------------------------\n");
                break;

            case 3:
                printf("\nPost-Order Traversal:\n");
                printf("Product ID | Perfume Name | Price | Quantity\n");
                printf("--------------------------------------------------\n");
                postOrderTraversal(perfumeTree.root);
                printf("--------------------------------------------------\n");
                break;

            case 4:
                printf("\nCurrent Perfumes:\n");
                printf("Product ID | Perfume Name | Price | Quantity\n");
                printf("--------------------------------------------------\n");
                inOrderTraversal(perfumeTree.root);
                printf("--------------------------------------------------\n");
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice, make a valid choice.\n");
                break;
        }
    }

    return 0;
}