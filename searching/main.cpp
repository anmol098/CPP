#include <iostream>

using namespace std;

int binarySearch(int a[], int n, int data) {
    // time complexity is O(log n)
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == data) {
            return mid;
        }
        if (a[mid] < data) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int recursiveBinarySearch(int a[], int low, int high, int data) {
    if (low > high) return -1;
    int mid = (low + high) / 2;
    if (a[mid] == data)
        return mid;
    else if (a[mid] < data) {
        return recursiveBinarySearch(a, mid + 1, high, data);
    } else {
        return recursiveBinarySearch(a, low, mid - 1, data);
    }
}

int firstOccRecursive(int a[], int low, int high, int x) {
    if (low > high) return -1;
    int mid = (low + high) / 2;

    if (a[mid] == x) {
        if (a[mid - 1] != a[mid] || mid == 0) {
            return mid;
        } else {
            return firstOccRecursive(a, low, mid - 1, x);
        }
    } else if (a[mid] < x) {
        return firstOccRecursive(a, mid + 1, high, x);
    } else {
        return firstOccRecursive(a, low, mid - 1, x);
    }
}

int lastOccRecursive(int a[], int low, int high, int x, int n) {
    if (low > high) return -1;
    int mid = (low + high) / 2;

    if (a[mid] == x) {
        if (a[mid + 1] != a[mid] || a[mid] == n - 1) {
            return mid;
        } else {
            return lastOccRecursive(a, mid + 1, n, x, n);

        }
    } else if (a[mid] < x) {
        return lastOccRecursive(a, mid + 1, high, x, n);
    } else {
        return lastOccRecursive(a, low, mid - 1, x, n);
    }
}

int firstOcc(int a[], int n, int data) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == data) {
            if (a[mid - 1] != a[mid] || mid == 0) {
                return mid;
            } else
                high = mid - 1;
        }
        if (a[mid] < data) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int countOccurrence(int a[], int n, int x) {
    int first = firstOcc(a, n, x);
    if (first == -1) {
        return 0;
    } else {
        return (lastOccRecursive(a, 0, n - 1, x, n) - first + 1);
    }

}

int countOneInBinaryArray(int a[], int n) {
    int first = firstOcc(a, n, 1);
    if (first == -1) {
        return 0;
    } else {
        return n - first;
    }
}

int squareRootFloor(int x) {
    // idea is simple to calculate the sq root of a number find the mid element in the range to x then check if square of mid is equal to x or change accordingly between the binary search range
    int low = 0;
    int high = x;
    int ans = -1;
    int mid = 0;

    while (low <= high) {
        mid = (low + high) / 2;
        int sq = mid * mid;
        if (sq == x) {
            return mid;
        } else if (sq > x) {
            high = mid - 1;
        } else {
            low = mid + 1;
            ans = mid;
        }
    }

    return ans;

}

int searchInfiniteArray(int a[], int n, int x) {
    //log (pos)
    if (a[0] == x) return 0;
    int i = 1;
    while (a[i] < x) {
        i = i * 2;
    }
    if (a[i] == x) return i;

    return recursiveBinarySearch(a, i / 2 + 1, i, x);
}

int rotatedSortedArray(int a[], int n, int x) {
    //log n
    int low = 0;
    int high = n - 1;
    int mid = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == x)
            return mid;
        else if (a[mid] < a[high]) {
            //right half is sorted
            if (x > a[mid] && x <= a[high]) {
                //if it lies in sorted range
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        } else {
            //left half is sorted
            if (x >= a[low] && x < a[mid]) {
                //if it lies in sorted range
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }
    return -1;
}

int peakElement(int a[], int n) {
    //every array has a peak element so idea is go to mid and check if it is greater from both neighbouring element then return mid
    //else check if left of mid is greater then iterate left array
    //else right of array is greatger then iterate right array
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if ((mid == 0 || a[mid - 1] <= a[mid]) && (mid == n - 1 || a[mid + 1] <= a[mid])) {
            return mid;
        }
        if (mid > 0 && a[mid - 1] > a[mid]) {
            high = mid - 1;
        } else
            low = mid + 1;
    }

    return -1;
}

bool isPair(int a[], int n, int sum) {
    // sum of two values in array equal to given sum if sum of number is greater then given sum then pointer move from last else from stating
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int pairSum = a[low] + a[high];
        if (pairSum == sum) {
            return true;
        } else if (pairSum > sum) {
            high = high - 1;
        } else {
            low = low + 1;
        }
    }
    return false;
}

int main() {
    int a[] = {2, 4, 8, 9, 11, 12, 20, 30};
    int arrSize = sizeof(a) / sizeof(a[0]);
    int result = isPair(a, arrSize, 233);
    cout << result;
    return 0;
}
