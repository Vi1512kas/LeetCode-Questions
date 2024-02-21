class Solution {
public:
    vector<list<int>> graph;
    void addEdge(int s, int e) {
	    graph[s].push_back(e);
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int> ans;
        graph.resize(n);
        for(int i=0;i<p.size();i++){
            addEdge(p[i][1],p[i][0]);
        }
        vector<int> indegree(graph.size(), 0);
	// traveres all neighours and increment the indegree nodes.
	for (int i = 0; i < graph.size(); i++) {
		for (auto neighbour : graph[i]) {
			indegree[neighbour]++;
		}
	}
	// indegree.
	// queue implementation.
	queue<int> q;
	unordered_set<int> vis;
	for (int i = 0; i < indegree.size(); i++) {
		if (indegree[i] == 0) {
			q.push(i);
			vis.insert(i);
		}
	}
	while (!q.empty()) {
		auto temp = q.front();
		q.pop();
		ans.push_back(temp);
		for (auto it : graph[temp]) {
			if (not vis.count(it)) {
				indegree[it]--;
				if (indegree[it] == 0) {
					q.push(it);
					vis.insert(it);
				}
			}
		}

	}
        if(ans.size()==n) return true;
        return false;
    }
};