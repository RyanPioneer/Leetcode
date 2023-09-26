/**
 * Source: t.ly/qlhUJ
 * Date: 2023/9/24
 * Skill:
 * Runtime: 41 ms, faster than 96.28% of C++ online submissions
 * Memory Usage: 21.50 MB, less than 13.18% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class ExamRoom {
    int n;
    map<int, int> idx2space;
    priority_queue<pairs> pq;
public:
    ExamRoom(int n) {
        this->n = n;
        this->idx2space[-1] = n;
        this->pq.push({n - 1 , 1});
    }

    int seat() {
        int idx, space, space2;
        do {
            idx = this->pq.top().second * -1; space = this->pq.top().first;
            this->pq.pop();
//            cout << idx << " " << space << endl;
            if (this->idx2space.find(idx) != end(this->idx2space))
                space2 = idx + this->idx2space[idx] == this->n - 1 ? this->idx2space[idx] - 1 : this->idx2space[idx] / 2 + this->idx2space[idx] % 2;
        } while (this->idx2space.find(idx) == end(this->idx2space) || space2 != space
                 || this->idx2space.find(idx + 1) != end(this->idx2space));
        space = this->idx2space[idx];
        if (idx == -1) {
            this->idx2space[0] = space - 1;
            this->idx2space[-1] = 0;
            if (idx + space == this->n - 1)
                this->pq.push({this->n - 2, 0});
            else
                this->pq.push({this->idx2space[0] / 2 + this->idx2space[0] % 2, 0});
            return 0;
        }
        if (idx + space == this->n - 1) {
            this->idx2space[idx] = space - 1;
            this->idx2space[this->n - 1] = 0;
            this->pq.push({this->idx2space[idx] / 2 + this->idx2space[idx] % 2, -idx});
            return this->n - 1;
        }
        int next_pos = idx + space / 2 + space % 2;
        this->idx2space[idx] = next_pos - idx - 1;
        this->idx2space[next_pos] = idx + space - next_pos;
        this->pq.push({this->idx2space[idx] / 2 + this->idx2space[idx] % 2, -idx});
        this->pq.push({this->idx2space[next_pos] / 2 + this->idx2space[next_pos] % 2, -next_pos});
//        cout << next_pos << endl;
        return next_pos;
    }

    void leave(int p) {
        int space = this->idx2space[p] + 1, space2;
        this->idx2space.erase(p);
        int prev_pos = prev(this->idx2space.lower_bound(p))->first;
        this->idx2space[prev_pos] += space;
        if (prev_pos == prev(end(this->idx2space))->first)
            space2 = this->idx2space[prev_pos] - 1;
        else
            space2 = this->idx2space[prev_pos] / 2 + this->idx2space[prev_pos] % 2;
        this->pq.push({space2, -prev_pos});
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */


int main() {
    ExamRoom* obj = new ExamRoom(8);
    for (int i = 0; i < 3; i++) {
        int res = obj->seat();
        cout << res << endl;
    }
    obj->leave(0);
    obj->leave(4);
    for (int i = 0; i < 9; i++) {
        int res = obj->seat();
        cout << res << endl;
    }
    obj->leave(0);
    obj->leave(4);
    for (int i = 0; i < 2; i++) {
        int res = obj->seat();
        cout << res << endl;
    }
    obj->leave(7);
    for (int i = 0; i < 1; i++) {
        int res = obj->seat();
        cout << res << endl;
    }
    obj->leave(3);
    for (int i = 0; i < 1; i++) {
        int res = obj->seat();
        cout << res << endl;
    }
    obj->leave(3);
    for (int i = 0; i < 1; i++) {
        int res = obj->seat();
        cout << res << endl;
    }
    obj->leave(9);
    for (int i = 0; i < 1; i++) {
        int res = obj->seat();
        cout << res << endl;
    }
//    Solution s;
    vector<vector<int>> arr1{{5, 3},
                             {2, 5},
                             {7, 4},
                             {10, 3}};
    vector<vector<int>> arr2{{0, 1},
                             {2, 2},
                             {1, 4}};
    string word = "aaabccccacacacaabcbaaabacbbbcabcbcaacbabccbababcabaacaacbbcbaabc";
}