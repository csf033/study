#include <iostream>
using namespace std;

class Address;

class Student{
  public:
    Student(char *name, int age, float score);
  public:
    void show(Address *pAddress);
  private:
    char *m_name;
    int m_age;
    float m_score;
};
class Address{
  public:
    Address(char *province, char *city, char *district);
  public:
    friend void Student::show(Address *pAddress);
  private:
    char *m_province;
    char *m_city;
    char *m_district;
};

Student::Student(char *name, int age, float score): m_name(name), m_age(age), m_score(score){}
void Student::show(Address *pAddress){
  cout<<m_name<<"的年龄是："<<m_age<<", 成绩是："<<m_score<<endl;
  cout<<pAddress->m_province<<pAddress->m_city<<pAddress->m_district<<endl;
}

Address::Address(char *province, char *city, char *district): m_province(province), m_city(city), m_district(district){}

int main(){
  Address address("广东省", "佛山市", "顺德区");
  Student student("jack",22,78);
  student.show(&address);
  return 0;
}