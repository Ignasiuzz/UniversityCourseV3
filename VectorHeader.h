#ifndef HEADER_H // redefinition apsauga
#define HEADER_H

#include "VectorIncludes.h"
#include "studentas.h"

void input1(Studentas& duom);
void input2(Studentas& duom);
void input3(Studentas& duom, int n);
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