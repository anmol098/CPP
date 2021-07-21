#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int>> &arr) {
    for (auto &i : arr) {
        for (int j : i) {
            cout << j << "  ";
        }
        cout << endl;
    }
}

void printSnake(vector<vector<int>> &arr) {
    int R = arr.size();
    int C = arr[0].size();
    for (int i = 0; i < R; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < C; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        } else {
            for (int j = C - 1; j >= 0; j--) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
}

void printBoundary(vector<vector<int>> &arr) {
    int R = arr.size();
    int C = arr[0].size();

    if (R == 1) {
        for (int i = 0; i < C; i++) {
            cout << arr[0][i] << " ";
        }
    } else if (C == 1) {
        for (int i = 0; i < R; i++) {
            cout << arr[i][0] << " ";
        }
    } else {
        for (int i = 0; i < C; i++) {
            cout << arr[0][i] << " ";
        }
        cout << endl;
        for (int i = 1; i < R; i++) {
            cout << arr[i][C - 1] << " ";
        }
        cout << endl;
        for (int i = C - 2; i >= 0; i--) {
            cout << arr[R - 1][i] << " ";
        }
        cout << endl;
        for (int i = R - 2; i > 0; i--) {
            cout << arr[i][0] << " ";
        }
    }
}

void transpose(vector<vector<int>> &arr) {
    int R = arr.size();
    int C = arr[0].size();
//    int temp[R][C];
//
//    for (int i = 0; i < R; i++) {
//        for (int j = 0; j < C; j++) {
//            temp[i][j] = arr[j][i];
//        }
//    }
//
//    for (int i = 0; i < R; i++) {
//        for (int j = 0; j < C; j++) {
//            arr[i][j] = temp[i][j];
//        }
//    }

    //idea is simple in transpose diagnoal remains same so we have to swap upper diagonal with lower diagonal

    for (int i = 0; i < R; i++) {
        for (int j = i + 1; j < C; j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }

    printMatrix(arr);
}

void rotateMatrix(vector<vector<int>> &arr) {
    //we have tp rotate a matrix by 90 degree anti clockwise
    //idea is simple in this the last coloumn become first row
    //second last row will become second row and soo on
    int R = arr.size();
    int C = arr[0].size();

    int temp[R][C];
//
//    for (int i = 0; i < R; i++) {
//        for (int j = 0; j < C; j++) {
//            temp[R-j-1][i] = arr[i][j];
//        }
//    }
//    for (int i = 0; i < R; i++) {
//        for (int j = 0; j < C; j++) {
//            arr[i][j] = temp[i][j];
//        }
//    }
//
//    printMatrix(arr);
    // efficent -> find the transpose then reverse the individual coloumn in matrix
    for (int i = 0; i < R; i++) {
        for (int j = i + 1; j < C; j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }
    for (int i = 0; i < R; i++) {
        int low = 0;
        int high = C - 1;
        while (low < high) {
            swap(arr[low][i], arr[high][i]);
            low++;
            high--;
        }
    }

    printMatrix(arr);
}

void printSpiralMatrix(vector<vector<int>> &arr) {
    int R = arr.size();
    int C = arr[0].size();

    int top = 0;
    int right = C - 1;
    int bottom = R - 1;
    int left = 0;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            cout << arr[top][i] << " ";
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            cout << arr[i][right] << " ";
        }
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                cout << arr[bottom][i] << " ";
            }
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                cout << arr[i][left] << " ";
            }
            left++;
        }
    }


}

int searchElement(vector<vector<int>> &arr, int num) {
    int R = arr.size();
    int C = arr[0].size();

    int i = 0, j = C - 1;
    while (i < R && j >= 0) {
        int pos = arr[i][j];
        if (num == pos) {
            return num;
        } else if (num < pos) {
            //num is less then the current position then we move left in coloumn
            j--;
        } else {
            // num is grater then current position then we move down in row
            i++;
        }
    }
    return 0;
}

int main() {
    vector<vector<int>> arr = {{10, 20, 30, 40},
                               {15, 25, 35, 45},
                               {27, 29, 37, 48},
                               {32, 33, 39, 50}
    };
    cout << searchElement(arr, 290);
    return 0;
}
