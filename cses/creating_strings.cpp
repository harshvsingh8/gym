/*
Given a string, your task is to generate all different strings that can be
created using its characters.

Input

The only input line has a string of length n. Each character is between a–z.

Output

First print an integer k: the number of strings. Then print k lines: the strings
in alphabetical order.

Constraints
1≤n≤8
Example

Input:
aabac

Output:
20
aaabc
aaacb
aabac
aabca
aacab
aacba
abaac
abaca
abcaa
acaab
acaba
acbaa
baaac
baaca
bacaa
bcaaa
caaab
caaba
cabaa
cbaaa
*/

#include <algorithm>
#include <bitset>
#include <iostream>
#include <list>
#include <set>
#include <vector>
using namespace std;

/*
  
  - It is a variation of the standard permutation generation logic
    where we need to skip the any duplicate generation (as a character
    can appear more than once in the input string).

  - The first cut of implementation can be done assuming all
    characters are unique. Then we need to skip considering next
    occurance of a character for the same chosen position.

  - The code tracks the previously occurred characters in a hash set
    so that it can skip those for the same position, and used a vector
    reference to build up the generation.

  - Note that for permutation generation, every level of recursion
    happens for position in of the generated array. We need to select
    each possible word character one by one, and mark the selections
    so that they can be skipped in the current (descending)
    generations.
 */

void Search(string &word, vector<char> &permutation, vector<bool> &chosen,
            list<string> &results) {
  int wordSize = word.size();

  if (permutation.size() == wordSize) {
    string result(permutation.begin(), permutation.end());
    results.push_back(result);
  } else {
    set<char> usedChars;

    for (int i = 0; i < wordSize; i++) {
      char c = word.at(i);

      if (chosen[i])
        continue;

      // skip char if it is already used for this position
      if (usedChars.find(c) != usedChars.end())
        continue;

      usedChars.insert(c);

      chosen[i] = true;
      permutation.push_back(c);

      Search(word, permutation, chosen, results);

      chosen[i] = false;
      permutation.pop_back();
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string input;
  cin >> input;

  int len = input.size();
  list<string> results;
  vector<char> permutation;
  vector<bool> chosen(len + 1, false);

  // sort chars - as the expected result is in alphabetical order
  sort(input.begin(),
       input.end(),
       [](char c1, char c2) -> bool { return c1 < c2; });

  Search(input, permutation, chosen, results);

  cout << results.size() << endl;

  for (const auto &result : results)
    cout << result << endl;

  return 0;
}
