#include<bits/stdc++.h>

#define ll long long

using namespace std;

class heap
{
private:
    ll nm;
    vector<ll> A;
public:
    heap(ll n)
    {
        nm = n;
        for(ll i = 0; i < nm; i++)
        {
            ll x;
            cin>>x;
            A.push_back(x);
        }
    }

    void max_heapify(ll ind, ll num)
    {
        ll left = (2 * ind) + 1;
        ll right = (2 * ind) + 2;
        ll max = ind;
        if(left < num && A[left] > A[max])
            max = left;
        if(right < num && A[right] > A[max])
            max = right;
        if(max != ind)
        {
            swap(A[ind], A[max]);
            max_heapify(max, num);
        }
    }

    void min_heapify(ll ind, ll num)
    {
        ll left = (2 * ind) + 1;
        ll right = (2 * ind) + 2;
        ll min = ind;
        if(left < num && A[left] < A[min])
            min = left;
        if(right < num && A[right] < A[min])
            min = right;
        if(min != ind)
        {
            swap(A[ind], A[min]);
            min_heapify(min, num);
        }
    }

    void display()
    {
        for(ll i = 0; i < nm; i++)
            cout<<A[i]<<" ";
        cout<<endl;
    }

    void g_sort()
    {
        for(ll i = nm/2 - 1; i>= 0; i--)
            max_heapify(i, nm);
        for(ll i = nm-1; i >= 0; i--)
        {
            swap(A[0], A[i]);
            max_heapify(0, i);
        }
    }
};

int main()
{
    ll n;
    cout<<"Number of elements in heap: ";
    cin>>n;
    heap h(n);
    h.max_heapify(0, n);
    cout<<"Max Heap is: ";
    h.display();
    h.g_sort();
    cout<<"Sorted Heap is: ";
    h.display();
    h.min_heapify(0, n);
    cout<<"Min Heap is: ";
    h.display();
}
