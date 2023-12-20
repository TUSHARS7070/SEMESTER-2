#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int linearSearch(char *arr[], int n, const char *key, int *elementComparisons, int *indexComparisons);
int sentinelSearch(char *arr[], int n, const char *key, int *elementComparisons, int *indexComparisons);
int binarySearch(char *arr[], int low, int high, const char *key, int *elementComparisons, int *indexComparisons);
void bubbleSort(char *arr[], int n, int *comparisons, int *dataTransfers);
void insertionSort(char *arr[], int n, int *comparisons, int *dataTransfers);

int linearSearch(char *arr[], int n, const char *key, int *elementComparisons, int *indexComparisons) {
    for (int i = 0; i < n; ++i) {
        (*elementComparisons)++;
        if (strcmp(arr[i], key) == 0) {
            (*indexComparisons)++;
            return i;
        }
    }
    return -1;
}

int sentinelSearch(char *arr[], int n, const char *key, int *elementComparisons, int *indexComparisons) {
    char *last = arr[n - 1];
    arr[n - 1] = (char *)key;

    int i = 0;
    while (strcmp(arr[i], key) != 0) {
        (*elementComparisons)++;
        i++;
    }

    arr[n - 1] = last;

    if (i < n - 1 || strcmp(arr[n - 1], key) == 0) {
        (*indexComparisons)++;
        return i;
    }

    return -1;
}

int binarySearch(char *arr[], int low, int high, const char *key, int *elementComparisons, int *indexComparisons) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        (*elementComparisons)++;

        if (strcmp(arr[mid], key) == 0) {
            (*indexComparisons)++;
            return mid;
        } else if (strcmp(arr[mid], key) < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

void bubbleSort(char *arr[], int n, int *comparisons, int *dataTransfers) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            (*comparisons)++;
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*dataTransfers)++;
            }
        }
    }
}

void insertionSort(char *arr[], int n, int *comparisons, int *dataTransfers) {
    for (int i = 1; i < n; ++i) {
        char *key = arr[i];
        int j = i - 1;

        (*comparisons)++;
        while (j >= 0 && strcmp(arr[j], key) > 0) {
            arr[j + 1] = arr[j];
            (*dataTransfers)++;
            j--;
        }

        arr[j + 1] = key;
        (*dataTransfers)++;
    }
}

int main() {
    int menu = 0;
    while (menu != 6) {
        char *arr[] = {"Chanel", "Dolce&Gabbana", "CalvinKlein", "TomFord", "Gucci", "Versace"};
        int n = sizeof(arr) / sizeof(arr[0]);
        char searchElement[50];
        char *key;

        int elementComparisons, indexComparisons, comparisons, dataTransfers;

        printf("\nMenu:\n1. Linear Search\n2. Sentinel Search\n3. Binary Search\n4. Bubble Sort\n5. Insertion Sort\n6. Exit\n--------------\n");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\n\nThe array we have used is: \n\t");
                for (int i = 0; i < n; i++) {
                    printf("%s, ", arr[i]);
                }
                printf("\n\nEnter the perfume you want to search: ");
                scanf("%s", &searchElement);
                key = searchElement;
                // Linear Search
                elementComparisons = indexComparisons = 0;
                int linearResult = linearSearch(arr, n, key, &elementComparisons, &indexComparisons);
                printf("\n\nLinear Search:\n");
                printf("Element Comparisons: %d\nIndex Comparisons: %d\n", elementComparisons, indexComparisons);
                if (linearResult != -1) {
                    printf("Perfume %s found at index %d\n", key, linearResult);
                } else {
                    printf("Perfume %s not found\n", key);
                }
                printf("\n");
                break;

            case 2:
                printf("\n\nThe array we have used is: \n\t");
                for (int i = 0; i < n; i++) {
                    printf("%s, ", arr[i]);
                }
                printf("\n\nEnter the perfume you want to search: ");
                scanf("%s", &searchElement);
                key = searchElement;
                // Sentinel Search
                elementComparisons = indexComparisons = 0;
                int sentinelResult = sentinelSearch(arr, n, key, &elementComparisons, &indexComparisons);
                printf("Sentinel Search:\n");
                printf("Element Comparisons: %d\nIndex Comparisons: %d\n", elementComparisons, indexComparisons);
                if (sentinelResult != -1) {
                    printf("Perfume %s found at index %d\n", key, sentinelResult);
                } else {
                    printf("Perfume %s not found\n", key);
                }
                printf("\n");
                break;

            case 3:
                printf("\n\nThe array we have used is: \n\t");
                for (int i = 0; i < n; i++) {
                    printf("%s, ", arr[i]);
                }
                printf("\n\nEnter the perfume you want to search: ");
                scanf("%s", &searchElement);
                key = searchElement;
                // Binary Search (requires sorted array)
                elementComparisons = indexComparisons = 0;
                int binaryResult = binarySearch(arr, 0, n - 1, key, &elementComparisons, &indexComparisons);
                printf("Binary Search:\n");
                printf("Element Comparisons: %d\nIndex Comparisons: %d\n", elementComparisons, indexComparisons);
                if (binaryResult != -1) {
                    printf("Perfume %s found at index %d\n", key, binaryResult);
                } else {
                    printf("Perfume %s not found\n", key);
                }
                printf("\n");
                break;

            case 4:
                printf("\n\nThe array we have used is: \n\t");
                for (int i = 0; i < n; i++) {
                    printf("%s, ", arr[i]);
                }
                // Bubble Sort
                comparisons = dataTransfers = 0;
                bubbleSort(arr, n, &comparisons, &dataTransfers);
                printf("Bubble Sort:\n");
                printf("Comparisons: %d\nData Transfers: %d\nSorted Array: ", comparisons, dataTransfers);
                for (int i = 0; i < n; ++i) {
                    printf("%s, ", arr[i]);
                }
                printf("\n\n");
                break;

            case 5:
                printf("\n\nThe array we have used is: \n\t");
                for (int i = 0; i < n; i++) {
                    printf("%s, ", arr[i]);
                }
                // Insertion Sort
                comparisons = dataTransfers = 0;
                insertionSort(arr, n, &comparisons, &dataTransfers);
                printf("Insertion Sort:\n");
                printf("Comparisons: %d\nData Transfers: %d\nSorted Array: ", comparisons, dataTransfers);
                for (int i = 0; i < n; ++i) {
                    printf("%s, ", arr[i]);
                }
                printf("\n\n");
                break;

            case 6:
                printf("Exiting...");
                break;

            default:
                printf("Invalid choice, make a valid choice.");
                break;
        }
    }
    return 0;
}