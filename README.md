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
- **`src/`**: Pagrindinis programos kodas.
- **`CMakeLists.txt`**: CMake instrukcijos kompiliavimui.
- **`ReadME.md`**: Programos instrukcija.


## V3.0
### Vector klasės funkcijų pavyzdžiai
#### 1. ```void erase(size_t index)```
Ši funkcija pašalina vieną konteinerio elementą, kurio index yra paduotas.
###### Veikimas:
Iš pradžių patikrinama ar paduotas **index** nėra didesnis nei esamo konteinerio dydis, jei ne, visi elementai esantys dešinėje index'o pastumiami į kairę ir pakeičiamas konteinerio dydis.

#### 2. ```V* erase(V* first, V* last)```
Ši funkcija, pašalina konteinerio elementus nuo į ja paduotų index: nuo ** V* first ** iki ** V* last ** 
###### Veikimas:
Patikrinama ar first nėra mažesnis už masyvo pradžią, ar last nėra didesnis už masyvo pabaigą, ir ar first < last. Tada pointeriai first ir last paverčiami į index'us, ir elementai kurie yra už 'last' yra pastumiami į kairę. Pakeičiamas konteinerio 'dydis' ir grąžinamas pirmo elemento po ištrintų iteratorius.  

#### 3. ```V& operator[](size_t index)```
Operatorius [], leidžia prieti prie norimo elemento konteineryje. Norint pasiekti bet kokį elementą konteineryje, naudojamas šis operatorius per norimo elemento index'ą. ```Pvz.: Vector[i]```
###### Veikimas:
Patikrinama ar index nėra didesnis už konteinerio dydį, jei ne grąžinamas duomenų masyvo elementas. ```return duom[index];```

#### 4. ```bool operator==(const Vektor<V>& other)```
Operatorius ==, šis leidžia patikrinti ar du konteineriai yra lygūs.
###### Veikimas:
Visų pirmą patikrinama ar konteinerių dydis lygus, jei ne iškart grąžinama **false** reikšmė. Jei konteinerių dydis toks pat, tuomet tikrinama ar kiekvinas konteinerių elementas lygus. Jei visi elementai lygūs, grąžinama **true** reikšmė.

#### 5. ```void pop_back()```
Ši funkcija leidžia pašalinti konteinerio paskutinį elementą.
###### Veikimas:
Patikrinama ar konteineris nėra tusčias, jei ne, tuomet jo dydis yra pamažinamas vienu. 
```--dydis;```

## Testavimas
#### Šiose lentelėse pateikiami skirtingų C++ konteinerių (vector, list, deque) testavimo rezultatai.  

### 🖥 Testavimo sistemos parametrai:

- **`Procesorius: Intel Core i5-10300H `**

- **`Operatyvioji atmintis: 2×4GB DDR4 3200MHz`**

- **`Diskas: 512GB NVMe SSD`**
----------------------------------------------------------------------------------------
#### Originalus Vector vs Vektor klasė
##### Užpildymas naudojant push_back() funkciją
| Dydis       | Vector       | Klasė      |     
|-------------|----------    |----------  |
| 10000       |  0.00010 s   |  0.00006 s |
| 100000      |  0.00101 s   |  0.00051 s |
| 1000000     |  0.00414 s   |  0.00477 s | 
| 10000000    |  0.04605 s   |  0.04761 s | 
| 100000000   |  0.50926 s   |  0.39100 s | 
| 1000000000  |  9.06876 s   |  6.91821 s | 

##### Programos spartos analizė
| Failas            | Vector     | Klasė      |      
|-------------------|----------  |----------  |
| Studentai10000    |  0.17188 s |  0.13205 s | 
| Studentai100000   |  1.03871 s |  1.09587 s | 
| Studentai1000000  |  9.88531 s |  10.2013 s | 
| Studentai10000000 |  100.456 s |  110.858 s | 