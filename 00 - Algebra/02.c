// Copyright (C) 2018 Mikhail Masyagin

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>

#define PREFIX_UNUSED(v) ((void)v)

int how_to_use(const char* prog_name);
void print_array(const long *arr, long n);
bool arr_cmp(const long *arr, const long n, const long *arr1, const long n1);

int main(int argc, char *argv[])
{
    long n;
    long *arr = NULL, *arr1 = NULL, *arr2 = NULL, *tmp = NULL;
    int i, j;
    bool flag;

    if (argc < 2) {
        return how_to_use(argv[0]);
    }

    n = argc - 1;
    arr = (long *) malloc(n * sizeof(long));
    if (arr == NULL) {
        printf("unable to allocate memory for arr\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        arr[i] = strtol(argv[i + 1], NULL, 10);
        if ((errno == ERANGE) || ((n == 0) && (argv[i + 1][0] != '0'))) {
            free(arr);
            return how_to_use(argv[0]);
        }
    }

    for (i = 1; i <= n; i++) {
        flag = false;
        for (j = 0; j < n; j++) {
            if (arr[j] == i) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            free(arr);
            return how_to_use(argv[0]);
        }
    }

    arr1 = (long *) malloc(n * sizeof(long));
    if (arr1 == NULL) {
        printf("unable to allocate memory for arr1\n");
        return 1;
    }
    arr2 = (long *) malloc(n * sizeof(long));
    if (arr2 == NULL) {
        printf("unable to allocate memory for arr2\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        arr1[i] = i + 1;
    }
    memcpy(arr2, arr1, n * sizeof(long));

    tmp = (long *) malloc(n * sizeof(long));
    if (tmp == NULL) {
        printf("unable to allocate memory for tmp\n");
        return 1;
    }

    print_array(arr1, n);
    while (true) {
        for (i = 0; i < n; i++) {
            tmp[i] = arr2[arr[i] - 1];
        }
        memcpy(arr2, tmp, n * sizeof(long));
        if (!arr_cmp(arr1, n, arr2, n)) {
            print_array(arr2, n);
        } else {
            break;
        }
    }

    free(arr);
    free(arr1);
    free(arr2);
    free(tmp);

    return 0;
}


int how_to_use(const char* prog_name) {
    printf("Usage: %s [number1] ... [numberN]\n", prog_name);
    printf("Example: %s 5 1 4 2 3\n", prog_name);
    return 1;
}

void print_array(const long *arr, long n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%ld ", arr[i]);
    }
    printf("\n");
}

bool arr_cmp(const long *arr, const long n, const long *arr1, const long n1) {
    int i;
    if (n != n1) {
        return false;
    }    
    for (i = 0; i < n; i++) {
        if (arr[i] != arr1[i]) {
            return false;
        }
    }
    return true;
}
