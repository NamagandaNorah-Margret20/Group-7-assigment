

#include<iostream>
#include<vector>
#include<string>
using namespace std;


vector<int>add(vector<int>regular_hours,vector<int>overtime_hours){
    vector<int>result;
    for(int i=0;i<regular_hours.size();i++){
        result.push_back(regular_hours[i]+overtime_hours[i]);
    }
    return result;
}
int main(){
    vector<string>employees={"A","B","C","D","E"};
    vector<int>regular_hours={40,35,40,38,36};
    vector<int>overtime_hours={5,3,8,2,4};
    vector<int>hourly_rate={5000,6000,5000,5500,4500};


    vector<int>total_hours=add(regular_hours,overtime_hours);
    cout<<"Total hours worked:"<<endl;
    for(int i=0;i<total_hours.size();i++){
        cout<<"Employee"<<" "<<employees[i]<<" "<<"-"<<" ";
        cout<<total_hours[i]<<" "<<"hours"<<endl;

    }
    return 0;

    
}
