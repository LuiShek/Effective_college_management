#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Student Class Definition
class Student {
public:
    string name;
    int roll;
    //string subject;
    string email;
    string phone;
    string address;
    string department;

    Student() {}
    Student(string n, int i, string e, string p, string a, string d)
        : name(n), roll(i), email(e), phone(p), address(a), department(d) {}

    void display() const {
        cout << "Roll-Number: " << roll << "\nName: " << name << "\nEmail: " << email << "\nPhone: " << phone << "\nAddress: " << address
             << "\nDepartment: " << department << endl;
    }

    friend ofstream& operator<<(ofstream& ofs, const Student& s);
    friend ifstream& operator>>(ifstream& ifs, Student& s);
};

ofstream& operator<<(ofstream& ofs, const Student& s) {
    ofs << s.roll << "\n" << s.name << "\n" << s.email << "\n"
        << s.phone << "\n" << s.address << "\n" << s.department << "\n";
    return ofs;
}

ifstream& operator>>(ifstream& ifs, Student& s) {
    ifs >> s.roll;
    ifs.ignore();
    getline(ifs, s.name);
    getline(ifs, s.email);
    getline(ifs, s.phone);
    getline(ifs, s.address);
    getline(ifs, s.department);
    return ifs;
}

// Student Management Class Definition
class StudentManagement {
private:
    vector<Student> students;
    const string filename = "students.txt";

public:
    StudentManagement() {
        loadFromFile();
    }

    ~StudentManagement() {
        saveToFile();
    }

    void addStudent() {
        string name, email, phone, address, department;
        int roll;
        cout << "Enter Roll-Number: ";
        cin >> roll;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Email: ";
        getline(cin, email);
        cout << "Enter Phone: ";
        getline(cin, phone);
        cout << "Enter Address: ";
        getline(cin, address);
        cout << "Enter Department: ";
        getline(cin, department);
        students.push_back(Student(name, roll, email, phone, address, department));
        cout << "Student added successfully!\n";
    }

    void displayAllStudents() const {
        for (const auto& student : students) {
            student.display();
            cout << "-----------------------\n";
        }
    }

    void searchStudent(int roll) const {
        for (const auto& student : students) {
            if (student.roll == roll) {
                student.display();
                return;
            }
        }
        cout << "Student not found!\n";
    }

    void updateStudent(int roll) {
        for (auto& student : students) {
            if (student.roll == roll) {
                cout << "Enter new details for student with Roll-Number " << roll << ":\n";
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, student.name);
                cout << "Enter Email: ";
                getline(cin, student.email);
                cout << "Enter Phone: ";
                getline(cin, student.phone);
                cout << "Enter Address: ";
                getline(cin, student.address);
                cout << "Enter Department: ";
                getline(cin, student.department);
                cout << "Student updated successfully!\n";
                return;
            }
        }
        cout << "Student not found!\n";
    }

    void deleteStudent(int roll) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->roll == roll) {
                students.erase(it);
                cout << "Student deleted successfully!\n";
                return;
            }
        }
        cout << "Student not found!\n";
    }

    void saveToFile() {
        ofstream ofs(filename);
        for (const auto& student : students) {
            ofs << student;
        }
    }

    void loadFromFile() {
        ifstream ifs(filename);
        Student student;
        while (ifs >> student) {
            students.push_back(student);
        }
    }
};

// Teacher Management Class
class Teacher {
public:
    string name;
    int id;
    string subject;
    string email;
    string phone;
    string address;
    double salary;
    string department;

    Teacher() {}
    Teacher(string n, int i, string s, string e, string p, string a, double sal, string d)
        : name(n), id(i), subject(s), email(e), phone(p), address(a), salary(sal), department(d) {}

    void display() const {
        cout << "ID: " << id << "\nName: " << name << "\nSubject: " << subject
             << "\nEmail: " << email << "\nPhone: " << phone << "\nAddress: " << address
             << "\nSalary: " << salary << "\nDepartment: " << department << endl;
    }

    friend ofstream& operator<<(ofstream& ofs, const Teacher& t);
    friend ifstream& operator>>(ifstream& ifs, Teacher& t);
};

ofstream& operator<<(ofstream& ofs, const Teacher& t) {
    ofs << t.id << "\n" << t.name << "\n" << t.subject << "\n" << t.email << "\n"
        << t.phone << "\n" << t.address << "\n" << t.salary << "\n" << t.department << "\n";
    return ofs;
}

ifstream& operator>>(ifstream& ifs, Teacher& t) {
    ifs >> t.id;
    ifs.ignore();
    getline(ifs, t.name);
    getline(ifs, t.subject);
    getline(ifs, t.email);
    getline(ifs, t.phone);
    getline(ifs, t.address);
    ifs >> t.salary;
    ifs.ignore();
    getline(ifs, t.department);
    return ifs;
}

// Teacher Management Class Definition
class TeacherManagement {
private:
    vector<Teacher> teachers;
    const string filename = "teachers.txt";

public:
    TeacherManagement() {
        loadFromFile();
    }

    ~TeacherManagement() {
        saveToFile();
    }

    void addTeacher() {
        string name, subject, email, phone, address, department;
        int id;
        double salary;
        cout << "Enter ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Subject: ";
        getline(cin, subject);
        cout << "Enter Email: ";
        getline(cin, email);
        cout << "Enter Phone: ";
        getline(cin, phone);
        cout << "Enter Address: ";
        getline(cin, address);
        cout << "Enter Salary: ";
        cin >> salary;
        cin.ignore();
        cout << "Enter Department: ";
        getline(cin, department);
        teachers.push_back(Teacher(name, id, subject, email, phone, address, salary, department));
        cout << "Teacher added successfully!\n";
    }

    void displayAllTeachers() const {
        for (const auto& teacher : teachers) {
            teacher.display();
            cout << "-----------------------\n";
        }
    }

    void searchTeacher(int id) const {
        for (const auto& teacher : teachers) {
            if (teacher.id == id) {
                teacher.display();
                return;
            }
        }
        cout << "Teacher not found!\n";
    }

    void updateTeacher(int id) {
        for (auto& teacher : teachers) {
            if (teacher.id == id) {
                cout << "Enter new details for teacher with ID " << id << ":\n";
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, teacher.name);
                cout << "Enter Subject: ";
                getline(cin, teacher.subject);
                cout << "Enter Email: ";
                getline(cin, teacher.email);
                cout << "Enter Phone: ";
                getline(cin, teacher.phone);
                cout << "Enter Address: ";
                getline(cin, teacher.address);
                cout << "Enter Salary: ";
                cin >> teacher.salary;
                cin.ignore();
                cout << "Enter Department: ";
                getline(cin, teacher.department);
                cout << "Teacher updated successfully!\n";
                return;
            }
        }
        cout << "Teacher not found!\n";
    }

    void deleteTeacher(int id) {
        for (auto it = teachers.begin(); it != teachers.end(); ++it) {
            if (it->id == id) {
                teachers.erase(it);
                cout << "Teacher deleted successfully!\n";
                return;
            }
        }
        cout << "Teacher not found!\n";
    }

    void saveToFile() {
        ofstream ofs(filename);
        for (const auto& teacher : teachers) {
            ofs << teacher;
        }
    }

    void loadFromFile() {
        ifstream ifs(filename);
        Teacher teacher;
        while (ifs >> teacher) {
            teachers.push_back(teacher);
        }
    }
};

// Library Management Class
class Book {
public:
    string title;
    int id;
    string author;
    int year;

    Book() {}
    Book(string t, int i, string a, int y)
        : title(t), id(i), author(a), year(y) {}

    void display() const {
        cout << "ID: " << id << "\nTitle: " << title << "\nAuthor: " << author
             << "\nYear: " << year << endl;
    }

    friend ofstream& operator<<(ofstream& ofs, const Book& b);
    friend ifstream& operator>>(ifstream& ifs, Book& b);
};

ofstream& operator<<(ofstream& ofs, const Book& b) {
    ofs << b.id << "\n" << b.title << "\n" << b.author << "\n" << b.year << "\n";
    return ofs;
}

ifstream& operator>>(ifstream& ifs, Book& b) {
    ifs >> b.id;
    ifs.ignore();
    getline(ifs, b.title);
    getline(ifs, b.author);
    ifs >> b.year;
    return ifs;
}

// Library Management Class Definition
class LibraryManagement {
private:
    vector<Book> books;
    const string filename = "books.txt";

public:
    LibraryManagement() {
        loadFromFile();
    }

    ~LibraryManagement() {
        saveToFile();
    }

    void addBook() {
        string title, author;
        int id, year;
        cout << "Enter ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Title: ";
        getline(cin, title);
        cout << "Enter Author: ";
        getline(cin, author);
        cout << "Enter Year: ";
        cin >> year;
        books.push_back(Book(title, id, author, year));
        cout << "Book added successfully!\n";
    }

    void displayAllBooks() const {
        for (const auto& book : books) {
            book.display();
            cout << "-----------------------\n";
        }
    }

    void searchBook(int id) const {
        for (const auto& book : books) {
            if (book.id == id) {
                book.display();
                return;
            }
        }
        cout << "Book not found!\n";
    }

    void updateBook(int id) {
        for (auto& book : books) {
            if (book.id == id) {
                cout << "Enter new details for book with ID " << id << ":\n";
                cout << "Enter Title: ";
                cin.ignore();
                getline(cin, book.title);
                cout << "Enter Author: ";
                getline(cin, book.author);
                cout << "Enter Year: ";
                cin >> book.year;
                cout << "Book updated successfully!\n";
                return;
            }
        }
        cout << "Book not found!\n";
    }

    void deleteBook(int id) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->id == id) {
                books.erase(it);
                cout << "Book deleted successfully!\n";
                return;
            }
        }
        cout << "Book not found!\n";
    }

    void saveToFile() {
        ofstream ofs(filename);
        for (const auto& book : books) {
            ofs << book;
        }
    }

    void loadFromFile() {
        ifstream ifs(filename);
        Book book;
        while (ifs >> book) {
            books.push_back(book);
        }
    }
};

// Fee Management Class
class Fee {
public:
    int rollNo;
    double amount;

    Fee() {}
    Fee(int r, double a) : rollNo(r), amount(a) {}

    void display() const {
        cout << "Roll No: " << rollNo << "\nAmount: " << amount << endl;
    }

    friend ofstream& operator<<(ofstream& ofs, const Fee& f);
    friend ifstream& operator>>(ifstream& ifs, Fee& f);
};

ofstream& operator<<(ofstream& ofs, const Fee& f) {
    ofs << f.rollNo << "\n" << f.amount << "\n";
    return ofs;
}

ifstream& operator>>(ifstream& ifs, Fee& f) {
    ifs >> f.rollNo >> f.amount;
    return ifs;
}

// Fee Management Class Definition
class FeeManagement {
private:
    vector<Fee> fees;
    const string filename = "fees.txt";

public:
    FeeManagement() {
        loadFromFile();
    }

    ~FeeManagement() {
        saveToFile();
    }

    void addFee() {
        int rollNo;
        double amount;
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cout << "Enter Amount: ";
        cin >> amount;
        fees.push_back(Fee(rollNo, amount));
        cout << "Fee added successfully!\n";
    }

    void displayFee(int rollNo) const {
        for (const auto& fee : fees) {
            if (fee.rollNo == rollNo) {
                fee.display();
                return;
            }
        }
        cout << "Fee record not found!\n";
    }

    void updateFee(int rollNo) {
        for (auto& fee : fees) {
            if (fee.rollNo == rollNo) {
                cout << "Enter new amount for Roll No " << rollNo << ": ";
                cin >> fee.amount;
                cout << "Fee updated successfully!\n";
                return;
            }
        }
        cout << "Fee record not found!\n";
    }

    void saveToFile() {
        ofstream ofs(filename);
        for (const auto& fee : fees) {
            ofs << fee;
        }
    }

    void loadFromFile() {
        ifstream ifs(filename);
        Fee fee;
        while (ifs >> fee) {
            fees.push_back(fee);
        }
    }
};

// Result Management Class
class Result {
public:
    int rollNo;
    double percentage;

    Result() {}
    Result(int r, double p) : rollNo(r), percentage(p) {}

    void display() const {
        cout << "Roll No: " << rollNo << "\nPercentage: " << percentage << "%" << endl;
    }

    friend ofstream& operator<<(ofstream& ofs, const Result& r);
    friend ifstream& operator>>(ifstream& ifs, Result& r);
};

ofstream& operator<<(ofstream& ofs, const Result& r) {
    ofs << r.rollNo << "\n" << r.percentage << "\n";
    return ofs;
}

ifstream& operator>>(ifstream& ifs, Result& r) {
    ifs >> r.rollNo >> r.percentage;
    return ifs;
}

// Result Management Class Definition
class ResultManagement {
private:
    vector<Result> results;
    const string filename = "results.txt";

public:
    ResultManagement() {
        loadFromFile();
    }

    ~ResultManagement() {
        saveToFile();
    }

    void addResult() {
        int rollNo;
        double percentage;
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cout << "Enter Percentage: ";
        cin >> percentage;
        results.push_back(Result(rollNo, percentage));
        cout << "Result added successfully!\n";
    }

    void displayResult(int rollNo) const {
        for (const auto& result : results) {
            if (result.rollNo == rollNo) {
                result.display();
                return;
            }
        }
        cout << "Result not found!\n";
    }

    void updateResult(int rollNo) {
        for (auto& result : results) {
            if (result.rollNo == rollNo) {
                cout << "Enter new percentage for Roll No " << rollNo << ": ";
                cin >> result.percentage;
                cout << "Result updated successfully!\n";
                return;
            }
        }
        cout << "Result not found!\n";
    }

    void saveToFile() {
        ofstream ofs(filename);
        for (const auto& result : results) {
            ofs << result;
        }
    }

    void loadFromFile() {
        ifstream ifs(filename);
        Result result;
        while (ifs >> result) {
            results.push_back(result);
        }
    }
};

// Main Menu Function
void displayMenu() {
    cout << "1. Student Management\n";
    cout << "2. Teacher Management\n";
    cout << "3. Library Management\n";
    cout << "4. Fee Management\n";
    cout << "5. Result System\n";
    cout << "6. Exit\n";
}

int main() {
    cout<<endl;
    cout<<"----------------------"<<endl;
    cout<<"*WELCOME TO KEC*"<<endl;
    cout<<"----------------------"<<endl;
    cout<<endl;
    StudentManagement sm;
    TeacherManagement tm;
    LibraryManagement lm;
    FeeManagement fm;
    ResultManagement rm;
    int choice;
    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            char sc;
            while (true) {
                cout << "\na. Add New Student\n";
                cout << "b. Display All Students\n";
                cout << "c. Search Student\n";
                cout << "d. Update Student\n";
                cout << "e. Delete Student\n";
                cout << "f. Back to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> sc;
                switch (sc) {
                case 'a':
                    sm.addStudent();
                    break;
                case 'b':
                    sm.displayAllStudents();
                    break;
                case 'c': {
                    int id;
                    cout << "Enter student ID to search: ";
                    cin >> id;
                    sm.searchStudent(id);
                    break;
                }
                case 'd': {
                    int id;
                    cout << "Enter student ID to update: ";
                    cin >> id;
                    sm.updateStudent(id);
                    break;
                }
                case 'e': {
                    int id;
                    cout << "Enter student ID to delete: ";
                    cin >> id;
                    sm.deleteStudent(id);
                    break;
                }
                case 'f':
                    goto mainMenu;
                default:
                    cout << "Invalid choice!\n";
                }
            }
        }
        case 2: {
            char tc;
            while (true) {
                cout << "\na. Add New Teacher\n";
                cout << "b. Display All Teachers\n";
                cout << "c. Search Teacher\n";
                cout << "d. Update Teacher\n";
                cout << "e. Delete Teacher\n";
                cout << "f. Back to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> tc;
                switch (tc) {
                case 'a':
                    tm.addTeacher();
                    break;
                case 'b':
                    tm.displayAllTeachers();
                    break;
                case 'c': {
                    int id;
                    cout << "Enter teacher ID to search: ";
                    cin >> id;
                    tm.searchTeacher(id);
                    break;
                }
                case 'd': {
                    int id;
                    cout << "Enter teacher ID to update: ";
                    cin >> id;
                    tm.updateTeacher(id);
                    break;
                }
                case 'e': {
                    int id;
                    cout << "Enter teacher ID to delete: ";
                    cin >> id;
                    tm.deleteTeacher(id);
                    break;
                }
                case 'f':
                    goto mainMenu;
                default:
                    cout << "Invalid choice!\n";
                }
            }
        }
        case 3: {
            char lc;
            while (true) {
                cout << "\na. Add New Book\n";
                cout << "b. Display All Books\n";
                cout << "c. Search Book\n";
                cout << "d. Update Book\n";
                cout << "e. Delete Book\n";
                cout << "f. Back to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> lc;
                switch (lc) {
                case 'a':
                    lm.addBook();
                    break;
                case 'b':
                    lm.displayAllBooks();
                    break;
                case 'c': {
                    int id;
                    cout << "Enter book ID to search: ";
                    cin >> id;
                    lm.searchBook(id);
                    break;
                }
                case 'd': {
                    int id;
                    cout << "Enter book ID to update: ";
                    cin >> id;
                    lm.updateBook(id);
                    break;
                }
                case 'e': {
                    int id;
                    cout << "Enter book ID to delete: ";
                    cin >> id;
                    lm.deleteBook(id);
                    break;
                }
                case 'f':
                    goto mainMenu;
                default:
                    cout << "Invalid choice!\n";
                }
            }
        }
        case 4: {
            char fc;
            while (true) {
                cout << "\na. Add Fee\n";
                cout << "b. Display Fee\n";
                cout << "c. Update Fee\n";
                cout << "d. Back to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> fc;
                switch (fc) {
                case 'a':
                    fm.addFee();
                    break;
                case 'b': {
                    int rollNo;
                    cout << "Enter roll no to display fee: ";
                    cin >> rollNo;
                    fm.displayFee(rollNo);
                    break;
                }
                case 'c': {
                    int rollNo;
                    cout << "Enter roll no to update fee: ";
                    cin >> rollNo;
                    fm.updateFee(rollNo);
                    break;
                }
                case 'd':
                    goto mainMenu;
                default:
                    cout << "Invalid choice!\n";
                }
            }
        }
        case 5: {
            char rc;
            while (true) {
                cout << "\na. Add Result\n";
                cout << "b. Display Result\n";
                cout << "c. Update Result\n";
                cout << "d. Back to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> rc;
                switch (rc) {
                case 'a':
                    rm.addResult();
                    break;
                case 'b': {
                    int rollNo;
                    cout << "Enter roll no to display result: ";
                    cin >> rollNo;
                    rm.displayResult(rollNo);
                    break;
                }
                case 'c': {
                    int rollNo;
                    cout << "Enter roll no to update result: ";
                    cin >> rollNo;
                    rm.updateResult(rollNo);
                    break;
                }
                case 'd':
                    goto mainMenu;
                default:
                    cout << "Invalid choice!\n";
                }
            }
        }
        case 6:
            cout<<"Thank you!!!"<<endl;
            return 0;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    mainMenu:
        continue;
    }
    return 0;
}