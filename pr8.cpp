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
        cout << "Имя: " << name << endl;
        cout << "Фамилия: " << surname << endl;
        cout << "Отчество: " << patronymic << endl;
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
        cout << "Должность: " << position << endl;
        cout << "Факультет: " << faculty << endl;
    }
};

class Rector : public UniversityEmployee {
public:
    Rector(string name, string surname, string patronymic) : UniversityEmployee(name, surname, patronymic, "Ректор", "") {}
    void print() const override {
        UniversityEmployee::print();
    }
};

class Dean : public UniversityEmployee {
public:
    Dean(string name, string surname, string patronymic, string faculty) : UniversityEmployee(name, surname, patronymic, "Декан", faculty) {}
};

class HeadOfDepartment : public UniversityEmployee {
public:
    HeadOfDepartment(string name, string surname, string patronymic, string faculty, string department) : UniversityEmployee(name, surname, patronymic, "Заведующий кафедрой", faculty) {}
};

class Professor : public UniversityEmployee {
public:
    Professor(string name, string surname, string patronymic, string faculty) : UniversityEmployee(name, surname, patronymic, "Профессор", faculty) {}
};

class AssociateProfessor : public UniversityEmployee {
public:
    AssociateProfessor(string name, string surname, string patronymic, string faculty) : UniversityEmployee(name, surname, patronymic, "Доцент", faculty) {}
};

class SeniorLecturer : public UniversityEmployee {
public:
    SeniorLecturer(string name, string surname, string patronymic, string faculty) : UniversityEmployee(name, surname, patronymic, "Старший преподаватель", faculty) {}
};

class Lecturer : public UniversityEmployee {
public:
    Lecturer(string name, string surname, string patronymic, string faculty) : UniversityEmployee(name, surname, patronymic, "Преподаватель", faculty) {}
};

class JuniorResearchFellow : public UniversityEmployee {
public:
    JuniorResearchFellow(string name, string surname, string patronymic, string faculty) : UniversityEmployee(name, surname, patronymic, "Младший научный сотрудник", faculty) {}
};

int main() {
    setlocale(LC_ALL, "Russian");

    Rector rector("Иван", "Иванов", "Иванович"); // Добавили объект класса Rector
    Dean dean1("Петр", "Петров", "Петрович", "Факультет информационных технологий");
    Dean dean2("Мария", "Маринина", "Мариновна", "Факультет естественных наук");
    HeadOfDepartment headOfDepartment1("Сидор", "Сидоров", "Сидорович", "Факультет информационных технологий", "Кафедра информатики");
    HeadOfDepartment headOfDepartment2("Елена", "Еленина", "Еленовна", "Факультет естественных наук", "Кафедра биологии");
    Professor professor1("Николай", "Николаев", "Николаевич", "Факультет информационных технологий");
    Professor professor2("Александр", "Александров", "Александрович", "Факультет естественных наук");
    AssociateProfessor associateProfessor1("Мария", "Маринина", "Мариновна", "Факультет информационных технологий");
    AssociateProfessor associateProfessor2("Василий", "Васильев", "Васильевич", "Факультет естественных наук");
    SeniorLecturer seniorLecturer1("Елена", "Еленина", "Еленовна", "Факультет информационных технологий");
    SeniorLecturer seniorLecturer2("Петр", "Петров", "Петрович", "Факультет естественных наук");
    Lecturer lecturer1("Александр", "Александров", "Александрович", "Факультет информационных технологий");
    Lecturer lecturer2("Сидор", "Сидоров", "Сидорович", "Факультет естественных наук");
    JuniorResearchFellow juniorResearchFellow1("Василий", "Васильев", "Васильевич", "Факультет информационных технологий");
    JuniorResearchFellow juniorResearchFellow2("Мария", "Маринина", "Мариновна", "Факультет естественных наук");

    vector<UniversityEmployee*> employees = { &rector, &dean1, &dean2, &headOfDepartment1, &headOfDepartment2, &professor1, &professor2, &associateProfessor1, &associateProfessor2, &seniorLecturer1, &seniorLecturer2, &lecturer1, &lecturer2, &juniorResearchFellow1, &juniorResearchFellow2 }; // Добавили объект класса Rector в вектор

    for (UniversityEmployee* employee : employees) {
        employee->print();
        cout << endl;
    }

    return 0;
}