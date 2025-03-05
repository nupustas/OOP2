# Student Grade Calculator

This project is a C++ application that calculates the final grades for students based on their homework and exam scores.

V0.2

# Student Grade Calculator

This project is a C++ application that calculates the final grades for students based on their homework and exam scores. The application allows users to input student data manually or generate it randomly.

## V0.4 Structure

- `.vscode/settings.json`: VSCode settings for file associations.
- `.vscode/tasks.json`: VSCode tasks for building the project.
- `manolib.h`: Header file containing the `Stud` structure and utility functions.
- `functions.h`: Header file containing function declarations.
- `main.cpp`: Main application file for vector-based implementation.
- `main.exe`: Executable generated from `main.cpp`.
- `ReadFile.cpp`: Source file for reading student data from a file.
- `FinalScore.cpp`: Source file for calculating final scores.
- `GenerateScores.cpp`: Source file for generating scores.
- `GenerateFiles.cpp`: Source file for generating files.
- `ManualInput.cpp`: Source file for manual input.
- `Output.cpp`: Source file for outputting results.
- `studentai10000.txt`: Generated sample input file with 10,000 students.


## New functions added via V0.4

- **Generate file**: The application can generate a file with a specified number of students.
- **Test function**: The function tests the efficiency of the file reading, writing and sorting functions


## Efficiency tests 
------------------------------
# File creation tests average of 5
* 1000     students ~0.0216s
* 10000    students ~0.210s
* 100000   students ~1.744s
* 1000000  students ~10.653s
* 10000000 students ~58.871s

# File reading tests average of 5
* 1000     students ~0.049s
* 10000    students ~0.098s
* 100000   students ~0.41s
* 1000000  students ~4.349s
* 10000000 students ~43.247s

# File splitting tests average of 5
* 1000     students ~0.018s
* 10000    students ~0.072s
* 100000   students ~0.82s
* 1000000  students ~7.040s 
* 10000000 students ~80.783s
