#include<iostream>
#include<cstring>
using namespace std;
class Card
{
protected:
    char nrCard[20];
    char NumeDetinator[20];
    char data_expirare[20];
    int CVV;
    double credit;
public:
    Card()
    {
        strcpy(nrCard,"Necunoscut");
        strcpy(NumeDetinator,"Necunoscut");
        strcpy(data_expirare,"Nedefinita");
        CVV=0;
        credit=0;
    }
    Card(char a[20],char b[20],char c[20],int d,double e)
    {
        strcpy(nrCard,a);
        strcpy(NumeDetinator,b);
        strcpy(data_expirare,c);
        CVV=d;
        credit=e;
    }
    Card(const Card &c)
    {
        strcpy(nrCard,c.nrCard);
        strcpy(NumeDetinator,c.NumeDetinator);
        strcpy(data_expirare,c.data_expirare);
        CVV=c.CVV;
        credit=c.credit;
    }
    ~Card(){
        strcpy(nrCard,"");
        strcpy(NumeDetinator,"");
        strcpy(data_expirare,"");
        CVV=0;
        credit=0;
    }
    void set_nrCard(char c[20])
    {
        strcpy(nrCard,c);
    }
    void set_NumeDetinator(char c[20])
    {
        strcpy(NumeDetinator,c);
    }
    void set_data(char c[20])
    {
        strcpy(data_expirare,c);
    }
    void set_CVV(int x){CVV=x;}
    void set_credit(double x){credit=x;}
    string get_nrCard(){return nrCard;}
    string get_NumeDetinator(){return NumeDetinator;}
    string get_data(){return data_expirare;}
    int get_CVV(){return CVV;}
    double get_credit(){return credit;}

    Card operator=(Card& c)
    {
        strcpy(nrCard,c.nrCard);
        strcpy(NumeDetinator,c.NumeDetinator);
        strcpy(data_expirare,c.data_expirare);
        CVV=c.CVV;
        credit=c.credit;
        return *this;
    }

    friend istream& operator>>(istream& in, Card& c)
    {
        cout<<"Numarul cardului este: ";
        in>>c.nrCard;
        cout<<'\n'<<"Numele detinatorului este: ";
        in>>c.NumeDetinator;
        cout<<'\n'<<"Data expirarii este: ";
        in>>c.data_expirare;
        cout<<'\n'<<"CVV: ";
        in>>c.CVV;
        cout<<'\n'<<"Credit: ";
        in>>c.credit;
        return in;
    }

    friend ostream& operator<<(ostream& out,Card& c)
    {
        out<<"Cardul cu numarul: "<<c.nrCard<<" este detinut de "<<c.NumeDetinator<<" si expira la data de "<<c.data_expirare<<" cu CVV-ul "<<c.CVV<<" dispune de suma de :"<<c.credit<<" lei";
        return out;

    }

};

class Card_standard: public Card
{
protected:
    int limitaExtragere;
    double comisionDepasireLimita;
public:
    Card_standard()
    {
        Card();
        limitaExtragere=0;
        comisionDepasireLimita=0;
    }
    Card_standard(int x,double y,char a[20],char b[20],char c[20],int d,double e)
    {
        Card(a,b,c,d,e);
        limitaExtragere=x;
        comisionDepasireLimita=y;
    }
    Card_standard(Card_standard& c)
    {
        Card(c.nrCard,c.NumeDetinator,c.data_expirare,c.CVV,c.credit);
        limitaExtragere=c.limitaExtragere;
        comisionDepasireLimita=c.comisionDepasireLimita;
    }
    ~Card_standard(){
        strcpy(nrCard,"");
        strcpy(NumeDetinator,"");
        strcpy(data_expirare,"");
        CVV=0;
        credit=0;
        limitaExtragere=0;
        comisionDepasireLimita=0;
    }

    void set_limita(int x){limitaExtragere=x;}
    void set_comision(int x) {comisionDepasireLimita=x;}
    int get_limita(){return limitaExtragere;}
    double get_comision(){return comisionDepasireLimita;}

    Card_standard operator=(Card_standard& c)
    {
        Card(c.nrCard,c.NumeDetinator,c.data_expirare,c.CVV,c.credit);
        limitaExtragere=c.limitaExtragere;
        comisionDepasireLimita=c.comisionDepasireLimita;
        return *this;
    }

    friend istream& operator>>(istream& in, Card_standard& c)
    {
        cout<<"Numarul cardului este: ";
        in>>c.nrCard;
        cout<<'\n'<<"Numele detinatorului este: ";
        in>>c.NumeDetinator;
        cout<<'\n'<<"Data expirarii este: ";
        in>>c.data_expirare;
        cout<<'\n'<<"CVV: ";
        in>>c.CVV;
        cout<<'\n'<<"Credit: ";
        in>>c.credit;
        cout<<'\n'<<"Limita de extragere: ";
        in>>c.limitaExtragere;
        cout<<'\n'<<"Comision de depasire: ";
        in>>c.comisionDepasireLimita;
        return in;
    }

    friend ostream& operator<<(ostream& out,Card_standard& c)
    {
        out<<"Cardul cu numarul: "<<c.nrCard<<" este detinut de "<<c.NumeDetinator<<" si expira la data de "<<c.data_expirare<<" cu CVV-ul "<<c.CVV<<" dispune de suma de :"<<c.credit<<" lei "<<"are limita la retragere de:"<<c.limitaExtragere<<" lei si un comision de "<<c.comisionDepasireLimita<<'\n';
        return out;

    }

    virtual void extragere(double suma_extragere)
    {
            if(suma_extragere<=limitaExtragere)
                credit=credit-suma_extragere;
            else
            {
                double d=suma_extragere-limitaExtragere;
                credit=credit-suma_extragere-(d*comisionDepasireLimita)/100;
            }
    }

};

class Card_premium: public Card_standard
{
    double cashback;
public:
    Card_premium()
    {
        Card_standard();
        cashback=0;
    }
    Card_premium(double x,char numarcard[20],char detinator[20],char data[20],int cvv,double creedit,int limita,double commision)
    {
        Card_standard(limita,commision,numarcard,detinator,data,cvv,creedit);
        cashback=x;
    }
    Card_premium(Card_premium& x)
    {
        Card_standard(x.limitaExtragere,x.comisionDepasireLimita,x.nrCard,x.NumeDetinator,x.data_expirare,x.CVV,x.credit);
        cashback=x.cashback;
    }
    ~Card_premium(){
        strcpy(nrCard,"");
        strcpy(NumeDetinator,"");
        strcpy(data_expirare,"");
        CVV=0;
        credit=0;
        limitaExtragere=0;
        comisionDepasireLimita=0;
        cashback=0;
    }
    Card_premium operator=(Card_premium& x)
    {
        Card_standard(x.limitaExtragere,x.comisionDepasireLimita,x.nrCard,x.NumeDetinator,x.data_expirare,x.CVV,x.credit);
        cashback=x.cashback;
        return *this;
    }
    friend istream& operator>>(istream& in, Card_premium& c)
    {
        cout<<"Numarul cardului este: ";
        in>>c.nrCard;
        cout<<'\n'<<"Numele detinatorului este: ";
        in>>c.NumeDetinator;
        cout<<'\n'<<"Data expirarii este: ";
        in>>c.data_expirare;
        cout<<'\n'<<"CVV: ";
        in>>c.CVV;
        cout<<'\n'<<"Credit: ";
        in>>c.credit;
        cout<<'\n'<<"Cashback-ul este de :";
        in>>c.cashback;
        return in;
    }

    friend ostream& operator<<(ostream& out,Card_premium& c)
    {
        out<<"Cardul cu numarul: "<<c.nrCard<<" este detinut de "<<c.NumeDetinator<<" si expira la data de "<<c.data_expirare<<" cu CVV-ul "<<c.CVV<<" dispune de suma de :"<<c.credit<<" lei "<<", iar cashback-ul este de "<<c.cashback;
        return out;

    }

    virtual void extragere(double suma_extragere)
    {
        credit=credit-suma_extragere;
        credit=credit+cashback/100*suma_extragere;
    }

};
int main()
{
    char tip[20];
    int ok;
    double suma;
    cout<<"Introduceti tipul cardului"<<'\n';
    cin>>tip;
    if(strcmp(tip,"Standard")==0)
    {
        cout<<"Card standard:"<<'\n';
        Card_standard c;
        cin>>c;
        cout<<"Alege optiunea:"<<'\n';
        cout<<"1. Retragere numerar."<<'\n';
        cout<<"2. Interogare sold."<<'\n';
        cin>>ok;
        if(ok==2)
        {
            double sol=c.get_credit();
            cout<<sol<<"lei"<<'\n';
        }
        else
        {
            cout<<"Suma pe care doriti sa o retrageti este: ";
            cin>>suma;
            if(suma>c.get_credit())
                cout<<"Credit insuficient!"<<'\n';
            else{
                c.extragere(suma);
                cout<<"\nSoldul disponibil este de :";
                cout<<c.get_credit();
                }
        }

    }
    else
    if(strcmp(tip,"Premium")==0)
    {
        cout<<"Card premium"<<'\n';
        Card_premium c;
        cin>>c;
        cout<<"Alege optiunea:"<<'\n';
        cout<<"1. Retragere numerar."<<'\n';
        cout<<"2. Interogare sold."<<'\n';
        cin>>ok;
        if(ok==2)
        {
            double sol=c.get_credit();
            cout<<sol<<"lei"<<'\n';
        }
        else
        {
            cout<<"Suma pe care doriti sa o retrageti este: ";
            cin>>suma;
            if(suma>c.get_credit())
                cout<<"Credit insuficient!"<<'\n';
            else{
                c.extragere(suma);
                cout<<"\nSoldul disponibil este de :";
                cout<<c.get_credit();
                }
        }
    }
    else
        cout<<"Tipul cardului nu exista.Mai incearca!";

    return 0;
}
