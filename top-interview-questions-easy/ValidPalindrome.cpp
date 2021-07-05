class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 1) return true;
        int j=0;
        
        for(int i=0;i<s.size();++i)
        {
            if(isalpha(s[i]) || isdigit(s[i]))
            {
                s[j] = tolower(s[i]);
                ++j;
            }
        }
        if(j == 0 || j == 1) return true;
        if(j == 2)
        {
            if(s[0] == s[1]) 
                return true;
            else
                return false;
        }
        s = s.substr(0, j);
        
        return checkFromMid(s, j/2 - ((j & 0x01) ? 0 : 1) , j/2);
    }
private:
    bool checkFromMid(string& s, int l, int r)
    {
        while(l >= 0 && r < s.size() && s[l] == s[r])
        {
            --l;
            ++r;
        }
        return (l<0);
    }
};
