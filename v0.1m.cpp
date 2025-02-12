#include "manolib.h"
const int MaxStud=100;
const int MaxPaz=20;

struct Stud
{
    string Vardas="a",Pavarde="b";
    int paz[MaxPaz];
    int pazcount;
    int egz;
    char vm;
    double galutinis;

};


int main()
{
    Stud grupe[MaxStud];
    int students=0;
    
    
        Stud laik;
        
        char a;
    cout<<"Do you want to input everything manually, input names and generate scores, or generate everything?(m/s/r)";
    cin>>a;
    while(a!= 'm' && a!= 's' &&a!= 'r') 
    {   
        cout<<"Invalid input. Enter m , s or r"<<endl;
        cin>>a;
    }

    if(a=='r')//Visko "generavimas"
    {
        cout<<"How many students do you want to generate? ";
        int n;
        cin>>n;
    
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
           
            for(int j=0; j<5; j++)
            {
                laik.paz[j]= rand()%11;
            }
            laik.egz=rand()%11;
            laik.pazcount=5;
            if(rand()%2==0) laik.vm='a';
            else laik.vm='m';
            grupe[students++]=laik;
        }
    }
     
    else if(a=='s') //Vardo ir pavardes ivedimas, pazymiu generavimas
     {
        cout<<"Input student names manually, generate scores"<<endl;

        while(true)
        {
            Stud laik;
            cout<<"Input name: ";
            cin>>laik.Vardas;
            cout<<"Input surname: ";
            cin>>laik.Pavarde;

            cout<<"How many homework scores do you want to generate? ";
            cin>>laik.pazcount;
            srand(time(NULL));
            for(int i=0; i<laik.pazcount; i++)
            {
                laik.paz[i]= rand()%11;
                
            }
                laik.egz=rand()%11;
            cout<<"Calculate final score with average or median? (a/m)";
            cin>>laik.vm;
            while(laik.vm!= 'a' && laik.vm!= 'm') 
            {   
                cout<<"Invalid input. Enter a or m"<<endl;
                cin>>laik.vm;
            }


            grupe[students++]=laik;

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
    
     //visko ivedimas ranka
    else{
        cout<<"Input students manually"<<endl;
        while(true)
        {
        cout<<"Input name: "<<endl;
        cin>>laik.Vardas;
        cout<<"Input surname: "<<endl;
        cin>>laik.Pavarde;

        cout<<"Input your hw scores 1-10. After your last one enter 11 "<<endl;
        int paz, i=0;
        cin>>paz;
        while(paz>=0 && paz<=10 && i<MaxPaz)
        {
            laik.paz[i++]= paz;
            cin>>paz;
        }
        laik.pazcount=i;
        
        cout<<"Enter exam score: ";
        cin>>laik.egz;

        cout<<"Calculate final score with average or median? (a/m)";
        cin>>laik.vm;
        while(laik.vm!= 'a' && laik.vm!= 'm') 
        {   
            cout<<"Invalid input. Enter a or m"<<endl;
            cin>>laik.vm;
        }

        grupe[students++]=laik;
    
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

    for(int i=0; i<students; i++){

        sort(grupe[i].paz, grupe[i].paz+grupe[i].pazcount);
        double suma=0;
            for(int j=0; j<grupe[i].pazcount; j++)
            {
            suma+=grupe[i].paz[j];
            }

            if(grupe[i].vm=='a'){
                grupe[i].galutinis= 0.4*(suma/grupe[i].pazcount)+ 0.6*grupe[i].egz;
            }
            else if (grupe[i].pazcount%2==0){
                grupe[i].galutinis=0.4*(grupe[i].paz[grupe[i].pazcount/2] + grupe[i].paz[grupe[i].pazcount/2-1])/2 +0.6*grupe[i].egz;
            }
            else{
                grupe[i].galutinis=0.4*grupe[i].paz[grupe[i].pazcount/2] +0.6*grupe[i].egz;
            }
        }

    cout<<std::left<<setw(10)<<"Vardas"<<setw(10)<<"Pavarde"<<setw(10)<<"Galutinis (Vid.)"<<" / "<<"Galutinis (Med.)"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    
for(int i=0; i<students; i++)
{
    cout<<std::left<<setw(15)<<grupe[i].Vardas<<setw(18)<<grupe[i].Pavarde<<setw(7);
    if(grupe[i].vm == 'a') cout<<std::fixed<<std::setprecision(2)<<grupe[i].galutinis<<"            -"<<endl;
    else cout<<" -                "<<std::fixed<<std::setprecision(2)<<grupe[i].galutinis<<endl;
}

}
