/*
Given a string, your task is to reorder its letters in such a way that
it becomes a palindrome (i.e., it reads the same forwards and
backwards).

Input

The only input line has a string of length n consisting of characters A–Z.

Output

Print a palindrome consisting of the characters of the original
string. You may print any valid solution. If there are no solutions,
print "NO SOLUTION".

Constraints
1≤n≤106
Example

Input:
AAAACACBA

Output:
AACABACAA
*/

#include <algorithm>
#include <bitset>
#include <iostream>
#include <list>
#include <set>
#include <vector>
using namespace std;

/*
  - Quick observation tells us that a solution is not possible if we
    have more than one character with odd count. Only one character
    can be present with the odd count - if at all. 

  - If we have an odd count character, then one instance of that would
    go in middle of the output array.

  - Then the rest of the values would be filled up from both ends or
    from the middle way out - that way we will evenly distribute all
    the numbers across the middle point.

  - For the given input range, it make sense to keep the character
    count in a simple array with index 0 re-presenting A and so on for
    all uppercase 26 english characters.
 */

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
 
  string input;
  cin >> input;
 
  vector<int> charCount(26, 0);
 
  for (const auto &c : input) {
    charCount[c - 'A']++;
  }
 
  // accept at max one char at odd count
 
  int oddCharIndex = -1;
  for (int i = 0; i < 26; i++) {
    if (charCount[i] % 2 != 0) {
      if (oddCharIndex != -1) {
        cout << "NO SOLUTION" << endl;
        return 0;
      }
      oddCharIndex = i;
    }
  }
 
  int inputSize = input.size();
 
  if (inputSize % 2 != 0 && oddCharIndex == -1) {
    cout << "NO SOLUTION" << endl;
    return 0;
  }
 
  vector<char> output(inputSize);
 
  // put the middle odd char - if exists at the mid point.
  if (inputSize % 2 != 0) {
    char c = 'A' + oddCharIndex;
    int midPoint = inputSize / 2;
    output[midPoint] = c;
    charCount[oddCharIndex]--;
  }
 
  // put the rest of chars in pairs - in left - right pairs.
  int leftPos = 0;
  int rightPos = inputSize - 1;

  for (int i = 0; i < 26; i++) {
    // lay out each character in the cascaded fashion.
    while (charCount[i] > 0) {
      char c = 'A' + i;
      output[leftPos++] = c;
      output[rightPos--] = c;
      charCount[i] -= 2;
    }
  }
 
  string result(output.begin(), output.end());
  cout << result << endl;
  return 0;
}
