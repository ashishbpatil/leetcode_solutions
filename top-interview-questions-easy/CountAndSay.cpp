class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
        {
            return "1";
        }
        string val = countAndSay(n-1);
        string ret;
        int count = 1;
        char oldCh = val[0];
        for(int i =1;i<val.size();++i)
        {
            if(oldCh == val[i])
            {
                ++count;
            }else{
                ret.append(to_string(count));
                ret.push_back(oldCh);
                count = 1;
            }
            oldCh = val[i];
        }
        ret.append(to_string(count));
        ret.push_back(oldCh);
        return ret;
    }
};
