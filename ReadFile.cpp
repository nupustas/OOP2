#include "manolib.h"

vector<string> ReadLinesFromFile(const string& filename) {
    vector<string> lines;
    auto start = std::chrono::high_resolution_clock::now();

    ifstream fd(filename);

    if (!fd) {
        cout << "File not found!" << endl;
        return lines;
    }

    string line;
    getline(fd, line); // Skip pirma eilute
    int count = 0;
    while (getline(fd, line)) {
        if (!line.empty()) { // skip tuscias linijas
            lines.push_back(line);    
        }
        count++;
    }

    fd.close();

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout<<"Read "<<count<< " lines in "<< duration.count() << " milliseconds" << endl;
    return lines;
}

// Function to process each line and extract student data
vector<Stud> ParseStudents(const vector<string>& lines) {
    vector<Stud> grupe;
    auto start = std::chrono::high_resolution_clock::now();
    for (const auto& line : lines) {
        std::istringstream iss(line);
        Stud laik;

        
            iss >> laik.Vardas >> laik.Pavarde;
            int num;

            while(iss >> num)
            {
            laik.paz.push_back(num);
            }

            if(!laik.paz.empty())
            {
                laik.egz = laik.paz.back();
                laik.paz.pop_back();
            }
                grupe.push_back(laik);
        
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Parsed " << grupe.size() << " students in " << duration.count() << " milliseconds" << endl;
    return grupe;
}
    

