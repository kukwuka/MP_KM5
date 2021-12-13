#include "ra.h"

int main() {
    int m;
    int n;
    int **array;
    generate_random_array(&array, &n, &m);
    find_more_often_value(&array,n,m);
    return 0;
}
