#include <stdio.h>
void inArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}
void selectSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int smallest = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[smallest])
                smallest = j;
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
    }
}
void outArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
