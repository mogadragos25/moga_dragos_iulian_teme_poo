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

    ~telefon ()
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
    delete Samsung;
    if (telefon::nr_telefoane == 1)
    {
        cout << endl << "Am construit un telefon!" << endl;
    }
    else
    {
        cout << endl
             << "Am construit " << telefon::nr_telefoane << "telefoane!" << endl;
    }
    return 0;
}