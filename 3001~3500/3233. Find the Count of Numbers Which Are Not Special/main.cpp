/**
 * Source: is.gd/UFp9dO
 * Date: 2025/1/19
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 8.56 MB, less than 80.81% of C++ online submissions
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
const int MX = 31622;
int cnt[MX+1] = {0};

auto init = []{
    for (int i = 2; i <= MX; i++) {
        if (cnt[i] == 0) {
            for (int j = i * i; j <= MX; j += i) {
                cnt[j] = -1;
            }
            cnt[i] = cnt[i-1] + 1;
        } else {
            cnt[i] = cnt[i-1];
        }
    }
    return 0;
}();


class Solution {
public:
    int nonSpecialCount(int l, int r) {
        return r - l + 1 - (cnt[int(sqrt(r))] - cnt[int(sqrt(l-1))]);
    }
};
