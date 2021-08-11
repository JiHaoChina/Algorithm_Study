class Solution {
public:
    string toLowerCase(string s) {
        string new_s ="";
        for(char c:s)
        {
            if('A'<=c && c<='Z')
                c = 'a'+ (c-'A');
            new_s.push_back(c);
        }
        return new_s;
    }
};