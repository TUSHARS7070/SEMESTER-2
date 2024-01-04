#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 50

typedef struct {
    int productId;
    char perfumeName[50];
    float price;
    int quantity;
} Perfume;

void displayPerfumes(Perfume arr[], int n) {
    printf("\nPerfume Data:\n");
    printf("--------------------------------------------------\n");
    printf("Product ID | Perfume Name | Price | Quantity\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-11d%-15s%-8.2f%-9d\n", arr[i].productId, arr[i].perfumeName, arr[i].price, arr[i].quantity);
    }
    printf("--------------------------------------------------\n");
}

void merge(Perfume arr[], int l, int m, int r, int *comparisons, int *dataTransfers) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    Perfume L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        (*comparisons)++;
        if (L[i].productId <= R[j].productId) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        (*dataTransfers)++;
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        (*dataTransfers)++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        (*dataTransfers)++;
    }
}

void mergeSort(Perfume arr[], int l, int r, int *comparisons, int *dataTransfers) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m, comparisons, dataTransfers);
        mergeSort(arr, m + 1, r, comparisons, dataTransfers);

        merge(arr, l, m, r, comparisons, dataTransfers);
    }
}

void generateRandomData(Perfume arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i].productId = rand() % 1000 + 1;
        sprintf(arr[i].perfumeName, "Perfume%d", i + 1);
        arr[i].price = (float)(rand() % 1000) / 10; // Random price between 0 and 100
        arr[i].quantity = rand() % 100;
    }
}

void writeDataToFile(const char *filename, Perfume arr[], int n) {
    FILE *file = fopen(filename, "wb");
    if (file != NULL) {
        fwrite(arr, sizeof(Perfume), n, file);
        fclose(file);
    } else {
        printf("Error opening file for writing.\n");
    }
}

void readDataFromFile(const char *filename, Perfume arr[], int n) {
    FILE *file = fopen(filename, "rb");
    if (file != NULL) {
        fread(arr, sizeof(Perfume), n, file);
        fclose(file);
    } else {
        printf("Error opening file for reading.\n");
    }
}

int partition(Perfume arr[], int low, int high, int *comparisons, int *dataTransfers) {
    Perfume pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        (*comparisons)++;
        if (arr[j].productId < pivot.productId) {
            i++;
            Perfume temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            (*dataTransfers)++;
        }
    }

    Perfume temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    (*dataTransfers)++;

    return i + 1;
}

void quickSort(Perfume arr[], int low, int high, int *comparisons, int *dataTransfers) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons, dataTransfers);

        quickSort(arr, low, pi - 1, comparisons, dataTransfers);
        quickSort(arr, pi + 1, high, comparisons, dataTransfers);
    }
}

int main() {
    int menu = 0;
    int n = 6; // Number of perfumes
    Perfume arr[n]; // Array of Perfume structures

    // Variables to store comparison and data transfer counts for sorting techniques
    int comparisons_merge = 0, dataTransfers_merge = 0;
    int comparisons_quick = 0, dataTransfers_quick = 0;

    while (menu != 6) {
        printf("\n\nMenu:\n1. Generate Random Data\n2. Write Data to File\n3. Read Data from File\n4. Merge Sort\n5. Quick Sort\n6. Exit\n--------------");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                generateRandomData(arr, n);
                printf("Random data generated.\n");
                displayPerfumes(arr, n);
                break;

            case 2:
                writeDataToFile("perfume_data.txt", arr, n);
                printf("Data successfully written to the file.\n");
                break;

            case 3:
                readDataFromFile("perfume_data.txt", arr, n);
                printf("Data successfully read from the file.\n");
                displayPerfumes(arr, n);
                break;

            case 4:
                comparisons_merge = dataTransfers_merge = 0;
                mergeSort(arr, 0, n - 1, &comparisons_merge, &dataTransfers_merge);
                printf("\nMerge Sort:\n");
                printf("Comparisons: %d\nData Transfers: %d\n", comparisons_merge, dataTransfers_merge);
                displayPerfumes(arr, n);
                break;

            case 5:
                comparisons_quick = dataTransfers_quick = 0;
                quickSort(arr, 0, n - 1, &comparisons_quick, &dataTransfers_quick);
                printf("\nQuick Sort:\n");
                printf("Comparisons: %d\nData Transfers: %d\n", comparisons_quick, dataTransfers_quick);
                displayPerfumes(arr, n);
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice, make a valid choice.\n");
                break;
        }
    }
    return 0;
}
