#include <stdio.h>
#include "ra.h"

int main() {

    int nRC = 0;
    int nCurVal = 1;
    int sum = 0;
    char inputArray[9];
    memset(inputArray,0,9);
    printf("enter binary value \n");
    scanf("%s", inputArray);
    int nPos = strlen(inputArray)-1;
    while(nPos >= 0)
    {
        if (!(inputArray[nPos] == '1'||inputArray[nPos] == '0')) {
            printf("write only 0 or 1 \n\r");
            return 0;
        }
        if( inputArray[nPos] == '1')
        {
            sum += nCurVal;
        }
        --nPos;
        nCurVal *= 2;
    }
    printf( "%s converted to decimal is %d\n", inputArray, sum);
    return nRC;
}


