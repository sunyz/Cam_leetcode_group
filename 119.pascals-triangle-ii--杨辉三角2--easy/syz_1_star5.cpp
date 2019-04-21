/*
 * @Author: sunyz
 * @github: https://github.com/sunyz
 * @LastEditors: sunyz
 * @Description: content
 * @Date: 2019-04-22 01:31:11
 * @LastEditTime: 2019-04-22 01:41:24
 */

//  * @Description: 和杨辉三角1的思路类似，直接套用1的也能直接一样的时间
//  * 不过还是在那个基础上做了简化，省很多空间
//  * 首先去除了函数调用，进行原地操作；
//  * 然后顺序变成倒序，这样不会对变化的产生影响
//  * 然后就是初始化直接初始化成已知数目的1。可以避免已知push_back(1)


// 执行用时 : 8 ms, 在Pascal's Triangle II的C++提交中击败了94.86% 的用户
// 内存消耗 : 8.2 MB, 在Pascal's Triangle II的C++提交中击败了94.86% 的用户


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> eve_row(rowIndex+1, 1);
        for (int i=1; i <= rowIndex; i++) {
            for (int j=i-1; j>0; j--) { //倒序不会对已经变化的产生影响
              eve_row[j] += eve_row[j-1];
            }   
        }
      return eve_row;
    }
};