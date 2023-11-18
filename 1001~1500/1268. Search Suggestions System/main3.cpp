/**
 * Source: twtr.to/ln4QA
 * Date: 2023/11/18
 * Skill:
 * Runtime: 37 ms, faster than 75.38% of C++ online submissions
 * Memory Usage: 28.85 MB, less than 75.33% of C++ online submissions
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
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        string cur;
        sort(begin(products), end(products));
        for (int i = 0; i < searchWord.length(); i++) {
            vector<string> ans;
            cur.push_back(searchWord[i]);
            auto iter = lower_bound(begin(products), end(products), cur);
            for (int j = 0; j < 3 && iter != end(products); j++, iter = next(iter)) {
                if ((*iter).substr(0, i + 1) != cur) break;
                ans.push_back(*iter);
            }
            res.push_back(ans);
        }
        return res;
    }
};


int main() {
    Solution s;
}