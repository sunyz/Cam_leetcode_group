class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        if (x < 4)
            return 1;
        return bsearch(x, 1, x/2 + 1);
    }
    int bsearch(int target, int start, int end) {
        int mid = (start + end) / 2;
        if (mid == start)
            return mid;
        //double mids = mid * mid;
        int midd = target / mid;
        if (mid < midd)
            return bsearch(target, mid, end);
        else if (mid > midd)
            return bsearch(target, start, mid);
        else
            return mid;
    }
};
