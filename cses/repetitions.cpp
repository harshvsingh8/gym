/*

You are given a DNA sequence: a string consisting of characters A, C,
G, and T. Your task is to find the longest repetition in the
sequence. This is a maximum-length substring containing only one type
of character.

Input

The only input line contains a string of n characters.

Output

Print one integer: the length of the longest repetition.

Constraints
1≤n≤106
Example

Input:
ATTCGGGA

Output:
3

*/

#include <bitset>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
  - The technique is to track count of current repeating
    character. Whenever we encounter a different character, check the
    current running count, update the maximum if that is the case, and
    then reset the current character and the count (to 1).
 */

int main() {
  char prevC = 0;
  char c;
 
  int maxReps = 1;
  int currentReps = 1;
 
  cin >> prevC;
 
  while (cin >> c) {
    if (c == prevC) {
      currentReps++;
      maxReps = max(maxReps, currentReps);
    } else {
      currentReps = 1;
    }
 
    prevC = c;
  }
 
  cout << maxReps << endl;
  return 0;
}
