#include "manolib.h"

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

    cout <<"Failas is " << grupe.size() << " studentu nuskaitytas per " 
         << std::fixed << std::setprecision(2) 
         << duration.count() << " s" << endl;

    return grupe;
}
