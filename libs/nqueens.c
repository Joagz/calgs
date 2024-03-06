// Created by cpm (C Project Manager) | Author: Joaquin Gomez
#include "nqueens.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int permnum = 0;
int print = 0;

typedef struct{
    int length;
    int * values;
} array; 

static void append(array *perm, int v){
    perm->values[perm->length] = v;
    perm->length += 1;
}


static void pop(array *perm){
    perm->values[perm->length-1] = 0x00;
    perm->length -= 1;
}

// Linear search because in this case permutations aren't ordered
static int has_el(int k, array *perm){

    for(int i = 0; i < perm->length; i++) 
    {
        if(perm->values[i] == k) return 1;
    }
    return 0;
};

static int can_be_extended(array * perm)
{
    int i = perm->length - 1;
    for(int j = 0; j < i; j++)
    {
        if((i - j) == abs(perm->values[i]-perm->values[j])) return 0;
    }
    return 1;
}

static void generate_perm(array *perm, int n)
{
    if(perm->length == n) {
        if(print == 1)
        {
            printf("[");
            for (int i = 0; i < n; i++) {
                printf("%d, ", perm->values[i]);
            }
            printf("]");
            printf("\n");
        }
        permnum++;
        return;
    }

    for(int i = 0; i < n; i++) {
        if(has_el(i, perm) != 1) {
            append(perm, i);

            if(can_be_extended(perm) == 1)
                generate_perm(perm, n);

            pop(perm);
        }
    }
}


void testperm(int argc, char **argv) 
{

    if(argc > 3 || argc == 1) exit(-1);
    if(argc == 3 && strcmp(argv[2], "print") == 0) print = 1;

    array *perm = (array *) malloc(sizeof(array));
    perm->values = (int*) malloc(sizeof(int) * 20);
    perm->length = 0;

    generate_perm(perm, atoi(argv[1]));
    printf("number of permutations is: %d", permnum);

}
