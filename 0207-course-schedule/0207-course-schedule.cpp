class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjL(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto it : prerequisites){
            adjL[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i] ==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adjL[node]){
                indegree[it]--;
                if(indegree[it] ==0){
                    q.push(it);
                }
            }
        }
        return (topo.size() == numCourses);
    }
};