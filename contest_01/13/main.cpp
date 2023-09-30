#include <iostream>
using namespace std;

int main(){
    long long int count; int count2 = 1;
    cin>>count;
    for(int n=2;true;n++){
        for(int i = 1; i<=n;i++){
            for(int j = 0; j<i;j++){
                cout <<count2<<" ";
                count2++;
                if (count<count2){
                    return 0;    
                }
            }
            cout<<'\n';
        }
        for(int i = n-1; i > 1; i--){
            for(int j = 0; j < i; j++){
                cout<<count2<<" ";
                count2++;
                if (count < count2){
                    return 0;
                }
            }
            cout<<'\n';
        }
    }
}
