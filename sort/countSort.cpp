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
for(int i = 0; i < n; i++)
	target[--count[arr[i]-min]] = arr[i];

return target;
}
