void shellSort1(int a[], int n) 
{
    int i, j, gap;
    for (gap = n/2; gap > 0; gap /= 2)
    {
        for(i = gap; i < n; i++)
	{
	    for(j = i - gap; j >=0 && a[j+gap] < a[j]; j -= gap)
	    {
	        Swap(a[j], a[j+1]);
	    }
	}
    }
}

