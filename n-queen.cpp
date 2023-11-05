#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    // Check if there is a queen in the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check if there is a queen in the upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check if there is a queen in the upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueens(vector<vector<int>>& board, int row, int n, int& solutions, int fixedRow = -1, int fixedCol = -1) {
    if (row == n) {
        solutions++;
        cout << "Solution " << solutions << ":\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;
        return false;
    }

    for (int col = 0; col < n; col++) {
        if (fixedRow != -1 && fixedCol != -1 && row == fixedRow && col == fixedCol) {
            // If a fixed position is provided, skip other positions
            if (isSafe(board, row, col, n)) {
                board[row][col] = 1;
                if (solveNQueens(board, row + 1, n, solutions, fixedRow, fixedCol)) {
                    return true;
                }
                board[row][col] = 0;
            }
            return false;
        } else {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 1;
                if (solveNQueens(board, row + 1, n, solutions, fixedRow, fixedCol)) {
                    return true;
                }
                board[row][col] = 0;
            }
        }
    }

    return false;
}

void solveNQueens(int n, int fixedRow = -1, int fixedCol = -1) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    int solutions = 0;

    if (fixedRow != -1 && fixedCol != -1) {
        if (fixedRow < 0 || fixedRow >= n || fixedCol < 0 || fixedCol >= n) {
            cout << "Invalid fixed Queen position. Please provide valid indices." << endl;
            return;
        }
        board[fixedRow][fixedCol] = 1;
        solveNQueens(board, 1, n, solutions, fixedRow, fixedCol);
    } else {
        solveNQueens(board, 0, n, solutions);
    }

    cout << "Total solutions: " << solutions << endl;
}

int main() {
    int N;
    cout << "Enter the number of queens (N): ";
    cin >> N;
    int fixedRow = -1, fixedCol = -1;

    // If you want to specify a fixed position, uncomment the following lines:
    cout << "Enter the row index for the fixed Queen (0-based): ";
    cin >> fixedRow;
    cout << "Enter the column index for the fixed Queen (0-based): ";
    cin >> fixedCol;

    solveNQueens(N, fixedRow, fixedCol);
    return 0;
}





/*#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    // Check if there is a queen in the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check if there is a queen in the upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check if there is a queen in the upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueens(vector<vector<int>>& board, int row, int n, int& solutions) {
    if (row == n) {
        solutions++;
        cout << "Solution " << solutions << ":\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;
        return false;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;
            if (solveNQueens(board, row + 1, n, solutions)) {
                return true;
            }
            board[row][col] = 0;
        }
    }

    return false;
}

void solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    int solutions = 0;
    solveNQueens(board, 0, n, solutions);

    cout << "Total solutions: " << solutions << endl;
}

int main() {
    int N;
    cout << "Enter the number of queens (N): ";
    cin >> N;
    solveNQueens(N);
    return 0;
}
*/