/*

You are given an array of n integers. You want to modify the array so
that it is increasing, i.e., every element is at least as large as the
previous element.

On each move, you may increase the value of any element by one. What
is the minimum number of moves required?

Input

The first input line contains an integer n: the size of the array.

Then, the second line contains n integers x1,x2,…,xn: the contents of
the array.

Output

Print the minimum number of moves.

Constraints
1≤n≤2⋅105
1≤xi≤109
Example

Input:
5
3 2 5 1 7

Output:
5

*/

#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

/*
  The term "move" is a bit confusing in the problem statement - it
  refers just the amount of increment to match the previous value.

  Here the idea is scan the numbers, and as we see new a new number in
  the input which is less than the just previous one just increase the
  global "turns" by the delta. In all cases, the need to keep track of
  the previous number. Care should be given to handle the very first
  number - which sets the base case.
 */

int main() {
  long n;
  cin >> n;
  long long num;
  long long prevNum = 0;
  long long turns = 0;
 
  for (long i = 0; i < n; i++) {
    cin >> num;
 
    if (prevNum == 0) {
      prevNum = num;
      continue;
    }
 
    if (num < prevNum) {
      long long dt = prevNum - num;
      turns += dt;
    } else {
      prevNum = num;
    }
  }
  cout << turns << endl;
  return 0;
}
