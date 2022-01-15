/*

A Gray code is a list of all 2n bit strings of length n, where any two
successive strings differ in exactly one bit (i.e., their Hamming
distance is one).

Your task is to create a Gray code for a given length n.

Input

The only input line has an integer n.

Output

Print 2n lines that describe the Gray code. You can print any valid
solution.

Constraints
1≤n≤16
Example

Input:
2

Output:
00
01
11
10
*/

#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <list>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
 
typedef long long ll;
 
using namespace std;

/*
  
  - Ref: https://en.wikipedia.org/wiki/Gray_code

  - Ref: https://cp-algorithms.com/algebra/gray-code.html

  - For this problem we can generate any valid Gray code sequence. We
    can recursively build the bit vector and print its value at when
    we reach its end.

  - The trick to generate valid Gray sequence is that any two
    consecutive results we have to make just one bit swap.

 */

void generate(int index, vector<int> &codes) {
  if (index == -1) {
    for (int x : codes) {
      cout << x;
    }
    cout << endl;
    return;
  }

  // Generate valid gray codes for bits 0...(index-1) 
  generate(index - 1, codes);

  // swap the bit value at "index"
  codes[index] = codes[index] == 0 ? 1 : 0;

  // Note that between the previous code generation and the upcoming
  // code generation, there is different of just one bit flag (which
  // happened in the above statement).
  
  // Generate valid gray codes for bits 0...(index-1) 
  generate(index - 1, codes);
  
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
 
  int n;
  cin >> n;
 
  vector<int> codes(n, 0);
  generate(n - 1, codes);
  return 0;
}
