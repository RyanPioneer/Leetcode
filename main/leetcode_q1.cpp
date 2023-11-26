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
#define ll long long
#define MK(X, Y) make_pair(X, Y)
typedef pair<int, int> PII;
typedef pair<char, char> PCC;
ll mod = 1e9+7;
const int MX = 30;


class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = SZ(matrix), n = SZ(matrix[0]), res = 0;
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] > 0) {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }
        }
        for (int i = m - 1; i >= 0; --i) {
            sort(begin(matrix[i]), end(matrix[i]));
            for (int j = 0; j < n; ++j) {
                res = max(res, (n - j) * matrix[i][j]);
            }
        }
        return res;
    }
};