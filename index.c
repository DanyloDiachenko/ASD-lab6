#include <stdio.h>

char findMinimalCharLinear(char arr[], int arrLength);
void bubbleSort(char arr[], int arrLength);
char findMinimalCharBinary(char arr[], int arrLength);

int main() {
    char arr1[10] = {};
    char arr2[10] = {};
    char resultArr[10] = {};
    int resultIndex = 0;
    char minimalCharLinear = ' ';
    char minimalCharBinary = ' ';

    for(int i = 0; i < 10; i++) {
        arr1[i] = i + 58;
        arr2[i] = 63 - i;
    }

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(arr1[i] == arr2[j]) {
                resultArr[resultIndex] = arr1[i];
                resultIndex++;
            }
        }
    }

    minimalCharLinear = findMinimalCharLinear(resultArr, resultIndex);

    bubbleSort(resultArr, resultIndex);

    minimalCharBinary = findMinimalCharBinary(resultArr, resultIndex);

    printf("%c", minimalCharLinear);
    printf("%c", minimalCharBinary);

    return 0;
}

char findMinimalCharLinear(char arr[], int arrLength) {
    char minimalChar = arr[0];

    for (int i = 1; i < arrLength; i++) {
        if ((int) arr[i] < (int) minimalChar) {
            minimalChar = arr[i];
        }
    }

    return minimalChar;
}

void bubbleSort(char arr[], int arrLength) {
    for (int i = 0; i < arrLength - 1; i++) {
        for (int j = 0; j < arrLength - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

char findMinimalCharBinary(char arr[], int arrLength) {
    int left = 0;
    int right = arrLength - 1;
    char minimalChar = arr[0];

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] < minimalChar) {
            minimalChar = arr[mid];
        }

        if (arr[mid] > arr[right]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return minimalChar;
}