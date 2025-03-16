#include "manolib.h"
//Visko generavimas
vector<Stud> GenerateEverything()
{
    vector<Stud> grupe;
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

            grupe.push_back(laik);
    }
    return grupe;
}

//Vardo ir pavardes ivedimas, pazymiu generavimas
vector<Stud> GenerateScores()
{
    cout << "Selected 2-Input names, generate scores" << endl;
        cout<<endl;
    vector<Stud> grupe;
        while(true)
        {
            Stud laik;
            cout<<"Input name: ";
            cin>>laik.Vardas;
            cout<<"Input surname: ";
            cin>>laik.Pavarde;

            cout<<"How many homework scores do you want to generate? ";
            int n;
            cin>>n;
            srand(time(NULL));
            for(int i=0; i<n; i++)
            {
                laik.paz.push_back(rand()%10);
            }
            laik.egz=rand()%10;

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

//Visko ivedimas ranka
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

//Nuskaitymas is failo
vector<Stud> ReadFile(string filename) {
    vector<Stud> grupe;
    grupe.reserve(1000001);

    ifstream fd(filename);
    while (!fd) {
        std::cerr << "File not found!" << endl;
        cout << "Enter existing file name: ";
        cin >> filename;
        fd.open(filename);
    }

    auto start = std::chrono::high_resolution_clock::now();
    
    string line;
    getline(fd, line); // Skip first line
    int count = 0;
    
    while (getline(fd, line)) {
        
            std::istringstream iss(line);
            
            Stud laik;
            iss >> laik.Vardas >> laik.Pavarde;
            int num;

            while (iss >> num) {
                laik.paz.push_back(num);
            }

            if (!laik.paz.empty()) {
                laik.egz = laik.paz.back();
                laik.paz.pop_back();}
                                    
            grupe.push_back(laik);
        count++;
    }
    grupe.shrink_to_fit();
    fd.close();

    auto end = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double> duration = end - start;

    /*cout <<"Failas is " << grupe.size() << " studentu nuskaitytas per " 
         << std::fixed << std::setprecision(2) 
         << duration.count() << " s" << endl;*/

    return grupe;
}