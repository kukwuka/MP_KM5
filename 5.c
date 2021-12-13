#include "ra.h"

int main() {
    int m;
    int n;
    int **array;
    generate_random_array(&array, &n, &m);
    find_max_min_average_in_range(&array, n, m);
    return 0;
}

