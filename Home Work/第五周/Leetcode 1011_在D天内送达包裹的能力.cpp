class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        //找到一个K,然后按照K进行是否可行的判断
		//左边界而言，由于我们不能「拆分」一个包裹，因此船的运载能力不能小于所有包裹中最重的那个的重量，
		//即左边界为数组 \textit{weights}weights 中元素的最大值。
        int left = *max_element(weights.begin(), weights.end()) ;
		
		//右边界而言，船的运载能力也不会大于所有包裹的重量之和，即右边界为数组 \textit{weights}weights 中元素的和。
        int right = accumulate(weights.begin(), weights.end(),0);
        while(left < right)
        {
            int mid = (left+right)/2;
            if(!possible(weights,days,mid))
                left = mid+1;
            else
                right = mid;
        }

        return left;
    }

    bool possible(vector<int>& weights, int days ,int mid)
    {
        int need =1 ,cur =0;
        for(int w:weights)
        {
            if(cur+ w > mid)
            {
                ++need;
                cur = 0;
            }
            cur += w;
        }
        return need<= days;
    }
};