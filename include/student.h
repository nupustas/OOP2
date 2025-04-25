// Stud.h
#pragma once
#include "human.h"
#include "manolib.h"


class Stud : public Zmogus {
private:
    std::vector<int> paz;
    int egz;
    char vm;
    double galutinis;

public:
    // Constructors
    Stud() : Zmogus(), egz(0), vm(' '), galutinis(0.0) {}
    Stud(const std::string& v, const std::string& p, const std::vector<int>& pazymiai, int e, char vmod, double gal)
        : Zmogus(v, p), paz(pazymiai), egz(e), vm(vmod), galutinis(gal) {}

    // Destructor
    ~Stud() { paz.clear(); }

    // Copy constructor
    Stud(const Stud& other)
        : Zmogus(other.Vardas, other.Pavarde), paz(other.paz), egz(other.egz), vm(other.vm), galutinis(other.galutinis) {}

    // Copy assignment
    Stud& operator=(const Stud& other) {
        if (this == &other) return *this;
        Vardas = other.Vardas;
        Pavarde = other.Pavarde;
        paz = other.paz;
        egz = other.egz;
        vm = other.vm;
        galutinis = other.galutinis;
        return *this;
    }

    // Move constructor
    Stud(Stud&& other) 
        : Zmogus(std::move(other.Vardas), std::move(other.Pavarde)), paz(std::move(other.paz)),
          egz(other.egz), vm(other.vm), galutinis(other.galutinis) {
        other.egz = 0;
        other.vm = ' ';
        other.galutinis = 0.0;
    }

    // Move assignment
    Stud& operator=(Stud&& other)  {
        if (this == &other) return *this;
        Vardas = std::move(other.Vardas);
        Pavarde = std::move(other.Pavarde);
        paz = std::move(other.paz);
        egz = other.egz;
        vm = other.vm;
        galutinis = other.galutinis;
        other.egz = 0;
        other.vm = ' ';
        other.galutinis = 0.0;
        return *this;
    }

    // Input operator
    friend std::istream& operator>>(std::istream& in, Stud& s) {
        std::cout << "Iveskite varda: ";
        in >> s.Vardas;
        std::cout << "Iveskite pavarde: ";
        in >> s.Pavarde;

        std::cout << "Iveskite pazymiu kieki: ";
        int kiekis;
        in >> kiekis;

        s.paz.clear();
        std::cout << "Iveskite pazymius: ";
        for (int i = 0; i < kiekis; ++i) {
            int pazymys;
            in >> pazymys;
            s.paz.push_back(pazymys);
        }

        std::cout << "Iveskite egzamino rezultata: ";
        in >> s.egz;

        std::cout << "Iveskite vertinimo metoda (a/m): ";
        in >> s.vm;

        s.FinalScore();
        return in;
    }

    // Output operator
    friend std::ostream& operator<<(std::ostream& out, const Stud& s) {
        out << std::left << std::setw(15) << s.Vardas
            << std::setw(18) << s.Pavarde;

        if (s.vm == 'a')
            out << std::fixed << std::setprecision(2) << std::setw(7) << s.galutinis << "            -" << std::endl;
        else
            out << " -                " << std::fixed << std::setprecision(2) << s.galutinis << std::endl;

        return out;
    }

    // getters & setters
    void setEgz(int e) { egz = e; }
    void setVm(char v) { vm = v; }
    void setGalutinis(double g) { galutinis = g; }
    void addPaz(int pazymys) { paz.push_back(pazymys); }

    int getEgz() const { return egz; }
    char getVm() const { return vm; }
    double getGalutinis() const { return galutinis; }
    std::vector<int> getPaz() const { return paz; }
    void removeLastPaz() { paz.pop_back(); }

    // Score calculation
    void FinalScore() {
        if (paz.empty()) {
            galutinis = 0.0;
            return;
        }
        if (vm == 'a') {
            double sum = 0.0;
            for (int pazymys : paz) sum += pazymys;
            galutinis = 0.4 * (sum / paz.size()) + 0.6 * egz;
        } else if (vm == 'm') {
            std::sort(paz.begin(), paz.end());
            int medianas = paz[paz.size() / 2];
            galutinis = 0.4 * medianas + 0.6 * egz;
        }
    }
};
