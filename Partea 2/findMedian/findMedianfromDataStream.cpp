/*
    Popescu Matei Calin, 334
    Am folosit doua heapuri de min/max ca sa am acces in O(1) la minimul/maximul din ele. In min heap retin elementele mai mari decat medie si in max heap pe cele mai mici decat medie.

    Cand inserez un element (O(log n)):
        -daca max heap e gol, il inserez pur si simplu
        -daca e mai mic decat radacina max heap il inserez in max heap
        -daca e mai mare sau egal il inserez in min heap
    La fiecare inserare echilibrez heapurile pana au ori aceeasi marime.

    Cand se cere sa aflu media (O(1)), fac media dintre varfurile celor doua heapuri. Daca un heap are cu un element mai mult (nr impar de elemente in total), media este chair topul max heap.
*/
#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    MedianFinder() {

    }

    void addNum(int num) {
        if (maxHeap.empty()) {
            maxHeap.push(num);
            return;
        }

        if (maxHeap.top() > num) {
            maxHeap.push(num);
            while (maxHeap.size() > minHeap.size()) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            return;
        }
        //daca ajung aici inseamnca ca maxHeap.top() <= num
        minHeap.push(num);
        while (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

    }

    double findMedian() {
        while (maxHeap.size() > minHeap.size()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        while (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        if (maxHeap.size() == minHeap.size())
            return (maxHeap.top() + minHeap.top()) / 2.0;

        //daca ajung aici inseamna ca max heap are cu un element mai mult
        return maxHeap.top();
    }
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */