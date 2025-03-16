#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void FinalScore(vector<Stud>& grupe);
vector<Stud> ReadFile(string filename);
vector<Stud> GenerateScores();
vector<Stud> ManualInput();
vector<Stud> GenerateEverything();
void Sorting(vector<Stud>& grupe);
void OutputToTerminal(vector<Stud>& grupe);
void OutputToFile(vector<Stud>& grupe);
string GenerateFile(int StudentCount);
void SplitFile(vector<Stud>& grupe);


#endif