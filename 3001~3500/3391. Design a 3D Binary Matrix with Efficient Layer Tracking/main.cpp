/**
 * Source: ibit.ly/LFZFq
 * Date: 2025/1/4
 * Skill:
 * Ref: 
 * Runtime: 99 ms, faster than 85.05% of C++ online submissions
 * Memory Usage: 401.69 MB, less than 22.43% of C++ online submissions
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

#define MK make_pair 

using namespace std;
typedef pair<int, int> PII;


class Matrix3D {
    vector<vector<vector<int> > > matrix; 
    vector<int> sum;
    int n;
public:
    Matrix3D(int n) {
        this->n = n;
        matrix.resize(n, std::vector<std::vector<int> >(n, std::vector<int>(n, 0)));
        sum.resize(n, 0);
    }
    
    void setCell(int x, int y, int z) {
        sum[x] += matrix[x][y][z] == 0;
        matrix[x][y][z] = 1;
    }
    
    void unsetCell(int x, int y, int z) {
        sum[x] -= matrix[x][y][z] == 1;
        matrix[x][y][z] = 0;
    }
    
    int largestMatrix() {
        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = sum[i] >= sum[mx] ? i : mx;
        }
        return mx;
    }
};

/**
 * Your Matrix3D object will be instantiated and called as such:
 * Matrix3D* obj = new Matrix3D(n);
 * obj->setCell(x,y,z);
 * obj->unsetCell(x,y,z);
 * int param_3 = obj->largestMatrix();
 */
