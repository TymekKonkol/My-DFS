#include <iostream>
 
using namespace std;
 
 
class Wierzcholek
{
        int ile_kwiatkow;
        int do_ktorej;
        int od_ktorej;
        
        bool czy_sprawdzono_lewe;
        bool czy_sprawdzono_prawe;
 
        bool czy_dodano;
        bool czy_jest_tabL;
        bool czy_jest_tabP;
 
public:
        Wierzcholek *nastepnyL;
        Wierzcholek *nastepnyR;
        Wierzcholek *poprzedni;
 
        int dlugosc_tabL;
        int dlugosc_tabP;
 
        int *tabL;
        int *tabP;
 
        Wierzcholek(int ile_kwiatow, int gdzie, int skad, Wierzcholek *ojciec);
 
        ~Wierzcholek()
        {
                delete(nastepnyL);
                delete(nastepnyR);
                delete(poprzedni);
                delete(tabL);
                delete(tabP);
        }
 
        bool zwroc_czy_dodano()
        {
                return this->czy_dodano;
        }
 
        void zmien_czy_dodano(bool na_co)
        {
                this->czy_dodano = na_co;
        }
 
        bool zwroc_czy_jest_tabL()
        {
                return this->czy_jest_tabL;
        }
        bool zwroc_czy_jest_tabP()
        {
                return this->czy_jest_tabP;
        }
        void zmien_czy_jest_tabL(bool na_co)
        {
                this->czy_jest_tabL = na_co;
        }
        void zmien_czy_jest_tabP(bool na_co)
        {
                this->czy_jest_tabP = na_co;
        }
 
 
        int zwroc_ilosc_kwiatkow()
        {
                return this->ile_kwiatkow;
        }
        void zmien_ilosc_kwiatkow(int na_ile)
        {
                this->ile_kwiatkow = na_ile;
        }
 
 
        int zwroc_do_ktorej()
        {
                return this->do_ktorej;
        }
        int zwroc_od_ktorej()
        {
                return this->od_ktorej;
        }
        void zmien_od_ktorej(int na_co)
        {
                this->od_ktorej = na_co;
        }
        void zmien_do_ktorej(int na_co)
        {
                this->do_ktorej = na_co;
        }
 
 
        void zmien_sprawdzenie_lewe(bool na_co)
        {
                this->czy_sprawdzono_lewe = na_co;
        }
        void zmien_sprawdzenie_prawe(bool na_co)
        {
                this->czy_sprawdzono_prawe = na_co;
        }
        bool zwroc_sprawdzenie_lewe()
        {
                return this->czy_sprawdzono_lewe;
        }
        bool zwroc_sprawdzenie_prawe()
        {
                return this->czy_sprawdzono_prawe;
        }
};
 
Wierzcholek::Wierzcholek( int ile_kwiatow, int gdzie, int skad, Wierzcholek *ojciec)
{
        this->ile_kwiatkow = ile_kwiatow;
        this->do_ktorej = gdzie;
        this->od_ktorej = skad;
        this->czy_sprawdzono_lewe = false;
        this->czy_sprawdzono_prawe = false;
        this->poprzedni = ojciec;
        this->nastepnyL = NULL;
        this->nastepnyR = NULL;
        this->tabL = NULL;
        this->tabP = NULL;
 
        this->dlugosc_tabL = 1;
        this->dlugosc_tabP = 1;
 
        this->czy_jest_tabL = false;;
        this->czy_jest_tabP = false;
 
        this->czy_dodano = false;
}
 
class Drzewo
{
private:
        Wierzcholek *pierwszy;
public:
        
        Drzewo()
        {
                pierwszy = NULL;
        }
        ~Drzewo()
        {
                delete (pierwszy);
        }
        void dodaj_nowy( int ile_sciezek, Wierzcholek **dane, int &ile_danych);
        void uporzadkuj_drzewo();
        int szukaj_najlepszej_sciezki(int jak_dluga_moze_byc_sciezka);
        Wierzcholek * szukaj_pierwszego(int skad, int ile_sciezek, Wierzcholek **dane);
        void szukaj_w_danych(int skad, int dokad, int &ile_sciezek, Wierzcholek **dane, Wierzcholek *tablica[2]);
        void max(int *tab1, int *tab2, int *tabWY, int dlugosc_t1, int dlugosc_t2, int ilosc_kwiatt3, int dlugosc_t3);
};
 
int Drzewo::szukaj_najlepszej_sciezki(int jak_dluga_moze_byc_sciezka)
{
        int droga = 0;
        int max = 0;
 
        int *tabWynik = new int[jak_dluga_moze_byc_sciezka+1];
        for(int i=0;i<jak_dluga_moze_byc_sciezka+1;i++)
                tabWynik[i] = 0 ;
 
        
        int dlugosc_tabWynik = 4;
 
        if (this->pierwszy != NULL)
        {
                Wierzcholek *ten = this->pierwszy;
                droga++;
                ten->tabL = new int[jak_dluga_moze_byc_sciezka + 1];
                ten->tabL[0] = 0;
                ten->tabP = new int[jak_dluga_moze_byc_sciezka + 1];
                ten->tabP[0] = 0;
                do
                {//             jezeli ma syna                                                                          i               nie jestem na max odleglosci    i               jeszcze tu nie bylem
                        
                                if (ten->nastepnyL != NULL && ten->zwroc_sprawdzenie_lewe() != true && droga<jak_dluga_moze_byc_sciezka)
                                {
                                        droga++;
 
                                        ten->zmien_sprawdzenie_lewe(true);
                                        ten = ten->nastepnyL;
                                        ten->tabL = new int[jak_dluga_moze_byc_sciezka + 1];
                                        ten->tabL[0] = 0;
                                        ten->tabP = new int[jak_dluga_moze_byc_sciezka + 1];
                                        ten->tabP[0] = 0;
                                }
                                else if (ten->nastepnyR != NULL && ten->zwroc_sprawdzenie_prawe() != true && droga<jak_dluga_moze_byc_sciezka)
                                {
                                        droga++;
 
                                        ten->zmien_sprawdzenie_prawe(true);
                                        ten = ten->nastepnyR;
                                        ten->tabL = new int[jak_dluga_moze_byc_sciezka + 1];
                                        ten->tabL[0] = 0;
                                        ten->tabP = new int[jak_dluga_moze_byc_sciezka + 1];
                                        ten->tabP[0] = 0;
                        
                        }
                        else
                        {
                                bool czy_dodano_dwie_tab = false;
                        
 
                                if ((ten->zwroc_sprawdzenie_lewe() != false || ten->nastepnyL==NULL) && (ten->zwroc_sprawdzenie_prawe() != false || ten->nastepnyR==NULL))
                                {
                                        //dodanie dwoch tabel
                                        if (ten->dlugosc_tabL > ten->dlugosc_tabP)
                                                dlugosc_tabWynik = ten->dlugosc_tabL *2;
                                        else
                                                dlugosc_tabWynik = ten->dlugosc_tabP *2;
 
                                        czy_dodano_dwie_tab = true;
                                        this->max(ten->tabL, ten->tabP, tabWynik, ten->dlugosc_tabL, ten->dlugosc_tabP, ten->zwroc_ilosc_kwiatkow(), jak_dluga_moze_byc_sciezka + 1);
                                }
                                else if ((ten->nastepnyL == NULL && ten->nastepnyR == NULL) || droga >= jak_dluga_moze_byc_sciezka)
                                {
 
                                        if (ten->poprzedni->zwroc_czy_jest_tabL() == false)
                                        {
                                                ten->poprzedni->tabL[0] = 0;
                                                ten->poprzedni->tabL[1] = ten->zwroc_ilosc_kwiatkow();
                                                ten->poprzedni->zmien_czy_jest_tabL(true);
                                        }
                                        else if (ten->poprzedni->zwroc_czy_jest_tabP() == false)
                                        {
                                                ten->poprzedni->tabP[0] = 0;
                                                ten->poprzedni->tabP[1] = ten->zwroc_ilosc_kwiatkow();
                                                ten->poprzedni->zmien_czy_jest_tabP(true);
                                        }       
                                }
 
 
                                // cofniecie do ojca
                                droga--;
 
                                if (czy_dodano_dwie_tab)
                                {
                                        if (ten->poprzedni->zwroc_czy_jest_tabL() == false)
                                        {
                                                for (int i = 0; i < jak_dluga_moze_byc_sciezka; i++)
                                                {
                                                        ten->poprzedni->tabL[i] = tabWynik[i];
                                                }
                                                ten->poprzedni->zmien_czy_jest_tabL(true);
                                        }
                                        else if (ten->poprzedni->zwroc_czy_jest_tabP() == false)
                                        {
                                                for (int i = 0; i < jak_dluga_moze_byc_sciezka ; i++)
                                                {
                                                        ten->poprzedni->tabP[i] = tabWynik[i];
                                                }
                                                ten->poprzedni->zmien_czy_jest_tabP(true);
                                        }
                                }
 
                                //ktora to tabela?
 
                                if (ten->poprzedni->zwroc_czy_jest_tabL() != false && ten->poprzedni->dlugosc_tabL == 1)
                                {
                                        if (ten->dlugosc_tabL > ten->dlugosc_tabP)
                                                ten->poprzedni->dlugosc_tabL = ten->dlugosc_tabL *2;
                                        else
                                                ten->poprzedni->dlugosc_tabL = ten->dlugosc_tabP *2;
                                }
                                else if (ten->poprzedni->zwroc_czy_jest_tabP() != false && ten->poprzedni->dlugosc_tabP == 1)
                                {
                                        if (ten->dlugosc_tabL > ten->dlugosc_tabP)
                                                ten->poprzedni->dlugosc_tabP = ten->dlugosc_tabL *2;
                                        else
                                                ten->poprzedni->dlugosc_tabP = ten->dlugosc_tabP *2;
                                }
 
                                delete(ten->tabL);
                                delete(ten->tabP);
                                ten = ten->poprzedni;
                                
                        }
                } while ((ten->zwroc_od_ktorej() != 1 && ten->zwroc_do_ktorej() != 1) || (ten->zwroc_sprawdzenie_lewe() != true || ten->zwroc_sprawdzenie_prawe() != true));
                //przeszukanie tablicy zeby znalezc najwieksze po³¹czenie
                this->max(ten->tabL, ten->tabP, tabWynik, ten->dlugosc_tabL, ten->dlugosc_tabP, ten->zwroc_ilosc_kwiatkow(), jak_dluga_moze_byc_sciezka + 1);
                max = tabWynik[jak_dluga_moze_byc_sciezka];
        }
        else
                max = 0;
 
        delete(tabWynik);
        return max;
}
 
 
void Drzewo::max(int *tab1, int *tab2, int *tabWY, int dlugosc_t1, int dlugosc_t2, int ilosc_kwiatt3, int dlugosc_t3)
{
 
        int max = 0;
 
        for (int i = 0; i < dlugosc_t3; i++)
        {
                if (i == 0)
                        tabWY[i] = 0;
                else if (i == 1)
                        tabWY[i] = ilosc_kwiatt3;
                else
                {
                        int b = 0;
                        int a;
                        if (dlugosc_t2 > dlugosc_t1)
                        {
                                a = i - dlugosc_t2;
                        }
                        else
                                a = i - dlugosc_t1;
 
                        if (a > 0)
                                b = a;
 
                        int zasieg_t1 = i - 1;
                        if (dlugosc_t1 - 1 < zasieg_t1)
                                zasieg_t1 = dlugosc_t1 - 1;
 
                        int zasieg_t2 = i - 1;
                        if (dlugosc_t2 - 1 < zasieg_t2)
                                zasieg_t2 = dlugosc_t2 - 1;
 
                        for (int j = 0; j < i - b; j++)
                        {
                                if (dlugosc_t2 > dlugosc_t1)
                                {
                                        int maxt = j + b;
                                        if (j + b >= dlugosc_t1)
                                                maxt = dlugosc_t1 - 1;
                                        if (tab1[maxt] + tab2[zasieg_t2 - j] > max)
                                                max = tab1[maxt] + tab2[zasieg_t2 - j];
                                }
                                else
                                {
                                        int maxt = j + b;
                                        if (j + b >= dlugosc_t1)
                                                maxt = dlugosc_t1 - 1;
                                        if (tab2[maxt] + tab1[zasieg_t1 - j] > max)
                                                max = tab2[maxt] + tab1[zasieg_t1 - j];
                                }
 
                        }
                        tabWY[i] = max + ilosc_kwiatt3;
                }
        }
}
 
 
void Drzewo::uporzadkuj_drzewo()
{
        if (this->pierwszy != NULL)
        {
                Wierzcholek *tymczasowy = pierwszy;
                do
                {
                        if (tymczasowy->zwroc_sprawdzenie_lewe() == true)
                        {
                                tymczasowy->zmien_sprawdzenie_lewe(false);
                                tymczasowy = tymczasowy->nastepnyL;
                        }
                        else if (tymczasowy->zwroc_sprawdzenie_prawe() == true)
                        {
                                tymczasowy->zmien_sprawdzenie_prawe(false);
                                tymczasowy = tymczasowy->nastepnyR;
                        }
                        else if (tymczasowy->zwroc_od_ktorej() != 1 && tymczasowy->zwroc_do_ktorej() != 1)
                                tymczasowy = tymczasowy->poprzedni;
                        else
                                break;
                } while (1 == 1);
        }
}
 
void Drzewo::dodaj_nowy(int ile_sciezek, Wierzcholek **dane, int &ile_danych)
{
        Wierzcholek *ten;
        Wierzcholek*tab[2];
        
                if (this->pierwszy == NULL)
                {
                        this->pierwszy = this->szukaj_pierwszego(1, ile_sciezek, dane);
                }
                else
                {
                        ten = this->pierwszy;
                        do
                        {
 
 
                                tab[0] = NULL;
                                tab[1] = NULL;
                                if (ten->zwroc_czy_dodano() == false)
                                {
                                        this->szukaj_w_danych(ten->zwroc_od_ktorej(), ten->zwroc_do_ktorej(), ile_danych, dane, tab);
                                        if (tab[0] != NULL)
                                        {
                                                ten->zmien_czy_dodano(true);
                                                ten->nastepnyL = tab[0];
                                                ten->nastepnyL->poprzedni = ten;
                                                if (tab[1] != NULL)
                                                {
                                                        ten->nastepnyR = tab[1];
                                                        ten->nastepnyR->poprzedni = ten;
                                                }
                                        }
                                        else
                                        {
                                                ten->zmien_czy_dodano(true);
                                                if (ten->zwroc_do_ktorej() == 1 || ten->zwroc_od_ktorej() == 1)
                                                        break;
                                                else
                                                        ten = ten->poprzedni;
                                        }
 
                                }
 
                                if (ten->zwroc_czy_dodano() == true && ten->zwroc_sprawdzenie_lewe() == false && ten->nastepnyL != NULL)
                                {
                                        ten->zmien_sprawdzenie_lewe(true);
                                        ten = ten->nastepnyL;
                                }
                                else if (ten->zwroc_czy_dodano() == true && ten->zwroc_sprawdzenie_prawe() == false && ten->nastepnyR != NULL)
                                {
                                        ten->zmien_sprawdzenie_prawe(true);
                                        ten = ten->nastepnyR;
                                }
                                else
                                {
                                        if (ten->zwroc_do_ktorej() == 1 || ten->zwroc_od_ktorej() == 1)
                                                break;
                                        else
                                                ten = ten->poprzedni;
                                }
                        } while (1 == 1);
                }
        
}
 
 
Wierzcholek * Drzewo::szukaj_pierwszego(int skad, int ile_sciezek, Wierzcholek **dane)
{
        Wierzcholek *ten;
 
        for (int i = 0; i < ile_sciezek; i++)
        {
                if (dane[i]->zwroc_od_ktorej() == skad || dane[i]->zwroc_do_ktorej() == skad)
                {
                        ten = dane[i];
                        dane[i] = new Wierzcholek(-1, -1, -1, NULL);
                        break;
                }
        }
        return ten;
}
 
 
void Drzewo::szukaj_w_danych(int skad, int dokad, int &ile_sciezek, Wierzcholek **dane, Wierzcholek *tablica[2])
{
        int a = 0;
        for (int i = 0; i < ile_sciezek; i++)
        {
                if (dane[i]->zwroc_od_ktorej() == skad || dane[i]->zwroc_do_ktorej() == skad || dane[i]->zwroc_od_ktorej() == dokad || dane[i]->zwroc_do_ktorej() == dokad)
                {
                        tablica[a] = dane[i];
                        a++;
                        dane[i] = new Wierzcholek(-1, -1, -1, NULL);
                        if (a == 2)
                                break;
                }
        }
}
 
int main()
{
        cin.sync_with_stdio(false);
 
        Drzewo *sciezki = new Drzewo();
 
        int ile_sciezek = 0;
        int ile_przechodzi_sciezek = 0;
 
        int ile_kwiatow = 0;
        int skad = 0;
        int dokad = 0;
 
        cin >> ile_sciezek;
        cin >> ile_przechodzi_sciezek;
 
        Wierzcholek **dane = new Wierzcholek*[ile_sciezek];
        int ile_jest_danych = ile_sciezek;
        if ( ile_przechodzi_sciezek != 0)
        {
                for (int i = 0; i < ile_sciezek; i++)
                {
                        cin >> skad;
                        cin >> dokad;
                        cin >> ile_kwiatow;
                        dane[i] = new Wierzcholek( ile_kwiatow, skad, dokad, NULL);
                }
                sciezki->dodaj_nowy(ile_sciezek, dane, ile_jest_danych);
                sciezki->dodaj_nowy(ile_sciezek, dane, ile_jest_danych);
                sciezki->uporzadkuj_drzewo();
                cout << sciezki->szukaj_najlepszej_sciezki(ile_przechodzi_sciezek);
        }
        else
                cout << 0;
        delete( dane);
        return 0;
}