class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int num =1;
        for(int i = digits.size()-1; i>=0;i--)
        {
            if(digits[i]+num>9)
            {
                digits[i] = (digits[i]+num)%10;
                if(i == 0)
                {
                    vector<int> newarray;
                    newarray.push_back(1);
                    for(int j=0;j<digits.size();j++)
                    {
                        newarray.push_back(digits[j]);
                    }
                    digits = newarray;
                }
                num = 1;
            }
            else
            {
                digits[i] = digits[i]+num;
                num = 0;
            }
        }
        return digits;
    }
};