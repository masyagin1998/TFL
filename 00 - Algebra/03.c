// Copyright (C) 2018 Mikhail Masyagin

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>

#define PREFIX_UNUSED(v) ((void)v)

int how_to_use(const char* prog_name);

void print_array(const long *arr, long n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%ld ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    long n;
    long q;
    long rn;
    long *arr = NULL, *arr1 = NULL, *res = NULL;
    int i, j;
    bool flag;

    if (argc < 3) {
        return how_to_use(argv[0]);
    }
    
    n = argc - 2;
    arr = (long *) malloc(n * sizeof(long));
    if (arr == NULL) {
        printf("unable to allocate memory for arr\n");
        return 1;
    }

    q = strtol(argv[1], NULL, 10);
    if ((errno == ERANGE) || ((n == 0) && (argv[1][0] != '0'))) {
        free(arr);
        return how_to_use(argv[0]);
    }
    
    for (i = 0; i < n; i++) {
        arr[i] = strtol(argv[i + 2], NULL, 10);
        if ((errno == ERANGE) || ((n == 0) && (argv[i + 2][0] != '0'))) {
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
    for (i = 0; i < n; i++) {
        arr1[i] = i + 1;
    }

    res = (long *) malloc(n * sizeof(long));
    if (res == NULL) {
        printf("unable to allocate memory for res\n");
        return 1;
    }
    rn = 0;

    i = q - 1;
    
    do {
        res[rn++] = arr1[i];
        i = arr[i] - 1;
    } while (arr1[i] != q);

    print_array(res, rn);

    free(arr);
    free(arr1);
    free(res);
    
    return 0;
}

int how_to_use(const char* prog_name) {
    printf("Usage: %s [number0]     [number1] ... [numberN]\n", prog_name);
    printf("Example: %s 4     5 1 4 2 3\n", prog_name);
    return 1;
}
