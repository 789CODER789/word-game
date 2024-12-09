#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

string words[] = {"xodim", "xayol", "xat", "xarajat", "xizmat", "xohish", "xulosa", "xarid", "xabar", "ahamiyat", "ahli", "ayol", "aholi", "alhamdulilloh", "alohidalik", "hol", "bahamjihat", "behafsala", "ehson", "ehtiros", "ehtiyot", "hadeb", "hadis", "hajviya"};

string toLowerCase(string str){
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main(){
    srand(time(0));
    char yanaOynaysizmi;
    
    do{
        int wordCount = sizeof(words) / sizeof(words[0]);
        string word = words[rand() % wordCount];
        string guess;
        int lives = 3;

        string text = word;
        int textLength = text.length();

        cout << "SO'Z O'YINI\n";
        cout << "SHARTLAR: Men taxmin qilgan so'zni topishga harakat qiling!\n";
        cout << "YORDAM: Bu so'z "<< word[0] <<" harifidan boshlanadi va so'z "<< textLength << " ta harifdan iborat.\n";
        cout << "Sizni 3ta urunishingiz bor. Omad!\n";
        bool gameOver = false;

        while (lives > 0 && !gameOver){
            cout << "So'z kiriting: ";
            cin >> guess;
            guess = toLowerCase(guess);
            cout << '\n';

            if(guess == word){
                cout << "Qoyil, Bu to'g'ri so'z! Toptingiz!\n";
                gameOver = true;
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
        yanaOynaysizmi = toLowerCase(string(1, yanaOynaysizmi))[0];

    } while (yanaOynaysizmi == 'H' || yanaOynaysizmi == 'h');

    cout << "O'yin tugadi. Raxmat!";
    
    return 0;
}
