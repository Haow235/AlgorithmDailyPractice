class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        return getSkylineUtil(buildings, 0, buildings.size()-1);
    }
    
private:
    vector<vector<int>> getSkylineUtil(vector<vector<int>>& buildings, int lp, int rp)
    {
        vector<vector<int>> re;
        
        if(lp == rp)
        {
            re.push_back({buildings[lp][0], buildings[lp][2]});
            re.push_back({buildings[lp][1], 0});
            
            return re;
        }
        
        int mid = (lp + rp)/2;
        vector<vector<int>> lre = getSkylineUtil(buildings, lp, mid);
        vector<vector<int>> rre = getSkylineUtil(buildings, mid+1, rp);
        
        return merge(lre, rre);
    }
    
    vector<vector<int>> merge(vector<vector<int>>& lh, vector<vector<int>>& rh)
    {
        int n = lh.size(), m = rh.size();
        int p1 = 0, p2 = 0;
        
        int preh = 0, curlh = 0, currh = 0, cur = 0, curx;
        
        vector<vector<int>> re;
        
        while(p1<n && p2<m)
        {
            if(lh[p1][0] < rh[p2][0])
            {
                curx = lh[p1][0];
                curlh = lh[p1++][1];
            }
            else if(lh[p1][0] > rh[p2][0])
            {
                curx = rh[p2][0];
                currh = rh[p2++][1];
            }
            else
            {
                curx = lh[p1][0];
                curlh = lh[p1++][1];
                currh = rh[p2++][1];
            }
            
            cur = max(curlh, currh);
            
            if(cur != preh)
            {
                preh = cur;
                
                if(!re.empty() && curx == re.back()[0])
                {
                    re[re.size()-1][1] = max(re[re.size()-1][1], cur);
                }
                else
                {
                    re.push_back({curx, cur});
                }
            }
        }
        
        while(p1<n)
        {
            curx = lh[p1][0];
            cur = lh[p1++][1];
                
            if(!re.empty() && curx == re.back()[0])
            {
                re[re.size()-1][1] = max(re[re.size()-1][1], cur);
            }
            else
            {
                re.push_back({curx, cur});
            }
        }
        
        while(p2<m)
        {
            curx = rh[p2][0];
            cur = rh[p2++][1];
                
            if(!re.empty() && curx == re.back()[0])
            {
                re[re.size()-1][1] = max(re[re.size()-1][1], cur);
            }
            else
            {
                re.push_back({curx, cur});
            }
        }
        
        return re;
    }
};
