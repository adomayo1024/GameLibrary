#include "../include/CycleInt.h"


myGE::CycleInt::CycleInt(int max) : i(0)
                                , max(max) {
}

myGE::CycleInt myGE::CycleInt::operator++(int) {
    CycleInt temp = *this;
    i = (i + 1) % max;
    return temp;
}

myGE::CycleInt myGE::CycleInt::operator--(int) {
    i = (i == 0) ? max - 1 : i - 1;
    return *this;
}


// TODO schöner machen nicht mit if abfrage
int myGE::CycleInt::operator-(int o) {
    int res;
    if(o < 0) {
        res = *this + (-1 * o);
    } else {
        // wenn o > max geht, man eh einmal herum, dann kann man auch einfach nur die nötigen Schritte, die dann noch bleiben, gehen.
        o = o % max;
        // wenn o > i ist, würde es in den negativen Bereich gehen, deshalb zieht man den Wert, der bei i - o herauskommt, vom Max ab.
        res = (o <= i) ? (i - o) % max : max + (i - o);
    }
    return res;
}

// TODO schöner machen nicht mit if abfrage
int myGE::CycleInt::operator+(int o) {
    int res;
    if(o < 0) {
        res = *this - (-1 * o);
    } else {
        o = o % max;
        res = (i + o >= max) ? 0 - (max - (i + o)) : i + o;
    }
    return res;
}

myGE::CycleInt::operator int() const {
    return i;
}

bool myGE::CycleInt::operator==(int o) {
    return i == 0;
}

myGE::CycleInt &myGE::CycleInt::operator=(const int &value) {
    if(value < max && value >= 0) {
        i = value;
    }
    return *this;
}
