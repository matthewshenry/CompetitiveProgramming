#include <iostream>
#include <string>
using namespace std;

string backspace(string input){
    string result;
    for (char chr:input){
        if (chr!='<') {
            result.push_back(chr);
        } else {
            if (!result.empty()){
                result.pop_back();
            } else{
                return "error";
            }
        }
    }
    return result;
}

int main() {
    string input;
    cin >> input;
    cout << backspace(input);
}
//VJudge: henrymatthews

