//g++ -o Laikas Laiko_Skaiciavimas.cpp vectorClass.cpp
#include <iostream>
#include "MainIncludes.h"
#include "vectorClass.h"

using namespace std;

int main(){
int perskirstymai1 = 0, perskirstymai2 = 0;

unsigned int sz = 100000000;  // 100000, 1000000, 10000000, 100000000

auto start_v1 = high_resolution_clock::now();

std::vector<int> v1;
for (int i = 1; i <= sz; ++i){
    v1.push_back(i);
    if(v1.capacity() == v1.size()){
        perskirstymai1++;
    }
}

auto stop_v1 = high_resolution_clock::now();
chrono::duration<double> diff_v1 = stop_v1 - start_v1;
cout << "| " << sz << " | " << diff_v1.count() << " seconds.";

auto start_v2 = high_resolution_clock::now();

vectorClass<int> v2;
for (int i = 1; i <= sz; ++i){
    v2.push_back(i);
    if(v2.get_capacity() == v2.size()){
        perskirstymai2++;
    }
}

auto stop_v2 = high_resolution_clock::now();
chrono::duration<double> diff_v2 = stop_v2 - start_v2;
cout << " | " << diff_v2.count() << " seconds. |" << endl;

cout << "std::vector atminties perskirtymai: " << perskirstymai1 << endl << "vectorClass atminties perskirtymai:" << perskirstymai2 << endl;
system("pause");
}