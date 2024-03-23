// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int size, int value) {
    int count = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if ((arr[i] + arr[j]) == value) {
                count += 1;
            }
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
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

int binarySearch(int* arr, int left, int right, int target) {
    int count = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            ++count;
            int l = mid - 1;
            int r = mid + 1;
            while (l >= left && arr[l] == target) {
                ++count;
                --l;
            }
            while (r <= right && arr[r] == target) {
                ++count;
                ++r;
            }
            return count;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return count;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        int index = binarySearch(arr, i + 1, len - 1, value - arr[i]);
        count += index;
    }
    return count;
}
