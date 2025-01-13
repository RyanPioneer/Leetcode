/**
 * Source: ibit.ly/zeDxw
 * Date: 2025/1/13
 * Skill:
 * Ref:
 * Runtime: 519 ms, faster than 77.10% of C++ online submissions
 * Memory Usage: 352.70 MB, less than 57.25% of C++ online submissions
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


class StatisticsTracker {
    queue<int> q;
    ll total;
    multiset<int> maxHeap; // 最大堆（存儲較小的一半數字）
    multiset<int, greater<>> minHeap; // 最小堆（存儲較大的一半數字
    unordered_map<int, int> freq;
    set<PII> freqSet;
public:
    StatisticsTracker() {
        this->total = 0;
    }
    
    void addNumber(int number) {
        q.push(number);
        total += number;
        freqSet.insert({++freq[number], -number});
        if (freq[number] > 1) {
            freqSet.erase({freq[number] - 1, -number});
        }
        minHeap.insert(number);
        if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.insert(*prev(minHeap.end()));
            minHeap.erase(prev(minHeap.end()));
        } else if (!maxHeap.empty() && number < *prev(maxHeap.end())) {
            int num = *prev(minHeap.end());
            minHeap.erase(prev(minHeap.end()));
            minHeap.insert(*prev(maxHeap.end()));
            maxHeap.erase(prev(maxHeap.end()));
            maxHeap.insert(num);
        }
    }
    
    void removeFirstAddedNumber() {
        int num = q.front();
        q.pop();
        total -= num;
        freqSet.erase({freq[num]--, -num});
        if (freq[num] > 0) {
            freqSet.insert({freq[num], -num});
        }
        if (num >= *prev(minHeap.end())) {
            minHeap.erase(minHeap.find(num));
        } else {
            maxHeap.erase(maxHeap.find(num));
        }
        if (maxHeap.size() + 1 < minHeap.size()) {
            maxHeap.insert(*prev(minHeap.end()));
            minHeap.erase(prev(minHeap.end()));
        } else if (maxHeap.size() > minHeap.size()) {
            minHeap.insert(*prev(maxHeap.end()));
            maxHeap.erase(prev(maxHeap.end()));
        }
    }
    
    int getMean() {
        return total / q.size();
    }
    
    int getMedian() {
        return *prev(minHeap.end());
    }
    
    int getMode() {
        return prev(freqSet.end())->second * -1;
    }
};

/**
 * Your StatisticsTracker object will be instantiated and called as such:
 * StatisticsTracker* obj = new StatisticsTracker();
 * obj->addNumber(number);
 * obj->removeFirstAddedNumber();
 * int param_3 = obj->getMean();
 * int param_4 = obj->getMedian();
 * int param_5 = obj->getMode();
 */
