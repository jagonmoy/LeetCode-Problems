class Solution {
public:

    int romanToInt(string s) {
        
        map<char,int> value ;
        
        value['I'] = 1 ;
        value['V'] = 5 ;
        value['X'] = 10 ;
        value['L'] = 50 ;
        value['C'] = 100 ;
        value['D'] = 500 ;
        value['M'] = 1000 ;
        
        int i = 0 ;
        int ans = 0 ;
        while(i < s.size()) {
            if ( value[s[i]] < value[s[i+1]]) {
                ans += (value[s[i+1]] - value[s[i]]);
                i += 2 ;
            }
            else {
                ans += value[s[i]];
                i++ ;
            }
        }
        return ans;
    }
};