/*
 * @Author: sunyz
 * @LastEditors: sunyz
 * @Description: content
 * @Date: 2019-05-02 23:24:33
 * @LastEditTime: 2019-05-03 00:03:45
 */

//  * @Description: emmm
//  * 变成数学问题了
//  * 向下或者向右走的总步数是一定的，一共m+n-2次
//  * 其中m-1次向右， n-1次向下
//  * 所以计算C(m+n-2, m-1)即可
//  * 没错我开心的按照上面的思路实现了。。。
//  * 然后炸了。。。
//  * 因为会溢出
//  * 所以还是老老实实动态规划
//  * dp : f(m,n) = f(m-1, n) + f(m, n-1);
//  * 很标准的解法
//  * 但是看了答案中快的那些，能直接这样声明动态规模的二维数组了？？？？
//  * 用vector可以更加谨慎一点


// 执行用时 : 8 ms, 在Unique Paths的C++提交中击败了86.74% 的用户
// 内存消耗 : 8.6 MB, 在Unique Paths的C++提交中击败了24.05% 的用户

class Solution {
public:
    int uniquePaths(int m, int n) {
        //vector<vector<int> > step(m,vector<int>(n));
        int step[m][n]; //存疑，为啥可以这么生命数组了。。emmm
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (i == 0 || j == 0) {
                    step[i][j] = 1;
                } else {
                    step[i][j] = step[i][j-1] + step[i-1][j]; 
                }
            }
        }
        return step[m-1][n-1];
    }
};


class Solution {
public:
    int uniquePaths(int m, int n) {
        long long tmp1 = 1;
        long long tmp2 = 1;
        for (int i=1; i<=m-1; i++) {
            tmp1 *= i;
        }
        for (int i=n; i<=m+n-2; i++) {
            tmp2 *= i;
        }
        return (int)tmp2 / tmp1;
    }
};