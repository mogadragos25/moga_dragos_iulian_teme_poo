#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class telefon
{
    private:
        const int id;
        string pin;
        int nr_aplicatii;
        string* aplicatii;
        float cont_bancar;

    public:
        int sanatate_baterie;
        string fus_orar;
        string data;
        bool wifi;
        static int nr_telefoane;

    telefon (int nr_aplicatii, string pin, const string* aplicatii_initiale, float cont_bancar) : id(++nr_telefoane)
    {
        this->pin = pin;
        this->nr_aplicatii = nr_aplicatii;
        this->aplicatii = new string[this->nr_aplicatii];
        for (int i = 0; i < this->nr_aplicatii; i++)
        {
            this->aplicatii[i] = aplicatii_initiale[i];
        }
        this->cont_bancar = cont_bancar;
        this->fus_orar = "Default";
        this->data = "Default";
        this->sanatate_baterie = 100;
        this->wifi = true;
    }

    void afisare_telefon ()
    {
        cout << "ID: " << this->id << endl;
        cout << "PIN: " << this->pin << endl;
        for (int i = 0; i < this->nr_aplicatii; i++)
        {
            cout << "Aplicatia[" << i+1 << "]: " << this->aplicatii[i] << endl;
        }
        cout << "Fonduri in contul bancar: " << this->cont_bancar << endl;
        cout << endl << "Setari:" << endl;
        cout << "Fusul orar este: " << this->fus_orar << endl;
        cout << "Data este: " << this->data << endl;
        cout << "Sanatatea bateriei este: " << this->sanatate_baterie <<"%" << endl;
        if (this->wifi == true)
        {
            cout << "WiFi: Pornit" << endl;
        }
        else
        {
            cout << "WiFi Oprit" << endl;
        }
    }

    int getNr_aplicatii ()
    {
        return this->nr_aplicatii;
    }

    void setNr_aplicatii (int nr_aplicatii_nou)
    {
        if (nr_aplicatii_nou > 0)
        {
            this->nr_aplicatii = nr_aplicatii_nou;
        }
        else
        {
            throw 404;
        }
    }

    string* getAplicatii ()
    {
        if (this->nr_aplicatii <= 0 || this->aplicatii == nullptr)
        {
            return nullptr;
        }

        string* aplicatii_noi = new string[this->nr_aplicatii];
        for (int i = 0; i < this->nr_aplicatii; i++)
        {
            aplicatii_noi[i] = this->aplicatii[i];
        }
        return aplicatii_noi;
    }

    void setAplicatii(int nr_aplicatii_nou, const string *aplicatii_nou)
    {
        if (nr_aplicatii_nou > 0)
        {
            if (this->aplicatii != nullptr)
            {
                delete[] this->aplicatii;
            }
            this->nr_aplicatii = nr_aplicatii_nou;
            this->aplicatii = new string[this->nr_aplicatii];
            for (int i = 0; i < this->nr_aplicatii; i++)
            {
                this->aplicatii[i] = aplicatii_nou[i];
            }
        }
        else
        {
            throw 404;
        }
    }

        ~telefon()
    {
        if (this->aplicatii != nullptr)
        {
            delete[] this->aplicatii;
        }
    }
};

int telefon::nr_telefoane = 0;

int main()
{
    const string app[] = {"Instagram", "WhatsApp", "YouTube"};
    telefon *Samsung = new telefon(3, "0000", app, 0);
    Samsung->afisare_telefon();

    try 
    {
        Samsung->setNr_aplicatii(-2);
    }
    catch (int cod)
    {
        cout << endl << "Erroare! Cod: " << cod << endl;
    }

    const string aplicatii_noi[] = {"TikTok", "Netflix"};
    Samsung->setAplicatii(2, aplicatii_noi);

    cout << endl << "Noul numar de aplicatii este: " << Samsung->getNr_aplicatii() << endl;

    string *aplicatii_preluate = Samsung->getAplicatii();
    int nr_apps = Samsung->getNr_aplicatii();
    for (int i = 0; i < nr_apps; i++)
    {
        cout << "Aplicatia[" << i + 1 << "]: " << aplicatii_preluate[i] << endl;
    }
    delete[] aplicatii_preluate;

    cout << endl << "Dupa setarea noilor aplicatii:" << endl;
    Samsung->afisare_telefon();   

    delete Samsung;
    
    if (telefon::nr_telefoane == 1)
    {
        cout << endl << "Am construit un telefon!" << endl;
    }
    else
    {
        cout << endl
             << "Am construit " << telefon::nr_telefoane << " telefoane!" << endl;
    }
    return 0;
}