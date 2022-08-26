#include <string>
#include <queue>
#include <iostream>
using namespace std;

queue<int> q;



int main(){
    string s;
    int n_instruction;
    int data;
    cin>>n_instruction;
    for(int i=0; i<n_instruction;i++){
        cin>>s;
        if(s.compare("push")==0){
            cin>>data;
            q.push(data);
        }
        else if(s.compare("pop")==0){
            if(q.empty()==0){
                data = q.front();
                cout<<data<<endl;
                q.pop();
            }
            else{
                cout<<-1<<endl;
            }
        }
        else if(s.compare("size")==0){
            cout<<q.size()<<endl;
        }
        else if(s.compare("empty")==0){
            cout<<q.empty()<<endl;
        }
        else if(s.compare("front")==0){
            if(q.empty()==0){
                cout<<q.front()<<endl;
            }
            else{
                cout<<-1<<endl;
            }
        }
        else if(s.compare("back")==0){
            if(q.empty()==0){
                cout<<q.back()<<endl;
            }
            else{
                cout<<-1<<endl;
            }
        }



    }


    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}