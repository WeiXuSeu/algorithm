#ifndef _HashTable_H
#define _HashTable_H

typedef int ElementType;
typedef unsigned int Index;

struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable HTable);
Position Find(ElementType Key, HashTable HTable);
void Insert(ElementType Key, HashTable HTable);
ElementType Retrieve(Position P);

#endif
