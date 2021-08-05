class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        fa = vector<int>(edges.size()+1, 0);
        for(int i =0 ;i<edges.size();i++)
            fa[i] =i;
        
        for(auto edge : edges)
        {
            int x= edge[0], y =edge[1];
            if(find(x) != find(y))
            {
                unionSet(x,y);
            }
            else
            {
                return edge;
            }
        }

        return {};
    }

    private:
    vector<int> fa;
    void unionSet(int x, int y)
    {
        x = find(x);
        y = find(y);
        if(x!=y)
            fa[x] = y;
    }

    int find(int x)
    {
        if(x == fa[x]) return x;

        return fa[x] = find(fa[x]);
    }
};