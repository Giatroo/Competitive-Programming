#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1, s2, s3, sf;
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, s3);
    if(s1 == "vertebrado"){
        if(s2 == "ave"){
            if(s3 == "carnivoro")
                sf = "aguia";
            else
                sf = "pomba";
        } else{
            if(s3 == "onivoro")
                sf = "homem";
            else
                sf = "vaca";
        }
    } else {
        if(s2 == "inseto"){
            if(s3 == "hematofago")
                sf = "pulga";
            else
                sf = "lagarta";
        } else {
            if(s3 == "hematofago")
                sf = "sanguessuga";
            else
                sf = "minhoca";
        }
    }
    cout << sf << endl;
    return 0;
}
