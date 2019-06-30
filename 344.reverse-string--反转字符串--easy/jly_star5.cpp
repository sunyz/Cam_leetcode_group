//是的，暴力就够了
class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int start = 0;
        int end = s.size() - 1;
        if (s.size() <= 1)
            return;
        char tmp = s[0];
        while(start < end) {
            s[start] = s[end];
            s[end] = tmp;
            end--;
            start++;
            tmp = s[start];
        }
        //s[end] = tmp;
    }
};
