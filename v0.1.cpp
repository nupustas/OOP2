#include "manolib.h"
#include "ReadFile.cpp"
#include "FullGenerate.cpp"
#include "GenerateScores.cpp"
#include "ManualInput.cpp"
#include "FinalScore.cpp"

int main()
{
    vector<Stud> grupe;

    char a; 
    cout<<"1-Input everything manually"<<endl;
    cout<<"2-Input names, generate scores"<<endl;
    cout<<"3-Generate everything"<<endl;
    cout<<"4-Read from file"<<endl;
    cin>>a;
    while(a!= '1' && a!= '2' &&a!= '3' &&a!= '4') 
    {   
        cout<<"Invalid input. Enter 1, 2, 3 or 4"<<endl;
        cin>>a;
    }

    if (a== '4') //Failo nuskaitymas
    {   
        string filename = "studentai10000.txt";
        int n;
        cout<<"How many students to read from file?";
        cin>>n;
        cout<<"How do you want to sort the students?"<<endl;
        cout<<"1-By name"<<endl;
        cout<<"2-By surname"<<endl;
        cout<<"3-By final score descending"<<endl;
        cout<<"4-By final score ascending"<<endl;
        int x;
        cin>>x;
        vector<string> lines = ReadLinesFromFile(filename, n);
        grupe = ParseStudents(lines);

        FinalScore(grupe);//Galutinio pazymio skaiciavimas
        if(x==1)std::sort(grupe.begin(), grupe.end(), compareByName);
        else if(x==2)std::sort(grupe.begin(), grupe.end(), compareBySurname);
        else if(x==3)std::sort(grupe.begin(), grupe.end(), [](const Stud& a, const Stud& b) {
            return a.galutinis > b.galutinis;
        });
        else std::sort(grupe.begin(), grupe.end(), [](const Stud& a, const Stud& b) {
            return a.galutinis < b.galutinis;
        });
        
    }
    else if(a=='3')//Visko "generavimas"
    {
        GenerateEverything(grupe);
        FinalScore(grupe);//Galutinio pazymio skaiciavimas
    }
    else if(a=='2') //Vardo ir pavardes ivedimas, pazymiu generavimas
     {  
        GenerateScores(grupe);
        FinalScore(grupe);//Galutinio pazymio skaiciavimas
     }   
    else //Visko ivedimas ranka
    {
        ManualInput(grupe);
        FinalScore(grupe);//Galutinio pazymio skaiciavimas
    }

    //Isvedimas
    cout<<std::left<<setw(15)<<"Vardas"<<setw(15)<<"Pavarde"<<setw(15)<<"Galutinis (Vid.)"<<" / "<<"Galutinis (Med.)"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
for(auto n :grupe)
{
    cout<<std::left<<setw(15)<<n.Vardas<<setw(18)<<n.Pavarde<<setw(7);
    if(n.vm == 'a') cout<<std::fixed<<std::setprecision(2)<<n.galutinis<<"            -"<<endl;
    else cout<<" -                "<<std::fixed<<std::setprecision(2)<<n.galutinis<<endl;
}

}
