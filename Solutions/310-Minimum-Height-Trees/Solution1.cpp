class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        // remove leaf node from the graph iteratively   
        // once we remo a leaf node, remove it from node which connects to it
        if(n == 1)
            return {0};
            
        unordered_map<int, set<int>> graph;
        
        // Construct Graph
        for(auto edge : edges){
            graph[edge.first].insert(edge.second);
            graph[edge.second].insert(edge.first);
        }
        // Record leaf nodes
        vector<int> leafs;
        vector<int> new_leafs;
        for(int i = 0; i < n; i++){
            if(graph[i].size() == 1)
                leafs.push_back(i);
        }
        // Remove leaf node, and generate new leaf node
        while(true){
            new_leafs.clear();
            for(auto leaf : leafs){
                for(auto it = graph[leaf].begin(); it != graph[leaf].end(); it++){
                    // remove leaf node from its neighbor node
                    graph[*it].erase(leaf);
                    // check whether the neighbor node is a new leaf node or not
                    if(graph[*it].size() == 1)
                        new_leafs.push_back(*it);
                }
            }
            // if new_leafs is empty, then there is only one node left or two nodes which are connected to each other
            if(new_leafs.size() == 0)
                break;
            leafs = new_leafs;
        }
        

        return leafs;
    }
};
