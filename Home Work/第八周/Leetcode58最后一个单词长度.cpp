class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size()-1;
        while(len>=0 && s[len]==' ') len--;
        if(len<0) return 0;
        int end = len;
        while(end>=0 && s[end]!=' ') end--;
        
        return len - end;
    }
};