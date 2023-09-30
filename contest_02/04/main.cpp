#include <iostream>
#include <tuple>
using namespace std;

std::tuple<int,int,int> find_lcm(int a, int b){
    int max;
    if(a>b) max = a;
    if (a<=b) max = b;
    while(true){
        if((max%a==0) && (max%b==0)) break;
        max+=1;
    }
    return std::make_tuple(max,max/a,max/b);
}

std::tuple<int,int> reduce(int a, int b){
    int min;
    int nod;
    if(a>b) min = a;
    if(a<=b) min = b;
    for(int i = 1; i <= min; i++){
        if((a%i==0)&&(b%i==0)) nod = i;
    }
    return std::make_tuple(a/nod,b/nod);
}


int main() {
    int m1, n1, m2, n2;
    char _;
    std::cin >> m1 >> _ >> n1
             >> m2 >> _ >> n2;
    std::tie(m1, n1) = reduce(m1, n1);
    std::tie(m2, n2) = reduce(m2, n2);

    auto[lcm, c1, c2] = find_lcm(n1, n2);
    auto[m, n] = reduce(m1 * c1 + m2 * c2, lcm);

    std::cout << m << '/' << n << std::endl;
}
