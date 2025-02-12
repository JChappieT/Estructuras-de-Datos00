#include <iostream>
#include <stack>
#include <queue>
using namespace std;

template<class T, int element> class Exp{
    public:
    T a[element];
    void put(){
        int x=1;
        for(int j=0; j<element; j++){
            a[j] = x;
            x++;
        }
    }

    void print(){
        for(int x=6; x<element; x++)
            cout << a[x] << " " << "\n";
        cout << "\n ...Fin! \n";
    }
};

//Utility fuction to display queue
void tool_cola(queue<string> objeto){
    cout << "\n Tamano de la cola: " << objeto.size() << "\n";

    while(!objeto.empty()){
        cout << objeto.front() << ", ";
        objeto.pop();
    }
    cout << endl;
}
int main(){
    //1
    Exp<int,2> objeto;
    objeto.put();
    objeto.print();
    
    //2
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    st.pop();
    st.pop();

    while (!st.empty()){
        cout << ' ' << st.top();
        st.pop();
    }
    cout << "\n ...Fin! \n";

    //3
    //Create a queue of string
    queue<string> animales;
    //push elements into the queue
    animales.push("Gato");
    animales.push("Hormiga");
    animales.push("Conejo");
    animales.push("Perro");

    cout << "\nCola Inicial: \n";
    tool_cola(animales);

    //remove element from queue
    animales.pop();
    cout << "\n Cola Final: \n";
    tool_cola(animales);

    //4
    //inicialize 2 vectors
    vector <int> v1, v2;

    //add elements into the _Vector_base
    for(int i = 1; i<=10; i++){
        v1.push_back(i);
        v2.push_back(i +2);
    }

    //initialize an iterator itr pointing to the firts element in vector 1
    vector<int>::iterator itr = v1.begin();
    //copy elements of vec 2 to vec 1 at the beggining
    copy(v2.begin(), v2.end(), inserter(v1,itr));
    //print the elements of vector 1
    cout << "Elements of v1 after copying elements of v2 are: " << endl;
    for(itr=v1.begin(); itr!= v1.end(); ++itr){
        cout << " " << *itr;
    }
    cout << "\n\n";
    return 0;
}