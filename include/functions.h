#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "manolib.h"

// Visko generavimas
template <typename Container>
Container GenerateEverything() {
    Container grupe;
    cout << "Selected '3-Generate everything' " << endl;
    cout << endl;
    int n, x;
    cout << "How many students do you want to generate? ";
    while (!(cin >> n) || n < 1) {
        cout << "Invalid input. Please enter a positive number: ";
        cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    cout << "How many homework scores do you want to generate? ";
    while (!(cin >> x) || x < 1) {
        cout << "Invalid input. Please enter a positive number: ";
        cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    for (int i = 0; i < n; i++) {
        Stud laik;
        int gender = rand() % 2;
        if (gender == 0) {
            laik.setVardas(FNames[rand() % 25]);
            laik.setPavarde(FSurnames[rand() % 25]);
            
        } else {
            laik.setVardas(MNames[rand() % 25]);
            laik.setPavarde(MSurnames[rand() % 25]);
        }

        for (int j = 0; j < x; j++) {
            laik.addPaz(rand() % 10);
            
        }
        laik.setEgz(rand() % 10);

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
        string Vardas, Pavarde;
        cout << "Input name: ";
        cin >> Vardas;
        laik.setVardas(Vardas);
        cout << "Input surname: ";
        cin >> Pavarde;
        laik.setPavarde(Pavarde);

        cout << "How many homework scores do you want to generate? ";
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            laik.addPaz((rand() % 10));
        }
        laik.setEgz((rand() % 10));

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
    std::cout << "Manual student input selected.\n" << std::endl;

    while (true) {
        Stud laik;

        // Naudojamas >> klasės operatorius
        std::cin >> laik;  
        
        grupe.push_back(laik);

        char more;
        std::cout << "Add another student? (y/n): ";
        std::cin >> more;
        while (more != 'y' && more != 'n') {
            std::cout << "Invalid input. Enter y or n: ";
            std::cin >> more;
        }
        if (more == 'n') break;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear leftover input
        std::cout << std::endl;
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
        string vardas, pavarde;
        iss >> vardas >> pavarde;
        laik.setVardas(vardas);
        laik.setPavarde(pavarde);
        int num;

        while (iss >> num) {
            laik.addPaz(num);
        }

        vector<int> pazymiai = laik.getPaz();
        if (!pazymiai.empty()) {
            laik.setEgz(pazymiai.back());
            laik.removeLastPaz(); 
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
    auto chrono_start = std::chrono::high_resolution_clock::now();
    
    auto comparator = [&](const Stud &a, const Stud &b) {
        if (x == '1') return a.getVardas() < b.getVardas();
        if (x == '2') return a.getPavarde() < b.getPavarde();
        if (x == '3') return a.getGalutinis() < b.getGalutinis();
        else return a.getGalutinis() > b.getGalutinis();
    };
    // constexpr apskaiciuoja kompiliavimo metu, o ne runtime metu
    if constexpr (is_same_v<Container, list<Stud>>) {
        grupe.sort(comparator);  // listo sortas
            } else {
        sort(grupe.begin(), grupe.end(), comparator);  // std::sort vectoriui ir deque
    }
    auto chrono_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = chrono_end - chrono_start;
    cout << "SORTING TOOK: " << fixed << setprecision(5) << duration.count() << " s" << endl;
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
        // Output naudojant << klasės operatoriu
        std::cout << n;
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
    out<<std::left<<setw(15)<<n.getVardas()<<setw(18)<<n.getPavarde()<<setw(7);
    if(n.getVm() == 'a') out<<std::fixed<<std::setprecision(2)<<n.getGalutinis()<<"            -"<<endl;
    else out<<" -                "<<std::fixed<<std::setprecision(2)<<n.getGalutinis()<<endl;
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
        return filename;
    }
    fd.close();

    auto start = std::chrono::high_resolution_clock::now();
    ofstream fr(filename);
    if(!fr)
    {
        cout<<"Error creating file" <<filename<<endl;
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

    auto startSplit = std::chrono::high_resolution_clock::now();
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
void SplitFile(Container& grupe) {
    auto start_split = std::chrono::high_resolution_clock::now();

    // padalina konteineri i 2
    auto it = std::partition(grupe.begin(), grupe.end(), [](const auto student) {
        return student.getGalutinis() < 5;
    });

    // sukuria konteineri vargsiukams is atskirtu elementu
    Container vargsai;
    vargsai.reserve(std::distance(grupe.begin(), it));
    std::move(grupe.begin(), it, std::back_inserter(vargsai));
    grupe.erase(grupe.begin(), it); // istrina atskirtus elem is pradinio konteinerio
    grupe.shrink_to_fit();

    auto end_split = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> split_duration = end_split - start_split;

    std::ofstream fr1("Vargsiukai.txt");
    std::ofstream fr2("Kietiakai.txt");

    if (!fr1 || !fr2) {
        std::cerr << "Error opening output files!" << std::endl;
        return;
    }

    auto startV = std::chrono::high_resolution_clock::now();
    fr1 << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde"
        << std::setw(15) << "Galutinis (Vid.)" << " / " << "Galutinis (Med.)" << std::endl;
    fr1 << "-----------------------------------------------------------" << std::endl;

    for (const auto& n : vargsai) {
        fr1 << std::left << std::setw(15) << n.getVardas() << std::setw(18) << n.getPavarde() << std::setw(7);
        if (n.getVm() == 'a')
            fr1 << std::fixed << std::setprecision(2) << n.getGalutinis() << "            -" << std::endl;
        else
            fr1 << " -                " << std::fixed << std::setprecision(2) << n.getGalutinis() << std::endl;
    }
    auto endV = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> Vduration = endV - startV;

    auto startK = std::chrono::high_resolution_clock::now();
    fr2 << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde"
        << std::setw(15) << "Galutinis (Vid.)" << " / " << "Galutinis (Med.)" << std::endl;
    fr2 << "-----------------------------------------------------------" << std::endl;
    for (const auto& n : grupe) {
        fr2 << std::left << std::setw(15) << n.getVardas() << std::setw(18) << n.getPavarde() << std::setw(7);
        if (n.getVm() == 'a')
            fr2 << std::fixed << std::setprecision(2) << n.getGalutinis() << "            -" << std::endl;
        else
            fr2 << " -                " << std::fixed << std::setprecision(2) << n.getGalutinis() << std::endl;
    }
    auto endK = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> Kduration = endK - startK;

    fr1.close();
    fr2.close();

    std::cout << "Skirstymas ir irasymas: " << Kduration.count() + Vduration.count() + split_duration.count() << " s" << std::endl;
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
        vector<int> paz = n.getPaz();
        sort(paz.begin(), paz.end());
        n.setVm(am);
        int suma=0;
            for(auto n: paz)
            {
            suma=suma+n;}
            if(am=='a'){
                n.setGalutinis(0.4*(suma/paz.size())+0.6*n.getEgz());
            }
            else if (paz.size()%2==0){
                n.setGalutinis(0.4*(paz[paz.size()/2] + paz[paz.size()/2-1])/2 +0.6*n.getEgz());
            }
            else{
                n.setGalutinis(0.4*paz[paz.size()/2] +0.6*n.getEgz());
            }
        }
}

#endif 
