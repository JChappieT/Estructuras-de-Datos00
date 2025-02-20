#include <set>
#include <iostream>
#include <list>

using namespace std;

int main(){
    set <string> conjunto00{"aa", "bb", "cc", "dd"};
    set<int> conjuto02{1,3,4,5};
    int i=5;
    for(auto it= conjunto00.begin(); it !=conjunto00.end(); ++it, ++i){
        conjuto02.insert('a'+i);
    }
    for(auto it= conjunto00.begin(); it !=conjunto00.end(); ++it, ++i){
        cout << "valor" << *it;
    }
}