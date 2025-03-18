# Student Grade Calculator

This project is a C++ application that calculates the final grades for students based on their homework and exam scores.

---------------------------------------------------------------------------------------------------
v1.0 efficiency tests

Hardware:
CPU: Intel Core i5-10300H
RAM: 2x4gb 3200mhz
SSD: NVMe 512gb

## Time tests using different types of containers
1.1 File creation tests average
Vector
| File              | Time     | 
|-------------------|----------|
| Studentai1000     |  0.0216s |
| Studentai10000    |  0.2120s | 
| Studentai100000   |  1.7440s | 
| Studentai1000000  |  10.653s | 
| Studentai10000000 |  32.871s | 

List
| File              | Time     | 
|-------------------|----------|
| Studentai1000     | Data 2   |
| Studentai10000    | Data 5   | 
| Studentai100000   | Data 5   | 
| Studentai1000000  | Data 5   | 
| Studentai10000000 | Data 5   | 

Deque
| File              | Time     | 
|-------------------|----------|
| Studentai1000     | Data 2   |
| Studentai10000    | Data 5   | 
| Studentai100000   | Data 5   | 
| Studentai1000000  | Data 5   | 
| Studentai10000000 | Data 5   | 

---------------------------------------------------------------------------------------------------
1.2 File reading tests average
Vector
| File              | Time     | 
|-------------------|----------|
| Studentai1000     |  0.0489s |
| Studentai10000    |  0.0985s | 
| Studentai100000   |  0.4100s | 
| Studentai1000000  |  4.3490s | 
| Studentai10000000 |  20.571s | 

List
| File              | Time     | 
|-------------------|----------|
| Studentai1000     | Data 2   |
| Studentai10000    | Data 5   | 
| Studentai100000   | Data 5   | 
| Studentai1000000  | Data 5   | 
| Studentai10000000 | Data 5   | 

Deque
| File              | Time     | 
|-------------------|----------|
| Studentai1000     | Data 2   |
| Studentai10000    | Data 5   | 
| Studentai100000   | Data 5   | 
| Studentai1000000  | Data 5   | 
| Studentai10000000 | Data 5   | 


---------------------------------------------------------------------------------------------------
1.3 File splitting and writing tests average
Vector
| File              | Time     | 
|-------------------|----------|
| Studentai1000     |  0.0178s |
| Studentai10000    |  0.0820s | 
| Studentai100000   |  0.8640s | 
| Studentai1000000  |  6.9530s | 
| Studentai10000000 |  53.871s | 

List
| File              | Time     | 
|-------------------|----------|
| Studentai1000     | Data 2   |
| Studentai10000    | Data 5   | 
| Studentai100000   | Data 5   | 
| Studentai1000000  | Data 5   | 
| Studentai10000000 | Data 5   | 

Deque
| File              | Time     | 
|-------------------|----------|
| Studentai1000     | Data 2   |
| Studentai10000    | Data 5   | 
| Studentai100000   | Data 5   | 
| Studentai1000000  | Data 5   | 
| Studentai10000000 | Data 5   | 
