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
    cin>>a;
    while(a!= '1' && a!= '2' &&a!= '3' &&a!= '4') 
    {   
        cout<<"Invalid input. Enter 1, 2, 3 or 4"<<endl;
        cin>>a;
    }

    if (a== '1') //Visko ivedimas ranka
    {   
        cout << "Selected 1-Input everything manually" << endl;
        cout<<endl;
    while(true)
    {
        Stud laik;
        cout<<"Input name: ";
        cin>>laik.Vardas;
        cout<<"Input surname: ";
        cin>>laik.Pavarde;

        cout<<"Input your hw scores 1-10. After your last one enter 11 "<<endl;
        int paz;
        cin>>paz;
        while(paz>=0 && paz<=10)
        {
            laik.paz.push_back(paz);
            cin>>paz;
        }

        cout<<"Enter exam score: ";
        cin>>laik.egz;

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
    else if(a=='3')//Visko "generavimas"
    {
    cout<<"Selected '3-Generate everything' "<<endl;
    cout<<endl;
    cout<<"How many students do you want to generate? ";
    int n;
    cin>>n;
    cout<<"How many homework scores do you want to generate? ";
    int x;
    cin>>x;
    
    srand(time(NULL));
    for(int i=0; i<n; i++)
    {
        Stud laik;
        
        int gender=rand()%2;
            if(gender==0){
                laik.Vardas=FNames[rand()%25];
                laik.Pavarde=FSurnames[rand()%25];
            }
            else{
                laik.Vardas=MNames[rand()%25];
                laik.Pavarde=MSurnames[rand()%25];
            }
           
            for(int j=0; j<x; j++)
            {
                laik.paz.push_back(rand()%10);
            }
            laik.egz=rand()%10; 
            
            grupe.push_back(laik);

    }
    }
    else if(a=='2') //Vardo ir pavardes ivedimas, pazymiu generavimas
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
     }   
    else //Failo nuskaitymas
    {
        grupe = ReadFile();
    }
        
    cout<<"Calculate final scores using average or median? (a/m)"<<endl;
    char am;
    cin>>am;
    while(am!= 'a' && am!= 'm') 
    {   
        cout<<"Invalid input. Enter a or m"<<endl;
        cin>>am;
    }
    FinalScore(grupe, am);//Galutinio pazymio skaiciavimas

    cout<<"How do you want to sort the students?"<<endl;
        cout<<"1-By name"<<endl;
        cout<<"2-By surname"<<endl;
        cout<<"3-By final score descending"<<endl;
        cout<<"4-By final score ascending"<<endl;
        char x;
        cin>>x;
        while(x!='1' && x!='2' && x!='3' && x!='4')
        {
            cout<<"Invalid input. Enter 1, 2, 3 or 4"<<endl;
            cin>>x;
        }

        if(x=='1')sort(grupe.begin(), grupe.end(), compareByName);
        else if(x=='2')sort(grupe.begin(), grupe.end(), compareBySurname);

            else if(x=='3')sort(grupe.begin(), grupe.end(), [](const Stud& a, const Stud& b) {
                return a.galutinis > b.galutinis;});

                else sort(grupe.begin(), grupe.end(), [](const Stud& a, const Stud& b) {
                    return a.galutinis < b.galutinis;});


        cout<<"Show results in file or terminal?"<<endl;
        cout<<"1-file"<<endl;
        cout<<"2-terminal"<<endl;
        int y;
        cin>>y;
        while(y!=1 && y!=2)
        {
            cout<<"Invalid input. Enter 1 or 2"<<endl;
            cin>>y;
        }


    //Isvedimas
   if (y==2) {
    cout<<std::left<<setw(15)<<"Vardas"<<setw(15)<<"Pavarde"
    <<setw(15)<<"Galutinis (Vid.)"<<" / "<<"Galutinis (Med.)"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
for(auto n :grupe)
{
    cout<<std::left<<setw(15)<<n.Vardas<<setw(18)<<n.Pavarde<<setw(7);
    if(n.vm == 'a') cout<<std::fixed<<std::setprecision(2)<<n.galutinis<<"            -"<<endl;
    else cout<<" -                "<<std::fixed<<std::setprecision(2)<<n.galutinis<<endl;
}
   }
   else
   {
       ofstream out("rezultatai.txt");
       out<<std::left<<setw(15)<<"Vardas"<<setw(15)<<"Pavarde"
       <<setw(15)<<"Galutinis (Vid.)"<<" / "<<"Galutinis (Med.)"<<endl;
       out<<"-----------------------------------------------------------"<<endl;
   for(auto n :grupe)
   {
       out<<std::left<<setw(15)<<n.Vardas<<setw(18)<<n.Pavarde<<setw(7);
       if(n.vm == 'a') out<<std::fixed<<std::setprecision(2)<<n.galutinis<<"            -"<<endl;
       else out<<" -                "<<std::fixed<<std::setprecision(2)<<n.galutinis<<endl;
   }
   out.close();
   }
}