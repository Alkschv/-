#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
protected:
    string name;
    string surname;
    string patronymic;
public:
    Person(string name, string surname, string patronymic) : name(name), surname(surname), patronymic(patronymic) {}
    virtual void print() const {
        cout << "���: " << name << endl;
        cout << "�������: " << surname << endl;
        cout << "��������: " << patronymic << endl;
    }
};

class UniversityEmployee : public Person {
protected:
    string position;
    string faculty;
public:
    UniversityEmployee(string name, string surname, string patronymic, string position, string faculty) : Person(name, surname, patronymic), position(position), faculty(faculty) {}
    virtual void print() const override {
        Person::print();
        cout << "���������: " << position << endl;
        cout << "���������: " << faculty << endl;
    }
};

class Rector : public UniversityEmployee {
public:
    Rector(string name, string surname, string patronymic) : UniversityEmployee(name, surname, patronymic, "������", "") {}
    void print() const override {
        UniversityEmployee::print();
    }
};

class Dean : public UniversityEmployee {
public:
    Dean(string name, string surname, string patronymic, string faculty) : UniversityEmployee(name, surname, patronymic, "�����", faculty) {}
};

class HeadOfDepartment : public UniversityEmployee {
public:
    HeadOfDepartment(string name, string surname, string patronymic, string faculty, string department) : UniversityEmployee(name, surname, patronymic, "���������� ��������", faculty) {}
};

class Professor : public UniversityEmployee {
public:
    Professor(string name, string surname, string patronymic, string faculty) : UniversityEmployee(name, surname, patronymic, "���������", faculty) {}
};

class AssociateProfessor : public UniversityEmployee {
public:
    AssociateProfessor(string name, string surname, string patronymic, string faculty) : UniversityEmployee(name, surname, patronymic, "������", faculty) {}
};

class SeniorLecturer : public UniversityEmployee {
public:
    SeniorLecturer(string name, string surname, string patronymic, string faculty) : UniversityEmployee(name, surname, patronymic, "������� �������������", faculty) {}
};

class Lecturer : public UniversityEmployee {
public:
    Lecturer(string name, string surname, string patronymic, string faculty) : UniversityEmployee(name, surname, patronymic, "�������������", faculty) {}
};

class JuniorResearchFellow : public UniversityEmployee {
public:
    JuniorResearchFellow(string name, string surname, string patronymic, string faculty) : UniversityEmployee(name, surname, patronymic, "������� ������� ���������", faculty) {}
};

int main() {
    setlocale(LC_ALL, "Russian");

    Rector rector("����", "������", "��������"); // �������� ������ ������ Rector
    Dean dean1("����", "������", "��������", "��������� �������������� ����������");
    Dean dean2("�����", "��������", "���������", "��������� ������������ ����");
    HeadOfDepartment headOfDepartment1("�����", "�������", "���������", "��������� �������������� ����������", "������� �����������");
    HeadOfDepartment headOfDepartment2("�����", "�������", "��������", "��������� ������������ ����", "������� ��������");
    Professor professor1("�������", "��������", "����������", "��������� �������������� ����������");
    Professor professor2("���������", "�����������", "�������������", "��������� ������������ ����");
    AssociateProfessor associateProfessor1("�����", "��������", "���������", "��������� �������������� ����������");
    AssociateProfessor associateProfessor2("�������", "��������", "����������", "��������� ������������ ����");
    SeniorLecturer seniorLecturer1("�����", "�������", "��������", "��������� �������������� ����������");
    SeniorLecturer seniorLecturer2("����", "������", "��������", "��������� ������������ ����");
    Lecturer lecturer1("���������", "�����������", "�������������", "��������� �������������� ����������");
    Lecturer lecturer2("�����", "�������", "���������", "��������� ������������ ����");
    JuniorResearchFellow juniorResearchFellow1("�������", "��������", "����������", "��������� �������������� ����������");
    JuniorResearchFellow juniorResearchFellow2("�����", "��������", "���������", "��������� ������������ ����");

    vector<UniversityEmployee*> employees = { &rector, &dean1, &dean2, &headOfDepartment1, &headOfDepartment2, &professor1, &professor2, &associateProfessor1, &associateProfessor2, &seniorLecturer1, &seniorLecturer2, &lecturer1, &lecturer2, &juniorResearchFellow1, &juniorResearchFellow2 }; // �������� ������ ������ Rector � ������

    for (UniversityEmployee* employee : employees) {
        employee->print();
        cout << endl;
    }

    return 0;
}