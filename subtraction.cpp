#include<iostream>
#include<vector>
#include<string>
using namespace std;


vector<int>subtract(vector<int>total_hours,vector<int>overtime_hours){
    vector<int>result;
    for(int i=0;i<total_hours.size();i++){
        result.push_back(total_hours[i]-overtime_hours[i]);
    }
    return result;
}
int main(){
    vector<string>employees={"A","B","C","D","E"};
    vector<int>total_hours={45,38,48,40,40};
    vector<int>overtime_hours={5,3,8,2,4};


    vector<int>regular_hours=subtract(total_hours,overtime_hours);
    cout<<"Recalculated regular hours:"<<endl;
    for(int i=0;i<regular_hours.size();i++){
        cout<<"Employee"<<" "<<employees[i]<<" "<<"-"<<" ";
        cout<<regular_hours[i]<<" "<<"hours"<<endl;

    }
    return 0;

    
}