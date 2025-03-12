#include "Tabla_hash.h"
using namespace std;
// Main function
int main(){
    // array of all the keys to be inserted in hash table
    int arr[] = {20, 34, 56, 54, 76, 87};
    int n = sizeof(arr)/sizeof(arr[0]);
    // table_size of hash table as 6
    HashMapTable ht(6);
    for (int i = 0; i< n; i++)
        ht.insertElement(arr[i]);
    // deleting element 34 from the hash table
    ht.deleteElement(34);
    // displaying the final data of hash table
    ht.displayHashTable();
    return 0;
}