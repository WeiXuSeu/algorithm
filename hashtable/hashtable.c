#include<stdlib.h>
#include<stdio.h>
#include "hashtable.h"
#include "fatal.h"

/***********************************************
#next prime
	int n;
    int i, j;
    scanf ("%d", &n);
    for (i = n+1; ;++i){
        for (j = 2; j*j <= i; ++j){
            if (i%j==0)break;
        }
        if (j*j > i){
            printf ("%d\n", i);
            break;
        }
    }
    return i;
***************************************************/

#define MinHashTableSize (3)

struct ListNode
{
	ElementType Element;
	Position    Next;
};

typedef Position List;

struct HashTbl
{
	int TableSize;
	List *TheLists;
};

static int NextPrime(int N)
{
	int i;
	if (N%2==0)
		N++;
	for(;;N+=2)
	{
		for(i=2;i*i<=N;i++)
			if(N%i==0)
				goto NextN;
		return N;
		NextN: ;
	}
}

Index Hash(ElementType Key, int TableSize)
{
	return Key%TableSize;
}

HashTable InitializeTable(int TableSize)
{
	HashTable H;
	int i;

	if(TableSize<MinHashTableSize)
	{
		Error("Table size too small!");
		return NULL;
	}

	H = malloc(sizeof(struct HashTbl));
	if(NULL==H)
		FatalError("Out of space!");
	H->TableSize = NextPrime(TableSize);
	H->TheLists = malloc(sizeof(List)*H->TableSize);
	if(NULL==H->TheLists)
		FatalError("Out of space");

	for(i=0; i<H->TableSize; i++)
	{
		H->TheLists[i]=malloc(sizeof(struct ListNode));
		if(NULL==H->TheLists[i])
			FatalError("Out of space!");
		else
			H->TheLists[i]->Next=NULL;
	}

	return H;
}

Position Find(ElementType Key, HashTable H)
{
	List L = H->TheLists[Hash(Key, H->TableSize)];
	Position P=L->Next;
	while(NULL != P && P->Element != Key)
		P=P->Next;
	return P;
}

void Insert(ElementType Key, HashTable H)
{
	Position P = Find(Key, H);
	Position NewCell=NULL;
	List L = H->TheLists[Hash(Key, H->TableSize)];
	if(NULL == P)
	{
		NewCell = malloc(sizeof(struct ListNode));
		if(NULL == NewCell)
			FatalError("Out of space!");
		else
		{
			NewCell->Element = Key;
			NewCell->Next = L->Next;
			L->Next = NewCell;
		}
	}
}

int IsLast(Position P)
{
	return NULL == P->Next;
}

Position FindPrevious(ElementType Key, List L)
{
	Position ElementPostion=L;
	while(ElementPostion->Next != NULL && ElementPostion->Next->Element!=Key )
		ElementPostion = ElementPostion->Next;
	return ElementPostion;
}

void Delete(ElementType Key, HashTable H)
{
	List L = H->TheLists[Hash(Key, H->TableSize)];
	Position PreviousPosition = FindPrevious(Key, L);
	if(!IsLast(PreviousPosition))
	{
		Position tmp = PreviousPosition->Next;
		PreviousPosition->Next=tmp->Next;
		free(tmp);
	}
}


void DestroyTable(HashTable H)
{
	int i;
	Position tmp;
	List L;
	for(i=0; i < H->TableSize; i++)
	{
		L = H->TheLists[i];
		while(NULL != L)
		{
			tmp = L->Next;
			free(L);
			L = tmp;
		}
	}
	free(H->TheLists);
	free(H);
}

void DumpHashTable(HashTable H)
{
	int ListIndex=0;
	Position ElementPosition = NULL;
	for(;ListIndex<H->TableSize;ListIndex++)
	{
		printf("List[%d]: ",ListIndex);
		ElementPosition = H->TheLists[ListIndex]->Next;
		while(NULL != ElementPosition)
		{
			printf("%d ", ElementPosition->Element);
			ElementPosition = ElementPosition->Next;
		}
		printf("\n");
	}
}

int main()
{
	HashTable hashtable = InitializeTable(4);
	int index=0;
	for(;index < 10; index++)
		Insert(index, hashtable);
	DumpHashTable(hashtable);
	Delete(6,hashtable);
	DumpHashTable(hashtable);
	return 0;
}