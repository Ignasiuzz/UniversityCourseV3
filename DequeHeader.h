#ifndef HEADER_H // redefinition apsauga
#define HEADER_H

struct Studentas {
    string Vardas, Pavarde;
    deque<int> namudarbas;
    int egzaminorez;
};

void input1(Studentas& duom);
void input2(Studentas& duom);
void input3(Studentas& duom, int n);
double Vidurkis(const deque<int>& namudarbas);
double Mediana(const deque<int>& namudarbas);
double GalutinisVid(const Studentas& duom);
double GalutinisMed(const Studentas& duom);
void OutputBy(const deque<Studentas>& student);
void OutputByVardas(deque<Studentas>& sortedStudent, string& file);
void OutputByPavarde(deque<Studentas>& sortedStudent, string& file);
void OutputByVidurkis(deque<Studentas>& sortedStudent, string& file);
void OutputByMediana(deque<Studentas>& sortedStudent, string& file);
void manualmode();
void readingmode(const string& fileName);
void filegeneration();
void SplitDeque(const deque<Studentas>& student);
void SplitDeque2(deque<Studentas>& student);
void SplitDeque3(deque<Studentas>& student);
int NumberVerification(const string& prompt, int minValue, int maxValue);
int NumberVerification(const string& prompt, int minValue);
char YesNoVerification(const string& prompt);

#endif // HEADER_H