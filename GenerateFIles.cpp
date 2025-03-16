#include "manolib.h"

string GenerateFile(int StudentCount)
{

    string filename = "Studentai"+std::to_string(StudentCount)+".txt";
    ifstream fd(filename);
    if(fd.good())
    {
        cout<<filename<<" already exists"<<endl;
    }
    fd.close();

    auto start = std::chrono::high_resolution_clock::now();
    ofstream fr(filename);
    if(!fr)
    {
        std::cerr<<"Error creating file" <<filename<<endl;
    }

    fr<<std::left<<setw(16)<<"Vardas Pavarde "<<std::left<<setw(20)<<"Pazymiai   "<<"Egzaminas"<<endl;
    for(int i=0; i<StudentCount; i++)
    {
        if(rand()%2==0)
        {
            fr<<MNames[rand()%25]<<" "<<MSurnames[rand()%25]<<" ";
        }
        else
        {
            fr<<FNames[rand()%25]<<" "<<FSurnames[rand()%25]<<" ";
        }
        for(int j=0; j<10; j++)
        {
            fr<<rand()%10<<" ";
        }
        fr<<rand()%10<<endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    cout<<filename <<" sukurtas per "<<fixed<<setprecision(5)<<duration.count() << " s" << endl;
    return filename;
}

void SplitFile(vector<Stud>& grupe)
{
    auto start_split = std::chrono::high_resolution_clock::now();

    vector<Stud> vargsai;
    vector<Stud> kietiakai;

    vargsai.reserve(grupe.size()); 
    kietiakai.reserve(grupe.size());

    for (auto& n : grupe)
    {
        if (n.galutinis < 5)
            vargsai.push_back(n);
        else
            kietiakai.push_back(n);
    }

    grupe.clear();
    grupe.shrink_to_fit();
    vargsai.shrink_to_fit();
    kietiakai.shrink_to_fit();

    auto end_split = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> split_duration = end_split - start_split;
    //cout << "Dalijimas uztruko: "<<fixed<<setprecision(5)<<split_duration.count() << " s" << endl;

    ofstream fr1("Vargsiukai.txt");
    ofstream fr2("Kietiakai.txt");

    if (!fr1 || !fr2)
    {
        std::cerr << "Error opening output files!" << endl;
        return;
    }

auto startV = std::chrono::high_resolution_clock::now();
    // Write headers
    fr1 << std::left << setw(15) << "Vardas" << setw(15) << "Pavarde"
        << setw(15) << "Galutinis (Vid.)" << " / " << "Galutinis (Med.)" << endl;
    fr1 << "-----------------------------------------------------------" << endl;

    // Write student data
    for (const auto& n : vargsai)
    {
        fr1 << std::left << setw(15) << n.Vardas << setw(18) << n.Pavarde << setw(7);
        if (n.vm == 'a')
            fr1 << fixed << setprecision(2) << n.galutinis << "            -" << endl;
        else
            fr1 << " -                " << fixed << setprecision(2) << n.galutinis << endl;
    }
    auto endV = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> Vduration = endV - startV;
    //cout << "Vargsu irasymo i faila: "<<fixed<<setprecision(5)<< Vduration.count() << " s" << endl;

    auto startK = std::chrono::high_resolution_clock::now();
fr2 << std::left << setw(15) << "Vardas" << setw(15) << "Pavarde"
        << setw(15) << "Galutinis (Vid.)" << " / " << "Galutinis (Med.)" << endl;
    fr2 << "-----------------------------------------------------------" << endl;
    for (const auto& n : kietiakai)
    {
        fr2 << std::left << setw(15) << n.Vardas << setw(18) << n.Pavarde << setw(7);
        if (n.vm == 'a')
            fr2 << fixed << setprecision(2) << n.galutinis << "            -" << endl;
        else
            fr2 << " -                " << fixed << setprecision(2) << n.galutinis << endl;
    }

    auto endK = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> Kduration = endK - startK;
    //cout << "Kietu irasymo i faila: "<<fixed<<setprecision(5)<< Kduration.count() << " s" << endl;

    fr1.close();
    fr2.close();   
}
