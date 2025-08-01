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
    i = (i - 1) % max;
    return *this;
}

int myGE::CycleInt::operator-(int o) {
    return (i - o) % max;
}

myGE::CycleInt::operator int() const {
    return i;
}

bool myGE::CycleInt::operator==(int o) {
    return i == 0;
}
