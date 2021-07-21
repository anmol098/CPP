#include <iostream>
#include <unordered_set>

using namespace std;
unordered_set<string> stringSet;

int factorial(int n) {
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * i;
    }
    return ans;
}

int gcd(int a, int b) {
    int mi = min(a, b);
    while (mi > 0) {
        if (a % mi == 0 & b % mi == 0) {
            break;
        }
        mi--;
    }
    return mi;
}

int lcm(int a, int b) {
    int res = max(a, b);
    while (true) {
        if (res % a == 0 && res % b == 0) {
            return res;
        }
        res++;
    }
}

bool isPrime(int n) {
    if (n == 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void primeFactor(int n) {
    for (int i = 2; i < n; i++) {
        if (isPrime(i)) {
            int x = i;
            while (n % x == 0) {
                cout << i;
                x = x * i;
            }
        }
    }
}

void trailingZero(int n) {
    int result = 0;
    for (int i = 5; i <= n; i = i * 5) {
        result = result + n / i;
    }
    cout << result;
}

void binary(int n) {
    if (n == 0)
        return;
    binary(n / 2);
    cout << n % 2;
}

void printtoN(int n) {
    if (n == 0)
        return;
    cout << n;
    printtoN(n - 1);
}

int fact(int n, int k) {
    if (n == 0 || n == 1) {
        return k;
    }
    return fact(n - 1, n * k);
}

int fibSum(int n) {
    if (n <= 1)
        return n;
    return fibSum(n - 1) + fibSum(n - 2) + 1;
}

int fib(int n) {
    if (n <= 1)
        return n;
    int a = fib(n - 1) + fib(n - 2);
    return a;
}

int sumNatural(int n) {
    if (n == 0)
        return 0;
    //cout << n;
    return n + sumNatural(n - 1);
}

bool palindromeString(string a, int start, int end) {
    if (start >= end) {
        return true;
    }
    return (a[start] == a[end]) && palindromeString(a, start + 1, end - 1);
}

int sumOfDigits(int n) {
    if (n <= 0)
        return n;
    //cout << n % 10 << " ";
    return (n % 10) + sumOfDigits(n / 10);
}

bool comp(int a, int b) {
    return (a < b);
}

int ropeCut(int n, int a, int b, int c) {
    if (n < 0)
        return -1;
    if (n == 0)
        return 0;

    int res = max(
            {
                    ropeCut(n - a, a, b, c),
                    ropeCut(n - b, a, b, c),
                    ropeCut(n - c, a, b, c)
            }, comp);
    if (res == -1)
        return -1;
    return res + 1;
}

void subset(string s, const string &curr = "", int i = 0) {
    if (i == s.length()) {
        cout << curr << endl;
        return;
    }
    subset(s, curr, i + 1);
    subset(s, curr + s[i], i + 1);

}

void towerOfHanoi(int n, string A = "A", string B = "B", string C = "C") {
    //A is initaial B is mid C is destination
    if (n == 1) {
        cout << "Move 1 from " + A + " to " + C << endl;
        return;
    }
    towerOfHanoi(n - 1, A, C, B);
    cout << "Move " << n << " from " + A + " to " + C << endl;
    towerOfHanoi(n - 1, B, A, C);
}

int jos(int n, int k) {
    if (n == 1) {
        return 0;
    } else {
        return (jos(n - 1, k) + k) % n;
    }
}

int countSubset(int s[], int n, int sum) {
    if (n == 0) {
        return (sum == 0) ? 1 : 0;
    }

    return countSubset(s, n - 1, sum) + countSubset(s, n - 1, sum - s[n - 1]);
}

void permute(string s, int i = 0) {
    if (i == s.length() - 1) {
        cout << s << "  ";
        stringSet.insert(s);
        return;
    }
    for (int j = i; j < s.length(); j++) {
        swap(s[i], s[j]);
        permute(s, i + 1);
        swap(s[i], s[j]);
    }

}
int main() {
    cout << "Hello, World!" << endl;
    int n, m;
    permute("123");
//    cin >> m;
//    cout << "gsd " << lcm(n, m);
//    int z = 0;
//    trailingZero(n);
//    cout << "orime Factor";
//    //primeFactor(n);
//    cout << "recur" << endl;
//    binary(27);
//    cout << endl;
//    printtoN(4);
//    cout << endl;
//    for (int i = 1; i < 10; i++)
//        cout << fib(i) << ",";
//    cout << endl;
//    cout << sumNatural(10);
//
//    cout << endl;
//    cout << palindromeString("abbaa", 0, 4);
//
//    cout << endl;
//    cout << sumOfDigits(345123);

//    cout << endl;
//    cout << ropeCut(5, 4, 2, 6);

    cout << endl;
//    subset("abc");
    //towerOfHanoi(3);
//    int balance[] = {10, 20, 15, 5};
//    cout << countSubset(balance, 4, 25);

    //subset("abc");

    return 0;
}
