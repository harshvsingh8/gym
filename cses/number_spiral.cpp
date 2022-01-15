/*

A number spiral is an infinite grid whose upper-left square has number
1. Here are the first five layers of the spiral:

https://cses.fi/file/bba36f2601b99c7edc15865aa2a49e680a271075f30e86aa0e4e18d00a779c21

Your task is to find out the number in row y and column x.

Input

The first input line contains an integer t: the number of tests.

After this, there are t lines, each containing integers y and x.

Output

For each test, print the number in row y and column x.

Constraints
1≤t≤105
1≤y,x≤109
Example

Input:
3
2 3
1 1
4 2

Output:
8
1
15

*/

#include <iostream>
#include <vector>
using namespace std;

/*
  - For every cell (row, col), there exists a contained square - which
    starts from (1,1) and its edge touches the cell.

  - First need to find that contained sqaure and then find the
    remaining running length to reach from to the target cell. 

  - The contained square would be (1,1) top-left to ( max(row, col)-1,
    max(row, col)-1) bottom-right. The base count would be sqaure of
    the side length.

  - The remaining running length calculation from the base square sum
    depends on the even and odd numbering of row and col values. To
    avoid any complexity, one simple approach is to break the next
    step into four cases:
    
    1. base-square-length: even AND cell is touching the vertical side of the square.
    2. base-square-length: even AND cell is touching the horizontal side of the square.
    3. base-square-length: odd AND cell is touching the vertical side of the square.
    4. base-square-length: odd AND cell is touching the horizontal side of the square.

  - Need to be be careful about the boundary calculations and exact summations.  

 */

long CellValue(int rowNum, int colNum)
{
  long containedSqrLen = max(rowNum, colNum) - 1;
  long nextSqrLen = containedSqrLen + 1;
  long baseCount = containedSqrLen * containedSqrLen;
  long value = 0;

  if (containedSqrLen % 2 == 0) {

    // CASE: rowNum 1...nextSqrLen, then colNum nextSqrLen...1
    if (rowNum <= nextSqrLen && colNum == nextSqrLen) {
      value = baseCount + rowNum;
    } else {
      value = baseCount + nextSqrLen + (nextSqrLen - colNum);
    }

  } else {

    // CASE: colNum 1..nextSqrLen, then rowNum nextSqrLen...1
    if (colNum <= nextSqrLen && rowNum == nextSqrLen) {
      value = baseCount + colNum;
    } else {
      value = baseCount + nextSqrLen + (nextSqrLen - rowNum);
    }
  }
  
  return value;
}
 
int main() {
  int tc;
  cin >> tc;
  
  for (int i = 0; i < tc; i++) {
    long rowNum, colNum;
    cin >> colNum;
    cin >> rowNum;
    cout<<CellValue(rowNum, colNum)<<endl;
  }

  return 0;
}
