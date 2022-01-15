/*
 
There are n apples with known weights. Your task is to divide the
apples into two groups so that the difference between the weights of
the groups is minimal.
 
Input
 
The first input line has an integer n: the number of apples.
 
The next line has n integers p1,p2,…,pn: the weight of each apple.
 
Output
 
Print one integer: the minimum difference between the weights of the
groups.
 
Constraints
 
1≤n≤20
1≤pi≤10^9
 
Example
 
Input:
5
3 2 7 4 1
 
Output:
1
 
*/
 
#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <list>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;

/*
  
  - One possible solution is to search the whole solution space and
    record the minimum weight difference between the two sets.

  - One way to explore the solution space is to begin with two sets,
    one empty and other full of all apples. And for each recursive
    move either select the next apple from other set and move it to
    the first or just leave it as it, and go to the next apple.
  
  - Improvement: one simplification could be that we do not track
    weight of the two sets, but just track the one (where selected
    apples are kept). The combined weight of that too would provide
    the weight difference as the total weight is known.
 */

void Search(const vector<ll> &weights,
            int pos,
            ll setWeight,
            ll unsetWeight,
            ll &minDiv) {
  if (pos == weights.size()) {
    return;
  }
 
  // With selection
  ll newDiv = abs((setWeight + weights[pos]) - (unsetWeight - weights[pos]));
  minDiv = min(newDiv, minDiv);
 
  Search(weights,
         pos + 1,
         setWeight + weights[pos],
         unsetWeight - weights[pos],
         minDiv);
 
  // Without selection
  Search(weights,
         pos + 1,
         setWeight,
         unsetWeight,
         minDiv);
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
 
  int n;
  cin >> n;
 
  vector<ll> weights(n);
 
  ll totalWeight = 0.0;
  for (int i = 0; i < n; i++) {
    cin >> weights[i];
    totalWeight += weights[i];
  }
 
  ll minDiv = totalWeight;
  Search(weights, 0, 0, totalWeight, minDiv);
  cout << minDiv << endl;
  return 0;
}
