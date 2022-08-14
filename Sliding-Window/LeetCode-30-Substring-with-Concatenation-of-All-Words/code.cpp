class Solution {
public:

    vector<int> findSubstring(string s, vector<string>& words) {        
        map < string,int> wordMap ;
        map < string,int> windowWord;
        int wordLength = words[0].length();
        int wordsCount = words.size();
        int desiredLength = wordLength*wordsCount ;
        int windowLength = 0 ;
        vector <int> result ;
        for ( int i = 0 ; i < wordsCount ; i++) wordMap[words[i]] += 1 ;
        
        for ( int i = 0 ; i < wordLength ; i++) {
            int l = i ;
            windowWord.clear();
            windowLength = 0 ;
            for ( int r = l ; r+wordLength-1 < s.size() ; r += wordLength) {
                string currWord = s.substr(r,wordLength);
                if (!wordMap[currWord]) {
                    windowWord.clear();
                    windowLength = 0 ;
                    l = r+wordLength ;
                }
                else {
                    windowLength += wordLength;
                    windowWord[currWord]++ ;
                    if(windowWord[currWord] > wordMap[currWord]) {
                        string firstWord = s.substr(l,wordLength) ;
                        while(windowWord[currWord] != wordMap[currWord]) {
                            windowWord[firstWord]-- ;
                            windowLength -= wordLength;
                            l += wordLength ;
                            firstWord = s.substr(l,wordLength) ;
                        }
                    }
                    if(windowLength == desiredLength) {
                        result.push_back(l);
                        windowWord[s.substr(l,wordLength)]-- ;
                        windowLength -= wordLength ;
                        l += wordLength ;
                    }
                }    
                
            }
          
        }
        return result;
    }
};