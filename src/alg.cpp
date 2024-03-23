// Copyright 2021 NNTU-CS
#include <iostream>

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                ++count;
                while (j < len - 1 && arr[j] == arr[j + 1])
                    ++j;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0, right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            ++count;
            while (left < right && arr[left] == arr[left + 1])
                ++left;
            while (left < right && arr[right] == arr[right - 1])
                --right;
            ++left;
            --right;
        } else if (sum < value) {
            ++left;
        } else {
            --right;
        }
    }
    return count;
}

int binarySearch(int *arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        int index = binarySearch(arr, i + 1, len - 1, value - arr[i]);
        if (index != -1) {
            ++count;
            for (int k = index; k < len - 1; ++k)
                arr[k] = arr[k + 1];
            --len;
        }
        while (i < len - 1 && arr[i] == arr[i + 1])
            ++i;
    }
    return count;
}

int main() {
    int arr[] = {20, 30, 30, 40, 40};
    int len = sizeof(arr) / sizeof(arr[0]);
    int value = 50;

    std::cout << "countPairs1: " << countPairs1(arr, len, value) << std::endl;
    std::cout << "countPairs2: " << countPairs2(arr, len, value) << std::endl;
    std::cout << "countPairs3: " << countPairs3(arr, len, value) << std::endl;

    return 0;
}
