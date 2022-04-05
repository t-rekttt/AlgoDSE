class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        
        int cnt[2] = { 0, 0 };
        
        int res = 0;
        
        for (int r = 0; r < nums.size(); r++) {
            ++cnt[nums[r]];
            
            while (cnt[0] > k && l <= r)
                --cnt[nums[l++]];
            
            // cout << l << " " << r << " " << cnt[0] << " " << cnt[1] << '\n';
            
            if (cnt[0] <= k)
                res = max(res, r - l + 1);
        }
        
        return res;
    }
};