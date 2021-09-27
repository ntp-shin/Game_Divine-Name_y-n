#include "Header.h"

void SaveGame(Node* root, ofstream &out) {
    if (root != NULL) {
        out << root->data << endl;
        SaveGame(root->left, out);
        SaveGame(root->right, out);
    }
}

void Nothing() {
    return;
}
Node* Play(Node* root, string& s) {
    system("CLS");
    Node* temp = root;
    Node* pre = temp;
    while (temp != NULL) {
        cout << temp->data << endl;
        cout << "Yes or No (y/n): ";
        cin >> s;
        cout << endl;
        if (s == "y") {
            pre = temp;
            temp = temp->left;
        }
        else if (s == "n") {
            pre = temp;
            temp = temp->right;
        }
    }
    if (s == "y")
        cout << "---------> Yes, I'm right !!!!!!!" << endl;
    else if (s == "n")
        cout << "---------> No, I'm wrong !!!!!!!!" << endl;
    return pre;
}

void Expand(Node*& t) {
    cout << "Ban co muon cai thien tro choi hay khong? (y/n): ";
    string a, q, temp;
    cin >> a;
    cin.ignore();
    if (a == "n")
        return;
    cout << "Con vat ban chon la gi: ";
    getline(cin, a);
    cout << t->data << " && " << a << " --- Chung co diem gi khac nhau? ";
    getline(cin, q);
    cout << q << " ??? " << a << " ---> Yes or No (y/n): ";
    getline(cin, temp);

    a = "#A - " + a + " ? ";
    q = "#Q - " + q + " ? ";
    if (temp == "y") {
        temp = t->data;
        t->data = q;
        t->left = new Node{ a, true, NULL, NULL };
        t->right = new Node{ temp, true, NULL, NULL };
    }
    else if (temp == "n") {
        temp = t->data;
        t->data = q;
        t->right = new Node{ a, true, NULL, NULL };
        t->left = new Node{ temp, true, NULL, NULL };
    }
    return;
}

int Menu() {
    system("CLS");
    ifstream in;
    in.open("Menu.txt");
        string s;
        while (!in.eof()) {
            getline(in, s);
            cout << s << endl;
        }
    in.close();
    cout << "\t\t\t\t\t-------------> Su lua chon cua ban la: ";
    int num;
    cin >> num;
    return num;        
}

void Start(Node* &root, string &s) {
    bool Check = true;
    int num;
    Node* temp = root;
    while (Check) {
        num = Menu();
        system("pause");
        if (num == 1) {
            temp = Play(root, s);
            if (s == "n") 
                Expand(temp);
                system("pause");
//            #Start(root, s);
        }
        if (num == 2) {
            ofstream out;
            out.open("input.txt");
                SaveGame(root, out);
            out.close();
            system("pause");
        }
        if (num == 3) {
            Check = false;
        }
    }
}
int main() {
    ifstream f("input.txt");
    Node* root = NULL;
    string s;
    while (!f.eof()) {
        getline(f, s);
        bool isAdded = false;
        root = add(root, s, isAdded);
    }
    Start(root, s);
    return 0;
}