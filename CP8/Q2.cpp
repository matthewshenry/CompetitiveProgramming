#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> fenwick_tree;
int n;

void update(int idx, int delta){
    while(idx <= n){
        fenwick_tree[idx] += delta;
        idx += idx & -idx;
    }
}

int prefix_sum(int idx){
    int sum = 0;
    while(idx > 0){
        sum += fenwick_tree[idx];
        idx -= idx & -idx;
    }
    return sum;
}

int range_sum(int l, int r){
    return prefix_sum(r) - prefix_sum(l - 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> n >> k;
    fenwick_tree.resize(n + 1, 0);
    vector<int> memory(n + 1, 0);
    while(k--){
        string query;
        cin >> query;
        if(query == "F"){
            int i;
            cin >> i;
            if(memory[i] == 0){
                update(i, 1);
                memory[i] = 1;
            }else{
                update(i, -1);
                memory[i] = 0;
            }
        }else if(query == "C"){
            int l, r;
            cin >> l >> r;
            cout << range_sum(l, r) << '\n';
        }
    }

    return 0;
}
