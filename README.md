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
# File creation tests average
* 1000     students ~0.0572s
* 10000    students ~0.1515s
* 100000   students ~1.3236s
* 1000000  students ~9.5843
* 10000000 students ~58.0035s

# File splitting tests average 
* 1000     students ~0.08s
* 10000    students ~0.93s
* 100000   students ~9.34s
* 1000000  students ~114.52s 
* 10000000 students ~208.48s
