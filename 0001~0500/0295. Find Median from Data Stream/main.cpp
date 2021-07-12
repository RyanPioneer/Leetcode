/** 
 * Source: https://leetcode.com/problems/find-median-from-data-stream/
 * Date: 2021/7/12
 * Answers within 10^-5 of the actual answer will be accepted.
 * Skill: Max-Heap and Min-Heap
 * Skill: 使用2個Heap，分別是Max-Heap與Min-Heap。2個Heap的大小維持整個輸入整數數量的一半，
 * Max-Heap的最大值為目前一半數量的最大值、Min-Heap的最小值為目前一半數量的最小值。
 * 取Median時，如果2個Heap大小一樣，取2邊Top的平均值；否則取數量較多的Top。
 * 新增數字的時間複雜度為O(logN)、取中位數的時間複雜度為O(1)
 * Priority queue: https://dangerlover9403.pixnet.net/blog/post/197006355-%5B%E6%95%99%E5%AD%B8%5D-priority-queue
 */

#include<iostream>
#include<string>
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
    }
    
    double findMedian() {
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();