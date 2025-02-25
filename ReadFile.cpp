#include "manolib.h"

using namespace std;

vector<string> ReadLinesFromFile() {
    vector<string> lines;
    
    string filename;
    cout << "Enter file name: ";
    cin>>filename;
    ifstream fd(filename);
    while(!fd) {
        cout << "File not found!" << endl;
        cout << "Enter existing file name: ";
        cin >> filename;
        fd.open(filename);
    }
 
    auto start = std::chrono::high_resolution_clock::now();
    string line;
    getline(fd, line); // Skip first line
    int count = 0;

    while (getline(fd, line)) {
        if (!line.empty()) { // Skip empty lines
            lines.push_back(line);
        }
        count++;
    }
    
    fd.close();

    auto end = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double> duration = end - start;

    cout << "Read " << count << " lines in " 
         << std::fixed << std::setprecision(2) 
         << duration.count() << " seconds" << endl;

    return lines;
}

// Atskiria studentus iš eilučių
vector<Stud> ParseStudents(const vector<string>& lines) {
    vector<Stud> grupe;
    auto start = std::chrono::high_resolution_clock::now();

    for (const auto& line : lines) {
        std::istringstream iss(line);
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

    auto end = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double> duration = end - start;

    cout <<"Split " << grupe.size() << " students in " 
         <<std::fixed << std::setprecision(2) 
         <<duration.count() << " seconds" << endl;

    return grupe;
}
