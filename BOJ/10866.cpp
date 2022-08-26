#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(){
    string s;
    int n_instruction;
    deque<int> dq;
    int data;
    cin>>n_instruction;
    for(int i=0;i<n_instruction;i++){
        cin>>s;
        if(s.compare("push_front")==0){
            cin>>data;
            dq.push_front(data);
        }
        else if(s.compare("push_back")==0){
            cin>>data;
            dq.push_back(data);
        }
        else if(s.compare("pop_front")==0){
            if(dq.empty()){
                cout<<-1<<endl;
            }
            else{
                data = dq.front();
                cout<<data<<endl;
                dq.pop_front();
            }
        }
        else if(s.compare("pop_back")==0){
            if(dq.empty()){
                cout<<-1<<endl;
            }
            else{
                data = dq.back();
                cout<<data<<endl;
                dq.pop_back();
            }
        }
        else if(s.compare("size")==0){
            cout<<dq.size()<<endl;
        }
        else if(s.compare("empty")==0){
            cout<<dq.empty()<<endl;
        }
        else if(s.compare("front")==0){
            if(dq.empty()){
                cout<<-1<<endl;
            }
            else{
                data = dq.front();
                cout<<data<<endl;
                
            }
        }
        else if(s.compare("back")==0){
            if(dq.empty()){
                cout<<-1<<endl;
            }
            else{
                data = dq.back();
                cout<<data<<endl;
                
            }
        }

    }

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}