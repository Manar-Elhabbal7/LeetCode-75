#define pb push_back

class Solution {
public:
    double dfs(unordered_map<string, vector<pair<string, double>>>& graph,
               const string& current, const string& target,
               unordered_set<string>& visited, double product = 1.0) {
        if (current == target) {
            return product;
        }
        
        visited.insert(current);
        for (const auto& neighbor : graph[current]) {
            if (visited.find(neighbor.first) == visited.end()) {
                double result = dfs(graph, neighbor.first, target, visited,
                                    product * neighbor.second);
                if (result != -1.0) {
                    return result;
                }
            }
        }
        visited.erase(current);
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double w = values[i];
            graph[u].pb({v, w});
            graph[v].pb({u, 1.0 / w});
        }

        vector<double> res;
        for (const auto& query : queries) {
            string a = query[0];
            string b = query[1];

            if (graph.find(a) == graph.end() or graph.find(b) == graph.end()) {
                res.pb(-1.0);
                continue;
            }

            if (a == b) {
                res.pb(1.0);
                continue;
            }

            unordered_set<string> visited;
            double result = dfs(graph, a, b, visited);
            res.pb(result);
        }
        return res;
    }
};
