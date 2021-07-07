#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int>time(n);
        for (int i=0; i<n; i++) {
            time[i] = dist[i]/speed[i];
            if (dist[i]%speed[i] != 0)
                time[i]++;
        }
        sort(time.begin(),time.end());
        for (int i=1; i<n; i++) {
            if (time[i] <= i)
                return i;
        }
        return n;
    }
};