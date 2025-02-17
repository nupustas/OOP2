#include "manolib.h"

void ReadFile(int n, vector<Stud> &grupe);
void CalculateFinalScore(vector<Stud> &grupe);

void ReadFile(int n, vector<Stud> &grupe)
{

std::ifstream fd("studentai10000.txt");
if(!fd)
{
    cout<<"File not found"<<endl;
    return;
}
for(int i=0; i<n; i++)
{
    Stud student;
    fd>>student.Vardas>>student.Pavarde;

    int paz;
    for(int j=0; j<15; j++)
    {
        fd>>paz;
        student.paz.push_back(paz);
        
    }
    fd>>student.egz;

    grupe.push_back(student);
}

}
