class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        if(n%2==1){
            return false;
        }
        while(!s.empty()){
             bool removed = false;
        for(int i = 0 ; i<n ; i++){
            if((s[i]=='(' && s[i+1]==')')||
            (s[i]=='{'&&s[i+1]=='}')||
            (s[i]=='['&&s[i+1]==']')){
                s.erase(i,2);
                removed = true;
                break;
            }
        }
        if(!removed){
            return false;
        }
        }
       
        return true;
        
    }
};