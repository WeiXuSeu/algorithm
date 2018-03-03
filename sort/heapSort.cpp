void scanDownSmall(int *arr, int i, int n)
{
    int parent = i;
    int child = 2*parent + 1;
    while(child < n)
    {
        if(child + 1 < n && arr[child+1] < arr[child])
    	    child++; //the smallest one in clildren
	if(arr[child] < arr[parent])
	    swap(&arr[child], &arr[parent]);
	else 
	    break;
	parent = child;
	child = 2*parent + 1;
    }
}

void builHeapSmall(int *arr, int n)
{
    int end = n-1;
    //(end-1)/2: the last non-left node, the parent of the last node
    for(int index = (end-1)/2; index >= 0; index--)
    {
        scanDownSmall(arr, index, n);    
    }
}

void heapSortSmall(int *arr, int n)
{
    for(int end = n-1; end > 0; end--)
    {
        swap(arr[0], arr[end]);
	//end: mark the number of new subarray need to be processed
	scanDownSmall(arr, 0, end);
    }
}

/*-----------------------------------------------------------------*/
/*---------------insert to a heap array----------------------------*/
//append it to the array, then scan up
void heapAppend(vector<int> &vec, int size, int x)
{
    vec.push_back(x);
    int child = size;
    while(child > 0)
    {
        parent = (child-1)/2;
	if(arr[child] < arr[parent])
	    swap(&arr[child], arr[parent]);
	else
	    break;
	child = parent;
	parent = (parent-1)/2;
    }
}

void heapAppent2(vector<int> &vec, int size, int x)
{
    vec.push_back(x);
    int child = size;
    int parent = (child-1)/2;
    for(;child > 0 && arr[child] < arr[parent]; child = parent, parent = (parent-1)/2)
        swap(&arr[child], &arr[parent]);
}























