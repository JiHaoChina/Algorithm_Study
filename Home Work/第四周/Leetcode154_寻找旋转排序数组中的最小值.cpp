class Solution {
public:
    //数组中的最后一个元素 X：在最小值右侧的元素，它们的值一定都小于等于 X；而在最小值左侧的元素，它们的值一定都大于等于 X。
    //因此，我们可以根据这一条性质，通过二分查找的方法找出最小值。
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;

        while(low < high)
        {
            int mid = (low+high)>>1;

            if(nums[mid]< nums[high])
            {
                high = mid;
            }
            else if(nums[mid]>nums[high])
            {
                low = mid+1;
            }
            else
            {
                high = high-1;
            }
        }

        return nums[low];
    }

};


//还想到了，重新排序，然后取首先元素
//sort(nums.begin(),nums.end());
//return nums[0];