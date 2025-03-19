# Student Grade Calculator

This project is a C++ application that calculates the final grades for students based on their homework and exam scores.

---------------------------------------------------------------------------------------------------

## Skirtingų konteinerių testavimas
Šiose lentelėse pateikiami skirtingų C++ konteinerių (vector, list, deque) testavimo rezultatai.  
🖥 Testavimo sistemos parametrai:

Procesorius: Intel Core i5-10300H

Operatyvioji atmintis: 2×4GB DDR4 3200MHz

Diskas: 512GB NVMe SSD

1.1 Failo sukūrimas

| Failas             | Vector   | List     | Deque    |        
|-------------------|----------|----------|----------|    
| Studentai1000     |  0.0216s |  0.0055s |  0.0062s |
| Studentai10000    |  0.2120s |  0.0645s |  0.0587s | 
| Studentai100000   |  1.7440s |  0.4373s |  0.4781s | 
| Studentai1000000  |  10.653s |  3.7508s |  3.8066s | 
| Studentai10000000 |  32.871s |  32.287s |  34.628s | 

---------------------------------------------------------------------------------------------------
1.2 Failo skaitymas
                               
| Failas            | Vector   | List     | Deque    |        
|-------------------|----------|----------|----------|    
| Studentai1000     |  0.0489s |  0.0233s |  0.0060s |
| Studentai10000    |  0.0985s |  0.0318s |  0.0298s | 
| Studentai100000   |  0.4100s |  0.2143s |  0.2151s | 
| Studentai1000000  |  4.3490s |  1.8480s |  1.7362s | 
| Studentai10000000 |  20.571s |  18.528s |  20.576s | 

---------------------------------------------------------------------------------------------------
1.3 Rušiavimas didėjimo tvarka
                               
| Failas            | Vector   | List     | Deque    |        
|-------------------|----------|----------|----------|    
| Studentai1000     |  0.0003s |  0.0001s |  0.0003s |
| Studentai10000    |  0.0031s |  0.0013s |  0.0044s | 
| Studentai100000   |  0.0521s |  0.0357s |  0.0471s | 
| Studentai1000000  |  0.4716s |  0.6341s |  0.5915s | 
| Studentai10000000 |  5.7443s |  9.6336s |  8.2021s |  

---------------------------------------------------------------------------------------------------
1.4 Studentų skirstymas į dvi grupes
                               
| Failas            | Vector   | List     | Deque    |        
|-------------------|----------|----------|----------|    
| Studentai1000     |  0.0178s |  0.0290s |  0.0053s |
| Studentai10000    |  0.0820s |  0.0478s |  0.0453s | 
| Studentai100000   |  0.8640s |  0.4039s |  0.4635s | 
| Studentai1000000  |  6.9530s |  4.5441s |  4.3977s | 
| Studentai10000000 |  53.871s |  59.936s |  52.829s | 


## Failo skirstymo į du, optimizaviams

1. Strategija

| Failas            | Vector   | List     | Deque    |        
|-------------------|----------|----------|----------|    
| Studentai1000     |  0.0470s |  0.0290s |  0.0653s |
| Studentai10000    |  0.1720s |  0.1478s |  0.2804s | 
| Studentai100000   |  1.0750s |  1.1539s |  1.1635s | 
| Studentai1000000  |  11.453s |  10.541s |  13.398s | 
| Studentai10000000 |  158.34s |  152.06s |  126.49s | 