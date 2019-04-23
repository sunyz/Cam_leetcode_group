// 神仙解法
// k和i的跳动构造的有点厉害
// i=k+1这句，表示只要遇到了重复的，上一个i所对应的最大长度已经确定了，要想找最大，则
// 要从k+1开始往后找

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int  size,i=0,j,k,max=0;
        size = s.size();
        for(j = 0;j<size;j++){
            for(k = i;k<j;k++)
                if(s[k]==s[j]){
                    i = k+1;
                    break;
                }
            if(j-i+1 > max)
                max = j-i+1;
        }
        return max;
    }
};