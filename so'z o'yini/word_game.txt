#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

string words[] = {"xodim", "xayol", "xat", "xarajat", "xizmat", "xohish", "xulosa", "xarid", "xabar"};

string toLowerCase(string str){
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main(){
    srand(time(0));
    char yanaOynaysizmi;
    
    do{
        string word = words[rand() % 9];
        string guess;
        int lives = 3;

        cout << "SO'Z O'YINI\n";
        cout << "SHARTLAR: Men taxmin qilgan so'zni topishga harakat qiling!\n";
        cout << "YORDAM: Bu so'z x harifidan boshlanadi.\n";
        cout << "Sizni 3ta urunishingiz bor. Omad!\n";

        while (lives > 0){
            cout << "So'z kiriting: ";
            cin >> guess;
            guess = toLowerCase(guess);
            cout << '\n';

            if(guess == word){
                cout << "Qoyil, Bu to'g'ri so'z! Toptingiz!\n";
                break;
            }
            else{
                lives--;
                cout << "Yo'q! Sizning urinishlaringiz " << lives << "ta qolgan\n";
            }
        }

        if(lives <= 0){
            cout << "Siz yutqazdingiz.To'g'ri so'z: " << word << '\n';
        }

        cout << "Yana o'ynaysizmi? (h/y)\n";
        cin>> yanaOynaysizmi;

    } while (yanaOynaysizmi == 'H' || yanaOynaysizmi == 'h');

    cout << "O'yin tugadi. Raxmat!";
    
    return 0;
}
