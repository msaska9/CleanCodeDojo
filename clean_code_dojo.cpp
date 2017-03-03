#include <bits/stdc++.h>
using namespace std;

int n;

int kulonbseg=0;

void Beolvas()
{
    cout<<"n=";
    cin>>n;
}

void Kiir(double valasz)
{
    cout<<"A valasz: "<<valasz<<endl;
}

void Jegyek(int szam, vector<int> &szamjegyek)
{
    while(szam>0)
    {
        szamjegyek.push_back(szam%3);
        szam/=3;
    }
}

int Hegye(int a, int b, int c)
{
    if(a<=b && c<=b) return 1;
    return 0;
}

int Volgye(int a, int b, int c)
{
    if(a>=b && c>=b && !(a==b && b==c)) return 1;
    return 0;
}

int HegyekVolgyekSzamol(int szam)
{
    int hegyszam=0;
    int volgyszam=0;
    vector<int> szamjegyek;
    Jegyek(szam, szamjegyek);
    for(int i=1; i<szamjegyek.size()-1; i++)
    {
        hegyszam+=Hegye(szamjegyek[i-1], szamjegyek[i], szamjegyek[i+1]);
        volgyszam+=Volgye(szamjegyek[i-1], szamjegyek[i], szamjegyek[i+1]);
    }
    return hegyszam-volgyszam;
}

void Megold()
{
    Beolvas();
    for(int i=1; i<=n; i++)
    {
        kulonbseg+=HegyekVolgyekSzamol(i);
    }
    double megoldas=(kulonbseg)/(n*1.0);
    Kiir(megoldas);
}

int main()
{
    Megold();
    return 0;
}
