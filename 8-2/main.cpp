#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

template<typename T>
long nbOcc(const T &aTrouver, T tab[], size_t nbElements) {
    return count(tab, tab + nbElements, aTrouver);
}

template<>
long nbOcc(const char *const &aTrouver, const char *tab[], size_t nbElements) {
    long cnt = 0;

    for(size_t i = 0; i < nbElements; ++i) {
        if (strcmp(aTrouver, tab[i]) == 0) {
            ++cnt;
        }
    }

    return cnt;
}

class Temps {
    int heure, minute;
public:
    Temps(int heure, int minute) : heure(heure), minute(minute) {}

    bool operator==(const Temps &other) const {
        return heure == other.heure and minute == other.minute;
    }

    bool operator!=(const Temps &other) const {
        return not(operator==(other));
    }
};

int main() {
    int t1[]{0, 1, 0};
    Temps t2[]{Temps(7, 45), Temps(9, 20), Temps(12, 00), Temps(21, 30)};
    string t3[]{"Paul", "Jacques", "Paul", "Jean", "Paul"};
    const char *t4[]{"Paul", "Jacques", "Paul", "Jean", "Paul"};

    cout << nbOcc(0, t1, 3) << endl;
    cout << nbOcc(Temps(12, 00), t2, 4) << endl;
    cout << nbOcc(string("Paul"), t3, 5) << endl;
    const char *paul = "Paul";
    cout << nbOcc(paul, t4, 5) << endl;
}