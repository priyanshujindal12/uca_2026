#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void generateRandom(int a[], int s) {
    int i;
    for (i = 0; i < s; i++) {
        a[i] = rand() % s + 1;
    }
}

void generateAscending(int a[], int s) {
    int i;
    for (i = 0; i < s; i++) {
        a[i] = i;
    }
}

void generateDescending(int a[], int s) {
    int i;
    for (i = 0; i < s; i++) {
        a[i] = s - i;
    }
}

int partition(int a[], int low, int high) {

    int pivot = a[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++) {

        if (a[j] <= pivot) {

            i++;

            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

void QuickSort(int a[], int low, int high) {

    if (low < high) {

        int pi = partition(a, low, high);

        QuickSort(a, low, pi - 1);
        QuickSort(a, pi + 1, high);
    }
}

void print(int a[], int s) {
    int i;
    for (i = 0; i < s; i++) {
        printf("%d ", a[i]);
    }
}

int main() {

    struct timeval te;

    int size = 8000;
    int step = 4000;
    int i;

    for (i = 0; i < 8; i++) {

        int a[size];

        generateRandom(a, size);

        print(a, size);

        gettimeofday(&te, NULL);
        long long start = te.tv_sec * 1000LL + te.tv_usec / 1000;

        QuickSort(a, 0, size - 1);

        gettimeofday(&te, NULL);
        long long end = te.tv_sec * 1000LL + te.tv_usec / 1000;

        printf("\nTime Taken: %lld ms\n\n", end - start);

        size += step;
    }

    return 0;
}