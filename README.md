# UniversityCourseV3
Objektinio programavimo paskutinioji užduotis. Sukurtas `vectorClass` konteineris padengiantis `std::vector` konteinerio metodus ir pilnai veikiantis su v1.5 programos versija.

# Efektyvumo/spartos analizė
Number of `int` type elements filling `vectors` using `push_back()` funkction.
| Number of elements | std::vector | vectorClass |
| :---: | :---: | :---: |
| 10000 | 0.000152 seconds. | 0.00009 seconds. |
| 100000 | 0.0010375 seconds. | 0.0007579 seconds. |
| 1000000 | 0.0086524 seconds. | 0.0059382 seconds. |
| 10000000 | 0.0767485 seconds. | 0.0648773 seconds. |
| 100000000 | 0.717261 seconds. | 0.543378 seconds. |

# Atminties perskirstymai
`vectorClass` ir `std::vector` užpildant vektorių 10.000.000 elementų įvyksta **27** atminties perskirstymai. Perskirstymas įvyksta tada, kai yra patenkinama sąlyga: `capacity() == size()`, t.y. kai nelieka vietos `capacity()` naujiems elementams.
# Spartos analizė
### Failo nuskaitymas
| Studentų įrašų skaičius | std::vector | vectorClass |
| :---: | :---: | :---: |
| 100.000 | 2.32839 seconds. | 2.34903 seconds. |
| 1.000.000 | 22.8893 seconds. | 23.1926 seconds. |
| 10.000.000 | 218.92 seconds. | 233.481 seconds. |

### Studentų rušiavimas į dvi grupes
| Studentų įrašų skaičius | std::vector | vectorClass |
| :---: | :---: | :---: |
| 100.000 | 0.0363991 seconds. | 0.0307202 seconds. |
| 1.000.000 | 0.364148 seconds. | 0.40457 seconds. |
| 10.000.000 | 3.49419 seconds. | 3.98185 seconds. |

### Studentų rikiavimas didejimo tvarka
| Studentų įrašų skaičius | std::vector | vectorClass |
| :---: | :---: | :---: |
| 100.000 | 0.221569 seconds. | 0.207835 seconds. |
| 1.000.000 | 2.61153 seconds. | 2.56135 seconds. |
| 10.000.000 | 34.2261 seconds. | 32.7805 seconds. |

### Studentų išvedimas i failą
| Studentų įrašų skaičius | std::vector | vectorClass |
| :---: | :---: | :---: |
| 100.000 | 0.736306 seconds. | 0.882708 seconds. |
| 1.000.000 | 7.33968 seconds. | 7.32049 seconds. |
| 10.000.000 | 72.7425 seconds. | 70.5485 seconds. |

# System
All the test were ran on `ryzen 5 5600x`, `32gb ddr4 3600mhz`, `rtx 4060`, `1m.2 samsung ssd`.
# vectorClass Functions
This part outlines some of the `functions` used in my custom `vectorClass`.
## 1. `push_back`
**Code Example:**

```cpp
#include <iostream>
#include "vectorClass.h"

void test_push_back() {
    vectorClass<int> myVec;
    myVec.push_back(1);
    myVec.push_back(2);
    myVec.push_back(3);
    std::cout << "vectorClass: ";
    for (int i = 0; i < myVec.size(); ++i) {
        std::cout << myVec[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    test_push_back();
    system("pause");
}
```
```
Output:
std::vector: 1 2 3 
vectorClass: 1 2 3 
```
## 2. `operator[]`
**Code Example:**

```cpp
#include <iostream>
#include "vectorClass.h"

void test_operator_index() {
    vectorClass<int> myVec;
    myVec.push_back(10);
    myVec.push_back(20);
    myVec.push_back(30);
    std::cout << "vectorClass: " << myVec[0] << " " << myVec[1] << " " << myVec[2] << std::endl;
}

int main() {
    test_operator_index();
    system("pause");
}
```
```
Output:
std::vector: 10 20 30
vectorClass: 10 20 30
```
## 3. `resize`
**Code Example:**

```cpp
#include <iostream>
#include "vectorClass.h"

void test_resize() {
    vectorClass<int> myVec;
    myVec.push_back(1);
    myVec.push_back(2);
    myVec.push_back(3);
    myVec.resize(5);
    std::cout << "vectorClass (resize to 5): ";
    for (int i = 0; i < myVec.size(); ++i) {
        std::cout << myVec[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    test_resize();
    system("pause");
}

```
```
Output:
std::vector (resize to 5): 1 2 3 0 0 
vectorClass (resize to 5): 1 2 3 0 0 
```
## 4. `at`
**Code Example:**

```cpp
#include <iostream>
#include "vectorClass.h"

void test_at() {
    vectorClass<int> myVec;
    myVec.push_back(100);
    myVec.push_back(200);
    myVec.push_back(300);
    try {
        std::cout << "vectorClass: " << myVec.at(1) << std::endl;
        std::cout << "vectorClass: " << myVec.at(3) << std::endl; // This will throw
    } catch (const std::out_of_range& e) {
        std::cout << "vectorClass out_of_range exception: " << e.what() << std::endl;
    }
}

int main() {
    test_at();
    system("pause");
}
```
```
Output:
std::vector: 200
std::vector out_of_range exception: vector::_M_range_check: __n (which is 3) >= this->size() (which is 3)
vectorClass: 200
vectorClass out_of_range exception: Index out of range
```
## 5. `insert`
**Code Example:**

```cpp
#include <iostream>
#include "vectorClass.h"

void test_insert() {
    vectorClass<int> myVec;
    myVec.push_back(1);
    myVec.push_back(2);
    myVec.push_back(4);
    myVec.insert(2, 3);
    std::cout << "vectorClass: ";
    for (int i = 0; i < myVec.size(); ++i) {
        std::cout << myVec[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    test_insert();
    return 0;
}
```
```
Output:
std::vector: 1 2 3 4 
vectorClass: 1 2 3 4 
```
