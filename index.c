#include <stdio.h>

int findMinimaCharLinear(char resultArr[], int resultArrLength) {
    int minimalChar = resultArr[0];

    for (int i = 1; i < resultArrLength; i++) {
        if ((int) resultArr[i] < (int) minimalChar) {
            minimalChar = resultArr[i];
        }
    }

    return minimalChar;
}

int main() {
    char arr1[10] = {};
    char arr2[10] = {};
    char resultArr[20] = {};

    for(int i = 0; i < 10; i++) {
        arr1[i] = i + 58;
        arr2[i] = 63 - i;
    }
    for(int i = 0; i < 20; i++) {
        if(i < 10) {
            resultArr[i] = arr1[i];
        } else {
            resultArr[i] = arr2[i - 10];
        }
    }
    for(int i = 0; i < 10; i++) {
        putchar(arr1[i]);
        printf(" ");
    }
    for(int i = 0; i < 10; i++) {
        putchar(arr2[i]);
        printf(" ");
    }
    printf("\n");
    for(int i = 0; i < 20; i++) {
        printf("%d", (int) resultArr[i]);
        printf(" ");
    }

    printf("\n");
    int resultArrLength = sizeof(resultArr) / sizeof(resultArr[0]);
    int minimalChar = findMinimaCharLinear(resultArr, resultArrLength);
    putchar(minimalChar);
}