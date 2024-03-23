// Copyright 2021 NNTU-CS
#include <iostream>
#include <iostream>

int countPairs1(int *arr, int size, int value) {
    int count = 0;
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if ((arr[i] + arr[j]) == value)
                count += 1;
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int left = 0;
    int count = 0;
    int right = len - 1;
    while (arr[right] > value) {
        right -= 1;
    }
    for (int i = 0; i < right; i++) {
        for (int j = right; j > i; j--) {
            int sum = arr[i] + arr[j];
            if (sum == value) {
                count++;
            }
        }
    }
    return count;
}

int cbinsearch(int* arr, int size, int value) {
    int right = size - 1;
    int count = 0;
    int left = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            count++;
            int left = mid - 1;
            int right = mid + 1;
            while (left >= 0 && arr[left] == value) {
                count++;
                left--;
            }
            while (right < size && arr[right] == value) {
                count++;
                right++;
            }
            return count;
        }
        if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return count;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int second = value - arr[i];
        count += cbinsearch(&arr[i + 1], len - i - 1, second);
    }
    return count;
}

// Пример использования
int main() {
    int arr[] = {20, 30, 30, 40, 40};
    int len = sizeof(arr) / sizeof(arr[0]);
    int value = 50;

    std::cout << "countPairs1: " << countPairs1(arr, len, value) << std::endl;
    std::cout << "countPairs2: " << countPairs2(arr, len, value) << std::endl;
    std::cout << "countPairs3: " << countPairs3(arr, len, value) << std::endl;

    return 0;
}

