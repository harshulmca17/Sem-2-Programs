
#include <iostream>
#include <fstream>
 
using namespace std;
 
int main()
{
    fstream file;
    //open file sample.txt in and Write mode
    file.open("9CFILE.txt",ios::out);
    if(!file)
    {
        cout<<"Error in creating file!!!";
        return 0;
    }
    //write A to Z
    file<<"ABCDEFGHIJKLMNO";
    //print the position
    cout<<"Current position is: "<<file.tellp()<<endl;
    file.close();
 
    //again open file in read mode
    file.open("9CFILE.txt",ios::in);
    if(!file)
    {
        cout<<"Error in opening file!!!";
        return 0;
    }
    cout<<"After opening file position is: "<<file.tellg()<<endl;
     
    //read characters untill end of file is not found
    char ch;
    while(!file.eof())
    {
        cout<<"At position : "<<file.tellg();   //current position
        file>>ch;   //read character from file
        cout<<" Character \""<<ch<<"\""<<endl;
    }
    file.seekp(4,ios::end);
    cout<<" \nGet Pointer after adjustment : "<<file.tellp();
    file.seekg(1,ios::cur);
    cout<<" \nPut Pointer after adjustment : "<<file.tellg();
    //close the file
    file.close();
    return 0;
}
