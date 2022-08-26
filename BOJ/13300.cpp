#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    vector<int> male(6);
    vector<int> female(6);
    int n_student, max_room;

    cin>>n_student;
    cin>>max_room;

    for(int i=0;i<n_student;i++){
        int sex, grade;
        cin>>sex;
        cin>>grade;
        if(sex==0){
            female[grade-1]++;
        }
        else{
            male[grade-1]++;
        }
    }
    int sum = 0;
    for(int i=0;i<6; i++){
        sum += (int)ceil(male[i]/(float)max_room);
        sum += (int)ceil(female[i]/(float)max_room);
    }

    cout<<sum;
    

    ios_base::sync_with_stdio(false);
    return 0;
}