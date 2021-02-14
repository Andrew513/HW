#include <iostream>
#include <cmath>
using namespace std;
class bankacc
{
private:
    double twd,sumtwd,optwd;
    double usd,sumusd,opusd;
    double eud,sumeud,opeud;
public:
    bankacc();
    bankacc(double taibi,double meijin,double oyen);
    void gettwd(double taibi);
    void getusd(double meijin);
    void geteud(double oyen);
    double obtaintwd();
    double obtainusd();
    double obtaineud();
    double settwd();
    double setusd();
    double seteud();
    double valueInNtd(double taibi,double meijin,double oyen);
    double valueInUsd(double taibi,double meijin,double oyen);
    double valueInEud(double taibi,double meijin,double oyen);
    void output();
    void output1();
};
double bankacc::obtaintwd()
{
    return twd;
}
double bankacc::obtainusd()
{
    return usd;
}
double bankacc::obtaineud()
{
    return eud;
}
void bankacc::gettwd(double taibi)//this is actually set
{
    twd=taibi;
}
void bankacc::getusd(double meijin)
{
    usd=meijin;
}
void bankacc::geteud(double oyen)
{
    eud=oyen;
}
double bankacc::settwd()//this is actually get
{
    return sumtwd;
}
double bankacc::setusd()
{
    return sumusd;
}
double bankacc::seteud()
{
    return sumeud;
}
double bankacc::valueInNtd(double taibi,double meijin,double oyen)
{
    sumtwd=taibi+(meijin*30)+(oyen*40);
    return sumtwd;
}
double bankacc::valueInUsd(double taibi,double meijin,double oyen)
{
    sumusd=(taibi/30)+(meijin)+(oyen*4/3);
    return sumusd;
}
double bankacc::valueInEud(double taibi,double meijin,double oyen)
{
    sumeud=(taibi/40)+(meijin*3/4)+(oyen);
    return sumeud;
}
void bankacc::output()
{
    cout<<"NTD:"<<sumtwd<<" USD:"<<sumusd<<" EUD:"<<sumeud<<endl;
}
const bankacc operator +(bankacc& bank1,bankacc& bank2)
{
    double alltwd=bank1.settwd()+bank2.settwd();
    double allusd=bank1.setusd()+bank2.setusd();
    double alleud=bank1.seteud()+bank2.seteud();
    return bankacc(alltwd,allusd,alleud);
}
const bankacc operator -(bankacc bank1,bankacc bank2)
{
    double alltwd=bank1.settwd()-bank2.settwd();
    double allusd=bank1.setusd()-bank2.setusd();
    double alleud=bank1.seteud()-bank2.seteud();
    return bankacc(alltwd,allusd,alleud);
}
const bankacc operator %(bankacc bank1,bankacc bank2)
{
    double alltwd, allusd, alleud,ttaltwd,ttalusd,ttaleud;
    if(bank1.obtaintwd()-bank2.obtaintwd()<0)
    {
        alltwd = -(bank1.obtaintwd() - bank2.obtaintwd());
    }
    else 
    {
        alltwd = bank1.obtaintwd() - bank2.obtaintwd();
    }
    if(bank1.obtainusd()-bank2.obtainusd()<0)
    {
        allusd = -(bank1.obtainusd() - bank2.obtainusd());
    }
    else 
    {
        allusd = bank1.obtainusd() - bank2.obtainusd();
    }
    if(bank1.obtaineud()-bank2.obtaineud()<0)
    {
        alleud = -(bank1.obtaineud() - bank2.obtaineud());
    }
    else 
    {
        alleud = bank1.obtaineud() - bank2.obtaineud();
    }
    ttaltwd = alltwd + allusd * 30 + alleud * 40;
    ttalusd = (alltwd / 30) + allusd + (alleud * 4 / 3);
    ttaleud = alltwd / 40 + allusd * 3 / 4 + alleud;
    return bankacc(ttaltwd, ttalusd, ttaleud);
}
const bankacc operator *(bankacc bank1,bankacc bank2)
{
    double alltwd=bank1.settwd()+bank2.settwd()*0.99;
    double allusd=bank1.setusd()+bank2.setusd()*0.99;
    double alleud=bank1.seteud()+bank2.seteud()*0.99;
    return bankacc(alltwd,allusd,alleud);
}
const bankacc operator /(bankacc bank1,bankacc bank2)
{
    double alltwd=bank1.settwd()-bank2.settwd()*1.01;
    double allusd=bank1.setusd()-bank2.setusd()*1.01;
    double alleud=bank1.seteud()-bank2.seteud()*1.01;
    return bankacc(alltwd,allusd,alleud);
}
bankacc::bankacc(double taibi,double meijin,double oyen)
{
    optwd=taibi;
    opusd=meijin;
    opeud=oyen;
}
void bankacc::output1()
{
    cout<<"NTD:"<<optwd<<" USD:"<<opusd<<" EUD:"<<opeud<<endl;
}
bankacc::bankacc()
{
    twd=0;
    usd=0;
    eud=0;
}
int main()
{
    double twd1,usd1,eud1,twd2,usd2,eud2;
    cin>>twd1>>usd1>>eud1>>twd2>>usd2>>eud2;
    bankacc bank1,bank2,a;
    bank1.gettwd(twd1);//setting twd1 to twd in private
    bank1.getusd(usd1);
    bank1.geteud(eud1);
    bank2.gettwd(twd2);
    bank2.getusd(usd2);
    bank2.geteud(eud2);
    bank1.valueInNtd(twd1,usd1,eud1);
    bank1.valueInUsd(twd1,usd1,eud1);
    bank1.valueInEud(twd1,usd1,eud1);
    bank2.valueInNtd(twd2,usd2,eud2);
    bank2.valueInUsd(twd2,usd2,eud2);
    bank2.valueInEud(twd2,usd2,eud2);
    bank1.output();
    bank2.output();
    a=bank1+bank2;
    cout<<"+:";
    a.output1();
    a=bank1-bank2;
    cout<<"-:";
    a.output1();
    a=bank1%bank2;
    cout<<"%:";
    a.output1();
    a=bank1*bank2;
    cout<<"*:";
    a.output1();
    a=bank1/bank2;
    cout<<"/:";
    a.output1();
}