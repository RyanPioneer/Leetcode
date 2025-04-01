/**
 * Source: t.ly/SzZ8O
 * Date: 2025/1/27
 * Skill:
 * Ref:
 * Runtime: 75 ms, faster than 46.35% of C++ online submissions
 * Memory Usage: 102.58 MB, less than 93.26% of C++ online submissions
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


class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int numOfChange = 0, head = 0, sz = colors.size();
        while (head < k-1) {
            if (colors[head] != colors[head+1]) {
                numOfChange++;
            }
            head++;
        }
        int res = numOfChange == k-1 ? 1 : 0;

        for (int i = 0; i < sz-1; i++) {
            if (colors[head] != colors[(head+1) % sz]) {
                numOfChange++;
            }
            int tail = (sz + head - k + 1) % sz;
            if (colors[tail] != colors[(tail + 1) % sz]) {
                numOfChange--;
            }
            head = (head+1) % sz;
            res += numOfChange == k-1 ? 1 : 0;
        }
        return res;
    }
};
