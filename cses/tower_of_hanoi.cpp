/*

The Tower of Hanoi game consists of three stacks (left, middle and
right) and n round disks of different sizes. Initially, the left stack
has all the disks, in increasing order of size from top to bottom.

The goal is to move all the disks to the right stack using the middle
stack. On each move you can move the uppermost disk from a stack to
another stack. In addition, it is not allowed to place a larger disk
on a smaller disk.

Your task is to find a solution that minimizes the number of moves.

Input

The only input line has an integer n: the number of disks.

Output

First print an integer k: the minimum number of moves.

After this, print k lines that describe the moves. Each line has two
integers a and b: you move a disk from stack a to stack b.

Constraints
1≤n≤16

Example

Input:
2

Output:
3
1 2
1 3
2 3
*/

#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <list>
#include <set>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;

using namespace std;

/*
  
  - This is a standard recursive algorithm. It is expensively covered
    in https://en.wikipedia.org/wiki/Tower_of_Hanoi . Check "Concrete
    Mathematics" for a more formal treatment.

  - The following implementation keeps tracks of total move count and
    pass around a string stream which records the movements.

  - TODO: Check Gray Code based solution. Covered in the last section
    of https://cp-algorithms.com/algebra/gray-code.html

 */

void transfer(char s, char i, char t, int count, int &moves, stringstream &ss) {

  // Just one disc is left, just move it from s (source) to t (target).
  if (count == 1) {
    ss << s << " " << t << endl;
    moves++;
    return;
  }

  // Move everything from source to intermediate peg using t, except the very last disc (at the bottom on s)
  transfer(s, t, i, count - 1, moves, ss);

  // Now move the largest disc in s which is at the bottom.
  ss << s << " " << t << endl;
  moves++;

  // Move the pending disc from temp peg (i) to the target peg (t) using s as the new temp peg.
  transfer(i, s, t, count - 1, moves, ss);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int moves = 0;
  stringstream ss;

  transfer('1', '2', '3', n, moves, ss);
  cout << moves << endl;
  cout << ss.str();

  return 0;
}
