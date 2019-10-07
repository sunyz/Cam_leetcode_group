正确答案见syz的提交，我没注意要考虑数字，然后悲剧，也不知道可以直接用isalnum这个函数
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        //cout << right << "--";
        while (left < right) {
            while (!isLetter(s[left])) {
                cout << "??";
                left++;
                if (left > s.size()-1)
                    return true;
            }
            //if (left > s.size()-1)
              //  break;
            while (!isLetter(s[right])) {
                right--;
                if (right < 0)
                    return true;
            }
            cout << "here" << left << right;
            if (equal(s[left], s[right])) {
                left++;
                right--;
            } else {
                return false;
            }
        }
        return true;
    }
    bool isLetter(char c) {
        if (c >= 'a' && c <= 'z')
            return true;
        if (c >= 'A' && c <= 'Z')
            return true;
        cout << "ssss" << endl;
        cout << c << endl;
        cout << c - 'A' << endl;
        cout << 'Z' - c << endl;
        return false;
    }
    bool equal(char a, char b) {
        const int dis = 'A' - 'a';
        int diff = a - b;
        if (diff == 0 || diff == dis || diff == -dis)
            return true;
        else
            return false;
    }
};
