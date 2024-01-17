/*
    Popescu Matei Calin, 334

    As fi putut rezolva problema si cu queue (construind numere formate strict din ciferele respective), dar mult mai simplu mi s-a parut sa iau restul si sa il adun la multiplii de-ai impartitorului, verificand la fiecare iteratie daca numarul obtinut este format din ciferele din cerinta.

    Aceasta metoda mi s-a parut mult mai simpla si posibil mai eficienta. Pentru fiecare verificare, complexitatea este O(log x). In cazul cel mai rau, ajung la limita de long int in INT64_MAX / P pasi, deci complexitatea totala ar fi O(T * (INT64_MAX / P) * log(x)).
*/
#include <fstream>
#include <queue>

std::ifstream in("cifre4.in");
std::ofstream out("cifre4.out");

long long T, N, P;

bool check(long long x) {
    while (x) {
        if (x % 10 != 2 && x % 10 != 3 && x % 10 != 5 && x % 10 != 7)
            return false;
        x /= 10;
    }
    return true;
}

void find() {
    bool ok = false;
    long long x = 0, i = 0;
    while (x < INT64_MAX && !ok) {
        x = i * P + N;
        i++;
        ok = check(x);
    }
    if (ok)
        out << x << '\n';
    else out << "-1\n";
}

int main() {
    in >> T;
    while (T--) {
        in >> N >> P;
        find();
    }
    return 0;
}