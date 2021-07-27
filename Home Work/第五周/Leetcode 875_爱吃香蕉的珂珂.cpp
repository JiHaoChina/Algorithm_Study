class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left =1 ,right = pow(10,9);
        while(left < right)
        {
            int mid = left + (right-left)/2;
            if(!possible(piles,h,mid))
                left = mid +1;
            else
                right = mid;
        }

        return left;
    }

    bool possible(vector<int>& piles, int h,int mid)
    {
        int time =0;
        for(int p: piles)
            time += (p-1)/mid +1;
        
        return time<= h;
    }
};