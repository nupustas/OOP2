#include<vector>
#include<iomanip> 
#include<iostream>
#include<ctime>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::setw;

string MNames[] = {
    "Andrius", "Dainius",   "Jonas"  "Marius", "Orestas", "Povilas", 
    "Aidas",  "Tomas",  "Vejas", "Žygimantas",  "Vaidotas",
    "Marius",   "Linas", "Kęstutis", "Tomas", "Vaidotas", "Dainius", 
     "Martynas",   "Gintaras",  "Dainius", "Tomas", "Vaidotas",
     "Antanas", "Paulius",   "Jonas"
};

string MSurnames[] = {
    "Petrauskas", "Jankauskas", "Kazlauskas", "Žukauskas", "Kavaliauskas", "Stankevičius", "Bieliauskas", 
    "Būdvytis", "Giedraitis",  "Rimkus",  "Valiukas", "Juknevičius", "Vaitkevičius", 
     "Vasiliauskas", "Navickas",  "Urbonas", "Grigonis", "Rutkauskas",  
    "Vaitkus", "Pakalnis", "Norkus", "Skripka", "Butkevičius", "Nedzinskas", "Mickevičius",  
};

string FNames[] = {
    "Eglė", "Indrė", "Lina","Neringa","Sigutė","Ugnė","Laura","Viktorija",
    "Rasa","Gintarė","Agne","Ieva", "Milda","Margarita","Aistė", "Vilma",
    "Rūta","Aistė","Gabija","Jūratė","Jurgita", "Vaiva", "Ula", "Greta",
    "Kotryna"

};
string FSurnames[] = {
"Kavaliauskaitė","Petronytė","Šeškinytė","Pakalnaitė","Daugėlaitė","Simonaitytė",
"Giedrė","Žukaitė", "Bieliauskaitė","Kaminskaitė",  "Dapšytė", "Kučinskaitė", 
"Vaitkevičiūtė", "Vasiliauskaitė", "Navickaitė", "Urbonaitė", "Grigonienė",
 "Rutkauskaitė", "Vaitkutė", "Pakalnytė", "Norkutė", "Skripkaitė", "Butkevičiūtė",
"Mickevičiūtė", "Brazaitė"
};