#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int balls(int n, int p, int k, const string& a, int x, int y){
    vector<int> min_platforms(n);
    for (int i = n - 1; i >= 0; --i){
        if (i + k < n){
            min_platforms[i] = min_platforms[i + k];
        }
        min_platforms[i] += (a[i] == '0');
    }
    int min_cost = INT_MAX;
    for (int i = 0; i <= n - p; ++i){
        int remove_cost = i * y;
        int add_cost = min_platforms[p - 1 + i];
        min_cost = min(min_cost, remove_cost + add_cost * x);
    }
    return min_cost;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, p, k, x, y;
        string a;
        cin >> n >> p >> k;
        cin >> a;
        cin >> x >> y;

        cout << balls(n, p, k, a, x, y) << endl;
    }
    return 0;
}