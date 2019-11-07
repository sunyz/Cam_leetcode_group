给定一个正整数，返回它在 Excel 表中相对应的列名称。

例如，

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/excel-sheet-column-title
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        
        while(n) {
            int rem = n % 26;
            n = n / 26;
            char c = 'A' + rem - 1;
            if (rem == 0) {
                n--;
                c = 'Z';
            }
            string tmp;
            tmp.push_back(c);
            res = tmp + res; 
        }
        return res;
    }
};
