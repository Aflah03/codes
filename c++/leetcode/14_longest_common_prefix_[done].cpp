#include <bits/stdc++.h>
#include <iostream>
using namespace std;
string longestCommonPrefix(vector<string> &strs) {
  int smallest_length = 0;
  for (auto str : strs) {
    if (smallest_length == 0 || str.length() < smallest_length)
      smallest_length = str.length();
  }
  int longest_common_prefix = 0;
  int flag = 0;
  for (int i = 1; i <= smallest_length; i++) {
    for (int j = 0; j < strs.size() - 1; j++) {
      if (strs[j].substr(0, i) != strs[j + 1].substr(0, i))
        {
        flag=1;
        break;
      }

      cout << "this i execouted for "<< i << "times"<<endl;
    }

      if(flag==1)
          break;
    longest_common_prefix++;
  }
  cout << "THe length of longestCommonPrefix: " << longest_common_prefix
       << endl;
  return strs[0].substr(0, longest_common_prefix);
}
int main() {
  vector<string> strs = {"dog","racecar","car"};
  string result = longestCommonPrefix(strs);
  cout << result << endl;
}
