class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low<high){
            int p = partition(arr,low,high);
            quickSort(arr,low,p-1);
            quickSort(arr,p+1,high);
        }
        return;
    }
    
    public:
    int partition (int arr[], int l, int h)
    {
       int pivot = arr[h]; //? always last element
    int i = l - 1;
    for (int j = l; j <= h - 1; j++)
    {
        if (arr[j] < pivot)
        {
            ++i;
            swap(arr[i], arr[j]); //? all smaller elements comes before pivot
        }
    }
    swap(arr[i + 1], arr[h]); //? swaps pivot element with next bigger element after i
    return (i + 1);
    }
};


// Quicksort Algorithm using 2 Different partition techniques ✅ + 1 Space-optimized quicksort function
// 1. Lomuto Partition
// The `quickSort` function takes in three arguments: an array `arr` to be sorted, and two integers `low` and `high` representing the starting and ending indices of the portion of the array to be sorted. The function first checks if `low` is less than `high`, which means that there are at least two elements to be sorted. If this is the case, it calls the `partition` function to partition the array around a pivot element. The pivot element is chosen to be the last element of the array (`arr[high]`) as per the Lomuto partition scheme. The `partition` function rearranges the elements in the array such that all elements smaller than the pivot come before it, and all elements greater than the pivot come after it. It then returns the index of the pivot element.
// After partitioning, the `quickSort` function recursively calls itself on the two subarrays on either side of the pivot element, excluding the pivot element itself. This process continues until the base case is reached, where `low >= high`, which means that there are less than two elements to be sorted, and the function returns.
// The `partition` function takes in three arguments: an array `arr`, and two integers `l` and `h` representing the starting and ending indices of the portion of the array to be partitioned. It chooses the last element of the array (`arr[h]`) as the pivot element. It then initializes a variable `i` to `l - 1`. The function then iterates over the elements in the array from index `l` to index `h - 1` using a for loop. If an element is smaller than the pivot, it increments `i` and swaps `arr[i]` with `arr[j]`. This way, all elements smaller than the pivot are moved to its left. After the for loop, it swaps `arr[i + 1]` with `arr[h]`, which moves the pivot element to its correct position in the sorted array. The function then returns `i + 1`, which is the index of the pivot element.
// The time complexity of QuickSort using Lomuto partition scheme is **O(n^2)** in the worst case, where n is the number of elements in the array. This happens when the input array is already sorted or reverse sorted, and causes QuickSort to perform poorly. However, its average time complexity is **O(n log n)**, which makes it an efficient sorting algorithm for most inputs.

// The space complexity of QuickSort is **O(log n)** for recursive calls on the call stack.

 

    void quickSort(int arr[], int low, int high)
    {
        if(low<high){
            int p = partition(arr,low,high);
            quickSort(arr,low,p-1);
            quickSort(arr,p+1,high);
        }
        return;
    }
    
    public:
    int partition (int arr[], int l, int h)
    {
    int pivot = arr[h]; //? always last element
    int i = l - 1;
    for (int j = l; j <= h - 1; j++)
    {
        if (arr[j] < pivot)
        {
            ++i;
            swap(arr[i], arr[j]); //? all smaller elements comes before pivot
        }
    }
    swap(arr[i + 1], arr[h]); //? swaps pivot element with next bigger element after i
    return (i + 1);
    }
// 2. Hoare's Partition [Better than lomuto]
// The quickSort function takes in three arguments: an array arr to be sorted, and two integers low and high representing the starting and ending indices of the portion of the array to be sorted.

// Check if low is less than high:

// If true, proceed with the sorting algorithm.
// If false, return as there are less than two elements to be sorted.
// Call the partition function with arguments arr, low, and high to partition the array around a pivot element.

// After partitioning, the array is rearranged such that all elements smaller than the pivot come before it, and all elements greater than the pivot come after it.

// Obtain the partition index, j, from the partition function.

// Recursively call quickSort on the subarrays:

// Call quickSort with arguments arr, low, and j - 1.
// Call quickSort with arguments arr, j + 1, and high.
// Repeat steps 1-5 until the base case is reached.

// The partition function takes in three arguments: an array arr, and two integers l and h representing the starting and ending indices of the portion of the array to be partitioned.

// Choose the pivot element to be the first element of the array, arr[l].

// Initialize two variables, i and j, to l - 1 and h + 1, respectively.

// Enter an infinite while loop:

// Increment i until an element greater than or equal to the pivot is found.
// Decrement j until an element less than or equal to the pivot is found.
// If i is greater than or equal to j, exit the loop.
// Otherwise, swap arr[i] with arr[j] to maintain the partitioning.
// Return the partition index j.

// The time complexity of QuickSort using Hoare's partition scheme is O(n^2) in the worst case, where n is the number of elements in the array. However, its average time complexity is O(n log n), making it an efficient sorting algorithm for most inputs.

// The space complexity of QuickSort is O(log n) for the recursive calls on the call stack.

// 🎁 Hoare's partition scheme is generally more efficient than Lomuto's partition scheme because it performs three times fewer swaps on average and creates more balanced partitions, even when all values are equal.

    void quickSort(int arr[], int low, int high)
    {
        if(low<high){
            int p = partition(arr,low,high); //p is partitioning index, arr[p] is now  at right place
            quickSort(arr,low,p); //separately sorts element before
            quickSort(arr,p+1,high);
        }
        return;
    }
    
    public:
    int partition (int arr[], int l, int h)
    {
            int pivot = arr[l]; // first element is pivot
    int i = l - 1, j = h + 1;
    while (true)
    {
        do
        {
            ++i;
        } while (arr[i] < pivot); // l to i must be smaller than =  pivot
        do
        {
            j--;
        } while (arr[j] > pivot); // j to h must be greater than =   pivot
        if (i >= j)               // i and j crossed each other
        {
            return j;
        }
        swap(arr[i], arr[j]);
    }
    return i+1;
    }
// 3. Tail Call Elimination Quicksort [Space Optimized]
// Like the previous implementations, this function takes in three arguments: an array arr to be sorted, and two integers low and high representing the starting and ending indices of the portion of the array to be sorted. The function first checks if low is less than high, which means that there are at least two elements to be sorted. If this is the case, it calls the partition function to partition the array around a pivot element. The pivot element is chosen according to the partition scheme used (Lomuto or Hoare). The partition function rearranges the elements in the array such that all elements smaller than the pivot come before it, and all elements greater than the pivot come after it. It then returns an index p.
// After partitioning, instead of making two recursive calls like in the previous implementations, this version of the function makes only one recursive call on the left subarray (from low to p). It then updates low to p + 1 and uses a goto statement to jump back to the beginning of the function. This effectively replaces the second recursive call with an iterative call, which reduces the space complexity.
    void quickSort(int arr[], int low, int high)
    {
begin:
    if (low < high)
    {
        int p = partition(arr, low, high); /* p is partitioning index, arr[p] is now
              at right place */
        quickSort(arr, low, p);                     // separately sorts element before
        low = p + 1;
        goto begin; // optimizes extra space;
    }
    return;
    }
