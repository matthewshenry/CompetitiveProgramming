#include <iostream>
#include <set>
using namespace std;

int main(){
    int n, m, num;
    set<int> set;
    cin >> n;
    num = n;
    while(n--){
        cin >> m;
        set.insert(m);
    }
    int answer = num - set.size();
    cout << answer;
}