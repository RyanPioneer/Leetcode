/**
 * Source: t.ly/Um6Eu
 * Date: 2023/11/10
 * Skill:
 * Runtime: 91 ms, faster than 98.30% of C++ online submissions
 * Memory Usage: 102.69 MB, less than 24.68% of C++ online submissions
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
#include <functional>
#include <list>


using namespace std;


class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1, total = 0, num = 0;
        for (int i = 1; i <= n; i++) total ^= i;
        for (int i = 1; i < n - 1; i += 2) num ^= encoded[i];
        vector<int> res;
        res.push_back(total ^ num);
        for (int i = 1; i < n; i++) {
            res.push_back(encoded[i - 1] ^ res.back());
        }
        return res;
    }
};


int main() {
    Solution s;
}