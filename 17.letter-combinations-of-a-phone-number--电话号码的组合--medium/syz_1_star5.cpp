/*
 * @Author: sunyz
 * @github: https://github.com/sunyz
 * @LastEditors: sunyz
 * @Description: content
 * @Date: 2019-04-15 00:47:07
 * @LastEditTime: 2019-04-15 01:47:34
 */

//  * @Description: 这个题第一反应肯定是暴力，不合适
//  * 然后的想法是BFS的递归实现，感觉可以，不过会不会复杂了一点
//  * 然后最后想到的是，将每个选择看成是一个很长的二进制数的每一位
//  * 则遍历count，然后字节分析就可以
//  * 这里参考了这个知乎回答，非常优秀
//  * https://www.zhihu.com/question/28867645
//  * 
//  * TODO: 试了一下评论区的hash表+BFS的实现方式，时空基本一样
//  * 所以之后再练练BFS好了

// // 使用的switch初始化
// // 看起来好的原因感觉是因为输入过少，建立hash表的开销反而抵消了查询的优化提升
// 执行用时 : 8 ms, 在Letter Combinations of a Phone Number的C++提交中击败了93.54% 的用户
// 内存消耗 : 8.4 MB, 在Letter Combinations of a Phone Number的C++提交中击败了90.33% 的用户

// // 使用的unordered map 哈希表 初始化，然后字节分析
// 执行用时 : 8 ms, 在Letter Combinations of a Phone Number的C++提交中击败了93.54% 的用户
// 内存消耗 : 8.5 MB, 在Letter Combinations of a Phone Number的C++提交中击败了70.92% 的用户

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.size() == 0) return ans;
        std::vector < std::string > input;
        // unordered_map<char, string> table{
        //     {'0', " "}, {'1',"*"}, {'2', "abc"},
        //     {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
        //     {'6',"mno"}, {'7',"pqrs"},{'8',"tuv"},
        //     {'9',"wxyz"}};
        // for(char w : digits){
        //     input.push_back(table[w]);
        // }
        for(int i=0;i<digits.length();i++){
            switch (digits[i]){
                case '2':input.push_back("abc");break;
                case '3':input.push_back("def");break;
                case '4':input.push_back("ghi");break;
                case '5':input.push_back("jkl");break;
                case '6':input.push_back("mno");break;
                case '7':input.push_back("pqrs");break;
                case '8':input.push_back("tuv");break;
                case '9':input.push_back("wxyz");break;
            }
        }
        int count = 1;
        for (int i=0; i<input.size(); i++) {
            count *= input[i].size();
        }
        string one_ans = "";
        int rem = 0;
        int res = 0;
        for (int i=0; i<count; i++) {
            rem = 0;
            res = i;
            one_ans = "";
            for (auto j = input.rbegin(); j < input.rend(); j++) {
                rem = res % (j->size());
                res = res / (j->size());
                one_ans = (*j)[rem] + one_ans;
            }
            ans.push_back(one_ans);
        }
        return ans;
    }
};

// 评论区的BFS算法
// TODO: 之后再实现一遍
// 执行用时 : 8 ms, 在Letter Combinations of a Phone Number的C++提交中击败了93.54% 的用户
// 内存消耗 : 8.5 MB, 在Letter Combinations of a Phone Number的C++提交中击败了78.28% 的用户
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> table{
            {'0', " "}, {'1',"*"}, {'2', "abc"},
            {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
            {'6',"mno"}, {'7',"pqrs"},{'8',"tuv"},
            {'9',"wxyz"}};  
        vector<string> res;
        if(digits == "") return res;
        func(res, "", digits, table, 0);
        return res;
    }
    
    void func(vector<string> &res, string str, string &digits, unordered_map<char, string> &m, int k){
        if(str.size() == digits.size()){
            res.push_back(str);
            return;
        }
        string tmp = m[digits[k]];
        for(char w : tmp){
            str += w;
            func(res, str, digits, m, k+1);
            str.pop_back();
        }
        return ;
    }
};