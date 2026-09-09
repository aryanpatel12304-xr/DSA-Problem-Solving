class Solution {
public:
    bool isSubsequence(string s, string t) {
        int x = s.length();
        int y = t.length();
        int i = 0;
        int j = 0;
        string ans = "";
        while(i<y && j<x ){
            if(t[i]==s[j]){
                ans = t[i];
                j++;
            }
            i++;
        }
      return j==x;
    }
};