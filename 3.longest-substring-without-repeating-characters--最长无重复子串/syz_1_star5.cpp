/*
 * @Author: sunyz
 * @LastEditors: sunyz
 * @Description: content
 * @Date: 2019-04-23 14:29:22
 * @LastEditTime: 2019-04-23 15:17:15
 */

//  * @Description: 核心思想是逐个遍历+用bit判断重复
//  * 遍历时，每次检查的起点是i+ans，是因为要找最大，
//  * 所以每次直接向后遍历，从当前已有的最大值长度开始检查
//  * 用bit判断这里64位int都不够，还好有__int128这个内置的
//  * 所以这种方法及其省空间，但是速度一般了
//  * FIXME: 之后再看看和实现一个速度高的算法

// 执行用时 : 40 ms, 在Longest Substring Without Repeating Characters的C++提交中击败了67.51% 的用户
// 内存消耗 : 8.8 MB, 在Longest Substring Without Repeating Characters的C++提交中击败了99.45% 的用户

class Solution {
public:

bool check_duplicate(char* str, int start, int end)
{
    __int128 dup = 0;
    __int128 base = 1;
    for(int i =start; i<=end ; i++)
    {
        int ch = str[i]-' ';
        if((dup & (base<<ch) )){
            return false;
        }   
        dup |= base<<ch; //将dup的ch位置1
    }
    return true;
}

    int lengthOfLongestSubstring(string s) {
       if (s.size()==0) return 0;
        int ans=1;
       char *str=(char *)s.c_str();
       for (int i=0; i<s.size()-1; i++) {
           int current_cnt=ans;
           for (int j=i+ans; j<s.size();j++) {
               if (check_duplicate(str,i,j)) {
                   current_cnt ++;
               } else {
                   break;
               }
           }
           ans = max(ans, current_cnt);
          // cout << "ans: "<<ans<<endl;;
       }
       return ans;   
    }
};