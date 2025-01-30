#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    cin.ignore();
    vector<ll> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    ll count = 0;
    ll maxLeft = arr[0];
    vector<ll> rightMin(n, INT_MAX);
    rightMin[n-1] = arr[n-1];
    for(ll i = n-2; i >= 0; i--){
        rightMin[i] = min(rightMin[i+1], arr[i]);
    }
    if(arr[0] < rightMin[1]) count++;
    if(arr[n-1] > rightMin[n-2]) count++;

    for(ll i = 1; i < n-1; i++){
        ll pivot = arr[i];
        maxLeft = max(maxLeft, pivot);
        if(maxLeft <= pivot && pivot < rightMin[i+1]){
            count++;
        }
    }
    cout << count << endl;
}
