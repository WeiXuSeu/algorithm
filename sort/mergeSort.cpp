//merge sorted array a[], b[] to c[]
void mergeArray(int a[], int m, int b[], int n, int c[])
{
    int i, j, k;
    i = j = k = 0;
    while(i < m && j < n)
    {
        if(a[i] < b[j])
	{
	    c[k++] = a[i++];
	}
	else 
	{
	    c[k++] = b[j++];
	}
    }
  
    while(i < m)
    {
        c[k++] = a[i++];
    }

    while(j < n)
    {
        c[k++] = b[j++];
    }
}

//---------merge to sorted arraies------------
void mergeArray(int a[], int first, int mid, int last, int tmp[])
{
    int i = first, j = mid +1;
    int m = mid, n = last;
    int k = 0;
    while(i <= m && j <= n)
    {
        if(a[i] < a[j])
	    tmp[k++] = a[i++];
	else 
	    tmp[k++] = b[j++];
    }

    while(i <= m)
    {
        tmp[k++] = a[i++];
    }

    while(j <= n)
    {
        tmp[k++] = b[j++];
    }
}

void mergetSort(int a[], int first, int last, int tmp[])
{
    if(first >= last)
        return;
    int mid = (first + last) / 2;
    mergeSort(a, first, mid, tmp);
    mergeSort(a, mid+1, last, tmp);
    mergeArray(a, first, mid, last, tmp);
}

bool MergeSort(int a[], int n)
{
    int *p = new int[n];
    if(p == NULL)
        return false;
    mergeSort(a, 0, n-1, p);
    delete[] p;
    return true;
}







