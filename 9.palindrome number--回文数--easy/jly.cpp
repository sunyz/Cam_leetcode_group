// 这个会溢出
class Solution {
public:
    int getRev(int x) {
        queue<int> s;
        while (x > 0) {
            int t = x % 10;
            x = x / 10;
            s.push(t);
            //cout << "pushed" << t <<endl;
        }
        int ret = 0;
        while(!s.empty()) {
            int t = s.front();
            
            s.pop();
            ret *= 10;
            ret += t;
            //cout << "ret here:" << ret << endl;
        }
        //cout << ret<<endl;
        return ret;
    }
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int rev = getRev(x);
        if (x == rev)
            return true;
        return false;
    }
};
