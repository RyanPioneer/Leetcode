/**
 * Source: t.ly/MlAX2
 * Date: 2023/9/19
 * Skill:
 * Runtime: 5 ms, faster than 28.34% of C++ online submissions
 * Memory Usage: 6.42 MB, less than 5.81% of C++ online submissions
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
    int consecutiveNumbersSum(int n) {
        int res = 0;
        for (int i = 1; i <= sqrt(2 * n); i++) {
            if ((2 * n - i * i + i) % (2 * i) == 0)
                res++;
        }
        return res;
    }
};

int main() {

}