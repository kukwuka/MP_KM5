# КМ-5 ГУСЕЙНОВ ЮНИС

#### ссылка на исходный файл (файл result.c):

https://github.com/kukwuka/MP_KM5/blob/main/result.c

#### ссылка на отчет:

https://github.com/kukwuka/MP_KM5/blob/main/REPORT.pdf

#### Задание:

Сгенерируйте 2 массива случайных чисел (от 1 до 10) формата 10 x 10. Сформировать третий массив аналогичного формата,
элементы третьего массива, в зависимости от запроса пользователя должны представлять из себя среднее арифметическое
соответствующих элементов первых двух массивов или остаток от деления элементов первого массива на элементы второго.

### Код

```c
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
```

### Результат в консоли

```shell

~/projects/c/rand (main)
$ gcc result.c -o result

~/projects/c/rand (main)
$ ./result.exe
n= 10 ; m=10
Generate  with size n*m
generated array is :
63      80      26      23      2       6       96      99      51      1
36      34      97      72      90      62      86      93      68      3
43      71      39      32      59      36      50      47      67      48
91      17      98      71      62      18      44      11      50      42
26      57      71      98      82      46      3       69      87      62
43      51      3       94      32      56      76      98      61      85
5       39      23      53      47      88      14      81      28      48
43      38      11      69      74      39      83      45      26      86
20      38      81      69      88      27      30      82      44      33
84      19      85      9       91      62      29      51      96      42
Generate  with size n*m
generated array is :
43      15      65      99      43      3       27      96      47      97
48      30      16      8       94      87      81      6       91      5
61      23      41      45      95      79      7       89      82      14
25      37      57      91      51      2       79      58      1       24
95      18      2       74      25      91      94      50      31      53
26      73      45      84      56      70      88      56      25      39
72      64      6       12      6       42      78      72      3       70
69      82      22      4       67      52      22      46      89      7
61      75      86      1       37      70      49      9       94      29
50      75      80      27      48      22      97      17      78      4
Choose option :
 1)new array with average value
 1)new array remainders
sda2
You type only '1' or '2'

~/projects/c/rand (main)
$ ./result.exe
n= 10 ; m=10
Generate  with size n*m
generated array is :
79      67      52      58      97      39      17      15      45      49
89      57      14      42      74      30      35      52      14      18
98      60      73      60      14      90      71      59      38      6
47      71      59      70      11      28      27      10      77      34
38      77      27      64      59      39      97      83      7       56
42      62      51      28      56      67      67      56      28      17
14      70      92      88      45      97      55      54      51      20
63      33      14      91      90      49      99      61      10      74
50      73      28      37      9       86      51      88      35      7
54      8       54      40      27      31      84      84      60      84
Generate  with size n*m
generated array is :
92      65      67      17      25      18      76      98      51      37
7       87      94      99      61      42      51      67      38      57
97      75      15      18      80      25      89      53      86      85
35      67      90      15      59      44      78      2       16      94
41      60      72      52      25      50      71      70      71      74
81      49      92      24      6       27      23      11      5       59
14      77      26      46      89      4       98      16      45      15
73      19      2       3       71      42      85      63      17      14
67      81      33      93      19      32      60      16      22      52
81      96      92      58      7       58      41      46      27      80
Choose option :
 1)new array with average value
 1)new array remainders
1
result array is
85      66      59      37      61      28      46      56      48      43
48      72      54      70      67      36      43      59      26      37
97      67      44      39      47      57      80      56      62      45
41      69      74      42      35      36      52      6       46      64
39      68      49      58      42      44      84      76      39      65
61      55      71      26      31      47      45      33      16      38
14      73      59      67      67      50      76      35      48      17
68      26      8       47      80      45      92      62      13      44
58      77      30      65      14      59      55      52      28      29
67      52      73      49      17      44      62      65      43      82

~/projects/c/rand (main)
$ ./result.exe
n= 10 ; m=10
Generate  with size n*m
generated array is :
82      25      97      66      16      5       60      58      25      39
40      2       76      56      92      45      25      64      63      80
30      98      41      45      64      61      96      3       33      97
78      23      31      49      20      90      4       29      3       52
98      82      58      37      94      58      57      47      89      54
43      83      41      74      61      89      26      48      81      43
16      57      7       36      64      20      3       48      55      73
47      31      34      17      93      51      82      25      86      72
36      40      17      51      12      19      36      10      53      40
29      65      48      85      74      84      37      52      72      33
Generate  with size n*m
generated array is :
63      36      87      1       80      60      66      58      71      45
98      39      89      18      74      92      85      80      87      8
25      86      69      52      57      74      86      26      46      20
77      73      18      19      81      53      39      90      19      9
89      9       86      47      24      42      26      54      98      19
13      65      62      91      56      19      69      22      21      3
41      59      89      33      6       37      62      64      54      44
15      86      58      23      13      80      59      27      2       15
88      4       82      52      35      25      63      17      7       36
27      42      15      65      99      7       11      14      37      95
Choose option :
 1)new array with average value
 1)new array remainders
2
result array is
19      25      10      0       16      5       60      0       25      39
40      2       76      2       18      45      25      64      63      0
5       12      41      45      7       61      10      3       33      17
1       23      13      11      20      37      4       29      3       7
9       1       58      37      22      16      5       47      89      16
4       18      41      74      5       13      26      4       18      1
16      57      7       3       4       20      3       48      1       29
2       31      34      17      2       51      23      25      0       12
36      0       17      51      12      19      36      10      4       4
2       23      3       20      74      0       4       10      35      33

```