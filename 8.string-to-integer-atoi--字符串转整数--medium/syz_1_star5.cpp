/*
 * @Author: sunyz
 * @Date: 2019-05-18 15:02:23
 * @LastEditors: sunyz
 * @LastEditTime: 2019-05-18 18:14:50
 */


//  * @Description: emmm朴素的哲学思想又一次取得了胜利。。
//  * 先遍历，找最初的数字或者符号，置flag位并保留正负
//  * 并记录第一个的位置
//  * 然后开始遍历数字，用isdigit函数直接判断数字，记录数字的长度
//  * 然后根据起始位置+size构建子字符串（待转换字符串
//  * 然后就可以愉快的用stoi函数了
//  * 注意！！因为可能越界，所以直接用try-catch判断越界情况了
//  * 运行效率美滋滋

// 执行用时 : 4 ms, 在String to Integer (atoi)的C++提交中击败了99.91% 的用户
// 内存消耗 : 8.6 MB, 在String to Integer (atoi)的C++提交中击败了75.82% 的用户

class Solution {
public:
    int myAtoi(string str) {
        if (str.size() == 0) return 0;
        string::iterator it = str.begin();
        int start = 0;
        int size = 1;
        bool flag = false;
        int zhengfu = 1;
        while (it != str.end()) {
            if (!flag) {
                if (*it == ' ') {
                    it ++;
                    start ++;
                    continue;
                } else if (*it == '+') {
                    it ++;
                    flag = true;
                    continue;
                } else if (*it == '-') {
                    it ++;
                    flag = true;
                    zhengfu = -1;
                    continue;
                } else if (isdigit(*it)) {
                    //cout <<*it <<endl;
                    flag = true;
                    it ++;
                    continue;
                } else {
                    return 0;
                }
            } else {
                if (isdigit(*it)) {
                    size ++;
                    //cout <<*it <<endl;
                } else {
                    break;
                }
                it ++;
            }
        }
        string ans=str.substr(start, size);
        int x=0;
        try {
            x = stoi(ans);
        }
        catch (std::invalid_argument&){
		    return 0;
        }
        catch (std::out_of_range&){
            if (zhengfu == 1) 
                return INT_MAX;
            else 
                return INT_MIN;
        }
        return x;
    }
};