class segment_tree{
public:
    vector<long long> tree;
    int size;
    segment_tree(int n){
        size = n;
        tree.resize(n * 2, -1e9);
    }
    void update(int pos, long long val){
        for(tree[pos += size] = val; pos > 1; pos >>= 1){
            tree[pos / 2] = max(tree[pos], tree[pos ^ 1]);
        }
    }
    int query(int left, int right){
        long long res = -1e9;
        for(int l = left + size, r = right + size + 1; l < r; l >>= 1, r >>= 1){
            if(l & 1) res = max(res, tree[l++]);
            if(r & 1) res = max(res, tree[--r]);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<pair<int, int>> sortedPairs, filtered;
        for(int i = 0; i < nums1.size(); ++i){
            sortedPairs.push_back({nums1[i], nums2[i]});
        }
        sort(sortedPairs.rbegin(), sortedPairs.rend());
        filtered.push_back(sortedPairs[0]);
        vector<pair<int, int>> temp;
        temp.push_back({sortedPairs[0].second, 0});
        int index = 0;
        for(int i = 0; i < sortedPairs.size(); ++i){
            pair<int, int> last = filtered.back();
            if(last.first >= sortedPairs[i].first && last.second >= sortedPairs[i].second) continue;
            filtered.push_back(sortedPairs[i]);
            temp.push_back({sortedPairs[i].second, ++index});
        }
        sort(temp.begin(), temp.end());
        map<int, vector<int>> valueIndexMap;
        for(auto& x : temp){
            valueIndexMap[x.first].push_back(x.second);
        }
        segment_tree stree(filtered.size());
        int n = filtered.size();
        for(int i = 0; i < queries.size(); ++i){
            queries[i].push_back(i);
            int low = 0, high = n - 1;
            while(low <= high){
                int mid = (low + high) / 2;
                if(filtered[mid].first < queries[i][0]){
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }
            queries[i].push_back(high);
            swap(queries[i][0], queries[i][3]);
            swap(queries[i][1], queries[i][2]);
        }
        sort(queries.begin(), queries.end());
        vector<int> result(queries.size());
        int processed = 0;
        for(int i = 0; i < queries.size(); ++i){
            while(processed <= queries[i][0]){
                int sum = filtered[processed].first + filtered[processed].second;
                int ix = valueIndexMap[filtered[processed].second].back();
                stree.update(ix, sum);
                processed++;
            }
            int threshold = queries[i][2];
            int low = 0, high = n - 1;
            while(low <= high){
                int mid = (low + high) / 2;
                if(temp[mid].first >= threshold){
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }
            result[queries[i][1]] = stree.query(low, n - 1);
        }
        for(int& x : result){
            if(x == -1e9) x = -1;
        }

        return result;
    }
};
