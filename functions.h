#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "manolib.h"
#include "Readfile.cpp"
#include "GenerateScores.cpp"
#include "FullGenerate.cpp"
#include "Calculations.cpp"
#include "Output.cpp"
#include "ManualInput.cpp"
#include "GenerateFIles.cpp"

void FinalScore(vector<Stud> grupe);
vector<Stud> ReadFile();
vector<Stud> GenerateScores();
vector<Stud> ManualInput();
vector<Stud> GenerateEverything();
void Sorting(vector<Stud> grupe);
void OutputToTerminal(vector<Stud> grupe);
void OutputToFile(vector<Stud> grupe);
void GenerateFile();
void SplitFile(vector<Stud> grupe);

#endif