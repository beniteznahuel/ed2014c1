typedef int K;
typedef int V;

Struct HashTableStr;
typedef HashTableStr* HashTable;

HashTable emptyHashTable();
void deleteHashTable(HashTable& t);
bool has(HashTable t, K k);
//Pre: has(t,k)
V get(HashTable t, K k);
//Pre: !has(t,k)
void put(HashTable& t, K k, V v);
//Pre: has(t,k)
void remove(HashTable& t, K k);
