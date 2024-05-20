#ifndef ZMOGUS_H
#define ZMOGUS_H

class Zmogus {
protected:
    std::string Vardas_;
    std::string Pavarde_;

public:
    // Default konstruktorius
    Zmogus() : Vardas_(""), Pavarde_("") {}
    Zmogus(const std::string& vardas, const std::string& pavarde) : Vardas_(vardas), Pavarde_(pavarde) {}

    // Virtualus destruktorius
    virtual ~Zmogus() {}

    // Virtualus outputeriai
    virtual std::string Vardas() const { return Vardas_; }
    virtual std::string Pavarde() const { return Pavarde_; }

    // Virtualus set'eriai
    virtual void setVardas(const std::string& vardas) { Vardas_ = vardas; }
    virtual void setPavarde(const std::string& pavarde) { Pavarde_ = pavarde; }

    // Virtuali funkcija be realizacijos tam, kad klase Zmogus butu abstrakti
    virtual void doSomething() = 0;
};

#endif