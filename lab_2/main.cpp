#include <iostream>

using namespace std;

class word{
private:
    int sum, del;
public:
    word (int a,int b){
        one(a,b);
    }
    void one(int a, int b){
        sum=a+b;
        del=b/a;
        cout<<sum<<" "<<del;
    }
    void two(){
        cout<<"test 2";
    }
};

int main() {
    int a=2, b=26;
    word object(a,b);
    cout<<endl;
    object.two();
}
