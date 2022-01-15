/*

Your task is to divide the numbers 1,2,…,n into two sets of equal sum.

Input

The only input line contains an integer n.

Output

Print "YES", if the division is possible, and "NO" otherwise.

After this, if the division is possible, print an example of how to
create the sets. First, print the number of elements in the first set
followed by the elements themselves in a separate line, and then,
print the second set in a similar way.

Constraints
1≤n≤10^6
Example 1

Input:
7

Output:
YES
4
1 2 4 7
3
3 5 6

Example 2

Input:
6

Output:
NO

*/

#include <algorithm>
#include <bitset>
#include <iostream>
#include <list>
#include <set>
#include <vector>
using namespace std;

/*
  - Obseravation: we can pair numbers from starting and ending
    positions - whose sum would be (n+1). We need to check how many
    such kind of combinations are possible which would divide the set
    into two equal sums.

  - If we have (n+1) sum count even then a division would be
    possible. In this happy path, we have: 12...N =>
    ((1+N),(1+N)),... pairs. This is only possible when r = N%4 eq 0.

  - What about other cases when r = 1, 2 or 3.

  - r=3 can be further divided as 1+2 and 3 - equal sum set, but r=1
    or r=2 cannot be further divided to make equal sums.

  - The following solution handles the two cases (r=0 and 3)
    separately. For r=3, it explicitly adds 1,2 in the begining of the
    first series and 3 in the begining of the other set.
 */

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int input;
  cin >> input;

  int r = input % 4;

  if (r == 0 || r == 3)
    cout << "YES" << endl;
  else {
    cout << "NO" << endl;
    return 0;
  }

  if (r == 0) {
    cout << input / 2 << endl;

    for (int i = 1; i <= input / 2; i += 2) {
      cout << i << " " << (input - i + 1) << " ";
    }

    cout << endl;
    cout << input / 2 << endl;

    for (int i = 2; i <= input / 2; i += 2) {
      cout << i << " " << (input - i + 1) << " ";
    }
    cout << endl;

  } else if (r == 3) {

    cout << (input - 3) / 2 + 2 << endl;
    cout << "1 2 ";

    if (input > 3)
      for (int i = 1; i < input / 2; i += 2) {
        cout << i + 3 << " " << (input - i + 1) << " ";
      }

    cout << endl;
    cout << (input - 3) / 2 + 1 << endl;
    cout << "3 ";

    if (input > 3)
      for (int i = 2; i < input / 2; i += 2) {
        cout << i + 3 << " " << (input - i + 1) << " ";
      }

    cout << endl;
  }

  return 0;
}
