/**
 * Source: jpeg.ly/_yudo
 * Date: 2025/1/16
 * Skill:
 * Ref:
 * Runtime: 3 ms, faster than 98.56% of C++ online submissions
 * Memory Usage: 25.58 MB, less than 80.22% of C++ online submissions
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


const int MX = 100, MAXDIGIT = 7;


class Solution {
public:
    int countPairs(vector<int>& nums) {
        int res = 0, n = nums.size();
        int numArray[MX][MAXDIGIT];
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            for (int j = 0; j < MAXDIGIT; j++) {
                numArray[i][j] = num % 10;
                num /= 10;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int diff1 = -1, diff2 = -1;
                bool check = true;
                for (int k = 0; k < MAXDIGIT; k++) {
                    if (numArray[i][k] != numArray[j][k]) {
                        if (diff1 == -1) {
                            diff1 = k;
                        } else if (diff2 == -1) {
                            diff2 = k;
                        } else {
                            check = false;
                            break;
                        }
                    }
                }
                if (check && (diff1 == -1 || diff2 != -1 && numArray[i][diff1] == numArray[j][diff2] && numArray[i][diff2] == numArray[j][diff1])) {
                    res++;
                }
            }
        }
        return res;
    }
};
