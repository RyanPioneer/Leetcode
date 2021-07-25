/** 
 * Source: https://leetcode.com/problems/word-ladder-ii/
 * Date: 2021/7/24
 * Skill: BFS
 * ! Runtime: Time Limit Exceeded
 * Memory Usage: 
 * Time complexity:
 * Space complexity: 
 * Constraints: 
 *      1 <= beginWord.length, endWord.length <= 5
 *      1 <= wordList.length <= 1000
 *      beginWord, endWord, and wordList[i] consist of lowercase English letters.
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return {};
        vector<vector<string>> ans;
        queue<vector<string>> myQue;
        myQue.push({beginWord});
        int finish = 0;
        while (!finish && !myQue.empty()) {
            int sz = myQue.size();
            for (int i = 1; i <= sz; i++) {
                vector<string> cur = myQue.front();
                myQue.pop();
                string last = cur.back();
                for (auto i: wordList) {
                    if (find(cur.begin(), cur.end(), i) == cur.end() && diff(last,i) == 1) {
                        vector<string> next = cur;
                        next.push_back(i);
                        if (i == endWord) {
                            finish = 1;
                            ans.push_back(next);
                        } else {
                            myQue.push(next);
                        }
                    }
                }
            }
        }
        return ans;
    }

    int diff(string a, string b) {
        int ans = 0;
        for (int i = 0; i < a.length(); i++)
            if (a[i] != b[i]) ans++;
        return ans;
    }
};

int main() {
    string s = "hit", t = "cog";
    vector<string> worfList = {"hot","dot","dog","lot","log"};
    Solution sol;
    vector<vector<string>> ans = sol.findLadders(s,t,worfList);
    for (auto i: ans) {
        for (auto j: i) cout<<j<<' ';
        cout<<endl;
    }
}

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();