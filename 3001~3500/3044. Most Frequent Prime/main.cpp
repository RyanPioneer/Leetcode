/**
 * Source: is.gd/r9kjdJ
 * Date: 2024/2/24
 * Skill: 如果將所有prime先找出來會TLE, 一個一個確認是否為prime則不會
 * Ref:
 * Runtime: 20 ms, faster than 68.97% of C++ online submissions
 * Memory Usage: 31.06 MB, less than 88.12% of C++ online submissions
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


class Solution {
public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), res = -1, mx = 0;
        int dirs[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
        unordered_map<int, int> cnt;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 8; k++) {
                    int x = i, y = j, num = 0;
                    while (0 <= x && x < m && 0 <= y && y < n) {
                        num = num * 10 + mat[x][y];
                        if (num > 10 && check_is_prime(num)) {
                            cnt[num]++;
                            if (cnt[num] > mx) {
                                mx = cnt[num];
                                res = num;
                            } else if (cnt[num] == mx) {
                                res = max(res, num);
                            }
                        }
                        x += dirs[k][0];
                        y += dirs[k][1];
                    }
                }
            }
        }
        return res;
    }
    bool check_is_prime(int num) {
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
};