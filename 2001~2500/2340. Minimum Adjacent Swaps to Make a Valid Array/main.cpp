/**
 * Source: t.ly/0u1tC
 * Date: 2024/5/29
 * Skill:
 * Ref:
 * Runtime: 60 ms, faster than 53.44% of C++ online submissions
 * Memory Usage: 52.38 MB, less than 22.02% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>
#include <functional>
#include <list>


using namespace std;


#define ll long long
#define SZ(X) ((int)(X).size())
#define For(i, a, b) for (int i = (a); i <= (b); i++)
#define Rep(i, a, b) for (int i = (a); i >= (b); i--)
typedef pair<int, int> PII;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


const int MX = 1e3 + 10;


class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(begin(nums), end(nums));
        int mi = *min_element(begin(nums), end(nums));
        int left, right;
        For(i,0,n-1) {
            if (nums[i] == mi) {
                left = i;
                break;
            }
        }
        Rep(i,n-1,0) {
            if (nums[i] == mx) {
                right = i;
                break;
            }
        }
        return left + (n - 1 - right) - (left > right);
    }
};