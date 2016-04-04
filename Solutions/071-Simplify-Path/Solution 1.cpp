class Solution {
public:
    string simplifyPath(string path) {
        string ret = "";
        vector<string> dirs;
        
        string dir_curr = "/";
        for(auto p : path){
            if(p == '/'){
                if(dir_curr == "/")
                    continue;
                if(dir_curr == "/.."){
                    if(! dirs.empty())
                        dirs.pop_back();
                }else if(dir_curr != "/.")
                    dirs.push_back(dir_curr);
                dir_curr = p;
            }else
                dir_curr += p;
        }
        if(dir_curr == "/.."){
            if(!dirs.empty())
                dirs.pop_back();
        }else if(dir_curr != "/" && dir_curr != "/.")
            dirs.push_back(dir_curr);
            
        if(dirs.empty()) return "/";
        for(auto d : dirs)
            ret += d;
        return ret;
    }
};
