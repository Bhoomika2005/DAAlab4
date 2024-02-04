#include <bits/stdc++.h>
using namespace std;

/*using sorting
time complexity: O(NlogN) as we are using STL sorting function once
space complexity: O(1) (no extra space)*/
int KthLargest(vector<int> &arr, int n, int k)
{
    sort(arr.begin(), arr.end());
    return arr[n - k];
}

/*using quick sort
time complexity: O(N^2) in the worst case
space complexity: O(1) (no extra space)*/
int partition(vector<int> &arr, int l, int h)
{
    int high = arr[h];
    int x = l;
    for (int i = l; i < h; i++)
    {
        if (arr[i] < high)
        { // If arr[i] is less than high, then swap arr[x] with arr[i]
            swap(arr[x], arr[i]);
            x++;
        }
    }
    swap(arr[x], arr[h]); // swap arr[x] with arr[h]
    return x;
}
int KthLargestElement(vector<int> arr, int n, int k)
{
    if (n == 1)
    {
        return arr[0];
    }
    int l = 0;
    int h = n - 1;
    int target = n - k;
    while (l <= h)
    {
        int pivot = partition(arr, l, h); // Initializing pivot with the value returned by partition function
        if (pivot < target)
        { // If the pivot is less than the target, then we have to go to the right side
            l = pivot + 1;
        }
        else if (pivot > target)
        { // If the pivot is greater than the target, then we have to go to the left side
            h = pivot - 1;
        }
        else
        { // If the pivot is equal to the target, return arr[pivot]
            return arr[pivot];
        }
    }
    return -1;
}

int main()
{
    const int n = 1000, k = 489;
    ofstream inputfile("input3.txt");
    inputfile << n << endl;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int num = rand() % 10;
        inputfile << num << " ";
    }

    inputfile.close();

    ifstream inputFile("input3.txt");
    for (int i = 0; i < n; i++)
    {
        int x;
        inputFile >> x;
        arr.push_back(x);
    }
    inputFile.close();

    ofstream outputfile("output3.txt");
    outputfile << "Kth largest element is: " << KthLargestElement(arr, n, k);
    outputfile.close();
    return 0;
}