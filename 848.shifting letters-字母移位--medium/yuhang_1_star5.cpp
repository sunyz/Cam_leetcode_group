// 速度4星，空间5星，从后往前遍历，一边遍历一边取模和相加shift位数
class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int tmp = 0;
        for (int i = S.length() - 1; i >= 0; i--) {
            shifts[i] = (tmp + shifts[i]) % 26;
            tmp = shifts[i];
            S[i] = S[i] > 'z' - tmp ? S[i] - 26 + tmp : S[i] + tmp;
        }
        return S;
    }
};
