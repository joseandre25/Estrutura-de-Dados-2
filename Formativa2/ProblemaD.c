#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int medianOfThree(int *v, int left, int right) {
    int mid = left + (right - left) / 2;
    if (v[left] > v[mid]) {
        swap(&v[left], &v[mid]);
    }
    if (v[mid] > v[right]) {
        swap(&v[mid], &v[right]);
    }
    if (v[left] > v[mid]) {
        swap(&v[left], &v[mid]);
    }
    return mid;
}

int partition(int *v, int left, int right) {
    int pivotIndex = medianOfThree(v, left, right);
    int pivot = v[pivotIndex];
    swap(&v[pivotIndex], &v[right]);
    int i = left;
    for (int j = left; j < right; j++) {
        if (v[j] < pivot) {
            swap(&v[i], &v[j]);
            i++;
        }
    }
    swap(&v[i], &v[right]);
    return i;
}

void quickselect(int *v, int left, int right, int k) {
    if (left >= right) return;
    int pivot = partition(v, left, right);
    if (pivot > k) {
        quickselect(v, left, pivot - 1, k);
    } else if (pivot < k) {
        quickselect(v, pivot + 1, right, k);
    }
}

void insertionsort(int *v, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int j = i;
        int tmp = v[j];
        while (j > left && tmp < v[j - 1]) {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = tmp;
    }
}

void quicksortM3(int *v, int left, int right) {
    if (right - left <= 32) {
        insertionsort(v, left, right);
        return;
    }
    int pivot = partition(v, left, right);
    quicksortM3(v, left, pivot - 1);
    quicksortM3(v, pivot + 1, right);
}

int main() {
    int n, p, x;
    scanf(" %d %d %d", &n, &p, &x);
    int *v = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf(" %d", &v[i]);
    }

    int startPage = (n - 1 < p * x) ? n - 1 : p * x;
    int endPage = (n - 1 < (p + 1) * x - 1) ? n - 1 : (p + 1) * x - 1;

    quickselect(v, 0, n - 1, startPage);
    quickselect(v, 0, n - 1, endPage);
    quicksortM3(v, startPage, endPage);

    for (int i = startPage; i < (n < (p + 1) * x ? n : (p + 1) * x); i++) {
        printf("%d\n", v[i]);
    }

    free(v);
    return 0;
}