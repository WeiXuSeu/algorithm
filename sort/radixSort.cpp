//assume all number (>=0)
int numLen(int *data, int n)
{
	int len = 1;
	int max = data[0];
	for(int i=1; i < n; i++)
	{
    	if(data[i] > max)
    		max = data[i];
	}
    while(max/10 > 0)
    {
    	len++;
    	max = max/10;
    }
    return len;
}

void radixSort(int *data, int n)
{
	int len = numLen(data, n);

	//the num of sort will be num times from lower bit to high bit
	int radix = 1;
	int *tmp = new int[n]();
	int member;
	int position;

	for(int count=1; count <= len; count++)
	{
    	//for each 'bit'(only contain 0~9), do a count sort
        int * count = new int[10]();
        for(int i=0; i<n; i++)
        {
        	member = (data[i]/radix)%10;
        	count[member]++;
        }

        //record the position of the value
        for(int i=1; i<10; i++)
        	count[i] += count[i-1];

        //do a count sort
        /*
        count[], 记录后从后往前排，对于某个相同的数
        所以，数组扫描时也要从后往前扫描，保证排序的稳定性；
        如5有3个，从count[5]-->count[5]-2排，所以从后扫描，算法稳定，后面的放在后面
        */
        for(int i=n-1; i>=0; i++)
        {
        	member = (data[i]/10)%10;
            position = --count[member];
            tmp[position] = data[i];
        }
        swap(tmp, data);
        radix = radix*10;
	}
	delete[] count;
	delete[] tmp;
}