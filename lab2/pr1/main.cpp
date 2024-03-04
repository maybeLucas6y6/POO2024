#include "NumberList.h"

int main() {
    NumberList nl;
    nl.Init(69);

    nl.Add(10);
    nl.Add(11);
    nl.Add(18);
    nl.Add(1);
    nl.Add(12);

    nl.Sort();
    nl.Print();

    nl.Uninit();
    return 0;
}
