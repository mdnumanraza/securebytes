#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string getFormattedName(const string& filename, char ch) {
    int i = 0, n = filename.size();
    string temp = "";
    while (i < n && filename[i] != ch) {
        temp.push_back(filename[i]);
        ++i;
    }
    if (ch == '.') {
        return temp + "-encrypt";
    } else {
        return temp + "-decrypt";
    }
}

void encryptFile(const string& filename, int key) {
    ifstream fin(filename, ios::binary);
    if (!fin) {
        cerr << "Error: Unable to open input file: " << filename << endl;
        return;
    }

    ofstream fout(getFormattedName(filename, '.') + ".enc", ios::binary);
    if (!fout) {
        cerr << "Error: Unable to create output file." << endl;
        fin.close();
        return;
    }

    char c;
    while (fin.get(c)) {
        c = c + key;
        fout.put(c);
    }

    fin.close();
    fout.close();

    cout << "Encrypted file name: " << getFormattedName(filename, '.') + ".enc" << endl;
    cout << "File encrypted successfully." << endl;
}

void decryptFile(const string& filename, int key, const string& filetype) {
    ifstream fin(filename, ios::binary);
    if (!fin) {
        cerr << "Error: Unable to open input file: " << filename << endl;
        return;
    }

    ofstream fout(getFormattedName(filename, '-') + filetype, ios::binary);
    if (!fout) {
        cerr << "Error: Unable to create output file." << endl;
        fin.close();
        return;
    }

    char c;
    while (fin.get(c)) {
        c = c - key;
        fout.put(c);
    }

    fin.close();
    fout.close();

    cout << "\nDecrypted file name: " << getFormattedName(filename, '-') + filetype << endl;
    cout << "File decrypted successfully.\n" << endl;
}

int main() {
    int choice, key;
    string filename, filetype;

    cout << "\n\t----------------  SecureBytes  ----------------\n\n";
    cout << "-----------  Encrypt and decrypt a file with a password -----------\n";

    while (true) {
        cout << "\nPress 1 to Encrypt file.\nPress 2 to Decrypt file.\nPress 3 to Exit." << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter File Name (with extension, e.g., .png, .pdf): ";
                cin >> filename;
                cout << "Enter Password (numeric key): ";
                cin >> key;
                encryptFile(filename, key);
                break;
            case 2:
                cout << "Enter name of encrypted file (.enc included): ";
                cin >> filename;
                cout << "Enter Password (numeric key) to decrypt: ";
                cin >> key;
                cout << "Enter original file type (example .png, .jpeg, .pdf): ";
                cin >> filetype;
                decryptFile(filename, key, filetype);
                break;
            case 3:
                cout << "\nThank you for Encrypting and Decrypting.\n";
                return 0;
            default:
                cerr << "Invalid choice. Please enter 1, 2, or 3." << endl;
                break;
        }
    }

    return 0;
}
