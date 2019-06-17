/*
 * @Author: litao 
 * @LastEditors: litao 
 * @Description: content
 * @Date: 2019-06-17 13:29:22
 * @LastEditTime: 2019-06-17 13:29:34
 */


// * @descriptin: 
// * 遍历字符串，
// * 遍历过程中，
// * 1. 搜索当前字符是否在当前搜索范围中出现，若出现则将左边界修改为当前左边界加1 
// * 2. 若未出现则建立新的map对
// * 3. 字符串长度为有边界减去左边界。

// 执行用时 : 40 ms , 在所有C++提交中击败了 50.69% 的用户
// 内存消耗 : 11 MB , 在所有C++提交中击败了 77.14% 的用户

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int lengthOfLongestSubstring(string s) {
  int max = 0;
  int left = 0;
  int length = 0;
  map<char, int> char_num;
  for (int j = left; j < s.size(); j++) {
    auto item = char_num.find(s[j]);
    if (item == char_num.end() || item->second < left) {
      length = j - left + 1;
    } else {
      left = item->second + 1 ;
    }
    char_num[s[j]] = j;
    if (length > max ) {
      max = length;
    }
  }
  return max;    
}

int main() {
  std::string str;
  cin >> str;
  int max = lengthOfLongestSubstring(str);
  std::cout << max << endl;
}
