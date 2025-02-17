#include "manolib.h"
//Vardo ir pavardes ivedimas, pazymiu generavimas
void GenerateScores(vector<Stud> &grupe)
{
    cout << "Selected 2-Input names, generate scores" << endl;
        cout<<endl;

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
                laik.paz.push_back(rand()%11);
            }
            laik.egz=rand()%11;

            cout<<"Calculate final score with average or median? (a/m)";
            cin>>laik.vm;
            while(laik.vm!= 'a' && laik.vm!= 'm') 
            {   
                cout<<"Invalid input. Enter a or m"<<endl;
                cin>>laik.vm;
            }

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
}