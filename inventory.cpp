#include<bits/stdc++.h>
#include<ctime>
using namespace std;


int main()
{
    int setupCost;
    cout<<"enter your setup cost: ";
    cin>>setupCost;
    int incrementCost;
    cout<<"enter your increment cost: ";
    cin>>incrementCost;

    int holdingCost;
    cout<<"enter your holding cost: ";
    cin>>holdingCost;

    int backlogCost;
    cout<<"enter your backlog cost: ";
    cin>>backlogCost;

    // order policy(S,s)=(15,4)
    int S,s;
    cout<<"enter your order limit(S,s): ";
    cin>>S>>s;

    int inventory;
    cout<<"enter your current product: ";
    cin>>inventory;
    cout<<endl;



    int hld_pd=inventory*5,blg_pd=0,order,receive_day=0,total_order=0; //initially holding-product and backlog-product is zero
    cout<<"demand occurs after 5 days."<<endl;
    int days,month;
    cout<<" Enter Month: ";
    cin>>month;
    days=30*month;

    srand(time(0));
    for(int i=5;i<=days;i+=5){
        ///If an order is placed at the end of the month,it comes after 15 days
        if(i%30==0 and inventory<s){
            order=S-inventory;
            total_order+=order;
            receive_day=i+15;
            cout<<i<<" place order and no of order= "<<order<<" and it comes after 15 days"<<endl;
        }

        int demand;
       //demand occurs after 5 days
        demand=rand()%5; // Assume demand limit 10
        cout<<"demand="<<demand<<endl;
        inventory-=demand;
        cout<<"inventory="<<inventory<<endl;

        if(i==receive_day){
            cout<<"receive order "<<order<<" product"<<endl;
            inventory+=order;
            cout<<"inventory="<<inventory<<endl;
        }

        if(inventory<0){
            blg_pd+=(-inventory)*5;
        }
        else{
            hld_pd+=inventory*5;
        }
        cout<<"holding product="<<hld_pd<<endl;
        cout<<"backlog product="<<blg_pd<<endl;

        cout<<endl<<endl;
    }
    cout<<"Total order product="<<total_order<<endl;
    cout<<"Average holding cost="<<(hld_pd*holdingCost)/month<<endl;
    cout<<"Average backlog cost="<<(blg_pd*backlogCost)/month<<endl;

    int avg_ordering_cost=setupCost+incrementCost*total_order;
    cout<<"Average ordering cost="<<avg_ordering_cost/month<<endl;


}
