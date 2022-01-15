/*

You are given all numbers between 1,2,…,n except one. Your task is to
find the missing number.

Input

The first input line contains an integer n.

The second line contains n−1 numbers. Each number is distinct and
between 1 and n (inclusive).

Output

Print the missing number.

Constraints
2≤n≤2⋅105
Example

Input:
5
2 3 1 5

Output:
4

 */

#include <bitset>
#include <iostream>
#include <vector>
 
using namespace std;

/*
  - Given the size of the range, we need to choose a data-structure
    which is optimized for size and look-up.

  - The technique uses vector<bool> which has a specialized
    implementation to use compact bit form to store booleans.

  - The solution does two passes - first mark all found positions and
    the next checks the un-marked location.

 */
int main() {
  int n;
  cin >> n;
  int c;
  vector<bool> bits(n+1);
  for (int i = 0; i < n - 1; i++) {
    cin >> c;
    bits[c] = true;
  }
 
  for (int i = 1; i <= n; i++) {
    if (!bits[i]) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}
