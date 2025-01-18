#include <stdio.h>
#include <string.h>

// 1. Print an array
void printArray(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 2. Check whether a string is a palindrome
void checkPalindrome(char str[]) {
    int len = strlen(str);
    int isPalindrome = 1;
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            isPalindrome = 0;
            break;
        }
    }
    if (isPalindrome)
        printf("The string \"%s\" is a palindrome.\n", str);
    else
        printf("The string \"%s\" is not a palindrome.\n", str);
}

// 3. Convert temperature from Celsius to Fahrenheit
void convertTemperature(float celsius) {
    float fahrenheit = (celsius * 9 / 5) + 32;
    printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);
}

// 4. Sort an array
void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Sorted array: ");
    printArray(arr, n);
}

// 5. Print largest and second largest element of the array
void findLargestElements(int arr[], int n) {
    if (n < 2) {
        printf("Not enough elements to find largest and second largest.\n");
        return;
    }
    int largest = -1, secondLargest = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }
    printf("Largest element: %d\n", largest);
    printf("Second largest element: %d\n", secondLargest);
}

// 6. Display Fibonacci series
void displayFibonacci(int n) {
    int a = 0, b = 1;
    printf("Fibonacci series: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        int next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

// 7. Print reverse of an array
void printReverseArray(int arr[], int n) {
    printf("Reversed array: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 8. Check the sum of all elements in an array
void sumOfArray(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    printf("Sum of array elements: %d\n", sum);
}

// 9. Check for duplicate numbers in an array
void checkDuplicates(int arr[], int n) {
    int hasDuplicates = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                hasDuplicates = 1;
                printf("Duplicate found: %d\n", arr[i]);
            }
        }
    }
    if (!hasDuplicates)
        printf("No duplicates found.\n");
}

int main() {
    int arr[] = {5, 3, 8, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    char str[] = "radar";
    float tempCelsius = 37.0;

    // Test each functionality
    printArray(arr, n);
    checkPalindrome(str);
    convertTemperature(tempCelsius);
    sortArray(arr, n);
    findLargestElements(arr, n);
    displayFibonacci(10);
    printReverseArray(arr, n);
    sumOfArray(arr, n);
    checkDuplicates(arr, n);

    return 0;
}
