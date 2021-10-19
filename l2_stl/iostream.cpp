void iostreamDemo() {
    istreamDemo();
    ostreamDemo();
}

void istreamDemo() {
    const int N = 13; // Hello, world! = 13 chars
    istreamDemoCIN(N);
    istreamDemoGET(N);
    istreamDemoGETLINE(N);
    istreamDemoSCANF(N);
}

void ostreamDemo() {
    char *string = initStr();
    const int N = 13;
    ostreamDemoCOUT(string, N);
    ostreamDemoPUT(string, N);
    ostreamDemoWRITE(string, N);
    ostreamDemoPRINTF(string, N);
    // formatted output - google!
}

void printString(char string[], const int &N) {
    for (int i = 0; i < N; i++) {
        cout << string[i];
    }
    cout << endl;
}

void istreamDemoCIN(const int &N) {
    char string1[N]; // C-string1
    cin >> string1[0] >> string1[1] >> string1[2] >> string1[3] >> string1[4] >> string1[5] >> string1[6] >>
        string1[7] >> string1[8] >> string1[9] >> string1[10] >> string1[11] >> string1[12];
    printString(string1, N);
    cin.ignore();

    // shit
    char string2[N];
    for (int i = 0; i < N; i++) {
        char tmp;
        cin >> tmp;
        string2[i] = tmp;
    }
    printString(string2, N);
    cin.ignore();
    // norm
}

void istreamDemoGET(const int &N) {
    char string1[N];
    cin.get(string1, N, '\n');
    string1[N - 1] = cin.get();
    printString(string1, N);
    cin.ignore();

    char string2[N];
    for (int i = 0; i < N; i++) {
        char tmp = cin.get();
        string2[i] = tmp;
    }

    printString(string2, N);
    cin.ignore();
}

void istreamDemoGETLINE(const int &N) {
    char string[N];
    cin.ignore(0);
    cin.getline(string, N + 1);
    printString(string, N);
}

void istreamDemoSCANF(const int &N) {
    char string1[N];
    scanf("%[^\n]", string1);
    printString(string1, N);
    cin.ignore();

    char string2[N];
    for (int i = 0; i < N; i++) {
        char tmp;
        scanf("%c", &tmp);
        string2[i] = tmp;
    }
    printString(string2, N);
    cin.ignore();
}

char *initStr() {
    char *string = "Hello, world!";
    return string;
}

void ostreamDemoCOUT(char string[], const int &N) {
    for (int i = 0; i < N; i++) cout << string[i];
    cout << endl;
}

void ostreamDemoPUT(char string[], const int &N) {
    for (int i = 0; i < N; i++) cout.put(string[i]);
    cout << endl;
}

void ostreamDemoWRITE(char string[], const int &N) {
    cout.write(string, N);
    cout << endl;
}

void ostreamDemoPRINTF(char string[], const int &N) {
    for (int i = 0; i < N; i++) printf("%c", string[i]);
    cout << endl;
    printf("%s", string);
    cout << endl;
}