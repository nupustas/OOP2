#include "manolib.h"

int main()
{
    std::vector<Stud> grupe;

    for(int i=0;i<1;i++)
    {
        Stud laik;
        cout<<"Input name: "<<endl;
        cin>>laik.Vardas;
        cout<<"Input surname: "<<endl;
        cin>>laik.Pavarde;

        cout<<"Input your hw scores 1-10. After your last one enter 11 "<<endl;
        int paz;
        cin>>paz;
        while(paz>0 && paz<=10)
        {
            laik.paz.push_back(paz);
            cin>>paz;
        }

        cout<<"Input exam score: "<<endl;
        cin>>laik.egz;

        cout<<"Skaiciuoti galutini bala pagal vidurki ar mediana? (v/m)"<<endl;
        cin>>laik.vm;

        grupe.push_back(laik);
    }

    for(auto &n :grupe){
        int suma=0;
            for(auto n: n.paz)
            {
            suma=suma+n;}
            if(n.vm=='v'){
                n.galutinis= 0.4*(suma/n.paz.size())+0.6*n.egz;
            }
            else if (n.paz.size()%2==0){
                n.galutinis=0.4*(n.paz[n.paz.size()/2]+n.paz[n.paz.size()/2-1])/2+0.6*n.egz;
            }
            else{
                n.galutinis=0.4*n.paz[n.paz.size()/2]+0.6*n.egz;
                
            }
            
        }

for(auto n :grupe){
    cout<<std::left<<setw(10)<<"Vardas"<<setw(10)<<"Pavarde"<<setw(10)<<"Galutinis (vid)"<<" / "<<"Galutinis (med)"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<std::left<<setw(10)<<n.Vardas<<setw(10)<<n.Pavarde<<setw(10);
    if(n.vm == 'v') cout<<std::fixed<<std::setprecision(2)<<n.galutinis<<"       0.00"<<endl;
    else cout<<"0.00               "<<std::fixed<<std::setprecision(2)<<n.galutinis<<endl;
}

}
