/**
 * Source: is.gd/ehsJae
 * Date: 2023/11/30
 * Skill:
 * Ref:
 * Runtime: 366 ms, faster than 57.32% of C++ online submissions
 * Memory Usage: 15.28 MB, less than 45.32% of C++ online submissions
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
const int MX = 1000;


class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int res = 0, sz = SZ(arr);
        unordered_map<int, int> num2idx, cnt;
        for (int i = 0; i < sz; i++) num2idx[arr[i]] = i;
        for (int i = 0; i < sz - 2; i++) {
            for (int j = i + 1; j < sz - 1; j++) {
                if (num2idx.find(arr[i] + arr[j]) != end(num2idx)) {
                    cnt[j * MX + num2idx[arr[i] + arr[j]]] = max(cnt[j * MX + num2idx[arr[i] + arr[j]]], cnt[i * MX + j] + 1);
                    res = max(res, cnt[j * MX + num2idx[arr[i] + arr[j]]] + 2);
                }
            }
        }
        return res;
    }
};