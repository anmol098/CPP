#include <iostream>

using namespace std;

int largestElement(int arr[], int size) {
    int large = -1;
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > large) {
            large = arr[i];
            index = i;
        }
    }
    return index;
}

int secondLargest(int a[], int size) {
    int l = 0;
    int l2 = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] > l) {
            l2 = l;
            l = a[i];
        } else if (a[i] > l2 && a[i] != l) {
            l2 = a[i];
        }
    }
    if (l2 == 0) {
        return 0;
    } else
        return l2;
}

bool isSorted(int a[], int size) {

    for (int i = 0; i < size - 1; i++) {
        if (a[i] > a[i + 1])
            return false;
    }
    return true;
}

void reverseArray(int a[], int size) {

    int low = 0, high = size - 1;
    int temp;
    while (low < high) {
        temp = a[low];
        a[low] = a[high];
        a[high] = temp;
        low++;
        high--;
    }
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
}

void removeDuplicate(int a[], int size) {
    int temp = 1;
    for (int i = 1; i < size; i++) {
//        if (a[i] != temp) {
//            temp = a[i];
//        } else {
//            a[i] = a[i + 1];
//            a[i + 1] = -1;
//            temp = a[i + 1];
//        }
        if (a[i] != a[temp - 1]) {
            a[temp] = a[i];
            temp++;
        }
    }
    cout << temp;
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << "  ";
    }
    cout << endl;
}

void initializeArrayToZero(int a[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] = 0;
    }
}

void moveZeroToEnd(int a[], int size) {
    int arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] != 0) {
//            arr[j] = a[i];
            swap(a[j], a[i]);
            j++;
        }
    }
    printArray(a, size);

}

void leftRotateByOne(int a[], int size) {
    int temp = a[0];
    for (int i = 1; i < size; i++) {
        a[i - 1] = a[i];
    }
    a[size - 1] = temp;
    printArray(a, size);
}

void reverseArray(int a[], int low, int high) {
    while (low < high) {
        swap(a[low], a[high]);
        low++;
        high--;
    }

}

void leftRotateByN(int a[], int size, int d) {
    reverseArray(a, 0, d - 1);
    reverseArray(a, d, size - 1);
    reverseArray(a, 0, size - 1);

    printArray(a, size);

}

void leadersInArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        bool le = true;
        for (int j = i + 1; j <= n; j++) {
            if (a[i] < a[j]) {
                le = false;
                break;
            }
        }
        if (le) {
            cout << a[i] << " ";
        }
    }
}

void MaximumDiffrence(int a[], int n) {
    int max = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int diff = a[j] - a[i];
            if (diff > max) {
                max = diff;
            }
        }
    }
    cout << max;
}

void frequencyInSortedArray(int a[], int n) {
    int p1 = 0, p2 = 0;
    int count = 0;
    while (p1 != n || p2 != n) {
        if (a[p1] == a[p2]) {
            p2++;
            count++;
        } else {
            cout << a[p1] << " " << count << endl;
            count = 0;
            p1 = p2;
        }
    }
}

void stockBuySell(int a[], int n) {
    int profit = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            profit = profit + (a[i] - a[i - 1]);
        }
    }
    cout << profit;
}

void getWater(int a[], int n) {
//    int res = 0;
//    for (int i = 0; i < n - 1; i++) {
//        int lmax = a[i];
//        for (int j = 0; j < i; j++) {
//            lmax = max(lmax, a[j]);
//        }
//        int rmax = a[i];
//        for (int j = i + 1; j < n; j++) {
//            rmax = max(rmax, a[j]);
//        }
//        res = res + min(lmax, rmax) - a[i];
//    }
//    cout << res;

    int res = 0;
    int lmax[n], hmax[n];
    lmax[0] = a[0];
    for (int i = 1; i < n; i++) {
        lmax[i] = max(lmax[i - 1], a[i]);
    }
    hmax[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        hmax[i] = max(hmax[i + 1], a[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        res = res + (min(lmax[i], hmax[i]) - a[i]);
    }
    cout << res;
}

void maxOne(int a[], int n) {
    int count = 0, max_count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            count = 0;
        } else {
            count++;
            max_count = max(max_count, count);
        }

    }
    cout << max_count;

}

int maxSumSubArray(int a[], int n) {
    //Kadane algorithm
    int res = a[0];
    int maxEnding = a[0];
    for (int i = 1; i < n; i++) {
        maxEnding = max(maxEnding + a[i], a[i]);
        res = max(maxEnding, res);
    }
    cout << res;
    return res;
}

int minimumSumSubarray(int a[], int n) {
    // modified kadane algorithm
    int res = a[0];
    int minEnding = a[0];
    for (int i = 1; i < n; i++) {
        minEnding = min(minEnding + a[i], a[i]);
        res = min(minEnding, res);
    }
    cout << res;
    return res;
}

int arraySum(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sum + a[i];
    }
    return sum;
}

void maxSumCircularSubArray(int a[], int n) {
    int maxSumSubarray = maxSumSubArray(a, n);
    int minSumSubarray = minimumSumSubarray(a, n);
    int sumOfArray = arraySum(a, n);
    int circularSubArraySumMax = sumOfArray - minSumSubarray;

    cout << "maximum sum subarray circular " << max(circularSubArraySumMax, maxSumSubarray);
}

void maxEvenOddSubarray(int a[], int n) {
    int curr = 1;
    int maxSubarray = 1;
    for (int i = 1; i < n; i++) {
        if ((a[i] % 2 == 0 & a[i - 1] % 2 != 0) || (a[i] % 2 != 0 && a[i - 1] % 2 == 0)) {
            curr++;
            maxSubarray = max(maxSubarray, curr);
        } else {
            curr = 1;
        }
    }
    cout << maxSubarray << endl;
}

void findMajority(int a[], int n) {
    int res = 0, count = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[res]) {
            count++;
        } else {
            count--;
        }
        if (count == 0) {
            res = i;
            count = 1;
        }
    }
    count = 0;
    for (int i = 0; i < n; i++) {
        if (a[res] == a[i]) {
            count++;
        }
    }
    if (count <= n / 2) {
        res = -1;
        cout << res << endl;
    } else {
        cout << res << endl;
    }
}

void minimumConsicutiveFlip(int a[], int n) {
    //Idea is simple if you flip second group weather it be 0 or 1 it will give the minimum required flip
    //    int a[] = {0, 0, 1, 1, 0, 0, 1, 1, 0, 1};
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            if (a[i] != a[0]) {
                cout << "From " << i << " to ";
            } else {
                cout << i - 1 << "  " << endl;
            }
        }
    }
    if (a[n - 1] != a[0]) {
        cout << n - 1 << endl;
    }
}

bool windowSliding(int a[], int n, int sum) {
    //given a unsorted arrray of non negative number find sub array ofith given sum exists or not
    int window = 0;
    int tempSum = 0;
    for (int i = 0; i < n; i++) {
        tempSum = a[i];
        if (tempSum > sum) {
            window = i;
            break;
        }
        if (tempSum == sum)
            return true;
    }
    int currSum = 0;
    int k = window + 1;
    for (int i = k; i < n; i++) {
        currSum += a[i] - a[i - k];
        if (currSum == sum)
            return true;
    }
    return false;
}

int main() {
    cout << "Hello, World!" << endl;
    int a[] = {1, 4, 20, 3, 10, 5};
    int arrSize = sizeof(a) / sizeof(a[0]);
    //cout << isSorted(a, 3);
    cout << windowSliding(a, arrSize, 33);
    return 0;
}
