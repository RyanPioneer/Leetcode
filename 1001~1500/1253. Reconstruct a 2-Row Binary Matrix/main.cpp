/**
 * Source: ibit.ly/4oI2M
 * Date: 2023/11/17
 * Skill:
 * Runtime: 35 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 62.86 MB, less than 13.50% of C++ online submissions
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
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int sz = colsum.size();
        vector<vector<int>> res(2, vector<int>(sz, 0)), empty;
        for (int i = 0; i < sz; i++) {
            int num = colsum[i];
            if (num == 2 && (upper == 0 || lower == 0)) return empty;
            if (num == 1 && (upper == 0 && lower == 0)) return empty;
            if (upper >= lower) {
                res[0][i]++;
                upper--;
                if (num == 2) {
                    res[1][num]++;
                    lower--;
                }
            } else {
                res[1][i]++;
                lower--;
                if (num == 2) {
                    res[0][i]++;
                    upper--;
                }
            }
        }
        return upper + lower == 0 ? res : empty;
    }
};


int main() {
    Solution s;
}