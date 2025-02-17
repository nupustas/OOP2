#include "manolib.h"
//Visko generavimas
void GenerateEverything(vector<Stud> &grupe)
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