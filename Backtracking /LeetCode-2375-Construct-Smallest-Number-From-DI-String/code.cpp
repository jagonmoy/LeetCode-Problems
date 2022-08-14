class Solution {
public:
     
    map <char,int> visit;
    bool check(string& singlePattern,char d) {
        bool found = false ;
        for ( int i = 0 ; i < singlePattern.size() ; i++) {
            if ( singlePattern[i] == d) {
                found = true;
                break ;
            }
        }
        return found;
    }
    void solution(char c,string& pattern,vector<string>& result,int index,string& singlePattern) {
        if (pattern.size()+1 == singlePattern.size()) {
            result.push_back(singlePattern);
            return ;
        }
        for ( char d = '1' ; d <= '9' ; d++) {
            if (pattern[index] == 'I' && c < d && !check(singlePattern,d)) {
                singlePattern += d ;
                solution(d,pattern,result,index+1,singlePattern);
                singlePattern.pop_back();
            }
            else if (pattern[index] == 'D' && c > d && !check(singlePattern,d)) {
                singlePattern += d ;
                solution(d,pattern,result,index+1,singlePattern);
                singlePattern.pop_back();
            }
        }
    }
    
    
    
    string smallestNumber(string pattern) {
        vector<string> result;
        string singlePattern;
       
        int sz = pattern.size();
        for ( char c = '1' ; c <= '9' ; c++) {
            singlePattern = c ;
            solution(c,pattern,result,0,singlePattern);
        }
        string ans = result[0] ;
        for ( int i = 1 ; i < result.size() ; i++) ans = min(ans,result[i]);
        
        return ans ;
    }
};