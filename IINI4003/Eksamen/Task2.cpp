#include <iostream>
#include <vector>

using namespace std;

class Butikk {
public:
    string navn;
    int antall;
    double mva(){
        return tax;
    };
    vector<Butikk> varer;
};

class MatVare {
public:
    double tax = 0.15;
    MatVare(string name, int amount) {

    }
};

class Vare {
public:
    double tax = 0.25;
    Vare(string name, int amount) {

    }
};

int main() {
    Butikk butikk;
    butikk.varer.emplace_back(new MatVare("NTNU-nistepakken", 5));
    butikk.varer.emplace_back(new Vare("NTNU-koppen", 10));
    for (auto &v : butikk.varer) {
        std::cout << v->navn << ", "
                  << v->antall << ", "
                  << v->mva() << std::endl;
    }
}