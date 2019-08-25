/*
执行用时 :
8 ms
, 在所有 C++ 提交中击败了
44.06%
的用户
内存消耗 :8.6 MB
, 在所有 C++ 提交中击败了8.57%的用户

要特别注意0，debug de出来的，这题很难一次写对
*/
class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        if (len == 0)
            return 0;
        vector<long long int> nums(len + 1, 0);
        nums[0] = 1;
        nums[1] = 1;
        if(s[0] == '0')
            nums[1] = 0;
        for (int i = 2; i < len + 1; i++) {
            if (s[i - 2] == '1') {
                //cout << "==1" << endl;
                if (s[i - 1] == '0')
                    nums[i] = nums[i - 2];
                else
                    nums[i] = nums[i - 1] + nums[i - 2];
            } else if (s[i - 2] == '2' && (s.c_str()[i - 1] - '0') < 7) {
                //cout << "==2" << endl;
                if (s[i - 1] == '0')
                    nums[i] = nums[i - 2];
                else
                    nums[i] = nums[i - 1] + nums[i - 2];
            } else {
                //cout << atoi(&s[i - 1]) << "--" << s[i-1] << endl;
      //          cout << "!=" << endl;
                if (s[i - 1] == '0')
                    nums[i] = 0;
                else
                    nums[i] = nums[i - 1];
            }
        }
        return nums[len];
        
    }
    #if 0
    int getNum(string&s, int end) {
        if (end == 0)
            return 1;
        int count = getNum(s, end - 1);
        if (s[end - 1] == '1') {
            cout << "here" << endl;
            
        }
    }
    #endif
};
