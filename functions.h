#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "manolib.h"
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <iostream>

using namespace std;

// Visko generavimas
template <typename Container>
Container GenerateEverything() {
    Container grupe;
    cout << "Selected '3-Generate everything' " << endl;
    cout << endl;
    cout << "How many students do you want to generate? ";
    int n;
    cin >> n;
    cout << "How many homework scores do you want to generate? ";
    int x;
    cin >> x;
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        Stud laik;
        int gender = rand() % 2;
        if (gender == 0) {
            laik.Vardas = FNames[rand() % 25];
            laik.Pavarde = FSurnames[rand() % 25];
        } else {
            laik.Vardas = MNames[rand() % 25];
            laik.Pavarde = MSurnames[rand() % 25];
        }

        for (int j = 0; j < x; j++) {
            laik.paz.push_back(rand() % 11);
        }
        laik.egz = rand() % 11;

        grupe.push_back(laik);
    }
    return grupe;
}

// Vardo ivedimas, pazymiu generavimas
template <typename Container>
Container GenerateScores() {
    cout << "Selected 2-Input names, generate scores" << endl;
    cout << endl;
    Container grupe;

    while (true) {
        Stud laik;
        cout << "Input name: ";
        cin >> laik.Vardas;
        cout << "Input surname: ";
        cin >> laik.Pavarde;

        cout << "How many homework scores do you want to generate? ";
        int n;
        cin >> n;
        srand(time(NULL));

        for (int i = 0; i < n; i++) {
            laik.paz.push_back(rand() % 10);
        }
        laik.egz = rand() % 10;

        grupe.push_back(laik);

        cout << "Enter more students? (y/n) ";
        char x;
        cin >> x;
        while (x != 'y' && x != 'n') {
            cout << "Invalid input. Enter y or n" << endl;
            cin >> x;
        }
        if (x == 'n') break;
    }
    return grupe;
}

// Visko ivedimas ranka
template <typename Container>
Container ManualInput() {
    Container grupe;
    cout << "Selected 1-Input everything manually" << endl;
    cout << endl;

    while (true) {
        Stud laik;
        cout << "Input name: ";
        cin >> laik.Vardas;
        cout << "Input surname: ";
        cin >> laik.Pavarde;

        cout << "Input your hw scores 1-10. After your last one enter 11 " << endl;
        int paz;
        cin >> paz;
        while (paz >= 0 && paz <= 10) {
            laik.paz.push_back(paz);
            cin >> paz;
        }

        cout << "Enter exam score: ";
        cin >> laik.egz;

        grupe.push_back(laik);

        cout << "Enter more students? (y/n) ";
        char x;
        cin >> x;
        while (x != 'y' && x != 'n') {
            cout << "Invalid input. Enter y or n" << endl;
            cin >> x;
        }
        if (x == 'n') break;
    }
    return grupe;
}

//Skaitymas is failo
template <typename Container>
Container ReadFile(string filename) {
    Container grupe;

    ifstream fd(filename);
    while (!fd) {
        cerr << "File not found!" << endl;
        cout << "Enter existing file name: ";
        cin >> filename;
        fd.open(filename);
    }

    string line;
    getline(fd, line); // Skip first line

    while (getline(fd, line)) {
        istringstream iss(line);
        Stud laik;
        iss >> laik.Vardas >> laik.Pavarde;
        int num;

        while (iss >> num) {
            laik.paz.push_back(num);
        }

        if (!laik.paz.empty()) {
            laik.egz = laik.paz.back();
            laik.paz.pop_back();
        }

        grupe.push_back(laik);
    }

    fd.close();
    return grupe;
}

//Rusiavimas
template <typename Container>
void Sorting(Container &grupe) {
    cout << "How do you want to sort the students?" << endl;
    cout << "1 - By name" << endl;
    cout << "2 - By surname" << endl;
    cout << "3 - By final score descending" << endl;
    cout << "4 - By final score ascending" << endl;

    char x;
    cin >> x;
    while (x != '1' && x != '2' && x != '3' && x != '4') {
        cout << "Invalid input. Enter 1, 2, 3, or 4: ";
        cin >> x;
    }

    // Lambda for sorting
    auto comparator = [&](const Stud &a, const Stud &b) {
        if (x == '1') return a.Vardas < b.Vardas;
        if (x == '2') return a.Pavarde < b.Pavarde;
        if (x == '3') return a.galutinis > b.galutinis;
        return a.galutinis < b.galutinis;
    };

    // Use different sorting depending on the container type
    if constexpr (is_same_v<Container, list<Stud>>) {
        grupe.sort(comparator);  // Use list's built-in sort
    } else {
        sort(grupe.begin(), grupe.end(), comparator);  // Use std::sort for vector & deque
    }
}

// Templated function to output results
template <typename Container>
void OutputToTerminal(Container &grupe) {
    cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde"
         << setw(15) << "Galutinis (Vid.)"
         << " / "
         << "Galutinis (Med.)" << endl;
    cout << "-----------------------------------------------------------" << endl;
    for (const auto &n : grupe) {
        cout << left << setw(15) << n.Vardas << setw(18) << n.Pavarde << setw(7);
        if (n.vm == 'a')
            cout << fixed << setprecision(2) << n.galutinis << "            -" << endl;
        else
            cout << " -                " << fixed << setprecision(2) << n.galutinis << endl;
    }
}

template <typename Container>
void OutputToFile(Container& grupe)
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

template <typename Container>
Container SpeedTesting()
{
    Container grupe;
    string filename;

    cout << "Ar norite generuoti faila? (y/n): ";
    char choice;
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
    {
        int StudentCount;
        cout << "Enter the number of students: ";
        cin >> StudentCount;

        filename = GenerateFile(StudentCount); 
    }

    if (filename.empty()) // If filename is still empty, ask for input
    {
        cout << "Iveskite testo faila: ";
        cin >> filename;
    }

    cout << "Chosen file: " << filename << endl;

    auto startRead = std::chrono::high_resolution_clock::now(); // Timer for file reading
    grupe = ReadFile<Container>(filename);
    auto endRead = std::chrono::high_resolution_clock::now();

    FinalScore(grupe);

    auto startSort = std::chrono::high_resolution_clock::now(); // Timer for sorting
    Sorting(grupe);
    auto endSort = std::chrono::high_resolution_clock::now();

    auto startSplit = std::chrono::high_resolution_clock::now(); // Timer for splitting
    SplitFile(grupe);
    auto endSplit = std::chrono::high_resolution_clock::now();

    // Calculate and display durations
    std::chrono::duration<double> durationRead = endRead - startRead;
    std::chrono::duration<double> durationSort = endSort - startSort;
    std::chrono::duration<double> durationSplit = endSplit - startSplit;

    cout << filename << " failo nuskaitymo laikas: " << fixed << setprecision(5) << durationRead.count() << " s" << endl;
    cout << filename << " failo rusiavimas: " << fixed << setprecision(5) << durationSort.count() << " s" << endl;
    cout << filename << " failo paskirstymo ir irasymo laikas: " << fixed << setprecision(5) << durationSplit.count() << " s" << endl;
    cout << filename << " is viso uztruko: " << fixed << setprecision(5) 
         << (durationRead.count() + durationSort.count() + durationSplit.count()) << " s" << endl;

    return grupe;
}

//Failo dalijimas i du (kietiakai, vargsiukai)
template <typename Container>
void SplitFile(Container grupe)
{
    auto start_split = std::chrono::high_resolution_clock::now();

    Container vargsai;
    Container kietiakai;

    //vargsai.reserve(grupe.size()); 
    //kietiakai.reserve(grupe.size());

    for (auto& n : grupe)
    {
        if (n.galutinis < 5)
            vargsai.push_back(n);
        else
            kietiakai.push_back(n);
    }

    //grupe.clear();
    //grupe.shrink_to_fit();
    //vargsai.shrink_to_fit();
    //kietiakai.shrink_to_fit();

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

template <typename Container>
void FinalScore(Container& grupe)
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

#endif 
