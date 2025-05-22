#pragma once
#include "manolib.h"

template<typename V>
class Vektor {
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

using value_type = V;
using size_type = size_t;

//Konstruktoriai
Vektor(): duom(nullptr), dydis(0), talpa(0) {}
//inicilizavimas su talpaa
Vektor(size_t d): dydis(0), talpa(d) {
    duom = new V[d];
}
Vektor(size_t d, const V& value): dydis(d), talpa(d) {
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
void erase(size_t index) {
    if (index >= dydis) throw std::out_of_range("Index out of range");
    for (size_t i = index; i < dydis - 1; ++i) {
        duom[i] = duom[i + 1];
    }
    --dydis;
}
V* erase(V* first, V* last) {
    if (first < duom || last > duom + dydis || first > last)
        throw std::out_of_range("Invalid iterator range");

    size_t start = first - duom;
    size_t end = last - duom;
    size_t range = end - start;

    for (size_t i = end; i < dydis; ++i) {
        duom[i - range] = duom[i];
    }

    dydis -= range;
    return duom + start;
}
void swap(Vektor<V>& other){
    std::swap(duom, other.duom);
    std::swap(dydis, other.dydis);
    std::swap(talpa, other.talpa);
}
void shrink_to_fit() {
    if (talpa > dydis) {
        V* temp = new V[dydis];
        for (size_t i = 0; i < dydis; ++i) {
            temp[i] = duom[i];
        }
        delete[] duom;
        duom = temp;
        talpa = dydis;}
    }

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
V& front() { return duom[0]; }
V& back() { return duom[dydis - 1]; }
void clear()
{
    delete[] duom;
    duom = nullptr;
    dydis = 0;
    talpa = 0;
}

//
V& operator[](size_t index) {
    if (index >= dydis) throw std::out_of_range("Index out of range");
    return duom[index];
}
// Copy constructor
Vektor(const Vektor<V>& other) : dydis(other.dydis), talpa(other.talpa) {
    duom = new V[talpa];
    for (size_t i = 0; i < dydis; ++i) {
        duom[i] = other.duom[i];
    }
}
// Copy assignment operator
Vektor<V>& operator=(const Vektor<V>& other) {
    if (this != &other) {
        delete[] duom;
        dydis = other.dydis;
        talpa = other.talpa;
        duom = new V[other.talpa];
        for (size_t i = 0; i < dydis; ++i) {
            duom[i] = other.duom[i];
        }
    }
    return *this;
}
// Move constructor
Vektor(Vektor<V>&& other) noexcept 
    : duom(other.duom), dydis(other.dydis), talpa(other.talpa) {
    other.duom = nullptr;
    other.dydis = 0;
    other.talpa = 0;
}

// Move assignment operator
Vektor<V>& operator=(Vektor<V>&& other) noexcept {
    if (this != &other) {
        delete[] duom;
        duom = other.duom;
        dydis = other.dydis;
        talpa = other.talpa;

        other.duom = nullptr;
        other.dydis = 0;
        other.talpa = 0;
    }
    return *this;
}
bool operator==(const Vektor<V>& other) const {
    if (dydis != other.dydis) return false;
    for (size_t i = 0; i < dydis; ++i) {
        if (!(duom[i] == other.duom[i])) return false;
    }
    return true;
}
bool operator!=(const Vektor<V>& other) const {
    return !(*this == other);
}
bool operator<(const Vektor<V>& other) const {
    for (size_t i = 0; i < std::min(dydis, other.dydis); ++i) {
        if (duom[i] < other.duom[i]) return true;
        if (duom[i] > other.duom[i]) return false;
    }
    return dydis < other.dydis;
}
bool operator<=(const Vektor<V>& other) const {
    return !(other < *this);
}
bool operator>(const Vektor<V>& other) const {
    return other < *this;
}
bool operator>=(const Vektor<V>& other) const {
    return !(*this < other);
}

}; 
