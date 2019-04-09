/*
 * @Author: sunyz
 * @github: https://github.com/sunyz
 * @LastEditors: sunyz
 * @Description: content
 * @Date: 2019-04-10 01:45:49
 * @LastEditTime: 2019-04-10 01:58:12
 */

//  * @Description: 这个就是超级经典算法：牛顿-拉夫逊迭代
//  * 寻找到递推公式迭代即可
//  * FIXME: 实现到一半想不起来了，参考了网上，自己之后再复现一遍
//  * 以及，用适合浮点数的某魔幻数试过，发现某个case会精度差1
 

// 执行用时 : 12 ms, 在Sqrt(x)的C++提交中击败了99.35% 的用户
// 内存消耗 : 8 MB, 在Sqrt(x)的C++提交中击败了0.41% 的用户

class Solution {
public:
    int mySqrt(int x) {
      if (x == 0) return 0;
      double last = 0;
      double res = 1;
      while (res != last)
      {
          last = res;
          res = (res + x / res) / 2;
      }
     return int(res);

    }
};