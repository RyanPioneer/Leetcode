#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> >ans;
        int sz = nums.size();
        for (int i=0; i<sz; i++) {
            for (int j=i+1; j<sz; j++) {
                for (int k=j+1; k<sz; k++) {
                    if (nums[i]+nums[j]+nums[k] == 0) {
                        vector<int>temp{nums[i],nums[j],nums[k]};
                        sort(temp.begin(),temp.end());
                        if (find(ans.begin(), ans.end(), temp) == ans.end())
                            ans.push_back(temp);
                    }
                }
            }
        }
        return ans;
    }
};