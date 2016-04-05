class Solution {
public:
    int minDistance(string word1, string word2) {
        // Dynamic promramming 
        // Dist[i][j] : the distance required to convert word1[1..i] to word2[1..j] (index base is 1)
        // Dist[i][0] = i
        // Dist[0][j] = j
        // Dist[i][j] = Dist[i-1][j-1] if word1[i] == word2[j]
        // Dist[i][j] = min(Dist[i-1][j-1], Dist[i][j-1], Dist[i-1][j]) + 1 if word1[i] != word2[j]
        int m = word1.length()+1, n = word2.length()+1;
        
        vector<vector<int>> Dist(m, vector<int>(n));
        
        for(int i = 0; i < m; i++) Dist[i][0] = i;
        for(int j = 0; j < n; j++) Dist[0][j] = j;
        
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++){
                if(word1[i-1] == word2[j-1])
                    Dist[i][j] = Dist[i-1][j-1];
                else
                    Dist[i][j] = min(Dist[i-1][j-1], min(Dist[i][j-1], Dist[i-1][j])) + 1;
            }
            
        return Dist[m-1][n-1];
    }
};