#include "ra.h"


int main() {
    int m = 10;
    int n = 10;
    printf("n= %d ; m=%d \n", n, m);
    int **array1;
    int **array2;
    int **array3;
    int option;

    //SEED FOR RANDOM
    srand((int) time(NULL));
    //GENERATE 2 ARRAYS 10X10 SIZE, WITH RANDAOM VALUES
    generate_random_array(&array1, &n, &m);
    generate_random_array(&array2, &n, &m);

    printf("Choose option : \n 1)new array with average value \n 1)new array remainders \n");
    // CLIENT SELECT OPTION
    scanf("%d", &option);
    // VALIDATE CHOSEN OPTION
    if (!(option == 1 || option == 2)) {
        printf("You type only '1' or '2' ");
        return 0;
    }

    // GET EMPTY ARRAY SIZE 10X10
    array3 = dynamic_array(n, m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (option == 1) {
                // SET AVERAGE BETWEEN  ARRAY1 AND ARRAY2  FOR ARRAY3
                array3[i][j] = (array1[i][j] + array2[i][j]) / 2.0;
            } else if (option == 2) {
                // SET REMAINDER OF THE DIVISION ARRAY1 AND ARRAY2  FOR ARRAY3
                array3[i][j] = array1[i][j] % array2[i][j];
            }
        }
    }

    // PRINT RESULT
    printf("result array is \n");
    print_array(&array3, n, m);
    return 0;
}