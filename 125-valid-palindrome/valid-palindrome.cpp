#include <bits/stdc++.h>
class Solution {
public:
    bool isPalindrome(string s) {
        string st="";
        for(int i=0;i<s.size();i++){
            char a;
            if(s[i]>='A' && s[i]<='Z'){
                a=tolower(s[i]);
                st+=a;
            }
            else if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
                a=s[i];
                st+=a;
            }
            else{
                continue;
            }
        }
        int n=st.size();
        for(int i=0;i<n/2;i++){
            if(st[i]!=st[n-i-1]){
                return false;
            }
        }
        return true;
    }
};