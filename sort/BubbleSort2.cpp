void BubbleSort2(int a[], int n)
{
    int j, k;
    bool flag;
    k = n;
    flag = true;
    while(flag) 
    {
        flag = false;
	for(j = 1; j < k; j++)
	{
	    Swap(a[j-1], a[j]);
	    flag = true;
	}
	k--;
    }
}

void BubbleSort2v2(int a[], int n)
{
    int i, j;
    bool flag = true;
    for(i = 0; i < n - 1; i++)
    {
        flag = false;
	for(j = 1; j < n - i; j++)
	{
	    if(a[j-1] > a[j]) 
	    {
	        Swap(a[j-1], a[j]);
		flag = true;
	    }
	}
	if(flag == false)
	    break;
    }
}
