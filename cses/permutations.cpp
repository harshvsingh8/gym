/*
A permutation of integers 1,2,…,n is called beautiful if there are no
adjacent elements whose difference is 1.

Given n, construct a beautiful permutation if such a permutation
exists.

Input

The only input line contains an integer n.

Output

Print a beautiful permutation of integers 1,2,…,n. If there are
several solutions, you may print any of them. If there are no
solutions, print "NO SOLUTION".

Constraints
1≤n≤106
Example 1

Input:
5

Output:
4 2 5 3 1

Example 2

Input:
3

Output:
NO SOLUTION

*/

#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

/*
  - The problem statement sounds complicated but the solution is very
  simple.
  
  - Arrange the numbers in natural order {1, 2, 3, 4, ... N}. and
  divide them into two (nearly) halves.

  - Generate a permutation by picking alternate numbers from each
    halves.
   
  - "NO SOLUTION" will only be the case when it is possible to divide
    the numbers separate enough.

  - N=1 is a valid solution though.
  
 */

int main() {
  long n;
  cin >> n;
  if (n != 1 && n <= 3) {
    cout << "NO SOLUTION" << endl;
    return 0;
  }

  // initialize two counters, one at the begining and the other from
  // the middle.
  int a = n / 2 + 1;
  int b = 1;
  
  for (int i = 1; i <= n; i++) {

    if (i % 2 != 0) {
      // for all odd positions, pick the value from the first range.
      cout << a << " ";
      a++;
    } else {
      // for the even positions, pick the value from the second range.
      cout << b << " ";
      b++;
    }
  }
  
  return 0;
}
