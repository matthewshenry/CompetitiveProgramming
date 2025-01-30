#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<long long> fenwick_tree;
int n;

void update(int idx, long long change){
    idx++;
    while(idx <= n){
        fenwick_tree[idx] += change;
        idx += idx & -idx;
    }
}

long long prefix_sum(int idx){
    idx++;
    long long sum = 0;
    while(idx > 0){
        sum += fenwick_tree[idx];
        idx -= idx & -idx;
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> n >> q;
    fenwick_tree.resize(n + 1, 0);
    string operation;
    int i;
    long long change;
    while(q--){
        cin >> operation;
        if(operation == "+"){
            cin >> i >> change;
            update(i, change);
        }else if(operation == "?"){
            cin >> i;
            cout << prefix_sum(i - 1) << '\n';
        }
    }

    return 0;
}
