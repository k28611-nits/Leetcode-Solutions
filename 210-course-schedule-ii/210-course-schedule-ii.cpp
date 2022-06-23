class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> result, indegree(numCourses);
        
        for(auto& prereq : prerequisites)
            graph[prereq[1]].push_back(prereq[0]),
            indegree[prereq[0]]++;
        
        function<void(int)> dfs = [&](int current) { 
            result.push_back(current);            
            indegree[current] = -1; 
            for(auto nextCourse : graph[current])          
                if(--indegree[nextCourse] == 0)     
                    dfs(nextCourse);                
        };
        for(int i = 0; i < numCourses; i++)
            if(indegree[i] == 0) dfs(i);
        if(size(result) == numCourses) return result;
        return {};
    }
};
