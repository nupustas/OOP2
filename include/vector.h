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
    V* temp = new V[n];
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
//inicilizavimas su talpaa
Vektor(int d): dydis(0), talpa(d) {
    duom = new V[d];
}
Vektor(int d, const V& value): dydis(d), talpa(d) {
    duom = new V[d];
    for (size_t i = 0; i < d; ++i) {
        duom[i] = value;
    }
}
~Vektor() {
    delete[] duom;
}

size_t size() const {return dydis;}
size_t max_size() const {return std::numeric_limits<size_t>::max();}
size_t capacity() const {return talpa;}
bool empty() const {return dydis ==0;}
void reserve(size_t n) {
    if (n > talpa) {
        resize(n);
    }
}

void swap(Vektor<V>& other){
    std::swap(duom, other.duom);
    std::swap(dydis, other.dydis);
    std::swap(talpa, other.talpa);
}
void shrink_to_fit() {
    if (cap > sz) {
        V* temp = new V[dydis];
        for (size_t i = 0; i < dydis; ++i) {
            temp[i] = duom[i];
        }
        delete[] duom;
        duom = temp;
        talpa = dydis;}}

//Vektoriaus funkciju realizacijos
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
void pop_back() {
    if (dydis == 0) {
        throw std::out_of_range("Cannot pop_back from empty vector");
    }
    --dydis;}

V* begin() {return duom;}
V* end() {return duom+dydis;}
V* clear()
{
    delete[] duom;
    duom = nullptr;
    dydis = 0;
    talpa = 0;
    return duom;
}


//
V& operator[](size_t index) {
    if (index >= dydis) throw std::out_of_range("Index out of range");
    return duom[index];
}


//setteriai


//getteriai


};