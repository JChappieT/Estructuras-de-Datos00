#include <stack>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector Numbers{3,4,5};
    stack<int> stack;
    stack.emplace(1);
    stack.emplace(2);
    //stack.push_range(Numbers);
    cout << "Top: " << stack.top();
}