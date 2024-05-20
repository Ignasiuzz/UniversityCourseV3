#include "VectorIncludes.h"
#include "VectorHeader.h"
#include "Studentas.h"
//g++ -o program Vector.cpp Studentas.cpp

int main() {
    cout << "---------------------------------------- " << endl;
    int mode = NumberVerification("Manual input mode   [1]\nRead from file mode [2]\nFile Generator      [3]\nInput: ", 1, 3);

    if (mode == 1) {
        manualmode();
    } 
    else if (mode == 2) {
        readingmode("100000_GeneratedStudents.txt");
    }
    else if (mode == 3){
        filegeneration();
    }
    system ("pause");
}

/* READING FROM FILE MODE */
void readingmode(const string& fileName){
    vector<Studentas> student;
    ifstream inputFile;
    try {
        inputFile.open(fileName);

        if (!inputFile) {
            throw invalid_argument("Neimanoma atidaryti failo.");
        }
    }
    catch (const invalid_argument& e) {
        cerr << "!ERROR! " << e.what() << endl;
        return;
    }

    // Pradedamas skaiciuoti laikas
    auto start = high_resolution_clock::now();

    string line;
    getline(inputFile, line);

    // SKaitoma ir apdorojama visa eilute
    while (getline(inputFile, line)) {
        Studentas duom;
        
        // Sukurtas "stringstream", kad galetume apdoroti kiekviena eilute
        istringstream get(line);
        duom.readStudent(get);
        student.push_back(duom);
    }

    // Stabdomas skaiciuojamas laikas
    auto stop = high_resolution_clock::now();
    chrono::duration<double> diff = stop - start;
    cout << "Failo nuskaitymas! File reading took " << diff.count() << " seconds." << endl;

    int int_temp = NumberVerification("Studentu dalijimas i dvi grupes\n1 Strategija [1]\n2 Strategija [2]\n3 Strategija [3]\nIvestis: ", 1, 3);
    if (int_temp == 1){
        SplitVector(student);
    }
    else if (int_temp == 2){
        SplitVector2(student);
    }
    else if (int_temp == 3){
        SplitVector3(student);
    }
}

/* MANUAL INPUT MODE */
char string_temp;
int int_temp;

void manualmode(){
    vector<Studentas> student;

    cout << "---------------------------------------- " << endl;
    int_temp = NumberVerification("Zinomas mokiniu ir pazymiu skaicius   [1]\nNezinomas mokiniu ir pazymiu skaicius [2]\nGeneruoti mokinius ir pazymius        [3]\nInput: ", 1, 3);
    cout << "---------------------------------------- " << endl;
    
    if (int_temp == 1) {
        int m = NumberVerification("Iveskite studentu skaiciu: ", 1);
        vector<Studentas> student(m);

        for (int i = 0; i < m; i++) {
            input1(student[i]);
        }

        OutputBy(student);
    }
    else if (int_temp == 2){
        do {
        Studentas duom;
        input2(duom);
        student.push_back(duom);

        string_temp = YesNoVerification("Ar norite ivesti kita studenta? (y/n): ");
        }
        while (string_temp == 'y');

        OutputBy(student);
    }
    else if (int_temp == 3){
        int m = NumberVerification("Iveskite studentu skaiciu: ", 1);
        int n = NumberVerification("Iveskite studento namu darbu kieki (n): ", 1);
        srand(time(0));

        vector<Studentas> student(m);

        for (int i = 0; i < m; i++) {
            input3(student[i], n);
        }

        OutputBy(student);
    } 
}

void input1(Studentas& duom) {
    string temp; // Naudojama ivedimui i klase
    cout << "Iveskite studento varda: ";
    cin >> temp;
    duom.setVardas(temp);

    cout << "Iveskite studento pavarde: ";
    cin >> temp;
    duom.setPavarde(temp);

    int_temp = NumberVerification("Iveskite studento namu darbu kieki (n): ", 1);
    vector<double> namudarbas;
    for (int i = 0; i < int_temp; i++) {
        int int_temp = NumberVerification("Iveskite namu darbo rezultata: ", 1, 10);
        namudarbas.push_back(int_temp);
    }
    duom.setNamudarbas(namudarbas);
    
    int_temp = NumberVerification("Iveskite studento egzamino rezultata:", 1, 10);
    duom.setEgzaminas(int_temp);
}

void input2(Studentas& duom) {
    string temp; // Naudojama ivedimui i klase
    cout << "Iveskite studento varda: ";
    cin >> temp;
    duom.setVardas(temp);

    cout << "Iveskite studento pavarde: ";
    cin >> temp;
    duom.setPavarde(temp);

    vector<double> namudarbas;

    do {
        int_temp = NumberVerification("Iveskite studento namu darbu kieki (n): ", 1);
        for (int i = 0; i < int_temp; i++) {
            int int_temp = NumberVerification("Iveskite namu darbo rezultata: ", 1, 10);
            namudarbas.push_back(int_temp);
        }
        duom.setNamudarbas(namudarbas);
        string_temp = YesNoVerification("Ar norite ivesti dar pazymiu? (y/n): ");
        
    } while (string_temp == 'y');

    int_temp = NumberVerification("Iveskite studento egzamino rezultata:", 1, 10);
    duom.setEgzaminas(int_temp);
}

void input3(Studentas& duom, int n) {
    vector<string> NameArray = { "Jonas", "Vytautas", "Antanas", "Tomas", "Juozas", "Petras", "Gediminas", "Danielius", "Oskaras", "Linas" };
    vector<string> SurnameArray = { "Kazlauskas", "Stankevicius", "Petrauskas", "Jankauskas", "Butkus", "Paulauskas", "Urbonas", "Navickas", "Rimkus", "Bagdonas" };

    duom.setVardas(NameArray[rand() % NameArray.size()]);
    duom.setPavarde(SurnameArray[rand() % SurnameArray.size()]);
    vector<double> namudarbas;
    for (int i = 0; i < n; i++) {
        namudarbas.push_back(rand() % 10);
    }
    duom.setNamudarbas(namudarbas);
    duom.setEgzaminas(rand() % 10);
}

// /* Output by selected sorting */
void OutputBy(const vector<Studentas>& student) {
    vector<Studentas> sortedStudent = student;
    string file;

    // Skirta failu uzvadinimui, tikrinima ar isvedami kietiakai ar nuskriaustukai
    if (GalutinisVid(sortedStudent[0])>=5){
        file = "Kietiakai";
    }
    else {
        file = "Nuskriaustukai";
    }

    int placeholder = NumberVerification("Sort by:\nVardas   [1]\nPavarde  [2]\nVidurkis [3]\nMediana  [4]\nInput: ", 1, 4);
    if ( placeholder == 1 ) {
    auto start = high_resolution_clock::now();
    sort(sortedStudent.begin(), sortedStudent.end(), [](const Studentas& a, const Studentas& b) {
        string vardasA = a.Vardas();
        string vardasB = b.Vardas();

        // Check if the names follow the VardasX format
        bool isVardasAX = vardasA.find("Vardas") != string::npos;
        bool isVardasBX = vardasB.find("Vardas") != string::npos;

        if (isVardasAX && isVardasBX) {
            // Extract the numerical part (X) and compare
            int numA = stoi(vardasA.substr(6));
            int numB = stoi(vardasB.substr(6));
            return numA < numB;
        } else {
            // Compare regular names
            return vardasA < vardasB;
        }
    });
    auto stop = high_resolution_clock::now();
    chrono::duration<double> diff = stop - start;
    cout << "studentu grupes rusiavimas didejimo tvarka! Took " << diff.count() << " seconds." << endl;

        int n = NumberVerification("Isvesti duomenis i konsole [1]\nIsvesti duomenis i faila   [2]\nInput: ", 1, 2);
        if (n == 1){
            cout << "-----------------------------------------------------------------" << endl;
            cout << "Vardas         Pavarde        Galutinis (Vid.) / Galutinis (Med.)" << endl;
            cout << "-----------------------------------------------------------------" << endl;
                for (const auto& duom : sortedStudent) {
                    cout << left << setw(15) << duom.Vardas() << setw(15) << duom.Pavarde() << setw(19) << fixed << setprecision(2) << GalutinisVid(duom) << fixed << setprecision(2) << GalutinisMed(duom) << endl;
                }
            cout << "-----------------------------------------------------------------" << endl;
        }
        else if (n == 2) {
            string fileName = to_string(sortedStudent.size()) + "_" + file + "_Studentai.txt";
            ofstream FileOff(fileName);
            FileOff << "-----------------------------------------------------------------" << endl;
            FileOff << "Vardas         Pavarde        Galutinis (Vid.) / Galutinis (Med.)" << endl;
            FileOff << "-----------------------------------------------------------------" << endl;
            for (const auto& duom : sortedStudent) {
                stringstream studentData;
                studentData << left << setw(15) << duom.Vardas() << setw(15) << duom.Pavarde() << setw(19) << fixed << setprecision(2) << GalutinisVid(duom) << fixed << setprecision(2) << GalutinisMed(duom);
                FileOff << studentData.str() << endl;
            }
            FileOff.close();
        }
    }

    else if ( placeholder == 2 ){
    sort(sortedStudent.begin(), sortedStudent.end(), [](const Studentas& a, const Studentas& b) {
        string PavardeA = a.Pavarde();
        string PavardeB = b.Pavarde();

        // Check if the names follow the VardasX format
        bool isPavardeAX = PavardeA.find("Pavarde") != string::npos;
        bool isPavardeBX = PavardeB.find("Pavarde") != string::npos;

        if (isPavardeAX && isPavardeBX) {
            // Extract the numerical part (X) and compare
            int numA = stoi(PavardeA.substr(7));
            int numB = stoi(PavardeB.substr(7));
            return numA < numB;
        } else {
            // Compare regular names
            return PavardeA < PavardeB;
        }
    });

        int n = NumberVerification("Isvesti duomenis i konsole [1]\nIsvesti duomenis i faila   [2]\nInput: ", 1, 2);
        if (n == 1){
            cout << "-----------------------------------------------------------------" << endl;
            cout << "Pavarde         Vardas        Galutinis (Vid.) / Galutinis (Med.)" << endl;
            cout << "-----------------------------------------------------------------" << endl;
                for (const auto& duom : sortedStudent) {
                    cout << left << setw(15) << duom.Pavarde() << setw(15) << duom.Vardas() << setw(19) << fixed<<setprecision(2) << GalutinisVid(duom) << fixed << setprecision(2) << GalutinisMed(duom) << endl;
                }
            cout << "-----------------------------------------------------------------" << endl;
        }
        else if (n == 2) {
            string fileName = to_string(sortedStudent.size()) + "_" + file + "_Studentai.txt";
            ofstream FileOff(fileName);
            FileOff << "-----------------------------------------------------------------" << endl;
            FileOff << "Pavarde         Vardas        Galutinis (Vid.) / Galutinis (Med.)" << endl;
            FileOff << "-----------------------------------------------------------------" << endl;
            for (const auto& duom : sortedStudent) {
                stringstream studentData;
                studentData << left << setw(15) << duom.Pavarde() << setw(15) << duom.Vardas() << setw(19) << fixed << setprecision(2) << GalutinisVid(duom) << fixed << setprecision(2) << GalutinisMed(duom);
                FileOff << studentData.str() << endl;
            }
            FileOff.close();
        }
    }

    if ( placeholder == 3 ){

        sort(sortedStudent.begin(), sortedStudent.end(), [](const Studentas& a, const Studentas& b) {
            return GalutinisVid(a) < GalutinisVid(b);
        });

        int n = NumberVerification("Isvesti duomenis i konsole [1]\nIsvesti duomenis i faila   [2]\nInput: ", 1, 2);
        if (n == 1){
            cout << "-----------------------------------------------------------------" << endl;
            cout << "Galutinis (Vid.) Pavarde        Vardas         Galutinis (Med.)  " << endl;
            cout << "-----------------------------------------------------------------" << endl;
            for (const auto& duom : sortedStudent) {
                cout << left << setw(17) << fixed << setprecision(2) << GalutinisVid(duom) << setw(15) << duom.Pavarde() << setw(15) << duom.Vardas() << setw(19) << fixed << setprecision(2) << GalutinisMed(duom) << endl;
            }
            cout << "-----------------------------------------------------------------" << endl;
        }
        else if (n == 2) {
            string fileName = to_string(sortedStudent.size()) + "_" + file + "_Studentai.txt";
            ofstream FileOff(fileName);
            FileOff << "-----------------------------------------------------------------" << endl;
            FileOff << "Galutinis (Vid.) Pavarde        Vardas         Galutinis (Med.)  " << endl;
            FileOff << "-----------------------------------------------------------------" << endl;
            for (const auto& duom : sortedStudent) {
                stringstream studentData;
                studentData << left << setw(17) << fixed << setprecision(2) << GalutinisVid(duom) << setw(15) << duom.Pavarde() << setw(15) << duom.Vardas() << setw(19) << fixed << setprecision(2) << GalutinisMed(duom);
                FileOff << studentData.str() << endl;
            }
            FileOff.close();
        }
    }

    else if ( placeholder == 4 ){

        sort(sortedStudent.begin(), sortedStudent.end(), [](const Studentas& a, const Studentas& b) {
            return GalutinisMed(a) < GalutinisMed(b);
        });

        int n = NumberVerification("Isvesti duomenis i konsole [1]\nIsvesti duomenis i faila   [2]\nInput: ", 1, 2);
        if (n == 1){
            cout << "-----------------------------------------------------------------" << endl;
            cout << "Galutinis (Med.) Pavarde        Vardas         Galutinis (vid.)  " << endl;
            cout << "-----------------------------------------------------------------" << endl;
            for (const auto& duom : sortedStudent) {
                cout << left << setw(17) << fixed << setprecision(2) << GalutinisMed(duom) << setw(15) << duom.Pavarde() << setw(15) << duom.Vardas() << setw(19) << fixed << setprecision(2) << GalutinisMed(duom) << endl;
            }
            cout << "-----------------------------------------------------------------" << endl;
        }
        else if (n == 2) {
            string fileName = to_string(sortedStudent.size()) + "_" + file + "_Studentai.txt";
            ofstream FileOff(fileName);
            FileOff << "-----------------------------------------------------------------" << endl;
            FileOff << "Galutinis (Med.) Pavarde        Vardas         Galutinis (vid.)  " << endl;
            FileOff << "-----------------------------------------------------------------" << endl;
            for (const auto& duom : sortedStudent) {
                stringstream studentData;
                studentData << left << setw(17) << fixed << setprecision(2) << GalutinisMed(duom) << setw(15) << duom.Pavarde() << setw(15) << duom.Vardas() << setw(19) << fixed << setprecision(2) << GalutinisMed(duom);
                FileOff << studentData.str() << endl;
            }
            FileOff.close();
        }
    }
}

void filegeneration(){
    RandInt rnd {1, 10}; /* Pazymiu diapozonas costum RandInt.hpp klasei */

    int n = NumberVerification("Kiek studentu norime generuoti: ", 1);
    int m = 10; // Pazymiu skaicius (galima pakeisti i NumberVerification jeigu norime galeti pasirinkti paziumiu skaiciu)

    auto start = high_resolution_clock::now();
    // File creation
    string fileName = to_string(n) + "_GeneratedStudents.txt";
    ofstream FileOff(fileName);

    // File writing
    stringstream Header;
    Header << left << setw(15) << "Vardas" << setw(16) << "Pavarde";
    for (int i = 0; i < m-1; ++i){
        Header << "ND" + to_string(i+1) << "\t";
    }
    Header << "Egz.";
    FileOff << Header.str() << endl;

    // Generation
    for (int i = 0; i < n; ++i) {
        stringstream studentData;
        studentData << left << setw(15) << "Vardas" + to_string(i+1) << setw(16) << "Pavarde" + to_string(i+1);

        for (int j = 0; j < m; ++j) {
            studentData << rnd() << "\t"; /* Costum RandInt.hpp klase skirta skaiciu generavimui */
        }

        FileOff << studentData.str() << endl;
    }
    FileOff.close();

    auto stop = high_resolution_clock::now();
    chrono::duration<double> diff = stop - start;
    cout << "Generation finished! File generation took " << diff.count() << " seconds." << endl;

    readingmode(fileName);
}

void SplitVector(const vector<Studentas>& student){
    auto start = high_resolution_clock::now();

    cout << "Lygtais kazkas veikia";
    vector<Studentas> nuskriaustukai;
    vector<Studentas> kietiakiai;
    for (const auto& duom : student) {
        if (GalutinisVid(duom) < 5){
            nuskriaustukai.push_back(duom);
        }
        else{
            kietiakiai.push_back(duom);
        }
    }

    auto stop = high_resolution_clock::now();
    chrono::duration<double> diff = stop - start;
    cout << "Studentu skirstymas i dvi grupes! Student sorting to two groups took " << diff.count() << " seconds." << endl;

    OutputBy(kietiakiai);
    OutputBy(nuskriaustukai);
}

void SplitVector2(vector<Studentas>& student) {
    auto start = high_resolution_clock::now();

    vector<Studentas> nuskriaustukai;

    size_t i = 0;
    while (i < student.size()) {
        if (GalutinisVid(student[i]) < 5) {
            nuskriaustukai.push_back(move(student[i]));
            student.erase(student.begin() + i);
        } else {
            ++i;
        }
    }

    auto stop = high_resolution_clock::now();
    chrono::duration<double> diff = stop - start;
    cout << "Studentu skirstymas i dvi grupes! Student sorting to two groups took " << diff.count() << " seconds." << endl;

    OutputBy(student);
    OutputBy(nuskriaustukai);
}

void SplitVector3(vector<Studentas>& student) {
    auto start = high_resolution_clock::now();

    vector<Studentas> nuskriaustukai;

    auto partition_point = partition(student.begin(), student.end(), [](const Studentas& student) {
        return GalutinisVid(student) < 5;
    });

    // Move students with GalutinisVid < 5 to nuskriaustukai and erase them from students
    auto remove_point = remove_if(student.begin(), partition_point, [](const Studentas& student) {
        return GalutinisVid(student) < 5;
    });

    // Move removed students to nuskriaustukai
    move(remove_point, partition_point, back_inserter(nuskriaustukai));

    student.erase(remove_point, partition_point);

    auto stop = high_resolution_clock::now();
    chrono::duration<double> diff = stop - start;
    cout << "Studentu skirstymas i dvi grupes! Student sorting to two groups took " << diff.count() << " seconds." << endl;

    OutputBy(student);
    OutputBy(nuskriaustukai);
}

int NumberVerification(const string& prompt, int minValue, int maxValue) {
    int value;
    string input;

    while (true) {
        cout << prompt;
        try {
            cin >> input;
            size_t pos;
            value = stoi(input, &pos);

            if (pos < input.size()) {
                throw invalid_argument("");  // Jeigu ivestas ne sveikasis skaicius
            }

            if (value < minValue || value > maxValue) {
                throw out_of_range("Ivestis uz diapazono ribu. Prasome ivesti skaiciu nuo " + to_string(minValue) + " iki " + to_string(maxValue) + ".");
            }
            
            return value;
        } catch (const invalid_argument& e) {
            cerr << "!Error! Prasome ivesti SVEIKAJI skaiciu." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Istrinama neteisinga ivestis
        } catch (const out_of_range& e) {
            cerr << "!Error! " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Istrinama neteisinga ivestis
        }
    }
}

int NumberVerification(const string& prompt, int minValue) {
    int value;
    string input;

    while (true) {
        cout << prompt;
        try {
            cin >> input;
            size_t pos;
            value = stoi(input, &pos);

            if (pos < input.size()) {
                throw invalid_argument("");  // Jeigu ivestas ne sveikasis skaicius
            }

            if (value < minValue) {
                throw out_of_range("Input is below the minimum allowed value. Please enter a number greater than or equal to " + to_string(minValue) + ".");
            }

            // If we reach here, the input is valid
            return value;
        } catch (const invalid_argument& e) {
            cerr << "!Error! Prasome ivesti SVEIKAJI skaiciu." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Istrinama neteisinga ivestis
        } catch (const out_of_range& e) {
            cerr << "!Error! " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Istrinama neteisinga ivestis
        }
    }
}

int YesNoVerification(const string& prompt) {
    char input;

    while (true) {
        cout << prompt;
        try {
            cin >> input;

            if ( input == 'y' || input == 'n' )
                return input;
            else 
                throw runtime_error("Prasome ivesti 'y' arba 'n'.");
            
        }
        catch (const exception& e) {
            cerr << "!Error! " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Istrinama neteisinga ivestis
        }
    }
}