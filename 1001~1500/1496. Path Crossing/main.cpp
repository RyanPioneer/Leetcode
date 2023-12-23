/**
 * Source: is.gd/YP3wL6
 * Date: 2023/12/23
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 7.08 MB, less than 93.92% of C++ online submissions
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
const long offset = 1e4+1;


class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<long> visited;
        long x = 0, y = 0;
        visited.insert(offset * offset + offset);
        for (auto &p: path) {
            if (p == 'N') y++;
            else if (p == 'S') y--;
            else if (p == 'E') x++;
            else if (p == 'W') x--;
            long hash = (x + offset) * offset + (y + offset);
            if (visited.find(hash) != end(visited)) return true;
            visited.insert(hash);
        }
        return false;
    }
};