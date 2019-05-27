/*
 * @Author: sunyz
 * @Date: 2019-05-28 00:05:49
 * @LastEditors: sunyz
 * @LastEditTime: 2019-05-28 00:07:13
 */

//  * @Description: 排序后然后比较
// FIXME(syz): 需要重做
//  * 
//  * 
// 执行用时 : 80 ms, 在Ransom Note的C++提交中击败了18.03% 的用户
// 内存消耗 : 11.1 MB, 在Ransom Note的C++提交中击败了76.00% 的用户

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());
        int last_loc = 0;
        for (int i=0; i<ransomNote.size(); i++) {
            bool flag =  false;
            for (int j=last_loc; j < magazine.size(); j++) {
                if (magazine[j] == ransomNote[i]) {
                    flag = true;
                    last_loc = j+1;
                    break;
                } 
            }
            if (flag == false) return false;
        }
        return true;
    }
};