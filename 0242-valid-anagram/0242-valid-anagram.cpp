class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        for(int i = 0 ; i<s.length() ; i++){
            if(t.find(s[i])==string::npos){
                return false;
            }
            else{
                t.erase(t.find(s[i]) ,1);
            }
        }
        return true;
    }
}; 