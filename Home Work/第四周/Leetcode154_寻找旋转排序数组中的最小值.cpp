class Solution {
public:
    //�����е����һ��Ԫ�� X������Сֵ�Ҳ��Ԫ�أ����ǵ�ֵһ����С�ڵ��� X��������Сֵ����Ԫ�أ����ǵ�ֵһ�������ڵ��� X��
    //��ˣ����ǿ��Ը�����һ�����ʣ�ͨ�����ֲ��ҵķ����ҳ���Сֵ��
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


//���뵽�ˣ���������Ȼ��ȡ����Ԫ��
//sort(nums.begin(),nums.end());
//return nums[0];