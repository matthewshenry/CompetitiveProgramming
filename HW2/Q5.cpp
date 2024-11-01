#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        stack.push('x')
        for(char c : s){
            if(c == '(' || c == '[' || c == '{'){
                stack.push(c);
            }else if(c == ')' && stack.top() == '('){
                    stack.pop();
            }else if(c == ']' && stack.top() == '['){
                    stack.pop();
            }else if(c == '}' && stack.top() == '{') {
                    stack.pop();
            }else{
                return false;
            }
        }
        stack.pop();
        if(stack.empty()){
            return true;
        }else{
            return false;
        }
    }
};