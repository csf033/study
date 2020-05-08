#include <iostream>
using namespace std;

//基类
class People{
  protected:
    char *m_name;
    int m_age;
  public:
    People(char *name, int age);
};
People::People(char *name, int age): m_name(name), m_age(age){}

class Student:public People{
  private:
    float m_score;
  public:
    Student(char *name, int age, float score);
    void display();
};
Student::Student(char *name, int age, float score): People(name,age),m_score(score){}
void Student::display(){
  cout<<m_name<<"的年龄是："<<m_age<<" ,的成绩是："<<m_score<<endl;
}

int main(){
  Student student("jack", 21, 98);
  student.display();
  return 0;
}