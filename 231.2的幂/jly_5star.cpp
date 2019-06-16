/*
给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
使用左移右移，更好的方法是判断n与n-1相与的结果是否等于0
执行用时 :
4 ms
, 在所有C++提交中击败了
92.33%
的用户
内存消耗 :
8.3 MB
, 在所有C++提交中击败了
5.71%
的用户
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int t = n;
        if (n <= 0)
            return false;
        int count = 0;
        while (t) {
            t = t >> 1;
            count++;
        }
        t = 1 << count-1;
        if (t == n)
            return true;
        else
            return false;
    }
};
