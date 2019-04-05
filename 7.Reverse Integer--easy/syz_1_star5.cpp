/*
 * @Author: aa.sunyongzhe 
 * @Date: 2019-04-01 23:41:23 
 * @Last Modified by: sunyongzhe
 * @Last Modified time: 2019-04-02 00:21:32
 */

//  @Description: emmm讲道理对函数的操作还是不够熟练，一边查语法一边实现的；
//  几个觉得需要注意的点：
//     1. 只考虑输入的数据范围不够，还要考虑输出的范围
//     2. 直接用atoi返回时不行的，如果溢出无法发现，且不会抛出异常
//     3. 所以先用atol返回long，比较之后再决定返回强制int还是0


// 执行用时 : 12 ms, 在Reverse Integer的C++提交中击败了97.78% 的用户
// 内存消耗 : 8 MB, 在Reverse Integer的C++提交中击败了0.67% 的用户 


#include <iostream>
#include <string>
#define MAX_INT 2147483647
#define MIN_INT -2147483648

class Solution {
public:
    int reverse(int x) {
        if (x > MAX_INT || x < MIN_INT) {
            return 0;
        } 
        std::stringstream  ss;
        std::string str_tmp;
        ss << x;
        ss >> str_tmp;
        if (x >= 0) {
            std::string ans_1(str_tmp.rbegin(),str_tmp.rend());
           long k = atol(ans_1.c_str());
            if (k > MAX_INT) {
                return 0;
            } else {
                return (int)k;
            }
        } else {
            std::string str_tmp2 = str_tmp.substr(1,str_tmp.length()-1);
            std::string ans_2(str_tmp2.rbegin(),str_tmp2.rend());
            long k = -atol(ans_2.c_str());
            if (k < MIN_INT) {
                return 0;
            } else {
                return (int)k;
            }
        }

    }
};