#include<string>
#include"price.h"
using namespace std;

const int MAX  = 6;
const int START_STU_ID = 100000;

class student
{
 private:
  /*const*/ int stuID;//initializing stuID as a constant data member
  static int curStuID;//initializing a static data member named curStuID the current student ID
  string fN;//first name
  string lN;//the last name
  char gender;// gender
  int numClasses ;//totsl number of classes student is enrolled in
  int classes[MAX];//holds the course numbers
  Price balance;

 public:
  student(string f,string l,char g, int i);
  student();
  string getFirstName()const;
  string getLastName()const;
  char getGender()const;
  int getNumClasses()const;
  int getStuID()const;
  int addCourse(int crn);
  void viewAllCourses();
  bool dropCourse(int crn);
  int getClassOf(int i)const;
  static int getCurStuID();
  Price getBalance()const;
  void addFee(int d, int c);
  void reduceFee(int d, int c);
};