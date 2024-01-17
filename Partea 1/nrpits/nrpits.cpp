/*
    Popescu Matei Calin, 334

    Folosind un stack, tin in el "varfurile" gropilor, dand mereu afara ce este "inauntrul" gropilor. Astfel, daca am secventa 12 1 10, in stack voi avea 12 10 la sfarsitul iteratiei respective. Astfel, stiu ca am gasit o groapa si in acelasi timp am si informatia pentru viitor daca apar gropi care se suprapun (conditia ca elementul curent da afara din stack elemente strict mai mici).

    In cod, iterez o singura data prin sirul initial, iar pentru fiecare element este posibil sa scot unul sau mai multe elemente din stack. Fiecare element poate sa apara o singura data in stack, deci complexitatea este O(n)
*/
#include <fstream>
#include <stack>
#include <vector>

std::ifstream in("nrpits.in");
std::ofstream out("nrpits.out");

int n, x;
std::vector<int>v;
std::stack<int>S;

int main() {
    in >> n;
    while (in >> x)
        v.push_back(x);

    x = 0;
    for (int i = 0; i < n; i++) {
        while (S.size() && S.top() < v[i]) {
            if (S.size() > 1)
                x++;
            S.pop();
        }
        S.push(v[i]);
    }
    out << x;

    return 0;
}
