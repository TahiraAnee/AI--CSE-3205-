#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> board;

bool isSafe(int row, int col) {
    for (int prevRow = 0; prevRow < row; prevRow++) {
        int prevCol = board[prevRow];
        if (prevCol == col || abs(prevCol - col) == abs(prevRow - row))
            return false;
    }
    return true;
}

bool solve(int row) {
    if (row == N) return true;

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            if (solve(row + 1))
                return true;
            board[row] = -1;
        }
    }
    return false;
}

int main() {
    cin >> N;
    board.assign(N, -1);

    if (solve(0)) {
        cout << "One possible solution:\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i] == j) cout << "Q ";
                else cout << ". ";
            }
            cout << "\n";
        }
    } else {
        cout << "No solution exists for N = " << N << "\n";
    }
}
