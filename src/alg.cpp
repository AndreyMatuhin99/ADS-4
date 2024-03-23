// Copyright 2021 NNTU-CS
#include <iostream>
#include <vector>
#include <algorithm>

int countPairs1(const std::vector<int>& arr, int value) {
    int count = 0;
    int len = arr.size();
    for (int i = 0; i < (len - 1); i++) {
        for (int j = i + 1; j < len; j++) {
            if ((arr[i] + arr[j]) == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(const std::vector<int>& arr, int value) {
    int count = 0, x = 0, j = 0;
    int len = arr.size();
    for (int i = 0; i < (len - 1); i++) {
        if ((arr[i] + arr[i + 1]) >= value) {
            x = i;
            break;
        }
    }
    for (int i = 0; i < (len - 1); i++) {
        if (arr[i] > value) {
            break;
        }
        if (x <= i) {
            j = i + 1;
        } else {
            j = x;
        }
        for (; j < len; j++) {
            if ((arr[i] + arr[j]) == value) {
                count++;
            }
            if (arr[j] > value) {
                break;
            }
        }
    }
    return count;
}

int countPairs3(const std::vector<int>& arr, int value) {
    int count = 0;
    int len = arr.size();
    int right, m1, m2, left;
    for (int i = 0; i < len; ++i) {
        right = len - 1;
        left = i + 1;
        m2 = value - arr[i];
        while (left <= right) {
            m1 = (left + right) / 2;
            if (arr[m1] == m2) {
                count++;
                int next = m1 - 1;
                while ((next > i) && (arr[next] == arr[m1])) {
                    count++;
                    next--;
                }
                int next2 = m1 + 1;
                while ((i < next2) && (arr[next2] == arr[m1])) {
                    count++;
                    next2++;
                }
                break;
            } else if (arr[m1] > m2) {
                right = m1 - 1;
            } else {
                left = m1 + 1;
            }
        }
    }
    return count;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6};
    int value = 7;

    int pairsCount1 = countPairs1(arr, value);
    int pairsCount2 = countPairs2(arr, value);
    int pairsCount3 = countPairs3(arr, value);

    std::cout << "Pairs count using countPairs1: " << pairsCount1 << std::endl;
    std::cout << "Pairs count using countPairs2: " << pairsCount2 << std::endl;
    std::cout << "Pairs count using countPairs3: " << pairsCount3 << std::endl;

    return 0;
}

