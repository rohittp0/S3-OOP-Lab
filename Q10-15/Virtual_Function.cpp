#include <iostream>
using namespace std;
class Student{
protected:
string name;
int age, reg_no;
public:
virtual void sort(int studentNo) = 0;
};
class BTechStudent : public Student{
float marks;
public:
void input(){
cout<<"Enter name: ";
cin>>name;
cout<<"Enter Age: ";
cin>>age;
cout<<"Enter Register No: ";
cin>>reg_no;
cout<<"Enter Total Mark: ";
cin>>marks;
}
void sort(int studentNo);
};
static BTechStudent bstudent[10];
void BTechStudent :: sort(int studentNo){
for(int i = 0;i<studentNo;i++){
BTechStudent temp;
for(int j = i+1;j<studentNo;j++){
if(bstudent[i].marks > bstudent[j].marks){
temp = bstudent[i];
bstudent[i] = bstudent[j];
bstudent[j] = temp;
}
if(bstudent[i].marks == bstudent[j].marks){
if(bstudent[i].name > bstudent[j].name){
temp = bstudent[i];
bstudent[i] = bstudent[j];
bstudent[j] = temp;
}}
}
}
cout<<"\nName\tAge\tRegister No\tMark\n";
for(int i = 0;i<studentNo;i++){
cout<<bstudent[i].name<<"\t"<<bstudent[i].age<<"\t"<<bstudent[i].reg_no<<"\t\t"<<bstudent[i].
marks<<"\n";
}
}
class MTechStudent : public Student{
float gpa;
public:
void input(){
cout<<"Enter name: ";
cin>>name;
cout<<"Enter Age: ";
cin>>age;
cout<<"Enter Register No: ";
cin>>reg_no;
cout<<"Enter Last CGPA: ";
cin>>gpa;
}
void sort(int studentNo);
};
MTechStudent mstudent[5];
void MTechStudent :: sort(int studentNo){
for(int i = 0;i<studentNo;i++){
MTechStudent temp;
for(int j = i+1;j<studentNo;j++){
if(mstudent[i].gpa > mstudent[j].gpa){
temp = mstudent[i];
mstudent[i] = mstudent[j];
mstudent[j] = temp;
}
if(mstudent[i].gpa == mstudent[j].gpa){
if(mstudent[i].name > mstudent[j].name){
temp = mstudent[i];
mstudent[i] = mstudent[j];
mstudent[j] = temp;
}
}}
}
cout<<"\nName\tAge\tRegister No\tGPA\n";
for(int i = 0;i<studentNo;i++){
cout<<mstudent[i].name<<"\t"<<mstudent[i].age<<"\t"<<mstudent[i].reg_no<<"\t\t"<<mstudent[i
].gpa<<"\n";
}
}
int main(){
int bstudentNo;
cout<<"Enter the Number of Btech Students: ";
cin>>bstudentNo;
for(int i = 0;i<bstudentNo;i++){
cout<<"\nEnter the details of student No: "<<i+1<<"\n";
bstudent[i].input();
cout<<"\n";
}
Student* student = new BTechStudent();
student->sort(bstudentNo);
int mstudentNo;
cout<<"\n\nEnter the Number of Mtech Students: ";
cin>>mstudentNo;
for(int i = 0;i<mstudentNo;i++){
cout<<"Enter the details of student No: "<<i+1<<"\n";
mstudent[i].input();
cout<<"\n";
}
student = new MTechStudent();
student->sort(mstudentNo);
}