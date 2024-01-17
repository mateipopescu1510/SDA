/*
    Popescu Matei Calin, 334
    Am folosit un min heap si un max heap ca sa am acces in O(1) la cutiile cu numar minim sau maxim de bomboane. Heap-urile folosesc perechi de doua int-uri ca sa pot retine si pozitia cutiei din care mut bomboane.

    Initial, cutiile cu nr de bomboane strict mai mic decat media au fost puse in min heap si vice versa.

    La fiecare pas iau numarul minim si maxim de bomboane, actualizez valorile lor si le inserez la loc in heapurile respective doar daca au ramas fie sub, fie peste medie.

    Per total, am O(n log n) => n pasi la care am operatii de O(1) (extragere top heap) si inserare in heap (log n).
*/
#include <fstream>
#include <sstream>
#include <queue>
#include <vector>

std::ifstream in("bomboane.in");
std::ofstream out("bomboane.out");
std::ostringstream rez;

struct MinHeapComp {
    bool operator()(std::pair<int, int>x, std::pair<int, int>y) {
        return x.first > y.first;
    }
};
struct MaxHeapComp {
    bool operator()(std::pair<int, int>x, std::pair<int, int>y) {
        return x.first < y.first;
    }
};

int n, suma, medie, S, D, B, nrpasi;
std::vector<int> bomboane;
std::priority_queue < std::pair<int, int>, std::vector<std::pair<int, int>>, MinHeapComp> minHeap;
std::priority_queue < std::pair<int, int>, std::vector<std::pair<int, int>>, MaxHeapComp> maxHeap;

int main() {
    in >> n;
    for (int i = 0; i < n; i++) {
        int x;
        in >> x;
        bomboane.push_back(x);
        suma += x;
    }

    if (suma % n) {
        out << "-1\n";
        return 0;
    }

    medie = suma / n;
    for (int i = 0; i < n; i++) {
        if (bomboane[i] < medie)
            minHeap.push({ bomboane[i], i });
        if (bomboane[i] > medie)
            maxHeap.push({ bomboane[i], i });
    }

    while (minHeap.size() && maxHeap.size()) {
        std::pair<int, int> minTop = minHeap.top(), maxTop = maxHeap.top();
        minHeap.pop();
        maxHeap.pop();

        S = maxTop.second + 1;
        D = minTop.second + 1;
        B = std::min(medie - minTop.first, maxTop.first - medie);

        minTop.first += B;
        maxTop.first -= B;

        if (minTop.first < medie)
            minHeap.push(minTop);
        if (maxTop.first > medie)
            maxHeap.push(maxTop);

        rez << S << ' ' << D << ' ' << B << '\n';
        nrpasi++;
    }
    out << nrpasi << '\n' << rez.str();
    return 0;
}