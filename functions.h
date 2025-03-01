#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "manolib.h"
#include "Readfile.cpp"
#include "GenerateScores.cpp"
#include "FullGenerate.cpp"
#include "Calculations.cpp"
#include "Output.cpp"

void FinalScore(vector<Stud> grupe);
vector<Stud> ReadFile();
vector<Stud> GenerateScores();
vector<Stud> ManualInput();
vector<Stud> GenerateEverything();
void Sorting(vector<Stud> grupe);
int OutputToTerminal(vector<Stud> grupe);
int OutputToFile(vector<Stud> grupe);

#endif