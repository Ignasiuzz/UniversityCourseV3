#ifndef HEADER_H // redefinition apsauga
#define HEADER_H

struct Studentas {
    string Vardas, Pavarde;
    list<int> namudarbas;
    int egzaminorez;
};

void input1(Studentas& duom);
void input2(Studentas& duom);
void input3(Studentas& duom, int n);
double Vidurkis(const list<int>& namudarbas);
double Mediana(const list<int>& namudarbas);
double GalutinisVid(const Studentas& duom);
double GalutinisMed(const Studentas& duom);
void OutputBy(const list<Studentas>& student);
void OutputByVardas(list<Studentas>& sortedStudent, string& file);
void OutputByPavarde(list<Studentas>& sortedStudent, string& file);
void OutputByVidurkis(list<Studentas>& sortedStudent, string& file);
void OutputByMediana(list<Studentas>& sortedStudent, string& file);
void manualmode();
void readingmode(const string& fileName);
void filegeneration();
void SplitList(const list<Studentas>& student);
void SplitList2(list<Studentas>& students);
void SplitList3(list<Studentas>& students);
int NumberVerification(const string& prompt, int minValue, int maxValue);
int NumberVerification(const string& prompt, int minValue);
char YesNoVerification(const string& prompt);

#endif // HEADER_H