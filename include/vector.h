#pragma once
#include "manolib.h"

template<typename V>
class Vektor{
private:
    V* duom;
    size_t dydis;
    size_t talpa;

void resize(size_t n)
{
    T* temp = new T[n];
    for(size_t i=0; i<dydis; i++)
    {
        temp[i] = duom[i];
    }
    delete[] duom;
    duom = temp;
    talpa = n;
}
public:

//Konstruktoriai
Vektor(): duom(nullptr), dydis(0), talpa(0) {}

//Destruktorius
~Vektor() {
    delete[] duom;
}

//Vektoriaus funkciju realizacija
void push_back(const V& value) {
    if (dydis == talpa) {
        size_t new_talpa;
        if (talpa == 0) {
            new_talpa = 1;
        } else {
            new_talpa = talpa * 2;
        }
        resize(new_talpa);
    }
    duom[dydis++] = value;
}

//setteriai
void setDydis(size_t d) { dydis = d; }
void setTalpa(size_t t) { talpa = t; }
void setDuom(V* d) { duom = d; }

//getteriai
size_t getDydis() const { return dydis; }
size_t getTalpa() const { return talpa; }
V* getDuom() const { return duom; }

};