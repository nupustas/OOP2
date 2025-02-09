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
    
    while(students < MaxStud)  
    {
        Stud laik;
        

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

    for(int i=0; i<students; i++){
        int suma=0;
            for(int j=0; j<grupe[i].pazcount; j++)
            {
            suma+=grupe[i].paz[j];}

            if(grupe[i].vm=='v'){
                grupe[i].galutinis= 0.4*(suma/grupe[i].pazcount)+0.6*grupe[i].egz;
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
    cout<<std::left<<setw(10)<<grupe[i].Vardas<<setw(10)<<grupe[i].Pavarde<<setw(10);
    if(grupe[i].vm == 'a') cout<<std::fixed<<std::setprecision(2)<<grupe[i].galutinis<<"         -"<<endl;
    else cout<<" -                "<<std::fixed<<std::setprecision(2)<<grupe[i].galutinis<<endl;
}

}
