#include "manolib.h"

void GenerateFile()
{
    int n, m;
    cout<<"Enter the number of students"<<endl;
    cin>>n;
    cout<<"Enter the number of grades"<<endl;
    cin>>m;

    ofstream fr("STUDENTAI.txt");

    fr<<std::left<<setw(16)<<"Vardas Pavarde "<<std::left<<setw(m*2)<<"Pazymiai "<<"Egzaminas"<<endl;
    for(int i=0; i<n; i++)
    {
        if(rand()%2==0)
        {
            fr<<MNames[rand()%25]<<" "<<MSurnames[rand()%25]<<" ";
        }
        else
        {
            fr<<FNames[rand()%25]<<" "<<FSurnames[rand()%25]<<" ";
        }
        for(int j=0; j<m; j++)
        {
            fr<<rand()%10<<" ";
        }
        fr<<rand()%10<<endl;
    }

}