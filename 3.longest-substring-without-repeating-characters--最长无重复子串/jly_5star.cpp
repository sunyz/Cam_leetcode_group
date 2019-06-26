/*
把以前看过但没实现的题实现一下
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[128] = {-1};
        memset(hash, -1, 128*sizeof(int));
        //cout << hash[21];
        int left = 0;
        int right = 0;
        int res = 0;
        if (s.size() == 0)
            return 0;
        while(right < s.size()) {
            //cout << right << endl;
            //cout << hash[s[0]] << endl;
            //if (right == 3)
            //    cout << "aaa"<< hash[s[right]] << " " << s[right]<< endl;
            if (hash[s[right]] >= left) {
                left = hash[s[right]] + 1;
                //cout << "here";
            }
            hash[s[right]] = right;
            res = max(res, right - left + 1);
            right++;
            
            //cout << "result" << res << endl;
        }
        return res;
    }
};
