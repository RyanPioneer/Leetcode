/**
 * Source: https://rb.gy/ed7qr
 * Date: 2023/9/19
 * Skill:
 * Runtime: 2 ms, faster than 62.79% of C++ online submissions
 * Memory Usage: 6.21 MB, less than 5.81% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        x1 -= xCenter; x2 -= xCenter;
        y1 -= yCenter; y2 -= yCenter;
        int x = x1 * x2 > 0 ? min(x1 * x1, x2 * x2) : 0;
        int y = y1 * y2 > 0 ? min(y1 * y1, y2 * y2) : 0;
        return x + y <= radius * radius;
    }
};

int main() {

}