#include <bits/stdc++.h>
using namespace std;

void spiral(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    int top = 0, bottom = n - 1, left = 0, right = m - 1;

    while (top <= bottom && left <= right) {
        // left ? right
        for (int i = left; i <= right; i++) {
            cout << mat[top][i] << " ";
        }
        top++;

        // top ? bottom
        for (int i = top; i <= bottom; i++) {
            cout << mat[i][right] << " ";
        }
        right--;

        // right ? left (check row still exists)
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                cout << mat[bottom][i] << " ";
            }
            bottom--;
        }

        // bottom ? top (check col still exists)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                cout << mat[i][left] << " ";
            }
            left++;
        }
    }
}

int main() {
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    
    cout << "Original Matrix:" << endl;
    for (auto row : mat) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    cout << "\nSpiral Order:" << endl;
    spiral(mat);

    return 0;
}

