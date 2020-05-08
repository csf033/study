#include <iostream>
using namespace std;

class Student{
    public:
        Student(char *name, int age, float score);
    public:
        friend void show(Student *stu);
    private:
        char *m_name;
        int m_age;
        float m_score;
};

Student::Student(char *name, int age, float score): m_name(name), m_age(age), m_score(score){}

void show(Student *pstu){
    cout<<pstu->m_name<<"的年龄是："<<pstu->m_age<<",成绩是："<<pstu->m_score<<endl;
}

int main(){
    Student stu1("小明",21,99);
    show(&stu1);
    Student *pstu2 = new Student("jack",22,88);
    show(pstu2);
    delete pstu2;
    return 0;
}