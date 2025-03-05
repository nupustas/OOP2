#include "manolib.h"
#include "functions.h"

int main()
{
    
    vector<Stud> grupe;

    char a; 
    cout<<"1-Input everything manually"<<endl;
    cout<<"2-Input names, generate scores"<<endl;
    cout<<"3-Generate everything"<<endl;
    cout<<"4-Read from file"<<endl;
    cout<<"5-Generate file"<<endl;
    cin>>a;
    while(a!= '1' && a!= '2' &&a!= '3' &&a!= '4' &&a!= '5') //Patikrinimas ar ivestas skaicius yra tinkamas
    {   
        cout<<"Invalid input. Enter 1, 2, 3 or 4"<<endl;
        cin>>a;
    }

try
{
    if (a== '1') //Visko ivedimas ranka
    {   
        grupe = ManualInput();
    } 
    else if(a=='2') //Vardo ir pavardes ivedimas, pazymiu generavimas
     {  
        grupe = GenerateScores();
     } 
    else if(a=='3')//Visko "generavimas"
    {
        grupe = GenerateEverything();
    }
    else if(a=='4') //Failo nuskaitymas
    {
        string filename;
    cout << "Enter file name: ";
    cin >> filename;
        grupe = ReadFile(filename);
    }
    else if(a=='5') //Failo generavimas
    {
        int StudentCount;
        cout<<"Enter the number of students"<<endl;
        cin>>StudentCount;

        auto start = std::chrono::high_resolution_clock::now();
        string filename = GenerateFile(StudentCount);
        cout<<filename<<endl;

        grupe = ReadFile(filename);
        FinalScore(grupe);
        SplitFile(grupe);
        
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        cout<<filename<<" failo testo laikas: "<<fixed<<setprecision(5)<<duration.count()<<" s"<<endl;
        return 0;
    }
}
catch(std::exception& e)
{
    std::cerr<<e.what()<<endl;
    return 0;
}


    try{
        FinalScore(grupe); //Galutinio pazymio skaiciavimas
       }
    catch(string& msg)
    {
        cout<<msg<<endl;
        return 0;
    }

    Sorting(grupe); //Rusiavimas


        cout<<"Show results in file or terminal?"<<endl;
        cout<<"1-file"<<endl;
        cout<<"2-terminal"<<endl;
        int y;
        cin>>y;
        while(y!=1 && y!=2 || y>10)
        {
            cout<<"Invalid input. Enter 1 or 2"<<endl;
            cin>>y;
        }

    //Isvedimas
   if (y==2) OutputToTerminal(grupe);
   else OutputToFile(grupe);

 return 0;
}