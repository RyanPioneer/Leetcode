// Source: https://leetcode.com/problems/longest-palindromic-substring/
// Date: 2021/7/10
// Dynamic Programming

#include<iostream>
#include<string>
using namespace std;


static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();