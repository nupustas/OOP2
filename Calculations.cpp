#include "manolib.h"

void FinalScore(vector<Stud>& grupe)
{
    cout<<"Calculate final scores using average or median? (a/m)"<<endl;
    char am;
    cin>>am;
    while(am!= 'a' && am!= 'm') 
    {   
        cout<<"Invalid input. Enter a or m"<<endl;
        cin>>am;
    }

    for(auto &n :grupe)
    {
        sort(n.paz.begin(), n.paz.end());
        n.vm=am;
        int suma=0;
            for(auto n: n.paz)
            {
            suma=suma+n;}
            if(am=='a'){
                n.galutinis= 0.4*(suma/n.paz.size())+0.6*n.egz;
            }
            else if (n.paz.size()%2==0){
                n.galutinis=0.4*(n.paz[n.paz.size()/2] + n.paz[n.paz.size()/2-1])/2 +0.6*n.egz;
            }
            else{
                n.galutinis=0.4*n.paz[n.paz.size()/2] +0.6*n.egz;
            }
        }
        
}

bool compareByName(const Stud& a, const Stud& b) {
    return a.Vardas < b.Vardas;  // (A-Z)
}
bool compareBySurname(const Stud& a, const Stud& b) {
    return a.Pavarde < b.Pavarde;  // (A-Z)
}

void Sorting(vector<Stud> grupe)
{
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

}



