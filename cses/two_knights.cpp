/*

Your task is to count for k=1,2,…,n the number of ways two knights can
be placed on a k×k chessboard so that they do not attack each other.

Input

The only input line contains an integer n.

Output

Print n integers: the results.

Constraints
1≤n≤10000
Example

Input:
8

Output:
0
6
28
96
252
550
1056
1848

*/

#include <iostream>
using namespace std;

/*
  - It is easy to stuck in this problem if we could not visualize the
    solution clearly and take a wrong approach (i.e. proceeding to
    directly find the asked value). 

  - On observation, it is clear that it may be easier to find out all
    the positions for which knight attack each other. Exploring all
    those cases in the direct way too would be overwhelming. 

  - Another observation is that a knight attack point is always bound
    in a 3x2 direction. So, it might make sense to find all such
    possible 3x2 blocks in the nxn matrix. In each block, we can have
    2 attacking pair positions. So, number of possible attacking
    positions would be: 2 * number-of-3x2-blocks

  - In nxn matrix, numbers of 3*2 blocks can be found by first laying
    down blocks horizontally and then vertically.

  - Formula for all attacking pairs combinations would be: 2 * (n - 2)
    * (n - 1) + 2 * (n - 1) * (n - 2) => 4 * (n - 1) * (n - 2)
   
  - the number of non-attacking positions = total positions - attacking-position

  - result = (n*n)_C_2 - attacking-positions

  - result = (n*n)(n*n-1)/2 - 4*(i-2)*(i-1)

  - Not need special case when the matrix is two or lesser in size, as
    there would be no attacking position and the above formula would
    take care of it.

 */

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
 
  int input;
  cin >> input;
  for (long long i = 1; i <= input; i++) {
    long long value = (i * i) * (i * i -1)/2 -
      ((i > 2) ? (4 * ((i - 2) * (i - 1))) : 0);
    cout << value << endl;
  }
  return 0;
}
