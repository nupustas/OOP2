#include "manolib.h"
#include "functions.h"
#include "student.h"
#include "vector.h"


using Container = std::vector<Stud>;
//using Container = std::deque<Stud>;
//using Container = std::list<Stud>;

int main()
{   
    srand(static_cast<unsigned int>(time(0)));

    try 
    {
        Container grupe;
        cout << "Using container: " << typeid(Container).name() << endl;
        char a;

        cout << "1 - Input everything manually" << endl;
        cout << "2 - Input names, generate scores" << endl;
        cout << "3 - Generate everything" << endl;
        cout << "4 - Read from file" << endl;
        cout << "5 - Performance test" << endl;
        cout << "6 - Class tests" << endl;
        cout << "7 - Vektor class tests" << endl;

        cin >> a;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        while (a < '1' || a > '7')  
        {
            cout << "Invalid input. Enter 1, 2, 3, 4, 5 or 6: ";
            cin >> a;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        if (a == '1') 
        {
            grupe = ManualInput<Container>();
        } 
        else if (a == '2') 
        {
            grupe = GenerateScores<Container>();
        } 
        else if (a == '3') 
        {
            grupe = GenerateEverything<Container>();
        } 
        else if (a == '4') 
        {
            string filename;
            cout << "Enter file name: ";
            cin >> filename;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            grupe = ReadFile<Container>(filename);
            
            if (grupe.empty()) 
            {
                throw std::runtime_error("Error: Could not read file or file is empty.");
            }
        } 
        else if (a == '5') 
        {   
            grupe = SpeedTesting<Container>();
            return 0;
        }
        else if (a == '6') 
        {   
            TestStud();  // Run the test function
            return 0;
        }
        else if (a == '7') 
        {   
            Vektor <int> test(4,25);
            Vektor <int> test2(4, 69);

            test.swap(test2);

            for(int i = 0; i < test.size(); i++)
            {
                cout << test[i] << " ";
            }
           
            return 0;
        }
        if (grupe.empty())  
        {
            throw std::runtime_error("Error: No data to process.");
        }

        FinalScore(grupe); // Calculating final scores

        Sorting(grupe); // Sorting students

        cout << "Show results in file or terminal?" << endl;
        cout << "1 - File" << endl;
        cout << "2 - Terminal" << endl;

        int y;
        cin >> y;
        
        while (cin.fail() || (y != 1 && y != 2)) 
        {
            cin.clear(); 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Enter 1 or 2: ";
            cin >> y;
        }
        if (y == 2) 
            OutputToTerminal(grupe);
        else 
            OutputToFile(grupe);
    } 
    catch (const std::exception& e) 
    {
        cerr << "An error occurred: " << e.what() << endl;
        return 1; 
    }
    catch (...) 
    {
        cerr << "An unknown error occurred." << endl;
        return 1; 
    }

    return 0;
}
