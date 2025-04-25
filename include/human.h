#pragma once
#include "manolib.h"

class Zmogus {
protected:
    string Vardas, Pavarde;

public:
    Zmogus() : Vardas(""), Pavarde("") {}
    Zmogus(const string& v, const string& p) : Vardas(v), Pavarde(p) {}
    virtual ~Zmogus() = default;


    string getVardas() const { return Vardas; }
    string getPavarde() const { return Pavarde; }

    void setVardas(const string& v) { Vardas = v; }
    void setPavarde(const string& p) { Pavarde = p; }
};
