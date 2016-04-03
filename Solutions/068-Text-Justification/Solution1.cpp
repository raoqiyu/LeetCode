class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        if(maxWidth < 1)
            return words;
            
        int n_words = words.size();
        int n_space ,evenly_space, extra_space;
        string tmp_s;
        int tmp_len = 0, tmp_cnt=0;
        for(int i = 0; i < n_words; i++){
            if( ((tmp_len + tmp_cnt + words[i].length()) > maxWidth)){
                tmp_s = "";
                n_space = maxWidth - tmp_len;
                if(tmp_cnt == 1){
                    tmp_s += words[i-1];
                    for(int k = 0; k < n_space; k++)
                            tmp_s += " ";
                }else{
                    evenly_space = n_space / (tmp_cnt-1);
                    extra_space = n_space % (tmp_cnt-1);
                    for(int j = i-tmp_cnt; j < i-1; j++){
                        tmp_s += words[j];
                        for(int k = 0; k < evenly_space; k++)
                            tmp_s += " ";
                        if(extra_space-- > 0)
                            tmp_s += " ";
                    }
                    tmp_s += words[i-1];
                }
                ret.push_back(tmp_s);
                tmp_len = words[i].length(); tmp_cnt=1;
            }else{
                tmp_len += words[i].length();
                tmp_cnt++;
            }
        }
        tmp_s = "";
        for(int j = n_words-tmp_cnt; j < n_words; j++){
            tmp_s += words[j];
            if(tmp_s.length() < maxWidth)
                tmp_s += " ";
        }
        n_space = maxWidth - tmp_len - tmp_cnt;
        while(n_space-- > 0) tmp_s += " ";
        ret.push_back(tmp_s);

        return ret;
        
    }
};
