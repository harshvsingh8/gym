/*

Your task is to calculate the number of trailing zeros in the factorial n!.

For example, 20!=2432902008176640000 and it has 4 trailing zeros.

Input

The only input line has an integer n.

Output

Print the number of trailing zeros in n!.

Constraints
1≤n≤10^9
Example

Input:
20

Output:
4

*/

#include <algorithm>
#include <bitset>
#include <iostream>
#include <list>
#include <set>
#include <vector>
using namespace std;

/*
  - The technique is descibed here: https://brilliant.org/wiki/trailing-number-of-zeros/

  - Observation: only factors of 5 would decide the total number of
    zeros in the final factorial, the matching factors of 2 would be
    abundant so there number won't matter.

  - 0-count = |_ n / 5 _| + |_ n / 5^2 _| + |_ n / 5^3 _| + |_ n / 5^4 _| ...
  
 */

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
 
  long input;
  cin >> input;
 
  long zeroCount = 0;
  long baseVal = 5;
 
  while (baseVal <= input) {
    long x = input / baseVal;
    zeroCount += x;
    baseVal = 5 * baseVal;
  }
 
  cout << zeroCount << endl;
  return 0;
}
