/**
 * Source: https://rb.gy/a7bbb
 * Date: 2023/9/4
 * Skill:
 * Runtime: 3 ms, faster than 61.20% of C++ online submissions
 * Memory Usage: 7.1 MB, less than 40.80% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= num.length <= 200
 *      num contains only digits.
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;


#define ll long long
class Solution {
    vector<int> res;
public:
    vector<int> splitIntoFibonacci(string num) {
        if (num.length() < 3)
            return res;
        for (int i = 0; i < num.length() - 2; i++) {
            if (num[0] == '0' && i > 0)
                break;
            ll first = stoll(num.substr(0, i + 1));
            if (first >= INT_MAX)
                break;
            res.push_back(first);
            for (int j = i + 1; j < num.length() - 1; j++) {
                if (num[i + 1] == '0' && j > i + 1)
                    break;
                ll second = stoll(num.substr(i + 1, j - i));
                if (second >= INT_MAX)
                    break;
                res.push_back(second);
                if (back_tracking(num, j + 1, first, second))
                    return res;
                res.pop_back();
            }
            res.pop_back();
        }
        return res;
    }
    bool back_tracking(string num, int pos, int first, int second) {
        if ((ll)first + (ll)second >= INT_MAX)
            return false;
        if (pos == num.length())
            return false;
        string s;
        for (int i = pos; i < num.length(); i++) {
            if (num[pos] == '0' && i > pos)
                break;
            s += num[i];
            if (stoll(s) >= INT_MAX)
                break;
            if (stoi(s) == first + second) {
                res.push_back(stoi(s));
                if (i == num.length() - 1)
                    return true;
                else if (back_tracking(num, i + 1, second, stoi(s)))
                    return true;
                res.pop_back();
            }
        }
        return false;
    }
};

//static const auto io_sync_off = []() {
//    // turn off sync
//    std::ios::sync_with_stdio(false);
//    // untie in/out streams
//    std::cin.tie(nullptr);
//    return nullptr;
//}();

int main() {
    Solution s;
    string ss = "1101111";
    vector<int> res = s.splitIntoFibonacci(ss);
    for (auto  i: res)
        cout << i << endl;
}