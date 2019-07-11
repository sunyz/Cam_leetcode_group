/**
执行用时 :
0 ms
, 在所有 C++ 提交中击败了
100.00%
的用户
内存消耗 :
8.7 MB
, 在所有 C++ 提交中击败了
9.61%
的用户
不知道为什么我这是0ms。。。
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        //int **a = (int**)calloc((m+1)*(n+1), sizeof(int));
        std::vector<std::vector<int>> a(m+1, vector<int>(n+1, 0));
        a[0][1] = 1;
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                a[i][j] = a[i-1][j] + a[i][j-1];
            }
        }
        return a[m][n];
    }
};
