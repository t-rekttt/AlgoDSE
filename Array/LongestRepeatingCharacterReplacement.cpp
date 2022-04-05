class Solution {
public:
    int characterReplacement(string s, int k) {
        int sum = 0;
        
        unordered_map<char, int> m;
        
        int l = 0;
        int r = 0;
        int res = 0;
        
        while (r < s.size()) {            
            int maxx =  0;
            
            for (auto &item : m)
                maxx = max(item.second, maxx);
            
            // cout << l << " " << r << " " << maxx << " " << (r - l - maxx) << '\n';
            
            if ((r - l - maxx) <= k) {
                res = max(res, r - l);
                ++m[s[r++]];
            } else if (l <= r) {
                --m[s[l++]];
            }
        }
        
        int maxx =  0;
            
        for (auto &item : m) {
            // cout << item.first << " " << item.second << '\n';
            maxx = max(item.second, maxx);
        }
        
        // cout << l << " " << r << " " << maxx << " " << (r - l - maxx) << '\n';
        
        if ((r - l - maxx) <= k)
            res = max(res, r - l);
        
        return res;
    }
};