#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    //(liters, price)
    int n, L;
    cin >> n >> L;
    vector<int> bottles(n);
    for (int i=0; i<n; i++) {
        cin >> bottles[i];
    }
    for (int i=0; i<n-1; i++){
        bottles[i+1] = min(bottles[i+1], 2*bottles[i]);
    }
    long long answer = (long long) 4e18;
    long long sum = 0;
    for (int i=n-1; i>=0; i--){
        int need = L / (1 << i); // 1 << i is 2^i
        sum += (long long) need * bottles[i];
        L -= need << i;
        answer = min(answer, sum + (L > 0) * bottles[i]);
    }
    cout << answer << endl;
    return 0;
}
