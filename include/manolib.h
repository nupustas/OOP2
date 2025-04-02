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
#include<limits>
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