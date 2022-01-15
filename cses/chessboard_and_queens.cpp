/*

Your task is to place eight queens on a chessboard so that no two
queens are attacking each other. As an additional challenge, each
square is either free or reserved, and you can only place queens on
the free squares. However, the reserved squares do not prevent queens
from attacking each other.

How many possible ways are there to place the queens?

Input

The input has eight lines, and each of them has eight characters. Each
square is either free (.) or reserved (*).

Output

Print one integer: the number of ways you can place the queens.

Example

Input:
........
........
..*.....
........
........
.....**.
...*....
........

Output:
65

*/

#include <bits/stdc++.h>
using namespace std;

/*
  - Observations:
    - 2 queens cannot be placed in a single row.
    - 2 queens cannot be placed in a single col.
    - 2 queens cannot be placed diagonally (there are 2 types - LR and RL)

  - Here we go apply solution search space exploration with
    back-tracking where we cannot proceed due to above conditions.

  - To track currently placed queens' attacking positions - we can
    keep 3 boolean arrays - for columns and diagonals.

  - We can recurse row wise (go next level for the next row), and for
    each row we will consider all column positions.

  - During the search exploration, we will place a queen where we can
    and update the attacking positions and then recurse to then next
    row level.

  - After returning back, we need to consider the next column
    position, but before we that we need to unplace the queen and
    reset her attacking positions.

  - If the recursion reaches the end of the board, then we have a
    valid placement - here we record the result count.
 */

int ans = 0;
bool takencols[8], takendiag1[16], takendiag2[16];

void place(string board[8], int r, int &ans) {
  if (r == 8) {
    ans++;
    return;
  }

  // Consider each column position
  for (int c = 0; c < 8; c++) {
    // Process only allowed cells.
    if (board[r][c] == '.') {
      // Check if the current queen position (r,c) is safe for the placement.
      if (!takencols[c] && !takendiag1[r - c + 8 - 1] && !takendiag2[r + c]) {
        // Update the new attacking positions for the queen placement.
        takencols[c] = takendiag1[r - c + 8 - 1] = takendiag2[r + c] = true;
        // Go check with the next queen in for the next row.
        place(board, r + 1, ans);
        // Reset the attacking positions, as queen needs to be unplaced and tried with a different column.
        takencols[c] = takendiag1[r - c + 8 - 1] = takendiag2[r + c] = false;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  string board[8];
  int ans = 0;
  for (int i = 0; i < 8; i++) {
    cin >> board[i];
  }
  place(board, 0, ans);
  cout << ans;
  return 0;
}
