#ifndef MANOLIB_H
#define MANOLIB_H

#include<vector>
#include<list>
#include<deque>
#include<iomanip> 
#include<iostream>
#include<ctime>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<chrono>
#include <limits>
#include <ios>
#include<string>
#include<type_traits>
#include<exception>


using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::setw;
using std::sort;
using std::left;
using std::fixed;
using std::setprecision;
using std::getline;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::list;
using std::deque;
using std::cerr;
using std::vector;
using std::string;
using std::setw;
using std::is_same_v;


class Stud {
    private:
        string Vardas, Pavarde;
        vector<int> paz;
        int egz;
        char vm;
        double galutinis;
    
        public:
        // Default constructor
        Stud() {
            Vardas = "";
            Pavarde = "";
            egz = 0;
            vm = ' ';
            galutinis = 0.0;
        }
        // Constructor with parameters
        Stud(const string& v, const string& p, const vector<int>& pazymiai, int e, char vmod, double gal) {
            Vardas = v;
            Pavarde = p;
            paz = pazymiai;
            egz = e;
            vm = vmod;
            galutinis = gal;
        }
        // Destructor 
        ~Stud() {
            paz.clear();
        }
        // Copy constructor
        Stud(const Stud& other) : Vardas(other.Vardas), Pavarde(other.Pavarde), paz(other.paz),
        egz(other.egz), vm(other.vm), galutinis(other.galutinis) {}

        // Copy assignment operator
    Stud& operator=(const Stud& other) {
        if (this != &other) {
            Vardas = other.Vardas;
            Pavarde = other.Pavarde;
            paz = other.paz;
            egz = other.egz;
            vm = other.vm;
            galutinis = other.galutinis;
        }
        return *this;
    }   

    // Move constructor
    Stud(Stud&& other) noexcept
        : Vardas(std::move(other.Vardas)), Pavarde(std::move(other.Pavarde)),
          paz(std::move(other.paz)), egz(other.egz), vm(other.vm), galutinis(other.galutinis) {
        other.egz = 0;
        other.vm = ' ';
        other.galutinis = 0.0;
    }
    // Move assignment operator
    Stud& operator=(Stud&& other) noexcept {
        if (this != &other) {
            Vardas = std::move(other.Vardas);
            Pavarde = std::move(other.Pavarde);
            paz = std::move(other.paz);
            egz = other.egz;
            vm = other.vm;
            galutinis = other.galutinis;    

            other.egz = 0;
            other.vm = ' ';
            other.galutinis = 0.0;
        }
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

        return in;
    }

    // Output operator
    friend std::ostream& operator<<(std::ostream& out, const Stud& s) {
        out << std::left << std::setw(15) << s.Vardas
            << std::setw(18) << s.Pavarde;

        if (s.vm == 'a')
            out << std::fixed << std::setprecision(2) << std::setw(7) << s.galutinis << "            -";
        else
            out << " -                " << std::fixed << std::setprecision(2) << s.galutinis;

        return out;
    }

        void setVardas(const string& v) { Vardas = v; }
        void setPavarde(const string& p) { Pavarde = p; }
        void setEgz(int e) { egz = e; }
        void setVm(char v) { vm = v; }
        void setGalutinis(double g) { galutinis = g; }
        void addPaz(int pazymys) { paz.push_back(pazymys); }
    

        string getVardas() const { return Vardas; }
        string getPavarde() const { return Pavarde; }
        int getEgz() const { return egz; }
        char getVm() const { return vm; }
        double getGalutinis() const { return galutinis; }
        vector<int> getPaz() const { return paz; }
        void removeLastPaz() { paz.pop_back(); }

    };

const string MNames[25] = {
    "Andrius", "Dainius", "Jonas" , "Marius", "Orestas", "Povilas", 
    "Aidas",  "Tomas",  "Vejas", "Zygimantas",  "Vaidotas",
    "Linas", "Kestutis", "Vaidotas", "Martynas",   "Gintaras",
     "Tomas", "Antanas", "Paulius",   "Jonas",  "Mantas", 
     "Mindaugas", "Rokas", "Lukas", "Kazimieras"
};
const string MSurnames[25] = {
    "Petrauskas", "Jankauskas", "Kazlauskas", "Zukauskas", "Kavaliauskas", "Stankevicius", "Bieliauskas", 
    "Budvytis", "Giedraitis",  "Rimkus",  "Valiukas", "Juknevicius", "Vaitkevicius", 
     "Vasiliauskas", "Navickas",  "Urbonas", "Grigonis", "Rutkauskas",  
    "Vaitkus", "Pakalnis", "Norkus", "Skripka", "Butkevicius", "Nedzinskas", "Mickevicius",  
};
const string FNames[25] = {
    "Egle", "Indre", "Lina","Neringa","Sigute","Ugne","Laura","Viktorija",
    "Rasa","Gintare","Agne","Ieva", "Milda","Margarita","Aiste", "Vilma",
    "Ruta","Aiste","Gabija","Jurate","Jurgita", "Vaiva", "Ula", "Greta",
    "Kotryna"

};
const string FSurnames[25] = {
"Norkute","Petronyte","Seskinyte","Pakalnaite","Daugelaite","Simonaityte",
"Giedre","Zukaite", "Norkute", "Kaminskaite", "Dapsyte", "Kucinskaite", 
"Vaitkeviciute", "Vasiliauskaite", "Navickaite", "Urbonaite", "Grigoniene",
 "Rutkauskaite", "Vaitkute", "Pakalnyte", "Norkute", "Skripkaite", "Butkeviciute",
"Mickeviciute", "Brazaite"
};

#endif