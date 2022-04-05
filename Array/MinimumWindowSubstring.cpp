class Solution {
public:
    const int INF = 1e9 + 7;
    
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        
        int l = 0;
        int r = 0;
        
        int lres, rres;
        
        int res = INF;
        
        for (auto c : t)
            m[c]++;
        
        int c = m.size();
        
        // cout << c << '\n';
        
        while (r < s.size()) {
            m[s[r]]--;
            
            if (m[s[r]] == 0)
                c--;
            
            while (c == 0 && l <= r) {
                // cout << l << " " << r << '\n';
                
                if (r - l + 1 < res) {
                    res = r - l + 1;
                    lres = l;
                    rres = r;
                }
                
                m[s[l]]++;
                
                if (m[s[l]] == 1)
                    c++;
                
                l++;
            }
            
            r++;
        }
        
        // cout << res << '\n';
        
        if (res == INF)
            return "";
        
        return s.substr(lres, rres - lres + 1);
    }
};