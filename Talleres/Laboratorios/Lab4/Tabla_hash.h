#ifndef TABLA_HASH_H
#define TABLA_HASH_H
#include <list>
class HashMapTable{
// size of the hash table
inttable_size;
// Pointer to an array containing the keys
list<int> *table;
public:
// creating constructor of the above class containing all the methods
HashMapTable(int key);
// hash function to compute the index using table_size and key
inthashFunction(int key) {
return (key % table_size);
}
// inserting the key in the hash table
void insertElement(int key);
// deleting the key in the hash table
void deleteElement(int key);
// displaying the full hash table
void displayHashTable();
};
#endif