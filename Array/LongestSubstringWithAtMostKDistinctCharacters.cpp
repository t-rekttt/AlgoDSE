class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        map<char, int> m;
        
        int l = 0;
        
        int res = 0;
        int c = 0;
        
        for (int r = 0; r < s.size(); r++) {
            if (++m[s[r]] == 1)
                c++;
            
            while (c > k && l <= r) {                
                if (--m[s[l++]] == 0)
                    c--;
            }
            
            // cout << l << " " << r << " " << c << '\n';
            
            if (c <= k)
                res = max(res, r - l + 1);
        }
        
        return res;
    }
};