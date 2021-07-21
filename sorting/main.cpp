#include <iostream>

using namespace std;

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool isSwapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                isSwapped = true;
            }
        }
        if (!isSwapped)
            break;
    }

    printArray(a, n);
}

void selectionSort(int a[], int n) {
    // O(n2)
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_index])
                min_index = j;
        }
        swap(a[i], a[min_index]);
    }

    printArray(a, n);
}

void insertionSort(int a[], int n) {
    // O(n2)
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    printArray(a, n);
}

void mergeSortedArrays(int a[], int n, int b[], int m) {
    //IDEA is simple take two pointers at starting of both array and stat comparision which elemnet is small incremnt that pointer when one pointer finished then copy the remaning element in other array
    int i = 0, j = 0;
    while (i != n && j != m) {
        if (a[i] <= b[j]) {
            cout << a[i] << " ";
            i++;
        } else {
            cout << b[j] << " ";
            j++;
        }
    }

    while (j < m) {
        cout << b[j] << " ";
        j++;
    }

    while (i < n) {
        cout << a[i] << " ";
        i++;
    }
}

void mergeArray(int a[], int low, int mid, int high) {
    //int a[] = {10, 15, 20, 40, 8, 11, 55};
    //    merge(a, 0, 3, 6);
    //idea is simple from mid the left of subarray is sorted and right of subarray is sorted
    //copy the elements in 2 seprate array then merge both array using the above merge techniquie
    int leftLimit = mid - low + 1;
    int rightLimit = high - mid;
    int left[leftLimit];
    int right[rightLimit];

    for (int c = low; c < leftLimit; c++) {
        left[c] = a[low + c];
    }
    for (int b = 0; b <= rightLimit; b++) {
        right[b] = a[mid + b + 1];
    }
    int j = 0, k = 0, l = low;
    while (j != leftLimit && k != rightLimit) {
        if (left[j] <= right[k]) {
            a[l] = left[j];
            j++;
        } else {
            a[l] = right[k];
            k++;
        }
        l++;
    }

    while (k < rightLimit) {
        a[l] = right[k];
        k++;
        l++;
    }

    while (j < leftLimit) {
        a[l] = left[j];
        j++;
        l++;
    }
}

void mergeSort(int a[], int l, int r) {
// O(nlogn)
    if (l >= r)
        return;

    int mid = l + (r - l) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    mergeArray(a, l, mid, r);

}

void intersectionSortedArray(int a[], int n, int b[], int m) {
    int i = 0;
    int j = 0;
    while (i != n && j != m) {
        if (i > 0 && a[i] == a[i - 1]) {
            i++;
            continue;
        }
        if (a[i] > b[j]) {
            j++;
        }
        if (a[i] < b[j]) {
            i++;
        }
        if (a[i] == b[j]) {
            cout << a[i] << endl;
            i++;
            j++;
        }
    }
}

void unionSortedArray(int a[], int n, int b[], int m) {
    int i = 0;
    int j = 0;
    while (i != n && j != m) {
        if (i > 0 && a[i] == a[i - 1]) {
            i++;
            continue;
        }
        if (j > 0 && b[j] == b[j - 1]) {
            j++;
            continue;
        }
        if (a[i] > b[j]) {
            cout << b[j] << " ";
            j++;
        }
        if (a[i] < b[j]) {
            cout << a[i] << " ";
            i++;
        }
        if (a[i] == b[j]) {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }

    while (i < n) {
        cout << a[i] << " ";
        i++;
    }
    while (j < m) {
        cout << b[j] << " ";
        j++;
    }
}

int countAndMerge(int a[], int low, int mid, int high) {
    int leftLimit = mid - low + 1;
    int rightLimit = high - mid;
    int left[leftLimit];
    int right[rightLimit];

    for (int i = 0; i < leftLimit; i++) {
        left[i] = a[low + i];
    }
    for (int j = 0; j < rightLimit; j++) {
        right[j] = a[mid + j + 1];
    }

    int i = 0, j = 0, k = low, res = 0;

    while (i != leftLimit && j != rightLimit) {
        if (left[i] <= right[j]) {
            a[k] = left[i];
            i++;
        } else {
            // when right elemnet is greater then left elemnet so all the elemnets on left array will be great from right element and it will create an inversion
            a[k] = right[i];
            res = res + (leftLimit - i);
            j++;
        }
        k++;
    }

    while (i < leftLimit) {
        a[k] = left[i];
        k++;
        i++;
    }

    while (j < rightLimit) {
        a[k] = right[j];
        k++;
        j++;
    }

    return res;
}

int inversionCount(int a[], int left, int right) {
    //O(nlogn)
    //inversion is pair of a[i], a[j] where i < j  and a[i] > a[j]
    int res = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        res += inversionCount(a, left, mid);
        res += inversionCount(a, mid + 1, right);
        res += countAndMerge(a, left, mid, right);

    }

    return res;
}

int hoarePartition(int a[], int l, int h) {
    // IDEA is simple pivot is the starting elemnet
    // and i and j two varibale just before and after array
    //keep iterating elements  tille i an j cross each otjher
    //swap a[i] and a[j] when a[i] less then pivot and a[j] > pivot
    int pivot = a[l];
    int i = l - 1;
    int j = h + 1;

    while (true) {
        do {
            i++;
        } while (a[i] < pivot);
        do {
            j--;
        } while (a[j] > pivot);
        if (i >= j) return j;
        swap(a[i], a[j]);
    }
}

void QSort(int a[], int l, int h) {
    //O(nlog n)
    if (l < h) {
        int p = hoarePartition(a, l, h);
        QSort(a, l, p);
        QSort(a, p + 1, h);
    }
}

int chocolateDistribution(int a[], int n, int m) {
    // given an array of packets of chocolates each elemnet in array contains the number of chocolate in each packet.
    //you have to distribute the choclate among each given children so that each gets one packet
    // and the diffrence of minimum number of choclate and maximum chocolate is minimum
    // example [3,4,1,9,56,7,9,12] number of choclate in each packets given to be distributed among 5 children
    // so o/p is 6 if you take pairs 3,4,7,9,9 => 9-3 = 6 none other pairs will give the difference less then 6

    //idea is simple sort the array. iterate the array from i to i+m-1 then find the diffrence between a[i] and a[i+m-1]
    //and compare the difference from the last diffrence.
    // O(nlog n)

    if (m > n) {
        return -1;
    }
    sort(a, a + n);
    int res = INT_MAX;
    for (int i = 0; (i + m - 1) < n; i++) {
        res = min(res, (a[i + m - 1] - a[i]));
    }
    return res;
}

void sortArrayWithTwoTypesOfElements(int a[], int n) {
    //question is asked in 3 ways
    //1. sort array such that negative are on one side and positive on other side
    //2. sort array such that even are on one side and odd on other side
    //3. sort array such that 0 on one side and 1 on other in binary array

    // idea is simple we use hoare partiontion and while condition will change accordingly

    int i = -1;
    int j = n;

    while (true) {
        do {
            i++;
        } while (a[i] == 0);
        do {
            j--;
        } while (a[j] == 1);
        if (i >= j)return;
        swap(a[i], a[j]);
    }

}

void sortThreeTypesOfElements(int a[], int n) {
    // idea is simple we divide array in 4 parts
    // low and mid are intially at 0 and high at last element
    // we will iterate till mid and high cross each other
    // if a[mid] == 0 then swap it with a[low] and a[mid] and increment both
    // else if a[mid] == 1 then incremnet mid
    // else swap a[mid] with a[high] and decrese high;
    //     int a[] = {1, 1, 1, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 1, 1, 0, 0, 1};
    // this question can have diffrent variation where a pivot is given all elemnts less the pivot on left and all elements greater then pivots on right
    // only the if conditons will change accordingly


    int low = 0;
    int high = n - 1;
    int mid = 0;

    while (mid <= high) {
        if (a[mid] == 0) {
            swap(a[low], a[mid]);
            low++;
            mid++;
        } else if (a[mid] == 1) {
            mid++;
        } else {
            swap(a[high], a[mid]);
            high--;
        }
    }
}

int getMinimumDifference(int a[], int n) {
    // idea is simple sort the array then iterate the array and check diffrence with the previous elemnet
    // O(nlogn)
    sort(a, a + n);
    int res = INT_MAX;
    for (int i = 1; i < n; i++) {
        res = min(res, abs(a[i] - a[i - 1]));
    }
    return res;
}

struct Interval {
    int start;
    int end;
};

bool mycomp(Interval a, Interval b) { return a.start < b.start; }

void mergerOverlappingIntervals(Interval a[], int n) {
    //idea is simple sort the array then iterate the array and check if the previous end time is gretaer the current start
    // then merge that time start will be min of both start and end will be max of both end
    // else increment the response pointer;
    sort(a, a + n, mycomp);
    int res = 0;
    for (int i = 1; i < n; i++) {
        if (a[res].end >= a[i].start) {
            a[res].start = min(a[res].start, a[i].start);
            a[res].end = max(a[res].end, a[i].end);
        } else {
            res++;
            a[res] = a[i];
        }
    }

    for (int i = 0; i <= res; i++) {
        cout << "[" << a[i].start << ", " << a[i].end << "] ";
    }
}

int maxGuest(int arr[], int dep[], int n, int m) {
    sort(arr, arr + n);
    sort(dep, dep + m);

    int i = 1, j = 0, curr = 1, res = 1;
    while (i <= n && j <= m) {
        if (arr[i] <= dep[j]) {
            curr++;
            i++;
        } else {
            curr--;
            j++;
        }
        res = max(res, curr);
    }

    return res;
}

int main() {
    int a[] = {10, 8, 1, 4};
    int b[] = {10, 20, 20, 20, 40};
    Interval in[] = {{3,  5},
                     {2,  3},
                     {4, 6},
                     {1,  6},{5,  6}};
    int arrSize = sizeof(a) / sizeof(a[0]);
    int arrSize1 = sizeof(in) / sizeof(in[0]);
    //int arrSize1 = sizeof(b) / sizeof(b[0]);
    mergerOverlappingIntervals(in, arrSize1);
    //printArray(a, arrSize);
    return 0;
}
