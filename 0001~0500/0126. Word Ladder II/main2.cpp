/**
 * Source: https://leetcode.com/problems/word-ladder-ii/
 * Date: 2021/7/25
 * Skill: BFS + Backtracking
 * Runtime: 12 ms, faster than 79.62% of C++ online submissions
 * Memory Usage: 10 MB, less than 55.18% of C++ online submissions
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
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    vector<string> curPath;
    unordered_set<string> mySet;
    unordered_map<string, vector<string>> myMap;
   
    vector<string> findNeighbor(string str) {
        vector<string> neighbors;
        for (int i = 0; i < str.length(); i++) {
            string oldStr = str;
            for (char j = 'a'; j <= 'z'; j++) {
                oldStr[i] = j;
                if (oldStr != str && mySet.find(oldStr) != mySet.end())
                    neighbors.push_back(oldStr);
            }
        }
        return neighbors;
    }

    void bfs(string beginWord, string endWord, vector<string>& wordList) {
        if (mySet.find(beginWord) != mySet.end()) mySet.erase(beginWord);
        queue<string> myQue;
        unordered_map<string, int> hasEnque;
        myQue.push(beginWord);
        hasEnque[beginWord] = 1;
        while (!myQue.empty()) {
            unordered_set<string> thisLayer;
            for (int i = myQue.size(); i > 0; i--) {
                string cur = myQue.front();
                myQue.pop();
                for (auto j: findNeighbor(cur)) {
                    myMap[cur].push_back(j);
                    if (thisLayer.find(j) == thisLayer.end()) thisLayer.insert(j);
                    if (hasEnque.find(j) == hasEnque.end()) {
                        hasEnque[j] = 1;
                        myQue.push(j);
                    }
                }
            }
            for (auto it = thisLayer.begin(); it != thisLayer.end(); it++) mySet.erase(*it);
        }
    }

    void backtracking(string endWord) {
        string last = curPath.back();
        if (last == endWord) {
            ans.push_back(curPath);
            return;
        } else {
            vector<string> neighbors = myMap[last];
            for (auto i: neighbors) {
                curPath.push_back(i);
                backtracking(endWord);
                curPath.pop_back();
            }
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        mySet = {wordList.begin(), wordList.end()};
        bfs(beginWord, endWord, wordList);
        curPath = {beginWord};
        backtracking(endWord);
        return ans;
    }
};

int main() {
    string s = "hit", t = "cog";
    vector<string> worfList = {"hot","dot","dog","lot","log","cog"};
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
