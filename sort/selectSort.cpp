/*
From index i to n-1;
select the min one in [i, n-1];
swap it with a[i];
*/
void selectSort(int a[], int n)
{
    int i, j, minIndex;
    for(i = 0; i < n -1; i++)
    {
        minIndex = i;
	for(j = i+1; j < n; j++)
	{
	    if(a[j] < a[minIndex])
	        minIndex = j;

        }
	Swap(a[minIndex], a[i])
    }
}

void swap1(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}


void swap2(int &a, int &b)
{
    if(a != b)
    {
        a ^= b;
	b ^= a;
	a ^= b;
    }
}

