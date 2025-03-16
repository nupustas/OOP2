#include "manolib.h"

void OutputToTerminal(vector<Stud>& grupe)
{
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

void OutputToFile(vector<Stud>& grupe)
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