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

| File              | Vector   | List     | Deque    |        
|-------------------|----------|----------|----------|    
| Studentai1000     |  0.0216s |  0.0489s |  0.0489s |
| Studentai10000    |  0.2120s |  0.0489s |  0.0489s | 
| Studentai100000   |  1.7440s |  0.0489s |  0.0489s | 
| Studentai1000000  |  10.653s |  0.0489s |  0.0489s | 
| Studentai10000000 |  32.871s |  0.0489s |  0.0489s | 

---------------------------------------------------------------------------------------------------
1.2 File reading tests average
                               
| File              | Vector   | List     | Deque    |        
|-------------------|----------|----------|----------|    
| Studentai1000     |  0.0489s |  0.0489s |  0.0489s |
| Studentai10000    |  0.0985s |  0.0489s |  0.0489s | 
| Studentai100000   |  0.4100s |  0.0489s |  0.0489s | 
| Studentai1000000  |  4.3490s |  0.0489s |  0.0489s | 
| Studentai10000000 |  20.571s |  0.0489s |  0.0489s | 
                                                
---------------------------------------------------------------------------------------------------
1.3 File splitting and writing tests average
                               
| File              | Vector   | List     | Deque    |        
|-------------------|----------|----------|----------|    
| Studentai1000     |  0.0178s |  0.0489s |  0.0489s |
| Studentai10000    |  0.0820s |  0.0489s |  0.0489s | 
| Studentai100000   |  0.8640s |  0.0489s |  0.0489s | 
| Studentai1000000  |  6.9530s |  0.0489s |  0.0489s | 
| Studentai10000000 |  53.871s |  0.0489s |  0.0489s | 
