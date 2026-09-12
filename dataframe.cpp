//Code snippet written by SENGENDO CRYSTAL ZAWEDDE 25/U/08615/PS
//Program calculating the percentage of the whole dataframe ocuppied by each of the rows 1,2,3.

# include <iostream>
# include <vector>
using namespace std;

int main(){
    vector<vector<double>> dataframe = {
{ 100,     120,     80},
{130,     140,     90},
{110,     150,     100},
{100,     105,     95}};
double grand_total = 0;
for (int rows = 0; rows < dataframe.size(); rows++){
    for (int col = 0; col < dataframe[rows].size(); col++){
        grand_total = grand_total + dataframe[rows][col];
    
    }
}
for (int col = 0; col < dataframe[0].size(); col++){
 double col_total = 0;
 double percentage;
 for (int rows = 0; rows < dataframe.size(); rows++){
        col_total = col_total + dataframe[rows][col]; 
        
        percentage = (col_total/grand_total)*100;
        }
        cout <<"Column " <<(col +1) <<" percentage = " <<percentage <<"%\n"; 
    }         
    return 0;
}