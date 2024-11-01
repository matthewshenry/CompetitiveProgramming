#include <iostream>
#include <string>
using namespace std;

string stringgame(string line){
    int count=0;
    for(int i=1; i<line.length(); i++){
        if(line[i] == line[i-1]){
            line.erase(i-1, 2);
            count++;
            i=i-2;
        }
    }
    if(count % 2 == 0){
        return "No";
    }else{
        return "Yes";
    }
}

int main(){
    string line;
    cin >> line;
    cout << stringgame(line) << endl;
    return 0;
}

