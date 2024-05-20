// Studentas.cpp
#include "Studentas.h"

// Duomenu manual irasymas
void Studentas::setVardas(const std::string& vardas) {
    Vardas_ = vardas;
}
void Studentas::setPavarde(const std::string& pavarde) {
    Pavarde_ = pavarde;
}
void Studentas::setEgzaminas(double egzaminas) {
    egzaminas_ = egzaminas;
}
void Studentas::setNamudarbas(const std::vector<double>& namudarbas) {
    namudarbas_ = namudarbas;
}

// Galutinio vidurkio skaiciavimas
double Studentas::Vidurkis(const std::vector<double>& namudarbas) {
    double sum = 0;
    for (double grade : namudarbas) {
        sum += grade;
    }
    return sum / namudarbas.size();
}
double Studentas::Mediana(const std::vector<double>& namudarbas) {
    std::vector<double> sortedVector = namudarbas;
    std::sort(sortedVector.begin(), sortedVector.end());

    if (sortedVector.size() % 2 == 0)
        return (sortedVector[sortedVector.size() / 2 - 1] + sortedVector[sortedVector.size() / 2]) / 2.0;
    else
        return sortedVector[sortedVector.size() / 2];
}
double GalutinisVid(const Studentas& duom) {
    double ndAverage = Studentas::Vidurkis(duom.namudarbas_);
    return 0.4 * ndAverage + 0.6 * duom.egzaminas_;
}
double GalutinisMed(const Studentas& duom) {
    double ndMedian = Studentas::Mediana(duom.namudarbas_);
    return 0.4 * ndMedian + 0.6 * duom.egzaminas_;
}

// Skaitymas is failo
std::istream& Studentas::readStudent(std::istream& is) {
    is >> Vardas_ >> Pavarde_;

    namudarbas_.clear();

    double grade;
    while (is >> grade) {
        namudarbas_.push_back(grade);
    }

    egzaminas_ = namudarbas_.back();
    namudarbas_.pop_back();
    return is;
}

// Default destructor
Studentas::~Studentas() {
}

/* Rule of Five */
// Copy constructor
Studentas::Studentas(const Studentas& other)
    : Zmogus(other), egzaminas_(other.egzaminas_), namudarbas_(other.namudarbas_) {}

// Move constructor
Studentas::Studentas(Studentas&& other) noexcept
    : Zmogus(std::move(other)), egzaminas_(std::move(other.egzaminas_)), namudarbas_(std::move(other.namudarbas_)) {
     other.egzaminas_ = 0;
}

// Copy assignment
Studentas& Studentas::operator=(const Studentas& other) {
    if (this != &other) {
        Zmogus::operator=(other); // Call base class assignment operator
        namudarbas_ = other.namudarbas_;
        egzaminas_ = other.egzaminas_;
    }
    return *this;
}

// Move assignment
Studentas& Studentas::operator=(Studentas&& other) noexcept {
    if (this != &other) {
        Zmogus::operator=(std::move(other)); // Call base class move assignment operator
        namudarbas_ = std::move(other.namudarbas_);
        egzaminas_ = std::move(other.egzaminas_);

        other.egzaminas_ = 0;
    }
    return *this;
}

// Virtualios funkcijos aprasymas, kad klase Zmogus butu abstrakti
void Studentas::doSomething() {
    std::cout << "Studentas is doing something." << std::endl;
}
