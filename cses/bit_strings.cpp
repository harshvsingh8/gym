/*

Your task is to calculate the number of bit strings of length n.

For example, if n=3, the correct answer is 8, because the possible bit
strings are 000, 001, 010, 011, 100, 101, 110, and 111.

Input

The only input line has an integer n.

Output

Print the result modulo 10^9 + 7.

Constraints
1≤n≤10^6
Example

Input:
3

Output:
8
*/

#include <algorithm>
#include <bitset>
#include <iostream>
#include <list>
#include <set>
#include <vector>
using namespace std;

/*
  - The problem to handle larger value of n, as those number of bits
    cannot be fit in any integer type.

  - Given we only need to return the modulo value; one option is to
    carry forward only the modulo of the bit-value in each step. 
    
  - The desired value is 2^N, but that cannot fit into any integer
    type (for the allowed range of N). 

  - Observation: we can only carry forward the remainder in the next
    step as the next value, that is its multiple of two divided by the
    same modulo wound not depend on the rest of the higher value
    digits (so the can be safely ignored).
*/

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
 
  long input;
  cin >> input;
 
  long long bitValue = 1;
  long long modValue = 1000000007;
 
  for (long i = 0; i < input; i++) {
    bitValue = 2 * bitValue;
    bitValue %= modValue;
  }
 
  cout << bitValue << endl;
  return 0;
}
