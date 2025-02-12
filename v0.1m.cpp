#include "manolib.h"
const int MaxStud=10000;

// dinaminio masyvo inicializavimas
void initializePazArray(Stud& student, int size) {
    student.pazArr = new int[size];
    student.pazcount = size;
}

// uzpildymas
void fillPazArray(Stud& student) {
    for(int i=0;i<student.pazcount;i++) 
    {
        student.pazArr[i] = rand() % 11;
    }
}

// atlaisvinimas
void freePazArray(Stud& student) {
    delete[] student.pazArr;
    student.pazArr = nullptr;
}

int main() {
    Stud grupe[MaxStud];
    int students = 0;
    srand(time(NULL));

    char a; 
    cout<<"1-Input everything manually"<<endl;
    cout<<"2-Input names, generate scores"<<endl;
    cout<<"3-Generate everything"<<endl;
    cin>>a;
    while(a != '1' && a != '2' && a != '3') {
        cout << "Invalid input. Enter 1, 2, or 3" << endl;
        cin >> a;
    }

    if(a == '3') { // visko generavimas
        cout<<"Selected '3-Generate everything' "<<endl;
        cout<<endl;
        cout<<"How many students do you want to generate? ";
        int n;
        cin>>n;
        cout<<"How many homework scores do you want to generate? ";
        int x;
        cin>>x;

        
        for(int i=0; i<n; i++) {
            Stud laik;
            laik.pazcount = x;
            int gender=rand() % 2;
            if(gender==0) {
                laik.Vardas = FNames[rand()%25];
                laik.Pavarde = FSurnames[rand()%25];
            } 
            else {
                laik.Vardas = MNames[rand()%25];
                laik.Pavarde = MSurnames[rand()%25];
            }
            initializePazArray(laik, laik.pazcount);
            fillPazArray(laik);
            laik.egz = rand() % 11;

            if(rand() % 2 == 0) laik.vm = 'a';
            else laik.vm = 'm';
            
            grupe[students++] = laik;
        }
    } 
    else if(a == '2') { // vardo ir pavardes ivedimas, pazymiu generavimas
        cout << "Selected 2-Input names, generate scores" << endl;
        cout<<endl;
        while(true) {
            Stud laik;
            cout << "Input name: ";
            cin >> laik.Vardas;
            cout << "Input surname: ";
            cin >> laik.Pavarde;

            cout << "How many homework scores do you want to generate? ";
            cin >> laik.pazcount;
            initializePazArray(laik, laik.pazcount);
            fillPazArray(laik);

            cout << "Enter exam score: ";
            cin >> laik.egz;
            cout << "Calculate final score with average or median? (a/m)";
            cin >> laik.vm;
            while(laik.vm != 'a' && laik.vm != 'm') {
                cout << "Invalid input. Enter a or m" << endl;
                cin >> laik.vm;
            }
            grupe[students++] = laik;

            cout << "Enter more students? (y/n)";
            char x;
            cin >> x;
            if(x == 'n') break;
        }
    } 
    else { // visko ivedimas ranka

        cout << "Selected 1-Input everything manually" << endl;
        cout<<endl;
        while(true) {
            Stud laik;
            cout << "Input name: ";
            cin >> laik.Vardas;
            cout << "Input surname: ";
            cin >> laik.Pavarde;
            
            cout << "How many homework scores do you want to input? ";
            cin>>laik.pazcount;
            initializePazArray(laik, laik.pazcount);

            for(int i=0; i<laik.pazcount; i++) {
                cin>>laik.pazArr[i];
            }

            cout << "Enter exam score: ";
            cin >> laik.egz;
            cout << "Calculate final score with average or median? (a/m)";
            cin >> laik.vm;
            grupe[students++] = laik;
            
            cout << "Enter more students? (y/n)";
            char x;
            cin >> x;
            if(x == 'n') break;
        }
    }

    // Calculate final scores
    for(int i = 0; i < students; i++) {
        sort(grupe[i].pazArr, grupe[i].pazArr + grupe[i].pazcount);
        double suma = 0;
        for(int j=0;j<grupe[i].pazcount;j++) {
            suma += grupe[i].pazArr[j];
        }
        if(grupe[i].vm == 'a'){
        grupe[i].galutinis = 0.4 * (suma / grupe[i].pazcount) + 0.6 * grupe[i].egz;}
 
        else if(grupe[i].pazcount % 2 == 0) {
            grupe[i].galutinis = 0.4*(grupe[i].pazArr[grupe[i].pazcount /2]+grupe[i].pazArr[grupe[i].pazcount /2 -1]) /2 +0.6 *grupe[i].egz;
        } 
        else {
            grupe[i].galutinis = 0.4*grupe[i].pazArr[grupe[i].pazcount /2] +0.6 *grupe[i].egz;
        }
        
        
    }

    // output
    cout<<left<<setw(15)<<"Vardas"<<setw(15)<<"Pavarde"<<"Galutinis(Vid.) / Galutinis(Med.)"<<endl;
    cout<< "-----------------------------------------------------------"<<endl;
    for(int i=0;i<students;i++) {
        cout<<left<<setw(15)<<grupe[i].Vardas<<setw(18)<<grupe[i].Pavarde<<setw(7);
        if(grupe[i].vm == 'a') cout<<fixed<<setprecision(2)<<grupe[i].galutinis<< "            -"<<endl;
    else cout<<" -                "<<fixed<<setprecision(2)<<grupe[i].galutinis<<endl;
    }
    
    // atlaisvinama atmintis
    for(int i = 0; i < students; i++) {
        freePazArray(grupe[i]);
    }
}
