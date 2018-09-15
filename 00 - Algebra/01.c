// Copyright (C) 2018 Mikhail Masyagin

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define PREFIX_UNUSED(v) ((void)v)

int how_to_use(const char* prog_name);

int main(int argc, char *argv[])
{
    int n;
    int i, j;
    
    if (argc != 2) {
        return how_to_use(argv[0]);
    }

    n = strtol(argv[1], NULL, 10);
    if ((errno == ERANGE) || ((n == 0) && (argv[1][0] != '0'))) {
        return how_to_use(argv[0]);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d * %d = %d\n", i, j, (i * j) % n);
        }
        printf("\n");
    }
    
    return 0;
}

int how_to_use(const char* prog_name) {
    printf("Usage: %s [number]\n", prog_name);
    printf("Example: %s 5\n", prog_name);
    return 1;
}
