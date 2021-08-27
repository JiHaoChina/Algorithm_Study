class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size();
        vector<int> height(n, 0);

        for (int i = 0; i < n; ++i)
        {
            // ��¼��ǰ�Ĵ��ڣ������¸߶�
            int l = positions[i][0];
            int h = positions[i][1];
            int r = l + h;
            height[i] += h;

            // ����������ķ��飬����н��棬���ܸ������ǵĸ߶�
            for (int j = i + 1; j < n; ++j)
            {
                int l2 = positions[j][0];
                int r2 = positions[j][1] + l2;
                // �н�����ȡ���߶�ȥ����
                if (l2 < r && r2 > l)
                {
                    height[j] = max(height[j], height[i]);
                }   
            }
        }

        for (int i = 1; i < n; ++i)
        {
            height[i] = max(height[i-1], height[i]);
        }

        return height;
    }
};