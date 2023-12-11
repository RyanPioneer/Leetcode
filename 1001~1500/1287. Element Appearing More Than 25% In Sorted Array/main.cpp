/**
 * Source: jpeg.ly/b30yF
 * Date: 2023/12/11
 * Skill:
 * Ref:
 * Runtime: 8 ms, faster than 78.76% of C++ online submissions
 * Memory Usage: 12.66 MB, less than 92.26% of C++ online submissions
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


#define SZ(X) ((int)(X).size())


class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int len = arr.size();
        for (int i = 0; i <= len * 3 / 4; i++) {
            if (arr[i] == arr[i + len / 4]) {
                return arr[i];
            }
        }
        return arr[0];
    }
};