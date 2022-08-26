#include <bits/stdc++.h>

using namespace std;
vector<long long> v;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        int data;
        cin>>data;
        v.push_back(data);
    }

    vector<long long> v2;
    bool priorPlus = false;
    v2.push_back(*v.begin());
    if(*v.begin() >0){
        priorPlus = true;
    }
    for(auto it=v.begin()+1; it != v.end(); it++){
        if(*it <=0){
            //--
            if(priorPlus == false){
                *v2.rbegin() += *it;
            }
            //+-
            else{
                v2.push_back(*it);
                priorPlus = false;
            }
        }
        else{
            //++
            if(priorPlus == true){
                *v2.rbegin() += *it;
                

            }
            //-+
            else{
                v2.push_back(*it);
                priorPlus = true;
            }
        }

    }

    /*
    for(int i =0; i<v2.size(); i++){
        cout<<v2[i]<<" ";
    }
    */
    if(v2.size()==1){
        long long max = *v2.begin();
        if(*v2.begin()>0){
            cout<<max;
        }
        else{
            for(auto it=v.begin(); it != v.end(); it++){
                if(*it >max){
                    max= *it;
                }
            }
            cout<<max;

        }

        return 0;
    }
    
    long long sum = v2[0];
    long long max = LONG_MIN;
    for(int i =1; i<v2.size(); i++){

        if(sum >0){
            //++
            if(v2[i]>0){
                sum += v2[i];
                if(max <sum){
                    max = sum;
                }
            }
            //+-
            else{
                if(abs(sum)>abs(v2[i])){
                     if(max <sum){
                        max = sum;
                    }
                    sum +=v2[i];
                }
                else{
                    sum = 0; 
                }
            }
        }
        else{
            //-+
             if(v2[i]>0){
                 sum = v2[i];
                  if(max <sum){
                    max = sum;
                }
            }
            //--
            else{
                if(abs(sum)<abs(v2[i])){
                     if(max <sum){
                        max = sum;
                    }
                    sum = v2[i];
                }
                else{
                    sum = v2[i]; 
                }
            }
        }
    }

    cout<<max;


    return 0;
}