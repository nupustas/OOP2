#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Readfile.cpp"
#include "FinalScore.cpp"

void FinalScore(vector<Stud> &grupe);
vector<Stud> ParseStudents(const vector<string>& lines);
vector<string> ReadLinesFromFile(const string& filename);

#endif