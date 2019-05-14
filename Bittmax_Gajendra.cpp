#include<bits/stdc++.h>
#define ll long long
using namespace std;

void open(string file_name)
{
    cout<<"This will print max 20 entry of the file"<<endl;
    ifstream ip(file_name);
    if(!ip.is_open())
    {
        cout<<"ERROR: In opening "<<file_name<<endl;
        exit(0);
    }
    int x=0;
    string id,timestamp,price;
    while(ip.good()&&x<20)
    {
        if(x==0)
        {
            x++;
            continue;
        }
        if(file_name=="all_unique_id.csv")
        {
            getline(ip,id,',');
            getline(ip,timestamp,',');
            getline(ip,price,'\n');
            cout<<id<<","<<timestamp<<","<<price<<endl;
        }
        else
        {
            getline(ip,timestamp,',');
            getline(ip,price,'\n');
            cout<<timestamp<<"\t"<<price<<endl;
        }
        x++;
    }
}
void if_no_agrument_passed()
{
    cout<<"No Agrument Passed"<<endl;
    exit(0);
}
main(int argc, char *argv[])
{
    if(argc==1)
        if_no_agrument_passed();
    ll zec_aud_count=0, ltc_aud_count=0, btc_aud_count=0;
    ll zec_aud_price=0, ltc_aud_price=0, btc_aud_price=0;
    ofstream zec,btc,ltc,all_unique_id;
    zec.open("ZEC-AUD.csv");
    ltc.open("LTC-AUD.csv");
    btc.open("BTC-AUD.csv");
    all_unique_id.open("all-unique-id.csv");
    zec<<"Timestamp"<<","<<"Price"<<endl;
    btc<<"Timestamp"<<","<<"Price"<<endl;
    ltc<<"Timestamp"<<","<<"Price"<<endl;
    all_unique_id<<"Unique_id"<<","<<"Timestamp"<<","<<"Price"<<endl;
    for(int i=1;i<argc;i++)
    {
        string file_name=argv[i];
        ifstream ip(file_name);
        if(!ip.is_open())
        {
            cout<<"ERROR: In opening "<<file_name<<endl;
            exit(0);
        }
        string id,timestamp,price;
        while(ip.good())
        {
           getline(ip,id,',');
           getline(ip,timestamp,',');
           getline(ip,price,'\n');
           if(id=="ZEC-AUD")
           {
               zec_aud_price+=stoll(price);
               zec<<timestamp<<","<<price<<endl;
               all_unique_id<<"ZEC-AUD"<<","<<timestamp<<","<<price<<endl;
               zec_aud_count++;
           }
           else if(id=="LTC-AUD")
           {
               ltc_aud_price+=stoll(price);
               ltc<<timestamp<<","<<price<<endl;
               all_unique_id<<"LTC-AUD"<<","<<timestamp<<","<<price<<endl;
               ltc_aud_count++;
           }
           else if(id=="BTC-AUD")
           {
               btc_aud_price+=stoll(price);
               btc<<timestamp<<","<<price<<endl;
               all_unique_id<<"BTC-AUD"<<","<<timestamp<<","<<price<<endl;
               btc_aud_count++;
           }
        }
        ip.close();
    }
    zec.close();
    btc.close();
    ltc.close();
    all_unique_id.close();
    cout<<"Total entries "<<zec_aud_count+ltc_aud_count+btc_aud_count<<endl;
    cout<<"Total ZEC-AUD entries found "<<zec_aud_count<<endl<<"Total LTC-AUD entries found "<<ltc_aud_count<<endl<<"Total BTC-AUD entries found "<<btc_aud_count<<endl;;
    cout<<"Average price"<<endl<<"ZEC-AUD \t"<<(double)zec_aud_price/zec_aud_count<<endl<<"LTC-AUD \t"<<(double)ltc_aud_price/ltc_aud_count<<endl<<"BTC-AUD \t"<<(double)btc_aud_price/btc_aud_count<<endl;
    cout<<"All four file have been created"<<endl<<"1. ZEC-AUD \n2. LTC-AUD\n3. BTC-AUD\n4. all-unique-id \nDo you want to see 20 entry of each file (Y/N)"<<endl;
    char option;
    cin>>option;
    if(option=='Y'||option=='y')
    {
        cout<<"ZEC-AUD FILE \n";
        open("ZEC-AUD.csv");
        cout<<"LTC-AUD FILE \n";
        open("LTC-AUD.csv");
        cout<<"BTC-AUD FILE \n";
        open("BTC-AUD.csv");
        cout<<"COMBINED FILE \n";
        open("all-unique-id.csv");
    }
}
