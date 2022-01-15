/*

Consider an infinite string that consists of all positive integers in
increasing order:

12345678910111213141516171819202122232425...

Your task is to process q queries of the form: what is the digit at
position k in the string?

Input

The first input line has an integer q: the number of queries.

After this, there are q lines that describe the queries. Each line has
an integer k: a 1-indexed position in the string.

Output

For each query, print the corresponding digit.

Constraints
1≤q≤1000
1≤k≤1018
Example

Input:
3
7
19
12

Output:
7
4
1

*/

#include <iostream>
#include <sstream>
using namespace std;

typedef long long ll;

/*
  - We can divide the number line in ranges of d-digit numbers.

  - The number line is like:
  1-digit-numbers...2-digit-numbers...3-digit-numbers...

  - Each sub-range (fixed digit size numbers) - has a starting and ending
  points.

  | Digits | Start | End      | Range Number Count               | Range Size     |
  |--------+-------+----------+----------------------------------+----------------|
  |      1 |  10^0 | 10^1 - 1 | End - Start + 1= 9 (9-1+1)       | 1 * 9 = 9      |
  |      2 |  10^1 | 10^2 - 1 | End - Start + 1= 90 (99-10+1)    | 2 * 90 = 180   |
  |      3 |  10^2 | 10^3 - 1 | End - Start + 1= 900 (999-100+1) | 3 * 900 =2700  |
  |--------+-------+----------+----------------------------------+----------------|

  - We need to take the position index, and keep reducing its size for
    each range size. When it goes below 0, that means the position
    lies in that digit-size number range.

  - Given the position in the range (say n), it is easy to locate the
    number and then the position's digit value.

  - Number = Range-Start + |_ n/digits _|

  - Digit = Number[ n % digit ]

 */


ll power10(ll x) { return x == 0 ? 1 : 10 * power10(x - 1); }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int q;
  cin >> q;

  for (int t = 0; t < q; t++) {
    ll targetPos;
    cin>>targetPos;

    // using targetPos - 1 as it is 1-indexed based position.
    // the following logic is based on 0-based position.
    targetPos -= 1;
    
    for(int digits = 1; digits <= 18; digits++)
      {
        ll start = power10(digits - 1);
        ll end = power10(digits) - 1;
        ll rangeCount = end - start + 1;
        ll rangeSize = digits * rangeCount;

        if(targetPos - rangeSize < 0)
          {
            ll number = start + (targetPos/ digits);
            int index = targetPos % digits;
            cout<<to_string(number)[index]<<endl;
            break;
          }
        else
          {
            targetPos -= rangeSize;
          }
        
      }
  }

  return 0;
}
