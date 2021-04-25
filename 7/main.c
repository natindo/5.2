#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGHT 128

void swap(int arr[], int a, int b) {
    int tmp;
    tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
    return;
}

void shell_sort(int v[], int n) {
    int gap, i, j;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
                swap(v, j, j + gap);
            }
        }
    }
}

int main(void) {
int n;
int i = 0;
int arr[MAX_LENGHT];

scanf("%d", &n);

while (i < n) {
    scanf("%d", &arr[i]);
    i++;
}

shell_sort(arr, n);

for (int j = 0; j < n; j++)
    printf("%d ", arr[j]);

printf("\n");
return 0;
}