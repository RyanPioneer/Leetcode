/**
 * Source: is.gd/qOYE6r
 * Date: 2024/4/14
 * Skill:
 * Ref:
 * Runtime: 277 ms, faster than 89.63% of C++ online submissions
 * Memory Usage: 132.50 MB, less than 97.63% of C++ online submissions
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
typedef pair<int, int> PII;


class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> nums(n, -1), father(n);

        iota(begin(father), end(father), 0);

        function<int(int)> findFather = [&](int i) {
            if (father[i] != i) father[i] = findFather(father[i]);
            return father[i];
        };

        function<void(int, int, int)> makeUnion = [&](int a, int b, int num) {
            int fatherA = findFather(a), fatherB = findFather(b);
            nums[fatherA] &= num;
            if (fatherA != fatherB) {
                nums[fatherA] &= nums[fatherB];
                father[fatherB] = fatherA;
            }
        };

        for (auto &e: edges) {
            makeUnion(e[0], e[1], e[2]);
        }

        vector<int> res;
        for (auto &q: query) {
            if (findFather(q[0]) != findFather(q[1])) res.push_back(-1);
            else res.push_back(nums[findFather(q[0])]);
        }
        return res;
    }
};