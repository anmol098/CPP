#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;


int countDistinct(int arr[], int n) {
//    unordered_set<int> s;
//    for (int i = 0; i < n; i++) {
//        s.insert(arr[i]);
//    }

    unordered_set<int> s(arr, arr + n);

    return s.size();
}

void countFrequency(int arr[], int n) {
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++) {
        m[arr[i]]++;
    }

    for (auto item :  m) {
        cout << item.first << " " << item.second << endl;
    }
}

void intersectionTwoArray(int a[], int b[], int n, int m) {
    //Two array are given find the number of elements same accross both array
    unordered_set<int> s(a, a + n);
    int count = 0;
    for (int i = 0; i < m; i++) {
        if (s.find(b[i]) != s.end()) {
            count++;
            s.erase(b[i]);
        }
    }

    cout << count;
}

bool isPair(int a[], int n, int sum) {
    //to get the pair of element that equal to sum
    //idea is simple we check if the sum - current element is present in set or not if there true else insert the elemebnt
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        if (s.find(sum - a[i]) != s.end()) {
            return true;
        } else {
            s.insert(a[i]);
        }
    }
    return false;
}

bool isZeroSubarray(int a[], int n) {
    //find the subarray with the sum = 0
    // idea is simple we find the previous sum with every new element if the same previous sum is present in set then return true else insert the previous sum
    // to handle corner case insert 0 in the set explicitly
    int previous_sum = 0;
    unordered_set<int> s;
    s.insert(0);
    for (int i = 0; i < n; i++) {
        previous_sum += a[i];
        if (s.find(previous_sum - 0) != s.end()) {
            return true;
        } else {
            s.insert(previous_sum);
        }
    }
    return false;
}

bool isSubarrayWithGivenSum(int a[], int n, int sum) {
    // find the subarray with given sum
    // idea is simple compute the previous sum with each element and then check if previous_sum - sum is present in set if present return true else return false;
    // to handle corner case insert 0 in the set explicitly
    unordered_set<int> s;
    int previous_sum = 0;
    s.insert(0);
    for (int i = 0; i < n; i++) {
        previous_sum += a[i];
        if (s.find(previous_sum - sum) != s.end()) {
            return true;
        } else {
            s.insert(previous_sum);
        }
    }
    return false;
}

int lengthOfSubarrayWithGivenSum(int a[], int n, int sum) {
    //we store the previous sum and the current index at map
    //if previous_sum-sum is present in map then we change the max seen so far with the index in map minus current index
    int res = 0;
    unordered_map<int, int> m;
    int previous_sum = 0;

    for (int i = 0; i < n; i++) {
        previous_sum += a[i];
        if (previous_sum == sum)
            res = i + 1;
        auto it = m.find(previous_sum - sum);
        if (it != m.end())
            res = max(res, abs(it->second - i));
        else
            m.insert({previous_sum, i});

    }

    return res;
}

int lengthOfSubarrayWithEqualBinary(int a[], int n) {
    //in this we are given a binary array we have to find the lenght of subarray with equal number of 0 &1
    //we have to change all the 0 to -1 and then find the subarray with sum = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            a[i] = -1;
        }
    }
    return lengthOfSubarrayWithGivenSum(a, n, 0);
}

int sameLengthSubarrayWithEqualSum(int a[], int n, int b[]) {
    // in this two binary array are given you have to find the length of subarray with equal sum on both array and starting and ending index of both subarray should be same.
    //idea is simple we have to do is find the diffrence of each index and store it in the temp array and then find length of subarray with sum 0;
    int temp[n];
    for (int i = 0; i < n; i++) {
        temp[i] = a[i] - b[i];
    }

    return lengthOfSubarrayWithGivenSum(temp, n, 0);
}

int longestConsicutiveSubsequence(int a[], int n) {
    //we are given a array we have to find the length of subsequence so that they are consicutive

//    sort(a, a + n);
//    int curr = 1, res = 1;
//    for (int i = 1; i < n; i++) {
//        if (a[i] - a[i - 1] == 1) {
//            curr++;
//        } else if (a[i] != a[i - 1]) {
//            res = max(res, curr);
//            curr = 1;
//        }
//    }
//
//    return max(res, curr);

//idea is simple put all elements in hash set then pick the elemnet check if number previous to current element is presnet in hash set or not if it is not present then that element is the first elemnt of subsequece not check the +1,+2,+3, etc elemnt in the hash table
    unordered_set<int> s(a, a + n);
    int res = 1;
    for (auto item: s) {
        if (s.find(item - 1) == s.end()) {
            int curr = 1;
            while (s.find(item + curr) != s.end()) {
                curr++;
            }
            res = max(res, curr);
        }
    }
    return res;
}

int main() {

    int arr[] = {2, 9, 4, 3, 10};
//    int arr2[] = {20, 10, 10, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    // int size2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << longestConsicutiveSubsequence(arr, size);
    return 0;
}
