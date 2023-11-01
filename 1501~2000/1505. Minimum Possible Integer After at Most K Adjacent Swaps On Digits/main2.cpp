/**
 * Source: t.ly/AW6EQ
 * Date: 2023/11/1
 * Skill:
 * Runtime: 35 ms, faster than 79.67% of C++ online submissions
 * Memory Usage: 20.04 MB, less than 15.45% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


const int MX = 1e4 * 3 + 1;
typedef pair<int, int> pairs;

class FenwickTree {
public:
    int nums[MX] = {0};
    int sz;

    FenwickTree(int n) {
        sz = n;
    }

    void update(int idx) {
        while (idx <= sz) {
            nums[idx] ++;
            idx += idx & -idx;
        }
    }

    int query_range(int idx) {
        int num = 0;
        while (idx > 0) {
            num += nums[idx];
            idx -= idx & -idx;
        }
        return num;
    }
};

class Solution {
public:
    string minInteger(string num, int k) {
        vector<pairs> nums;
        for (int i = 0; i < num.size(); i++) {
            nums.push_back({num[i] - '0', i});
        }
        sort(nums.begin(), nums.end());
        string res;
        priority_queue<pairs, vector<pairs>, greater<pairs>> pq;
        int used[MX] = {0}, sz = num.length(), cost;
        FenwickTree *tree = new FenwickTree(nums.size() + 1);
        for (int i = 0; i < num.size() && k > 0; i++) {
            while (!pq.empty() && (cost = pq.top().first - tree->query_range(pq.top().first + 1)) <= k) {
                res += to_string(pq.top().second);
                k -= cost;
                used[pq.top().first] = 1;
                tree->update(pq.top().first + 1);
                pq.pop();
            }
            cost = nums[i].second - tree->query_range(nums[i].second + 1);
            if (cost <= k) {
                res += to_string(nums[i].first);
                k -= cost;
                used[nums[i].second] = 1;
                tree->update(nums[i].second + 1);
            } else {
                pq.push({nums[i].second, nums[i].first});
            }
        }
        for (int i = 0; i < sz; i++) {
            if (used[i] == 0) res += num[i];
        }
        return res;
    }
};


int main() {
    Solution s;
}