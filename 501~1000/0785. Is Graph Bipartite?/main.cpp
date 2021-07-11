// Source: https://leetcode.com/problems/is-graph-bipartite/
// Date: 2021/7/10

#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;

class Solution {
public:
    queue<pair<int,int>>myQue; 
    int color[101];

    bool isBipartite(vector<vector<int>>& graph) {
        fill(color,color+101,-1);
        int num = graph.size();
        for(int i=0; i<num; i++) {
            if(color[i] == -1) {
                myQue.push(make_pair(i,0));
                color[i] = 0;
                while(!myQue.empty()) {
                    int curNode = myQue.front().first;
                    int dis = myQue.front().second;
                    myQue.pop();
                    for(auto j:graph[curNode]) {
                        if(color[j] == -1) {
                            myQue.push(make_pair(j,dis+1));
                            color[j] = (dis+1)%2;
                        } else if(color[j] == color[curNode])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};

/*class Solution {

private:
    vector<int> checked;

public:
    bool isBipartite(vector<vector<int>>& graph) {

        checked = vector<int>(graph.size(), -1);
        for(int i = 0 ; i < graph.size() ; i ++)
            if(checked[i] == -1)
                if(!check(graph, i, 0))
                    return false;
        return true;
    }

private:
    bool check(const vector<vector<int>>& graph, int index, int group){

        if(checked[index] != -1)
            return checked[index] == group;

        checked[index] = group;
        for(int next: graph[index])
            if(!check(graph, next, 1 - group))
                return false;
        return true;
    }
};*/



static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    vector<vector<int>> test = {{1,3},{0,2},{1,3},{0,2}};
    Solution s;
    int ans = s.isBipartite(test);
    for(int i=0; i<4; i++)
        cout<<s.color[i]<<endl;
}