#include <iostream>
#include <algorithm>
using namespace std;

int partition(int a[], int s, int e)
{
    int piv = a[e], i = s, j = e-1;
    
    while (true){
        while (a[i] < piv){
            i++;
        }
        while (a[j] > piv){
            j--;
        }
        
        if (i >= j){
            break;
        }
        swap(a[i], a[j]);
        i++; j--;
    }
    swap(a[i], a[e]);
    return i;
}

void qs(int a[], int l, int r)
{
    if (l >= r){
        return;
    }
    int p = partition(a, l, r);
    qs(a, l, p-1);
    qs(a, p+1, r);
}

int main()
{
    int n;
    cin >> n; 
    int ar[n];
    for (int i = 0; i < n; i++){
        cin >> ar[i];
    }
    
    qs(ar, 0, n-1);
}