#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main(){
    int h, change=0, label = 0;
    string path;
    cin >> h;
    for(int i = 0; i <= h; i++){
        label += pow(2, i);
    }
    if(!(cin >> path)){
        path = "";
    }
    for(char dir: path){
        if(dir == 'L'){
            change = 2*change+1;
        }else if (dir == 'R'){
            change = 2*change+2;
        }
    }
        cout << label-change;
}
