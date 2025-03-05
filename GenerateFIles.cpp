#include "manolib.h"

void GenerateFile()
{
    int n,m;
    cout<<"Enter the number of students"<<endl;
    cin>>n;
    cout<<"Enter the number of grades"<<endl;
    cin>>m;

    ofstream fr("STUDENTAI.txt");

    fr<<std::left<<setw(16)<<"Vardas Pavarde "<<std::left<<setw(m*2)<<"Pazymiai "<<"Egzaminas"<<endl;
    for(int i=0; i<n; i++)
    {
        if(rand()%2==0)
        {
            fr<<MNames[rand()%25]<<" "<<MSurnames[rand()%25]<<" ";
        }
        else
        {
            fr<<FNames[rand()%25]<<" "<<FSurnames[rand()%25]<<" ";
        }
        for(int j=0; j<m; j++)
        {
            fr<<rand()%10<<" ";
        }
        fr<<rand()%10<<endl;
    }

}

void SplitFile(vector<Stud> grupe)
{   
    auto start = std::chrono::high_resolution_clock::now();
    sort(grupe.begin(), grupe.end(), [](const Stud& a, const Stud& b) {
        return a.galutinis > b.galutinis;});
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        cout<<grupe.size()<<"rusiavimas truko: "<<duration.count()<<" s"<<endl;

    ifstream fr("STUDENTAI.txt");
    ofstream fr1("Vargsiukai.txt");
    ofstream fr2("Kietiakai.txt");

    for(auto &n:grupe)
    {
        if(n.galutinis<5)
        {
            fr1<<std::left<<setw(15)<<"Vardas"<<setw(15)<<"Pavarde"
    <<setw(15)<<"Galutinis (Vid.)"<<" / "<<"Galutinis (Med.)"<<endl;
    fr1<<"-----------------------------------------------------------"<<endl;
for(auto n :grupe)
  {
    fr1<<std::left<<setw(15)<<n.Vardas<<setw(18)<<n.Pavarde<<setw(7);
    if(n.vm == 'a') fr1<<std::fixed<<std::setprecision(2)<<n.galutinis<<"            -"<<endl;
    else fr1<<" -                "<<std::fixed<<std::setprecision(2)<<n.galutinis<<endl;
  }
        }
        else
        {
            fr2<<std::left<<setw(15)<<"Vardas"<<setw(15)<<"Pavarde"
    <<setw(15)<<"Galutinis (Vid.)"<<" / "<<"Galutinis (Med.)"<<endl;
    fr2<<"-----------------------------------------------------------"<<endl;
for(auto n :grupe)
  {
    fr2<<std::left<<setw(15)<<n.Vardas<<setw(18)<<n.Pavarde<<setw(7);
    if(n.vm == 'a') fr2<<std::fixed<<std::setprecision(2)<<n.galutinis<<"            -"<<endl;
    else fr2<<" -                "<<std::fixed<<std::setprecision(2)<<n.galutinis<<endl;
        }

    }

}   
}