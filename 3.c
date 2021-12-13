#include <stdio.h>
#include "ra.h"


int main() {
    int n;
    printf("Enter number: \n\r");
    scanf("%d", &n);
    printf("%d in hex would be %s \n", n, int2bin(n));
}