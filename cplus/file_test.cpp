#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

void foo1(){
  ifstream inFile;
  inFile.open("test.txt", ios::in);
  if(inFile){
    inFile.close();
  }else{
    cout<<"test.txt does not exist"<<endl;
  }

  ofstream outFile;
  outFile.open("test1.txt", ios::out);
  if(outFile){
    outFile.close();
  }else{
    cout<<"error1"<<endl;
  }

  outFile.open("test2.txt", ios::in | ios::out);
  if(outFile){
    outFile.close();
  }else{
    cout<<"error2"<<endl;
  }

  fstream ioFile;
  ioFile.open("test3.txt", ios::in | ios::out | ios::trunc);
  if(ioFile){
    ioFile.close();
  }else{
    cout<<"error3"<<endl;
  }
}

const int MAX_NUM = 100;
int a[MAX_NUM];
int MyCompare(const void *e1, const void *e2){
  return *((int *)e1) - *((int *)e2);
}
void foo2(){
  int total = 0;
  ifstream srcFile("in.txt", ios::in);
  if(!srcFile){
    cout<<"open in file failed"<<endl;
    return;
  }

  ofstream destFile("out.txt", ios::out);
  if(!destFile){
    srcFile.close();
    cout<<"open dest file failed"<<endl;
    return;
  }

  int x;
  while(srcFile >> x){
    a[total++] = x;
  }
  qsort(a, total, sizeof(int), MyCompare);
  for(int i=0; i<total; i++){
    destFile << a[i] << " ";
  }

  destFile.close();
  srcFile.close();
}

class CStudent{
  public:
    string szName;
    int age;
};

void foo3(){
  CStudent s;
  ofstream outFile("students.dat", ios::out | ios::binary);
  while(cin>>s.szName>>s.age){
    outFile.write((char *)&s, sizeof(s));
  }
  outFile.close();
}

void foo4(){
  CStudent s;
  ifstream inFile("students.dat", ios::in | ios::binary);
  if(!inFile){
    cout<<"open student.dat error"<<endl;
    return;
  }
  while(inFile.read((char *)&s, sizeof(s))){
    int readedBytes = inFile.gcount();
    cout<<"read bytes="<<readedBytes<<endl;
    cout<<s.szName<<" "<<s.age<<endl;
  }
  inFile.close();
}

int main(){
  // foo1();
  // foo2();
  // foo3();
  foo4();
  return 0;
}
