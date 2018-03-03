/*
The bigest one bubble to the upest position a[n-1]
Then apply it to a[0, n-2]
*/
void BubbleSort1(int a[], int n)
{
    int i, j;
    for(i = 0； i < n - 1; i++)
        for(j = 1; j < n - i; j++) 
	{
	    if(a[j-1] > a[j])
	        Swap(a[j-1], a[j]);
	}
}

/*
if in one scan process, no swith happen, 
data in this target array had sorted sequence,
break;
*/
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

/*
mark the pleace where the last switch happen;
so we know data after it no need to sort;
only need to sort the data before it [0, flag);
*/
void BubbleSort3(int a[], int n) 
{
    int j, k;
    int flag;
    
    flag = n;
    while(flag > 0) 
    {
        k = flag;
	flag = 0;
	for(j = 1; j < k; j++)
	{
	    if(a[j-1] < a[j]) 
	    {
	        Swap(a[j-1], a[j]);
		flag = j;
	    }
	}
    }
}
