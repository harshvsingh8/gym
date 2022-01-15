/*

There are 88418 paths in a 7×7 grid from the upper-left square to the
lower-left square. Each path corresponds to a 48-character description
consisting of characters D (down), U (up), L (left) and R (right).

For example, the path

Ref:
https://cses.fi/file/3624b569007eb03818b6611755f1bdbe4cdbd0a8334baf9fedc5365914bdd661

corresponds to the description DRURRRRRDDDLUULDDDLDRRURDDLLLLLURULURRUULDLLDDDD.

You are given a description of a path which may also contain
characters ? (any direction). Your task is to calculate the number of
paths that match the description.

Input

The only input line has a 48-character string of characters ?, D, U, L and R.

Output

Print one integer: the total number of paths.

Example

Input:
??????R??????U??????????????????????????LD????D?

Output:
201

*/

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

typedef long long ll;

/*
  
  - The following implementation traces all valid paths and count
    those whose end point reaches the target location.
  
  - For many test cases, it is getting TLE.

  - TODO - check optimization (the logic however is correct).
*/

inline bool is_valid_move(int row, int col, vector<vector<bool>>& grid)
{
  return !(row < 0 || row > 6 || col < 0 || col > 6||grid[row][col]);
}

void travel(const string &path, int index, int row, int col,
            vector<vector<bool>> &grid, int &count) {

  // return back if we go beyond the boundary or to a cell which is already on the current path.
  // if(row < 0 || row > 6 || col < 0 || col > 6 || grid[row][col])
  //   {
  //     return;
  //   }

  grid[row][col] = true;

  // Handle terminal - positive case
  if (row == 6 && col == 0) {
    // Check if we have covered all cell before reaching here.
    bool invalid = false;
    for (const auto &r : grid) {
      for (const auto &c : r) {
        if (!c) {
          invalid = true;
          break;
        }
      }
      if (invalid) {
        break;
      }
    }

    if (!invalid) {
      // increment valid path count by 1.
      count++;
    }

    grid[row][col] = false;
    return;
  }
  
  // From the given row/col position - we will try to navigate to next possible locations
  char pos = path[index];
  
  switch(pos)
    {
    case 'D':
      if(is_valid_move(row+1, col, grid)) travel(path, index+1, row+1, col, grid, count);
      break;
    case 'U':
      if(is_valid_move(row-1, col, grid)) travel(path, index+1, row-1, col, grid, count);
      break;
    case 'L':
      if(is_valid_move(row, col-1, grid)) travel(path, index+1, row, col-1, grid, count);
      break;
    case 'R':
      if(is_valid_move(row, col+1, grid)) travel(path, index+1, row, col+1, grid, count);
      break;
    case '?':
      // Try all cases and let the call roll-back for invalid moves.
      if(is_valid_move(row+1, col, grid)) travel(path, index+1, row+1, col, grid, count);
      if(is_valid_move(row-1, col, grid)) travel(path, index+1, row-1, col, grid, count);
      if(is_valid_move(row, col-1, grid)) travel(path, index+1, row, col-1, grid, count);
      if(is_valid_move(row, col+1, grid)) travel(path, index+1, row, col+1, grid, count);
      break;
    default:
      break;
    }

  grid[row][col] = false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<vector<bool>> grid(7);

  for (auto &g : grid) {
    g = vector<bool>(7, false);
  }

  string path;
  cin >> path;

  int count = 0;
  travel(path, 0, 0, 0, grid, count);
  cout << count << endl;
  return 0;
}
