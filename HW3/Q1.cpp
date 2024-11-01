#include <iostream>
#include <vector>
using namespace std;

char batmanacci(long long n, long long k, vector<long long> &lengths){
    if(n == 0){
        return 'N';
    }
    if(n == 1){
        return 'A';
    }
    if(k <= lengths[n-2]) {
        return batmanacci(n-2, k, lengths);
    }else if(lengths[n-2] == 0){
        return batmanacci(n-2, k, lengths);
    }else{
        return batmanacci(n-1, k - lengths[n-2], lengths);
    }
}

int main(){
    long long n, k;
    cin >> n;
    cin >> k;
    vector<long long> lengths(n);
    lengths[0] = 1;
    lengths[1] = 1;
    for(long long i=2; i<n; i++){
        lengths[i] = lengths[i-2] + lengths[i-1];
        if (lengths[i] > k) break;
    }
    for(long long i=0; i<n; i++){
        cout << lengths[i];
    }
    cout << batmanacci(n-1, k, lengths);
}