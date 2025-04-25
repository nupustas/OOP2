## Studentų galutinio balo skaičiavimo programa

Šis projektas yra C++ programa, kuri apskaičiuoja galutinį studento balą pagal jų namų darbų, bei egzamino įvertinimus.

# v1.5
Pridėta bazinė klasė "Zmogus", Stud klasė - jos išvestinė

Visi 1.2 versijos metodai veikia


# v1.2
## 1.2 versijoje pridėti metodai:
| Metodas                       | Paaiškinimas                                                    |      
|-------------------            |--------------                                                   |
| Copy konstruktorius           | Sukuria naują objektą kopijuodamas esamo objekto duomenis       | 
| Copy asignment operatorius    | Nukopijuoja vieno objekto duomenis į jau esamą kitą objektą     |
| Move konstruktorius           | Perkelia duomenis iš kito objekto, atiduodamas jo turinį        | 
| Move asignment operatorius    | Perkelia duomenis į jau esamą objektą, atlaisvindamas šaltinį   |
| Įvesties operatorius '>>'     | Leidžia įvesti objekto duomenis iš konsolės ar kito srauto      |
| Išvesties operatorius '<<'    | Leidžia išvesti objekto duomenis į konsolę                      |



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


