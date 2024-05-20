#include "VectorIncludes.h"
#include "Studentas.h"
//g++ -o program test.cpp Studentas.cpp

void test_constructors() {
    // Test default constructor
    Studentas s1;
    cout << "Test default constructor " << s1.Vardas() << endl;
    cout << "Test default constructor " << s1.Pavarde() << endl;
    cout << "Test default constructor ";
    for (double grade : s1.Namudarbas()) {
        cout << grade << " ";
    }
    cout << endl << "Test default constructor " << s1.Egzaminas() << endl;

    // Test constructor with input stream
    istringstream iss("John Doe 1 1 1 1 1");
    Studentas s2;
    s2.readStudent(iss);
    cout << "Test constructor with input stream " << s2.Vardas() << endl;
    cout << "Test constructor with input stream " << s2.Pavarde() << endl;
    cout << "Test constructor with input stream ";
    for (double grade : s2.Namudarbas()) {
        cout << grade << " ";
    }
    cout << endl << "Test constructor with input stream " << s2.Egzaminas() << endl;

    // Test copy constructor
    Studentas s3 = s2;
    cout << "Test copy constructor " << s3.Vardas() << endl;
    cout << "Test copy constructor " << s3.Pavarde() << endl;
    cout << "Test copy constructor ";
    for (double grade : s3.Namudarbas()) {
        cout << grade << " ";
    }
    cout << endl << "Test copy constructor " << s3.Egzaminas() << endl;

    // Test move constructor
    Studentas s4 = move(s3);
    cout << "Test move constructor " << s4.Vardas() << endl;
    cout << "Test move constructor " << s4.Pavarde() << endl;
    cout << "Test move constructor ";
    for (double grade : s4.Namudarbas()) {
        cout << grade << " ";
    }
    cout << endl << "Test move constructor " << s4.Egzaminas() << endl;
}

void test_assignment_operators() {
    // Test copy assignment
    Studentas s1("John", "Doe", 2, {2, 2, 2, 2});
    Studentas s2;
    s2 = s1;
    cout << "Test copy assignment " << s2.Vardas() << endl;
    cout << "Test copy assignment " << s2.Pavarde() << endl;
    cout << "Test copy assignment ";
    for (double grade : s2.Namudarbas()) {
        cout << grade << " ";
    }
    cout << endl << "Test copy assignment " << s2.Egzaminas() << endl;

    // Test move assignment
    Studentas s3;
    s3 = move(s2);
    cout << "Test move assignment " << s3.Vardas() << endl;
    cout << "Test move assignment " << s3.Pavarde() << endl;
    cout << "Test move assignment ";
    for (double grade : s3.Namudarbas()) {
        cout << grade << " ";
    }
    cout << endl << "Test move assignment " << s3.Egzaminas() << endl;
}

void test_input_output_methods() {
    // Test manual input
    Studentas s1;
    s1.setVardas("John");
    s1.setPavarde("Doe");
    s1.setNamudarbas({3, 3, 3, 3});
    s1.setEgzaminas(3);

    // Test output to screen
    cout << "Test manual input " << s1.Vardas() << endl;
    cout << "Test manual input " << s1.Pavarde() << endl;
    cout << "Test manual input ";
    for (double grade : s1.Namudarbas()) {
        cout << grade << " ";
    }
    cout << endl;
    cout << "Test manual input " << s1.Egzaminas() << endl;
}

void test_AverageCalculations() {
    Studentas s1("John", "Doe", 8, {6, 7, 3, 4, 9});
    cout << "Test GalutinisMed calculations (7.2) " << GalutinisMed(s1) << endl;
    cout << "Test GalutinisVid calculations (7.12) " << GalutinisVid(s1) << endl;
}

int main() {
    test_constructors();
    test_assignment_operators();
    test_input_output_methods();
    test_AverageCalculations();
    
    //Zmogus duom("Jonas", "Jonaitis");
    system ("pause");
}