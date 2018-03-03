int * countSort(int *arr, int n)
{
//find the min and max value to get the arrange in array
int min = arr[0];
int max = arr[0];
for(int i = 0; i < n; i++)
{
	if(arr[i] < min)
		min = arr[i];
	if(arr[i] > max)
		max = arr[i];
}	
int len = max - min + 1;
//get array couont to store count of value x in arr[x] (relate to min)
int * count = new int[len](); //initialize to zero using ()

//array target to store sorted array
int * target = new int[n]();

for(int i = 0; i < n; i++)
	count[arr[i]-min]++;

//store count of value x in [min, x] in count[x]
for(int i = 1; i < len; i++)
	count[i] = count[i] + count[i-1];

//i --> value(arr[i]) --> index:count(--count[arr[i]-min])-->right position
//xth largest value put at position (x-1)
//do a count sort
/*
count[], 记录后从后往前排，对于某个相同的数
所以，数组扫描时也要从后往前扫描，保证排序的稳定性；
如5有3个，从count[5]-->count[5]-2排，所以从后扫描，算法稳定，后面的放在后面
*/
for(int i = n-1; i >= 0; i--)
{
	int position = --count[arr[i]-min];
	target[position] = arr[i];
}
	
return target;
}
