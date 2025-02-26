# Student Grade Calculator

This project is a C++ application that calculates the final grades for students based on their homework and exam scores.

V0.2
## V0.2 Structure

- `.vscode/settings.json`: VSCode settings for file associations.
- `.vscode/tasks.json`: VSCode tasks for building the project.
- `manolib.h`: Header file containing the `Stud` structure and utility functions.
- `functions.h`: Header file containing function declarations.
- `v0.1.cpp`: Main application file for vector-based implementation.
- `v0.1.exe`: Executable generated from `v0.1.cpp`.
- `ReadFile.cpp`: Source file for reading student data from a file.
- `FinalScore.cpp`: Source file for calculating final scores.
- `studentai10000.txt`: Sample input file with 10,000 students.
- `studentai100000.txt`: Sample input file with 100,000 students.

## New functions added via V0.2
- Read from file: The application can now read student data from a file.
- Sort options: The application provides options to sort students by name, surname, or final score (ascending or descending).
- Output options: The application can output results to a file or the terminal.

## Efficiency tests
  studentai10000.txt ~0.2s

  studentai100000.txt ~1.75s

  studentai1000000.txt ~12.5s
    
