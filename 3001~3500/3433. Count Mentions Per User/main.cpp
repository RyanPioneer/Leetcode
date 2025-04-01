/**
 * Source: t.ly/dMZ2S
 * Date: 2025/1/27
 * Skill:
 * Ref:
 * Runtime: 21 ms, faster than 88.24% of C++ online submissions
 * Memory Usage: 41.33 MB, less than 100.00% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      
 */


#include <iostream>
#include <sstream>
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


class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(begin(events), end(events), [](const vector<string>& a, const vector<string>& b) {
            if (a[1] == b[1]) {
                return a[0] == "OFFLINE" ? true : false;
            }
            return stoi(a[1]) < stoi(b[1]);
        });

        vector<int> users(numberOfUsers, 1), res(numberOfUsers, 0);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto &event: events) {
            int timestamp = stoi(event[1]);
            while (!pq.empty() && pq.top().first + 60 <= timestamp) {
                users[pq.top().second] = 1;
                pq.pop();
            }

            if (event[0] == "MESSAGE") {
                if (event[2] == "ALL") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        res[i]++;
                    }
                } else if (event[2] == "HERE") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (users[i]) {
                            res[i]++;
                        }
                    }
                } else {
                    istringstream stream(event[2]); // 創建字串流
                    std::string user; // 暫存每次讀取的結果

                    while (stream >> user) {
                        std::string number_part;
                        for (char ch : user) {
                            if (std::isdigit(ch)) {
                                number_part += ch; // 將數字字符添加到結果中
                            }
                        }

                        int number = std::stoi(number_part);
                        res[number]++;
                    }
                }
            } else {
                std::string number_part;
                for (char ch : event[2]) {
                    if (std::isdigit(ch)) {
                        number_part += ch; 
                    }
                }

                int number = std::stoi(number_part);
                users[number] = 0;
                pq.push({timestamp, number});
            }
        }

        return res;
    }
};
