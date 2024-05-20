#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include "Zmogus.h"

class Studentas : public Zmogus{
private:
    double egzaminas_;
    std::vector<double> namudarbas_;

public:
    // Default konstruktoriai
    Studentas() : Zmogus(), egzaminas_(0), namudarbas_({}) {}
    Studentas(const std::string& vardas, const std::string& pavarde, double egzaminas, const std::vector<double>& namudarbas) : Zmogus(vardas, pavarde), egzaminas_(egzaminas), namudarbas_(namudarbas) {}

    // Rule of Five
    ~Studentas();
    Studentas(const Studentas& other); // Copy constructor
    Studentas(Studentas&& other) noexcept; // Move constructor
    Studentas& operator=(const Studentas& other); // Copy assignment
    Studentas& operator=(Studentas&& other) noexcept; // Move assignment
    
    // Outputeriai
    std::string Vardas() const { return Vardas_; }
    std::string Pavarde() const { return Pavarde_; }
    double Egzaminas() const { return egzaminas_; }
    std::vector<double> Namudarbas() const { return namudarbas_; }

    // Set'eriai
    void setVardas(const std::string& vardas);
    void setPavarde(const std::string& pavarde);
    void setEgzaminas(double egzaminas);
    void setNamudarbas(const std::vector<double>& namudarbas);
    std::istream& readStudent(std::istream&);

    // Calculations
    friend double GalutinisVid(const Studentas& duom);
    friend double GalutinisMed(const Studentas& duom);
    
    // Static functions for calculations
    static double Vidurkis(const std::vector<double>& namudarbas);
    static double Mediana(const std::vector<double>& namudarbas);

    // Virtualios funkcijos deklaracija, kad klase Zmogus butu abstrakti
    virtual void doSomething();
};
#endif