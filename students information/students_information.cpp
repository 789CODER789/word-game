
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct Student{
    int id;
    string name;
    int age;
    string group;
};

vector<Student> students;

void load(){
    ifstream fayl("students.txt");
    if(!fayl){
        cout << "Fayl mavjud emas, yangi fayl yaratiladi.\n";
        ofstream yangiFayl("students.txt");
        yangiFayl.close();
        return;
    }
    Student student;
    while(fayl >> student.id){
        fayl.ignore();
        if(!getline(fayl, student.name) || !(fayl >> student.age) || !getline(fayl.ignore(), student.group)){
            cout << "Fayl formatida xatolik mavjud.\n";
            break;
        }
        students.push_back(student);
    }
    fayl.close();
    cout << "Ma'lumotlar muvafaqiyatli yuklandi.\n";
}

void stirage(){
    ofstream fayl("students.txt");
    for(const auto &student : students){
        fayl << student.id << '\n'
             << student.name << '\n'
             << student.age << '\n'
             << student.group << '\n';
    }
    fayl.close();
    cout << "Ma'lumotlar muvafaqiyatli saqlandi.\n";
}

int newID(){
    if(students.empty()){
        return 1;
    }
    return students.back().id + 1;
}

void addStudent(){
    Student yangi;
    yangi.id = newID();
    cout << "Avtomatik tayinlangan ID: " << yangi.id << '\n';
    cin.ignore();
    cout << "Talaba ismi: ";
    getline(cin, yangi.name);
    cout << "Talaba yoshi: ";
    cin >> yangi.age;
    cin.ignore();
    cout << "Guruhi: ";
    getline(cin, yangi.group);
    students.push_back(yangi);
    cout << "Talaba muvafaqiyatli qo'shildi!\n";
    stirage();
}

void korish(){
    if(students.empty()){
        cout << "Talabalar ro'yxati bo'sh.\n";
        return;
    }
    cout << "Talabalar ro'yxati:\n";
    for(const auto &student : students){
        cout << "--------------------------------\n";
        cout << "ID: " << student.id << '\n';
        cout << "Ism: " << student.name << '\n';
        cout << "Yosh: " << student.age << '\n';
        cout << "Guruh: " << student.group << '\n';
    }
    cout << "--------------------------------\n";
    cout << "Jami: " << students.size() << " talaba\n";
}

void searchStudent(){
    int id;
    cout << "Qidirilayotgan talaba ID sini kiriting: ";
    cin >> id;
    for(const auto &student : students){
        if(student.id == id){
            cout << "Natija: \n";
            cout << "--------------------------------\n";
            cout << "ID: " << student.id << '\n';
            cout << "Ism: " << student.name << '\n';
            cout << "Yosh: " << student.age << '\n';
            cout << "Guruh: " << student.group << '\n';
            return;
        }
    }
    cout << "Talaba topilmadi. Qayta urinib ko'ring.\n\n";
    cout << "--------------------------------\n";
}

void deleteStudent(){
    int id;
    cout << "O'chirilayotgan talaba ID sini kiriting: ";
    cin >> id;
    bool topildi = false;
    for (auto it = students.begin(); it != students.end(); ++it){
        if(it->id == id){
            students.erase(it);
            cout << "Talaba muvaffaqiyatli o'chirildi!\n";
            topildi = true;
            break;
        }
    }
    if(!topildi){
        cout << "Talaba topilmadi. Qayta urinib ko'ring.\n";
    }
    stirage();
}

int main(){
    load();
    int tanlov;
    while(tanlov != 5){
        cout << "========== Talabalarni boshqaruv tizimi ==========\n";
        cout << "1. Yangi talabani qo'shish\n2. Talabalar ro'yxatini ko'rish\n3. Talabani qidirish\n4. Talabani o'chirish\n5. Chiqish\n";
        cout << "Tanlovingizni kiriting: ";
        cin >> tanlov;

        switch (tanlov){
            case 1:
                addStudent();
                break;
            case 2:
                korish();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                cout << "Dasturdan chiqilmoqda...\n";
                return 0;
            default:
                cout << "Noto'g'ri tanlov kiritildi. Iltimos, qayta urinib ko'ring.\n"; 
                break;
        }
    }

    return 0;
}
