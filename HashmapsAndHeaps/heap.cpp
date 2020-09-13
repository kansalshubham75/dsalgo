#include <iostream>
#include <vector>
using namespace std;

vector<int> pq;
bool isMax = true;
void downHeapify(int pi)
{
    int lci = 2 * pi + 1;
    int rci = 2 * pi + 2;
    int maxi = pi;

    if (lci < pq.size() && pq[lci] > pq[maxi])
    {
        maxi = lci;
    }
    if (rci < pq.size() && pq[rci] > pq[maxi])
    {
        maxi = rci;
    }

    if (maxi != pi)
    {
        swap(pq[pi], pq[maxi]);
        downHeapify(maxi);
    }
}

void pop()
{
    swap(pq[0], pq[pq.size() - 1]);
    // cout<<pq[pq.size()-1]<<" ";
    pq.erase(pq.begin() + pq.size() - 1);
    downHeapify(0);
}

void upHeapify(int ci)
{
    int pi = (ci - 1) / 2;
    if (pi >= 0 && pq[pi] < pq[ci])
    {
        swap(pq[pi], pq[ci]);
        upHeapify(pi);
    }
}

void setPq()
{
    for (int i = pq.size() - 1; i >= 0; i--)
        downHeapify(i);
}

void push(int val)
{
    pq.push_back(val);
    upHeapify(pq.size() - 1);
}

void display()
{
    for (int i : pq)
        cout << i << " ";
    cout << endl;
}
int main()
{
    pq = {10, 20, 30, -2, -3, -4, 5, 6, 8, 7, 9, 22, 11, 13};
    setPq();

    while (pq.size() != 3)
    {
        // cout << pq[0] <<endl;
        display();
        pop();
    }
    push(50);
    display();
    push(100);
    display();
    return 0;
}