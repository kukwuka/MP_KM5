#include <stdlib.h>
#include <stdio.h>
#include "ht.h"

void generate_random_array(int ***array, int *n, int *m);

void print_array(int ***array, int n, int m);


void find_more_often_value(int ***array, int n, int m);

void find_max_min_average_in_range(int ***array, int n, int m);

int **dynamic_array(size_t n, size_t m);

int **dynamic_array(size_t n, size_t m) {
    int **array = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i) {
        array[i] = (int *) malloc(m * sizeof(int *));
    }
    return array;
}


//RANDOM ARRAY WITH SIZE n AND m
void generate_random_array(int ***array, int *n, int *m) {


    printf("Generate  with size n*m \n\r");
    printf("Enter n size: \n\r");
    scanf("%d", n);
    printf("Enter m size: \n\r");
    scanf("%d", m);
    *array = dynamic_array(*n, *m);

    srand((int) time(NULL));
    for (int i = 0; i < *n; ++i) {
        for (int j = 0; j < *m; ++j) {
            (*array)[i][j] = rand() % 0x63;
        }
    }

    printf("generated array is : \n\r");
    print_array(array, *n, *m);
}


void print_array(int ***array, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d \t", (*array)[i][j]);
        }
        printf("\r\n");
    }
}

char *int2bin(int i) {
    size_t bits = sizeof(int) * CHAR_BIT;

    char *str = malloc(bits + 1);
    if (!str) return NULL;
    str[bits] = 0;

    unsigned u = *(unsigned *) &i;
    for (; bits--; u >>= 1)
        str[bits] = u & 1 ? '1' : '0';

    return str;
}

int bin2int(const char *s) {
    return (int) strtol(s, NULL, 2);
}

void find_more_often_value(int ***array, int n, int m) {
    hashtable_t *hashtable = ht_create(n * m);
    int max_count = 0;
    int max_value = 0x00;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int value = (*array)[i][j];
            char *buffer = int2bin(value);
            char *count_str = ht_get(hashtable, buffer);
            if (count_str == NULL) {
                int count = 0 + 1;
                ht_set(hashtable, buffer, int2bin(1));
                max_count = count;
                max_value = value;
            } else {
                int count = bin2int(count_str) + 1;
                if (max_count < count) {
                    max_count = count;
                    max_value = value;
                }
                ht_set(hashtable, buffer, int2bin(count));
            }
        }
    }
    printf("%d is max, %d times\n", max_value, max_count);
}

void find_max_min_average_in_range(int ***array, int n, int m) {
    for (int i = 0; i < n; ++i) {
        int max = (*array)[i][0];
        int min = (*array)[i][0];
        int ave = 0;
        for (int j = 0; j < m; ++j) {
            int value = (*array)[i][j];
            if (max < value) {
                max = value;
            }
            if (min > value) {
                min = value;
            }
            ave += value;
        }
        double res_average = (double) ave / m;
        printf("For row number %d, max : %d, min: %d, average: %f \n", i, max, min, res_average);
    }

}
