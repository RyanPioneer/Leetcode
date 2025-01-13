/**
 * Source: ibit.ly/3FFzn
 * Date: 2025/1/13
 * Skill:
 * Ref:
 * Runtime: 368 ms, faster than 41.96% of C++ online submissions
 * Memory Usage: 389.40 MB, less than 26.79% of C++ online submissions
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
typedef pair<int, int> PII;


class TaskManager {
    set<PII> tasks;
    unordered_map<int, int> taskToUserId, taskToPriority;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            add(t[0], t[1], t[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskToUserId[taskId] = userId;
        taskToPriority[taskId] = priority;
        tasks.insert({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        tasks.erase({taskToPriority[taskId], taskId});
        taskToPriority[taskId] = newPriority;
        tasks.insert({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        tasks.erase({taskToPriority[taskId], taskId});
    }
    
    int execTop() {
        if (tasks.empty()) return -1;
        auto it = prev(tasks.end());
        int userId = taskToUserId[it->second];
        rmv(it->second);
        return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
