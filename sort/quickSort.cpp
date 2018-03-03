void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int partition1(int *arr, int start, int end)
{
    int pivot = arr[end];
    int left = start;
    int index = start;
    while(index < end)
    {
        if(arr[index] < pivot)
	{
	    if(index != left)
	    {
	        swap(&arr[index], &arr[left]);
	    }
	    //mark the boundary position(last+1) of left target array(< pivot)
	    left++;
	}
	index++;
    }
    swap(&arr[end],&arr[left]);
    return left;
}

int partition2(int *arr, int start, int end)
{
    int pivot = arr[end];
    int left = start;
    int right = end - 1;
    //two index [left, right], scan from left & right
    while(left < right)
    {
        while(arr[left] < pivot && left < right)
	    left++;
	while(arr[right] >= pivot && left < right)
	    right--;
	swap(&arr[left], &arr[right]);
    }
    //find the target positon for pivot, swap it with arr[end];
    //left mark the boundary of target array in left which (<pivot) (last + 1) except one case
    //if all items in [left, right] small than pivot, then left = right, mark the last one;
    if(arr[left] < pivot)
        //if all items in [left, right] samll than pivot, again make it mark (last + 1), make sure it point to the one (>=pivot) 
	//first one not in left target array
        left++;
    //put pivot to suitable positon	
    swap(&arr[left], &arr[end]);
    return left;
}

void quickSort(int *arr, int start, int end)
{
    if(start>=end)
        return;
    int pivotPosition = partition(arr, start, end);
    quickSort(arr, start, pivotPosition-1);
    quickSort(arr, pivotPosition+1, end);
}

void quickSortAlg(int *arr, int n)
{
    if(NULL == arr)
        return;
    int end = n-1;
    int start = 0;
    quickSort(arr, start, end);
}
