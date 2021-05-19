#include <iostream>
#include <fstream>
#include <cstdlib>
//js/ // j // p//on -- //
using namespace std;
class Bankomat{
public:
    int id;
    int pin;
    int kasa;
    int idq[6];
    int pinq[6];
    int kasaq[6];

    int nowypin[5];

    int wplata;
    int wyplata;

    int dt[10][10][10];

    Bankomat(){
        int idp;
        int pinp;
        int kasap;
        int i=0;
        fstream odczyt;
        odczyt.open("all.txt", ios::in);
        while(!odczyt.eof()){
                if(i==5) break;
            odczyt>>idp>>pinp>>kasap;
            idq[i]=idp;
            pinq[i]=pinp;
            kasaq[i]=kasap;
           // cout<<idp<<" "<<pinp<<" "<<kasap<<endl;
        i++;
        }
    }

    void getPin(){
        cout<<"**********************************************************"<<endl;
        cout<<"*****WITAMY W BANKOMACIE**********************************"<<endl;
        cout<<"**********************************************************"<<endl;
        cout<<"Zaloguj sie by moc wykonywac operacje na swoim koncie!"<<endl;
        cout<<"Podaj ID klienta: "<<endl;

        cin>>id;
        cout<<"**********************************************************"<<endl;
        cout<<"Podaj swoj PIN: "<<endl;
        cin>>pin;
        cout<<"**********************************************************"<<endl;
        check();
        upgrade();
    }


protected:
private:
    bool czypasuje = false;
    void check(){ //inaczej czy istnieje

            for(int i=0; i<5; i++){
                if((pin == pinq[i]) && (id == idq[i])){
                czypasuje = true;
                if(czypasuje == true){
                    cout<<"Twoje konto jest aktywne! - Pomyslnie zalogowano!"<<endl;
                }else{
                    cout<<"Nie ma takiego uzytkownika!"<<endl;
                }
                //cout<<"Pomyslnie zalogowano: "<<endl;
                cout<<"Twoje srodki na koncie to: "<<kasaq[i]<<endl;
                transaction(kasaq[i], i, pinq[i], idq[i]);
         }
        }
    }

    void transaction(int kwoat, int j, int nowypin, int usert){
         int wybor;
         do{
        cout<<"**********************************************************"<<endl;
        cout<<"Jaka operacje chcesz wykonac?"<<endl;
        cout<<"1. Wyplata srodkow"<<endl;
        cout<<"2. Wplata srodkow"<<endl;
        cout<<"3. Zmiana PINU"<<endl;
        cout<<"4. Przeprowadz transakcje"<<endl;
        cout<<"5. Wyjscie"<<endl;
        cout<<"**********************************************************"<<endl;
        cin>>wybor;
        switch(wybor){
        case 1:
           // for(int i=0; i<5; i++){
            cout<<"Ile srodkow chcesz wyplacic?"<<endl;
            cin>>wyplata;

            kwoat = kwoat-wyplata;
            cout<<"Pomyslnie wyplacono pieniadze!"<<endl;
            cout<<"**********************************************************"<<endl;
            cout<<"Twoj stan konta po wyplaceniu: "<<kwoat<<endl;
            kasaq[j] = kwoat;
            upgrade();
            break;
           // }
            break;
        case 2:
           // for(int i=0; i<5; i++){
            cout<<"Ile srodkow chcesz wplacic?"<<endl;
            cin>>wplata;
            kwoat = kwoat+wplata;
            cout<<"Pomyslnie wplacono pieniadze!"<<endl;
            cout<<"**********************************************************"<<endl;
            cout<<"Twoj stan konta po wplaceniu: "<<kwoat<<endl;
            kasaq[j] = kwoat;
              upgrade();
            break;
           // }
            break;
        case 3:
            // for(int i=0; i<5; i++){
                cout<<"Podaj swoj aktualny PIN:"<<endl;
                cin>>pin;
                if(pin == pinq[j]){
                cout<<"Podaj swoj nowy PIN:"<<endl;
                cin>>nowypin;
                pinq[j] = nowypin;
              upgrade();
              }
              else{
                cout<<"Blad"<<endl;
              }
            break;
           // }
            break;
        case 4:
          //  for(int i=0; i<5; i++){
            cout<<"Podaj ponownie swoj PIN"<<endl;
            cin>>pin;
            cout<<"**********************************************************"<<endl;
            if(pin == pinq[j]){
                int ilosc_transakcji;
                cout<<"Ile chcesz przeprowadzic transakcji?"<<endl;
                cin>>ilosc_transakcji;
                int kwoty;
                for(int i=1; i<=ilosc_transakcji; i++){
                    cout<<"Podaj kwote dla transakcji (np. zakup w sklepie)";
                    cin>>kwoty;
                    cout<<"**********************************************************"<<endl;
                    if(kwoty>kwoat){
                        kwoty = 0;
                    }
                    kwoat = kwoat - kwoty;
                    cout<<"**********************************************************"<<endl;
                    cout<<"Pomyslnie przeprowadzono transakcje"<<endl;
                    cout<<"Twoj stan konta po przeprowadzonych transakcjach: "<<kwoat<<endl;
                    cout<<"**********************************************************"<<endl;
                    kasaq[j] = kwoat;
                    upgrade();
                }
            }



            break;
           // }
            break;
        case 5:
            system("PAUSE");
            break;

        default:
            cout<<"Zly numer"<<endl;
        }
        }
        while(wybor != 5);
    }
 void upgrade(){
        fstream zapis;

        zapis.open("all.txt", ios::out);
        int id2, pin2, kasa2;
            for(int i=0; i<5; i++){
                    id2 = idq[i];
                    pin2 = pinq[i];
                    kasa2 = kasaq[i];
                zapis<<id2<<" "<<pin2<<" "<<kasa2<<endl;
            }
    }
/*void transakcja(){
int ilosc_transakcji;
int tablica[5];
int id_usera;
int kwoty;
cout<<"Podaj ponownie swoj PIN"<<endl;
cin>>pin;

cout<<"Podaj id uzytkownika do ktorego chcesz zrobic przelew: "<<endl;
cin>>id_usera;

cout<<"Ile chcesz przeprowadzic transakcji do powyzszego uzytkownika?"<<endl;
cin>>ilosc_transakcji;

for(int i=0; i<=ilosc_transakcji; i++){
    cout<<"Podaj kwote dla "<<i<<" transakcji:";
    cin>>kwoty;
    tablica[i] = kwoty;
}
cout<<"Pomyslnie wykonano"<<endl;
}*/
};
int main()
{
    Bankomat b1;
    b1.getPin();
    return 0;
}
