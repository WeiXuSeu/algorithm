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
