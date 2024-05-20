#ifndef HEADER_H // redefinition apsauga
#define HEADER_H

struct Studentas {
    string Vardas, Pavarde;
    vector<int> namudarbas;
    int egzaminorez;
};

void input1(Studentas& duom);
void input2(Studentas& duom);
void input3(Studentas& duom, int n);
double Vidurkis(const vector<int>& namudarbas);
double Mediana(const vector<int>& namudarbas);
double GalutinisVid(const Studentas& duom);
double GalutinisMed(const Studentas& duom);
void OutputBy(const vector<Studentas>& student);
void manualmode();
void readingmode(const string& fileName);
void filegeneration();
void SplitVector(const vector<Studentas>& student);
void SplitVector2(vector<Studentas>& student);
void SplitVector3(vector<Studentas>& student);
int NumberVerification(const string& prompt, int minValue, int maxValue);
int NumberVerification(const string& prompt, int minValue);
int YesNoVerification(const string& prompt);

#endif // HEADER_H