class Solution {
public:
    bool isPalindrome(string s) {
        int l=0,r=s.length()-1;

        while(l<=r){
            // isalnum returns true if the char is a-z, A-Z, 0-9
            while(l<r && !isalnum(s[l])) l++;
            while(l<r && !isalnum(s[r])) r--;

            if(tolower(s[l])!=tolower(s[r])) return false;

            l++,r--;
        }
        return true;
    }
};