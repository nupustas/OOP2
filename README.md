## Studentų galutinio balo skaičiavimo programa

Šis projektas yra C++ programa, kuri apskaičiuoja galutinį studento balą pagal jų namų darbų, bei egzamino įvertinimus.

## Projekto paleidimas naudojant CMake

#### 1. Reikalingi įrankiai
Prieš paleidžiant projektą, įsitikinkite, kad turite šiuos įrankius:

- **CMake**: [Atsisiųsti CMake](https://cmake.org/download/) (minimum v3.10)
- **C++ kompiliatorius** (GCC, CLANG, MSVC)

#### 2. Parsisiųskite projektą, jei jo dar neturite
##### Projekto klonavimas iš git:
```bash
git clone https://github.com/nupustas/oop.vp
```
Paklonave projektą, atidarykite jo aplanką.

##### Projekto kompiliavimas:
```
mkdir build
cd build
cmake ..
```
```
cmake --build . --config Release
```
##### Projekto paleidimas:
```
cd release
OOP.exe
```
## Projekto struktūra:

- **`include/`**: Aplankalas, kuriame laikomi projekto header failai.
- **`src/`**: Programos kodas, kuriame yra `.cpp` failai.
- **`CMakeLists.txt`**: CMake instrukcijos kompiliavimui.
- **`ReadME.md`**: Programos instrukcija.


## Struktūros ir klasės palyginimas
#### Šiose lentelėse pateikiami struktūros ir klasės.  

### 🖥 Testavimo sistemos parametrai:

- **`Procesorius: Intel Core i5-10300H `**

- **`Operatyvioji atmintis: 2×4GB DDR4 3200MHz`**

- **`Diskas: 512GB NVMe SSD`**
---------------------------------------------------------------------------------------------------
#### 1 Be optimizavimo
                               
| Failas            | Laikas   | .exe dydis |      
|-------------------|----------|------------|
| Studentai100000   |  6.3394s |  267 776 B |  
| Studentai1000000  | 62.9744s |  267 776 B |  

---------------------------------------------------------------------------------------------------
#### 1.1 -O1
                               
| Failas            | Laikas   | .exe dydis |      
|-------------------|----------|------------|
| Studentai100000   |  1.2681s |  382 976 B |  
| Studentai1000000  |  11.383s |  382 976 B |  

---------------------------------------------------------------------------------------------------
#### 1.2 -O2
                               
| Failas            | Laikas   | .exe dydis |      
|-------------------|----------|------------|
| Studentai100000   |  1.0493s |  406 528 B |  
| Studentai1000000  |  10.555s |  406 528 B |  

---------------------------------------------------------------------------------------------------
#### 1.3 -O3
                               
| Failas            | Laikas   | .exe dydis |      
|-------------------|----------|------------|
| Studentai100000   |  1.0029s |  437 248 B |  
| Studentai1000000  |  9.3880s |  437 248 B |  