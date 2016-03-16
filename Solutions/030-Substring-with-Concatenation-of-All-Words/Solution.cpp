class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        int words_cnt = words.size(), word_length = words[0].size();
        int words_size = words_cnt * word_length;
        if(s.size() < words_size || s.size() < 1)
            return ret;
        //Notice that:
        // a valid substring must just a concatenation of each word in words exactly once and without any intervening
        // So , for each substring of size words_size in s, we check if there are repeated word or missing word in words,
        //      it's invalid
        map<string,int> wc;
        for(int k = 0; k < words_cnt; k++)
            ++wc[words[k]];
        map<string, int> check;
        int i, j;
        for(i = 0; i <= s.size()-words_size; i++){
            check.clear();
            for(j = 0; j < words_cnt; j++){
                string w = s.substr(i+j*word_length, word_length);
                if(wc.find(w) != wc.end()){
                    ++check[w];
                    // if w occurs more thar wc[w] times, it is a repeated word
                    if(check[w] > wc[w])
                        break;
                }else
                    // this word in not in words, that means at least one word in words is not in this substring
                    break;
            }
            if(j == words_cnt)
                ret.push_back(i);
        }
        return ret;
    }
};
