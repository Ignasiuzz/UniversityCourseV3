#include "DequeIncludes.h"
#include "DequeHeader.h"

int main() {
    cout << "---------------------------------------- " << endl;
    int mode = NumberVerification("Manual input mode   [1]\nRead from file mode [2]\nFile Generator      [3]\nInput: ", 1, 3);

    if (mode == 1) {
        manualmode();
    } 
    else if (mode == 2) {
        cout << "---------------------------------------- " << endl;
        cout<< "Galimi 1000, 10000, 100000, 1000000\nIveskite kiek studentu norime nuskaityti: ";
        string n;
        cin >> n;
        string string_temp = n + "_GeneratedStudents.txt";
        cout << "---------------------------------------- " << endl;
        readingmode(string_temp);
    }
    else if (mode == 3){
        filegeneration();
    }
    system("pause");
}

/* READING FROM FILE MODE */
void readingmode(const string& fileName){
    deque<Studentas> student;
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

        get >> duom.Vardas >> duom.Pavarde;
        int grade;
        // Nuskaitomi visi skaiciai iki eilutes galo
        while (get >> grade) {
            duom.namudarbas.push_back(grade);
        }
        // Priskiriamas egzamino rezultatas yra paskutinis is nuskaitytu skaicius
        duom.egzaminorez = duom.namudarbas.back();
        duom.namudarbas.pop_back();

        student.push_back(duom);
    }
    inputFile.close();

    // Stabdomas skaiciuojamas laikas
    auto stop = high_resolution_clock::now();
    chrono::duration<double> diff = stop - start;
    cout << "Failo nuskaitymas! File reading took " << diff.count() << " seconds." << endl;

    int int_temp = NumberVerification("Studentu dalijimas i dvi grupes\n1 Strategija [1]\n2 Strategija [2]\n3 Strategija [3]\nIvestis: ", 1, 3);
    if (int_temp == 1){
        SplitDeque(student);
    }
    else if (int_temp == 2){
        SplitDeque2(student);
    }
    else if (int_temp == 3){
        SplitDeque3(student);
    }
}

/* MANUAL INPUT MODE */
char string_temp;
int int_temp;

void manualmode(){
    deque<Studentas> student;

    cout << "---------------------------------------- " << endl;
    int_temp = NumberVerification("Zinomas mokiniu ir pazymiu skaicius   [1]\nNezinomas mokiniu ir pazymiu skaicius [2]\nGeneruoti mokinius ir pazymius        [3]\nInput: ", 1, 3);
    cout << "---------------------------------------- " << endl;
    
    if (int_temp == 1) {
        int m = NumberVerification("Iveskite studentu skaiciu: ", 1);
        deque<Studentas> student(m);

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

        deque<Studentas> student(m);

        for (int i = 0; i < m; i++) {
            input3(student[i], n);
        }

        OutputBy(student);
    } 
}

void input1(Studentas& duom) {
    cout << "Iveskite studento varda: ";
    cin >> duom.Vardas;

    cout << "Iveskite studento pavarde: ";
    cin >> duom.Pavarde;

    int_temp = NumberVerification("Iveskite studento namu darbu kieki (n): ", 1);
    for (int i = 0; i < int_temp; i++) {
        int int_temp = NumberVerification("Iveskite namu darbo rezultata: ", 1, 10);
        duom.namudarbas.push_back(int_temp);
    }
    
    int_temp = NumberVerification("Iveskite studento egzamino rezultata:", 1, 10);
    duom.egzaminorez = int_temp;
}

void input2(Studentas& duom) {
    cout << "Iveskite studento varda: ";
    cin >> duom.Vardas;

    cout << "Iveskite studento pavarde: ";
    cin >> duom.Pavarde;

    do {
        int_temp = NumberVerification("Iveskite studento namu darbu kieki (n): ", 1);
        for (int i = 0; i < int_temp; i++) {
            int int_temp = NumberVerification("Iveskite namu darbo rezultata: ", 1, 10);
            duom.namudarbas.push_back(int_temp);
        }

        string_temp = YesNoVerification("Ar norite ivesti dar pazymiu? (y/n): ");
        
    } while (string_temp == 'y');
    
    int_temp = NumberVerification("Iveskite studento egzamino rezultata:", 1, 10);
    duom.egzaminorez = int_temp;
}

void input3(Studentas& duom, int n) {
    deque<string> NameArray = { "Jonas", "Vytautas", "Antanas", "Tomas", "Juozas", "Petras", "Gediminas", "Danielius", "Oskaras", "Linas" };
    deque<string> SurnameArray = { "Kazlauskas", "Stankevicius", "Petrauskas", "Jankauskas", "Butkus", "Paulauskas", "Urbonas", "Navickas", "Rimkus", "Bagdonas" };

    duom.Vardas = NameArray[rand() % NameArray.size()];
    duom.Pavarde = SurnameArray[rand() % SurnameArray.size()];

    for (int i = 0; i < n; i++) {
        duom.namudarbas.push_back(rand() % 10);
    }

    duom.egzaminorez = rand() % 10;
}

/* Output by selected sorting */
void OutputBy(const deque<Studentas>& student) {
    deque<Studentas> sortedStudent = student;
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
        string vardasA = a.Vardas;
        string vardasB = b.Vardas;

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
                    cout << left << setw(15) << duom.Vardas << setw(15) << duom.Pavarde << setw(19) << fixed << setprecision(2) << GalutinisVid(duom) << fixed << setprecision(2) << GalutinisMed(duom) << endl;
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
                studentData << left << setw(15) << duom.Vardas << setw(15) << duom.Pavarde << setw(19) << fixed << setprecision(2) << GalutinisVid(duom) << fixed << setprecision(2) << GalutinisMed(duom);
                FileOff << studentData.str() << endl;
            }
            FileOff.close();
        }
    }

    else if ( placeholder == 2 ){

    sort(sortedStudent.begin(), sortedStudent.end(), [](const Studentas& a, const Studentas& b) {
        string PavardeA = a.Pavarde;
        string PavardeB = b.Pavarde;

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
                    cout << left << setw(15) << duom.Pavarde << setw(15) << duom.Vardas << setw(19) << fixed<<setprecision(2) << GalutinisVid(duom) << fixed << setprecision(2) << GalutinisMed(duom) << endl;
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
                studentData << left << setw(15) << duom.Pavarde << setw(15) << duom.Vardas << setw(19) << fixed << setprecision(2) << GalutinisVid(duom) << fixed << setprecision(2) << GalutinisMed(duom);
                FileOff << studentData.str() << endl;
            }
            FileOff.close();
        }
    }

    else if ( placeholder == 3 ){

        sort(sortedStudent.begin(), sortedStudent.end(), [](const Studentas& a, const Studentas& b) {
            return GalutinisVid(a) < GalutinisVid(b);
        });

        int n = NumberVerification("Isvesti duomenis i konsole [1]\nIsvesti duomenis i faila   [2]\nInput: ", 1, 2);
        if (n == 1){
            cout << "-----------------------------------------------------------------" << endl;
            cout << "Galutinis (Vid.) Pavarde        Vardas         Galutinis (Med.)  " << endl;
            cout << "-----------------------------------------------------------------" << endl;
            for (const auto& duom : sortedStudent) {
                cout << left << setw(17) << fixed << setprecision(2) << GalutinisVid(duom) << setw(15) << duom.Pavarde << setw(15) << duom.Vardas << setw(19) << fixed << setprecision(2) << GalutinisMed(duom) << endl;
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
                studentData << left << setw(17) << fixed << setprecision(2) << GalutinisVid(duom) << setw(15) << duom.Pavarde << setw(15) << duom.Vardas << setw(19) << fixed << setprecision(2) << GalutinisMed(duom);
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
                cout << left << setw(17) << fixed << setprecision(2) << GalutinisMed(duom) << setw(15) << duom.Pavarde << setw(15) << duom.Vardas << setw(19) << fixed << setprecision(2) << GalutinisMed(duom) << endl;
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
                studentData << left << setw(17) << fixed << setprecision(2) << GalutinisMed(duom) << setw(15) << duom.Pavarde << setw(15) << duom.Vardas << setw(19) << fixed << setprecision(2) << GalutinisMed(duom);
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

void SplitDeque(const deque<Studentas>& student){
    auto start = high_resolution_clock::now();

    deque<Studentas> nuskriaustukai;
    deque<Studentas> kietiakiai;
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

void SplitDeque2(deque<Studentas>& student) {
    auto start = high_resolution_clock::now();

    deque<Studentas> nuskriaustukai;

    auto it = student.begin();
    while (it != student.end()) {
        if (GalutinisVid(*it) < 5) {
            nuskriaustukai.push_back(*it);
            it = student.erase(it);
        } else {
            ++it;
        }
    }

    auto stop = high_resolution_clock::now();
    chrono::duration<double> diff = stop - start;
    cout << "Studentu skirstymas i dvi grupes! Student sorting to two groups took " << diff.count() << " seconds." << endl;

    OutputBy(student);
    OutputBy(nuskriaustukai);
}

void SplitDeque3(deque<Studentas>& student) {
    auto start = high_resolution_clock::now();

    deque<Studentas> nuskriaustukai;

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
// Apskaiciuojamas namu darbu rezultatu vidurkis
double Vidurkis(const deque<int>& namudarbas) {
    double sum = 0;
    for (int i = 0; i < namudarbas.size(); i++) {
        sum += namudarbas[i];
    }
    return sum / namudarbas.size();
}
// Apskaiciuojamas galutinis paprastas vidurkis
double GalutinisVid(const Studentas& duom) {
    double ndAverage = Vidurkis(duom.namudarbas);
    return 0.4 * ndAverage + 0.6 * duom.egzaminorez;
}
// Apskaiciuojama namu darbu rezultatu mediana
double Mediana(const deque<int>& namudarbas) {
    deque<int> sortedVector = namudarbas;
    sort(sortedVector.begin(), sortedVector.end());

    if (sortedVector.size() % 2 == 0)
        return (sortedVector[sortedVector.size() / 2 - 1] + sortedVector[sortedVector.size() / 2]) / 2.0;
    else
        return sortedVector[sortedVector.size() / 2];
}
// Apskaiciuojamas galutinis vidurkis su mediana
double GalutinisMed(const Studentas& duom) {
    double ndAverage = Mediana(duom.namudarbas);
    return 0.4 * ndAverage + 0.6 * duom.egzaminorez;
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

char YesNoVerification(const string& prompt) {
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