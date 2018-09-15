// Copyright (C) 2018 Mikhail Masyagin

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define PREFIX_UNUSED(v) ((void)v)

#define A 0
#define B 1
#define C 2
#define D 3
#define F 4

static const char names[][2] = {"A", "B", "C", "D", "F"};

void check_associativity(int n, int arr[][n]);
void find_left_units(int n, int arr[][n]);
void find_right_units(int n, int arr[][n]);
void find_units(int n, int arr[][n]);
void find_generating_elements(int n, int arr[][n]);

int main(int argc, char *argv[])
{
    PREFIX_UNUSED(argc);
    PREFIX_UNUSED(argv);

    int n = 5;
    int arr[][5] = {
        {A, A, A, D, D},
        {A, B, C, D, D},
        {A, C, B, D, D},
        {D, D, D, A, A},
        {D, F, F, A, A}
    };

    printf("1.1) Associativity:\n");
    check_associativity(n, arr);
    printf("\n");
    
    printf("2.1) Left Units:\n");
    find_left_units(n, arr);
    printf("2.2) Right Units:\n");
    find_right_units(n, arr);
    printf("2.3) Units:\n");
    find_units(n, arr);
    printf("\n");

    printf("3.1) Generating elements:\n");
    find_generating_elements(n, arr);
    return 0;
}

void check_associativity(int n, int arr[][n]) {
    int i, j, k;
    bool flag = true;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                if (arr[k][arr[j][i]] != arr[arr[k][j]][i]) {
                    printf("%s = (%s * %s) * %s != %s * (%s * %s) = %s\n",
                           names[arr[k][arr[j][i]]], names[i], names[j], names[k],
                           names[i], names[j], names[k], names[arr[arr[k][j]][i]]);
                    flag = false;
                    break;
                }
            }
        }
    }

    if (flag) {
        printf("     Operation is associative\n");
    } else {
        printf("     Operation is NOT associative\n");
    }
}

void find_left_units(int n, int arr[][n]) {
    int i, j;
    bool flag;

    for (i = 0; i < n; i++) {
        flag = true;
        for (j = 0; j < n; j++) {
            if (arr[j][i] != j) {
                flag = false;
            }
        }
        if (flag) {
            printf("     %s is left unit\n", names[i]);
        }
    }
}

void find_right_units(int n, int arr[][n]) {
    int i, j;
    bool flag;

    for (i = 0; i < n; i++) {
        flag = true;
        for (j = 0; j < n; j++) {
            if (arr[i][j] != j) {
                flag = false;
            }
        }
        if (flag) {
            printf("     %s is right unit\n", names[i]);
        }
    }
}

void find_units(int n, int arr[][n]) {
    int i, j;
    bool flag;

    for (i = 0; i < n; i++) {
        flag = true;
        for (j = 0; j < n; j++) {
            if ((arr[j][i] != j) || (arr[i][j] != j)) {
                flag = false;
            }
        }
        if (flag) {
            printf("     %s is unit\n", names[i]);
        }
    }
}

void find_generating_elements(int n, int arr[][n]) {
    int i, j;
    int tmp;
    bool arr1[n];
    bool flag;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            arr1[j] = false;
        }
        arr1[i] = true;
        tmp = i;
        j = 1;
        while ((i != arr[i][tmp]) && (j <= n)) {
            tmp = arr[i][tmp];
            arr1[tmp] = true;
            j++;
        }
        flag = true;
        for (j = 0; j < n; j++) {
            if (!arr1[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            printf("      %s is generating element\n", names[i]);
        }
    }
}
