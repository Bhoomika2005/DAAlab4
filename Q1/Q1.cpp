#include <bits/stdc++.h>
using namespace std;
#define ll long long

/* naive approach: time complexity: O(N^2) as we have nested loop
space complexity: O(1) as we are not using any extra space.
we can optimise this by using mergesort to O(Nlogn), auxiliary space: O(N)*/

ll inversionCount(int A[], int n)
{
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] > A[j])
                cnt++;
        }
    }
    return cnt;
}

int MergeSort(int arr[], int temp[], int left, int right);
// function merges two sorted arrays and returns inversion count in the arrays.
int merge(int A[], int C[], int left, int mid,
          int right)
{
    int i, j, k;
    int cnt = 0;

    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if (A[i] <= A[j])
        {
            C[k++] = A[i++];
        }
        else
        {
            C[k++] = A[j++];
            cnt = cnt + (mid - i);
        }
    }

    while (i <= mid - 1)
        C[k++] = A[i++];

    while (j <= right)
        C[k++] = A[j++];

    for (i = left; i <= right; i++)
        A[i] = C[i];

    return cnt;
}

int mergeSort(int A[], int n)
{
    int C[n];
    return MergeSort(A, C, 0, n - 1);
}

/* function that sorts the input array and
 returns the number of inversions in the array.*/
int MergeSort(int A[], int C[], int left, int right)
{
    int mid, cnt = 0;
    if (right > left)
    {
        mid = (right + left) / 2;
        cnt += MergeSort(A, C, left, mid);
        cnt += MergeSort(A, C, mid + 1, right);

        // Merge the two parts
        cnt += merge(A, C, left, mid + 1, right);
    }
    return cnt;
}

int main()
{
    const int n = 1000;
    ofstream inputfile("input1.txt");
    inputfile << n << endl;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        int num = rand() % 10;
        inputfile << num << " ";
    }

    inputfile.close();

    ifstream inputFile("input1.txt");
    for (int i = 0; i < n; i++)
    {
        inputFile >> A[i];
    }
    inputFile.close();

    ofstream outputfile("output1.txt");
    // outputfile << "counts of inversions: " << inversionCount(A, n) << endl;

    outputfile << " Number of inversions are " << mergeSort(A, n);
    outputfile.close();
    return 0;
}