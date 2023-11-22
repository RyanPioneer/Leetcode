/**
 * Source: twtr.to/DsVyc
 * Date: 2023/11/22
 * Skill: dp[i]: 以i為所在書架最後一本書，總高度最低值
 * Ref:
 * Runtime: 3 ms, faster than 87.53% of C++ online submissions
 * Memory Usage: 8.64 MB, less than 52.15% of C++ online submissions
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
const int MX = 1e3+2;


class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        books.insert(begin(books), {shelfWidth, 0});
        int n = SZ(books), dp[MX] = {0};
        for (int i = 1; i < n; i++) {
            int height = books[i][1], width = books[i][0];
            dp[i] = dp[i - 1] + height;
            for (int j = i - 1; j >= 0; j--) {
                if (width + books[j][0] > shelfWidth) break;
                width += books[j][0];
                height = max(height, books[j][1]);
                dp[i] = min(dp[i], dp[j - 1] + height);
            }
        }
        return dp[n - 1];
    }
};