class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for(const auto& prereq : prerequisites){
            int a = prereq[0];
            int b = prereq[1];
            graph[b].push_back(a);
            indegree[a]++;
        }
        queue<int> zeroIndegreeQ;
        for(int i = 0; i < numCourses; ++i){
            if (indegree[i] == 0){
                zeroIndegreeQ.push(i);
            }
        }
        vector<int> order;
        while(!zeroIndegreeQ.empty()){
            int course = zeroIndegreeQ.front();
            zeroIndegreeQ.pop();
            order.push_back(course);
            for(int nextCourse : graph[course]){
                indegree[nextCourse]--;
                if (indegree[nextCourse] == 0){
                    zeroIndegreeQ.push(nextCourse);
                }
            }
        }
        if(order.size() == numCourses){
            return order;
        }else{
            return {};
        }
    }
};