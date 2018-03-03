/*
sort array: a[0, i-1]
unsort array: a[i, n-1]
insert a[i] to a[0, i-1] to generate a new sort array
*/

void InsertSort1(int a[], int n) 
{
    int i, j, k;
    for(i = 1; i < n; i++)
    {
        for(j = i - 1; j >= 0 && a[j] > a[j+1]; j--)
	    Swap(a[j], a[j+1]);
    }
}

void InsertSort1v2(int a[], int n)
{
    int i, j, k;
    for(i = 1; i < n; i++)
    {
        for(j = i; j >= 1 && a[j] > a[j-1]; j--)
	    Swap(a[j], a[j-1]);
    }
}
