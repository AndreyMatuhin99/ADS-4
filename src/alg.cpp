// Copyright 2021 NNTU-CS
#include <algorithm>

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                ++count;
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

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        int low = i + 1, high = len - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[i] + arr[mid] == value) {
                ++count;
                break;
            } else if (arr[i] + arr[mid] < value) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return count;
}
