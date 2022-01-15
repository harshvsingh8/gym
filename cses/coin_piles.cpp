/*

You have two coin piles containing a and b coins. On each move, you
can either remove one coin from the left pile and two coins from the
right pile, or two coins from the left pile and one coin from the
right pile.

Your task is to efficiently find out if you can empty both the piles.

Input

The first input line has an integer t: the number of tests.

After this, there are t lines, each of which has two integers a and b:
the numbers of coins in the piles.

Output

For each test, print "YES" if you can empty the piles and "NO" otherwise.

Constraints
1≤t≤105
0≤a,b≤109
Example

Input:
3
2 1
2 2
3 3

Output:
YES
NO
YES

*/

#include <algorithm>
#include <bitset>
#include <iostream>
#include <list>
#include <set>
#include <vector>
using namespace std;

/*
  - Possible moves: (-1, -2) or (-2, -1)

  - On either move, the total count is reduced by 3, so if original
    sum is not modulo of 3 then there won't be any solution.

  - Assuming we apply first type of move P times, and the second type
    for Q times. To satisfy the end condition, after all moves A and B
    both should be reduced to 0.

  - Forming equations: A - P - 2Q = 0 and B - 2P - Q = 0

  - Solving the above equation yeilds: P = (2B - A)/3 and Q = (2A -
    B)/3, the both values should be non-negative integer.

  - Above equation should be solvable for any natural P and Q. That is
    both (2B - A) and (2A - B) should be divisible by 3.
 */

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long testCases;
  cin >> testCases;

  for (long t = 0; t < testCases; t++) {
    long a;
    long b;
    cin >> a >> b;

    if ((a + b) % 3 != 0) {
      cout << "NO" << endl;
      continue;
    }

    if ( (2 * a - b) >= 0 && (2 * a - b) % 3 == 0 && (2 * b - a) >= 0 && (2 * b - a) % 3 == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
