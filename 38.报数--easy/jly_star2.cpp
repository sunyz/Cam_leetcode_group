/*
报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：

1.     1
2.     11
3.     21
4.     1211
5.     111221


1 被读作  "one 1"  ("一个一") , 即 11。
11 被读作 "two 1s" ("两个一"）, 即 21。
21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。

给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。

注意：整数顺序将表示为一个字符串。

 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-and-say
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
执行用时 :
16 ms
, 在所有 C++ 提交中击败了
29.29%
的用户
内存消耗 :
77.4 MB
, 在所有 C++ 提交中击败了
5.03%
的用户
*/
class Solution {
public:
    int n_;
    string countAndSay(int n) {
        n_ = n;
        return func(1, "1");
    }
    
    
    string func(int i, string curr) {
        if (i < n_) {
            string res ="";
            //res.append("1");
            int count = 0;
            char current = curr[0];
            for (auto ch : curr) {
                if (ch == current) {
                    count++;
                } else {
                    //res.append(to_string(count));
                    res = res + to_string(count);
                    res = res + current;
                    //res.append(current);
                    count = 1;
                    current = ch;
                }
                //cout << ch;                
            }
            res = res + to_string(count);
            res = res + current;
            //cout << res;
            return func(i + 1, res);
        } else {
            return curr;
        }
    }
};
