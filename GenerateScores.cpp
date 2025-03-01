#include "manolib.h"

//Vardo ir pavardes ivedimas, pazymiu generavimas
vector<Stud> GenerateScores()
{
    cout << "Selected 2-Input names, generate scores" << endl;
        cout<<endl;
    vector<Stud> grupe;
        while(true)
        {
            Stud laik;
            cout<<"Input name: ";
            cin>>laik.Vardas;
            cout<<"Input surname: ";
            cin>>laik.Pavarde;

            cout<<"How many homework scores do you want to generate? ";
            int n;
            cin>>n;
            srand(time(NULL));
            for(int i=0; i<n; i++)
            {
                laik.paz.push_back(rand()%10);
            }
            laik.egz=rand()%10;

            grupe.push_back(laik);

            cout<<"Enter more students? (y/n)";
            char x;
            cin>>x;
            while(x!= 'y' && x!= 'n') 
            {   
                cout<<"Invalid input. Enter y or n"<<endl;
                cin>>x;
            }
            if(x=='n') break;
            
        }
        return grupe;
}