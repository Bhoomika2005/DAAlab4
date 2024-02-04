#include <bits/stdc++.h>
using namespace std;

int maximum(int a, int b);
int minimum(int a, int b);

/*we can find median by merging given two sorted arrays,
time complexity: O(n+m) and space complexity: O(n+m)

below is the optimised approach using binary search
 time complexity: O(log(min(n,m))), space complexity: O(1)*/

// Function to find median of two sorted arrays
double findMedianSortedArrays(int *a, int n, int *b, int m)
{

    int min_index = 0, max_index = n, i, j, median;

    while (min_index <= max_index)
    {
        i = (min_index + max_index) / 2;
        j = ((n + m + 1) / 2) - i;

        if (j < 0)
        {
            max_index = i - 1;
            continue;
        }

        if (i < n && j > 0 && b[j - 1] > a[i])
            min_index = i + 1;

        else if (i > 0 && j < m && b[j] < a[i - 1])
            max_index = i - 1;

        else
        {
            if (i == 0)
                median = b[j - 1];
            else if (j == 0)
                median = a[i - 1];
            else
                median = maximum(a[i - 1], b[j - 1]);
            break;
        }
    }

    if ((n + m) % 2 == 1)
        return (double)median;

    if (i == n)
        return (median + b[j]) / 2.0;

    if (j == m)
        return (median + a[i]) / 2.0;

    return (median + minimum(a[i], b[j])) / 2.0;
}

int maximum(int a, int b)
{
    return a > b ? a : b;
}

int minimum(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    const int m = 1000, n = 1000;
    ofstream inputfile("input2.txt");
    inputfile << m << endl;
    int a[m];
    for (int i = 0; i < m; i++)
    {
        int num = rand() % 10;
        inputfile << num << " ";
    }
    inputfile << endl;
    inputfile << n << endl;
    int b[n];
    for (int i = 0; i < n; i++)
    {
        int num = rand() % 100;
        inputfile << num << " ";
    }
    inputfile << endl;
    inputfile.close();

    ifstream inputFile("input2.txt");
    for (int i = 0; i < m; i++)
    {
        inputFile >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        inputFile >> b[i];
    }
    inputFile.close();

    ofstream outputfile("output2.txt");
    if (n < m)
        outputfile << "The median is : "
                   << findMedianSortedArrays(a, n, b, m);
    else
        outputfile << "The median is : "
                   << findMedianSortedArrays(b, m, a, n);

    outputfile.close();
    return 0;
}
