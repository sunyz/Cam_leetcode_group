/*
 * @Author: sunyz
 * @github: https://github.com/sunyz
 * @LastEditors: sunyz
 * @Description: content
 * @Date: 2019-04-24 23:22:23
 * @LastEditTime: 2019-04-24 23:39:23
 */

//  * @Description: 从下往上和从上往下的结果是一致的
//  * 所以逆向考虑，能省最后一次min操作。。
//  * 然后就是其实只和相邻的前一层有关，能到达当前节点的前一个节点，
//  * 必然是已经是最小的路径
//  * 所以最后规约到顶点自动获得最小的路径和

// 执行用时 : 12 ms, 在Triangle的C++提交中击败了95.98% 的用户
// 内存消耗 : 9.7 MB, 在Triangle的C++提交中击败了82.10% 的用户

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int cnt = triangle.size() - 1;
        if (cnt == 0) return triangle[0][0];
        vector<int> line = triangle[cnt];
        while (cnt > 0) {
            for (int i=0; i<cnt; i++) {
                line[i] = triangle[cnt-1][i] + min(line[i], line[i+1]);
            }
            cnt --;
        }
        return line[0];
    }
};