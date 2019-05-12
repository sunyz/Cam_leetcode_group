/**
syz原来也在刷腾讯精选
*/
class Solution {
public:
    int climbStairs(int n) {
        // fibernaci
        // using formulation should be fastest
        if (n == 1)
            return 1;
        int* f = (int*)malloc(n *sizeof(int));
        f [0] = 1;
        f [1] = 2;
        for (int i = 2; i< n; i++) {
            f[i] = f[i-1] + f[i-2];
        }
        return f[n-1];
    }
};
