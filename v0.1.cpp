#include "manolib.h"

int main()
{
    vector<Stud> grupe;

    char a; 
    cout<<"1-Input everything manually"<<endl;
    cout<<"2-Input names, generate scores"<<endl;
    cout<<"3-Generate everything"<<endl;
    cin>>a;
    while(a!= '1' && a!= '2' &&a!= '3') 
    {   
        cout<<"Invalid input. Enter 1, 2 or 3"<<endl;
        cin>>a;
    }

    if(a=='3')//Visko "generavimas"
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
                laik.paz.push_back(rand()%11);
            }
            laik.egz=rand()%11;

            if(rand()%2==0) laik.vm='a';
            else laik.vm='m';
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
    
    else //Visko ivedimas ranka
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

    //Galutinio pazymio skaiciavimas
    for(auto &n :grupe){
        sort(n.paz.begin(), n.paz.end());

        int suma=0;
            for(auto n: n.paz)
            {
            suma=suma+n;}
            if(n.vm=='v'){
                n.galutinis= 0.4*(suma/n.paz.size())+0.6*n.egz;
            }
            else if (n.paz.size()%2==0){
                n.galutinis=0.4*(n.paz[n.paz.size()/2] + n.paz[n.paz.size()/2-1])/2 +0.6*n.egz;
            }
            else{
                n.galutinis=0.4*n.paz[n.paz.size()/2] +0.6*n.egz;
            }
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
