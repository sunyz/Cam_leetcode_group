/*
 * @Author: sunyz
 * @github: https://github.com/sunyz
 * @LastEditors: sunyz
 * @Date: 2019-05-06 00:29:49
 * @LastEditTime: 2019-05-06 00:31:30
 */

//  * @Description: 就是一个找规律题。。。
//  * 一个tricky的地方：
//  * 能被2^N整除（N >= 1），则a的二进制表示中，低N位全为0，因此：
//  * (a %  2)  <==> (a &  1)  
// (a %  4)  <==> (a &  3)  
// (a %  8)  <==> (a &  7)  
// (a % 16)  <==> (a & 15)  <==> (a & ((1 << 4) - 1))  


// 执行用时 : 4 ms, 在Nim Game的C++提交中击败了97.21% 的用户
// 内存消耗 : 8.2 MB, 在Nim Game的C++提交中击败了5.69% 的用户

class Solution {
public:
    bool canWinNim(int n) {
        return n&3;
    }
};
