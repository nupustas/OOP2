#include "manolib.h"

vector<Stud> ManualInput()
{
vector<Stud> grupe;
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
 return grupe;
}