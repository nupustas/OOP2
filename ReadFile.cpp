#include "manolib.h"

vector<string> ReadLinesFromFile(const string& filename, int studentCount) {
    vector<string> lines;
    ifstream fd(filename);
    
    if (!fd) {
        cout << "File not found!" << endl;
        return lines;
    }

    string line;
    int count = 0;
    while (getline(fd, line) && count < studentCount) {
        if (!line.empty()) { // Avoid empty lines
            lines.push_back(line);
            count++;
        }
    }

    fd.close();
    return lines;
}

// Function to process each line and extract student data
vector<Stud> ParseStudents(const vector<string>& lines) {
    vector<Stud> grupe;
    
    for (const auto& line : lines) {
        std::istringstream iss(line);
        Stud laik;
        
        // Read first two words as name and surname
        iss >> laik.Vardas >> laik.Pavarde;

        // Read grades (15 homework scores)
        laik.paz.clear();
        int paz;
        for (int j = 0; j < 15; j++) {
            if (!(iss >> paz)) {
                cout << "Error reading grade for " << laik.Vardas << " " << laik.Pavarde << endl;
                break;
            }
            laik.paz.push_back(paz);
        }

        // Read the final exam score
        if (!(iss >> laik.egz)) {
            cout << "Error reading final exam score for " << laik.Vardas << " " << laik.Pavarde << endl;
            continue;
        }

        grupe.push_back(laik);
    }

    return grupe;
}
    

