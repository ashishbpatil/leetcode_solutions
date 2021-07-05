class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        
        unordered_map<char, int> sTemp;
        for(auto c : s)
        {
            sTemp[c]++;
        }
        
        for(auto c: t)
        {
            if(sTemp[c] > 0)
            {
                sTemp[c]--;
            }else{
                return false;
            }
        }
        
        return true;        
    }
};
