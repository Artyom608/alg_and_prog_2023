#include <iostream>
#include <string>
#include <map>

using namespace std;
int main()
{
    int count;
    cin>>count;
    map<string, string> maps;
    for(int i = 0; i< count; i++)
    {
        string line;
        cin>>line;
        int end = line.find(';', 0);
        maps[line.substr(0,end)] = line.substr(end + 1, 2000);
    }
    int count2;
    cin>>count2;
    for(int i = 0; i < count2; i++){
    	string line;
        cin>>line;
        cout<<maps[line]<<' ';
    }    
}
