#include <stdio.h>
#include <stdlib.h>

int cmp(void *a, void *b) {
    int *query = malloc(sizeof(int*));
    int *temp = malloc(sizeof(int*));
    query = a;
    printf("query value: %d", *query);
    temp = b;
    printf("temp value: %d", *temp);
    if (query < temp) return -1;
    if (query > temp) return 1;
    free(query);
    free(temp);
    return 0;
}

int binarySearch_R(void * arr[], int first, int last, void * query) {
    printf("binary search called\n");
    if (last >= first) {
        int mid = first + (last - first)/2;
        printf("Mid: %d\n", mid);
    
        if (cmp(query, arr[mid]) == 0) {
            return mid;
        }
        if (cmp(query, arr[mid]) < 0) {
            return binarySearch_R(arr, first, (mid - 1), query);
        }
        return binarySearch_R(arr, (mid + 1), last, query);
    }

    return -1;
}

int binarySearch_I(void * arr[], int first, int last, void * query) {
    printf("binary search called\n");
    while(last >= first) {
        int mid = first + (last - first)/2;
        printf("Mid: %d\n", mid);

        if(cmp(query, arr[mid]) == 0) {
            return mid;
        }
        if (cmp(query, arr[mid]) < 0) {
            last = (mid - 1);
        }
        if(cmp(query, arr[mid]) > 0) {
            first = (mid + 1);
        }
    }
    return -1;
}

int main() {
    int arr[] = { 2, 3, 4, 9, 13, 27, 409, 68700, 170000 };
    int *n = malloc(sizeof(int*));
    *n = 409;
    int result = binarySearch_I((void*)arr, 0, 8, n);
    (result == -1) ? printf("Element not found") : printf("Element at index %d", result);
    free(n);
    return 0;
}