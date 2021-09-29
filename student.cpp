#include "student.h"
#include<iostream>
#include"array.h"
using namespace std;
int student::curStuID = START_STU_ID;
//int student::stuID = curStuID;
//this is the constructor
student::student(string f,string l,char g, int i)//:stuID(curStuID)
{

  curStuID++;
  fN = f;
  lN = l;
  gender = g;
  numClasses = 0;
  stuID = i;
  //  balance = bal;//this is equalling bal  to balance
}
//default constructor
student::student()//:stuID(curStuID()
{
  fN = "unknown";
  lN = "unknown";
  gender = 'x';
  numClasses = 0;
  curStuID++;
  stuID = -1;
}
string student::getFirstName()const
{
  return fN;
}
string student::getLastName()const
{
  return lN;
}
char student::getGender()const
{
  return gender;
}
int student::getNumClasses()const
{

  return  numClasses;
  //  return  print(numClasses,classes);
}
int student::getStuID()const
{
  return stuID;
}
int student::getClassOf(int i)const
{
  return  classes[i];
}
int student::getCurStuID()
{
   return curStuID;
}
Price student::getBalance()const
{
  return balance;
}
void student::addFee(int d, int c)
{
  Price p(d,c);
  balance = balance + p;
}
void student::reduceFee(int d, int c)
{
  Price g(d,c);
  balance = balance - g;
}
/****************************************************************
this will add courses to a specific student and check if the student is already added into that class
and if a student is trying to add the same class more than once it will give them an error
mesage saying they cannot add that class because they already have it added if student is taking maximm number of classes
they cannont add more classes
****************************************************************/
int student::addCourse(int crn)
{
  if(numClasses == MAX)
    {
      //cout << crn << " this class couldnt be added " << fN << endl;
      //      cout << crn << " was not added because " << fN << "schedule is full. " << endl;
       return -1;
      //cout << "the array is already full" << endl;
      //return false;
    }
  else
    {
      int found = find(classes,MAX,crn);//this will go thorugh the array and find the crn/key of the class the user inputt\
ed
      if(found  == -1)// if the key is equal to -1 then you can add the course to the array goes inside of if statement
        {
          //  cout << crn << " has been added successfully to " << fN << endl;
          classes[numClasses] = crn;
          numClasses++;
          return 1;
        }
      else//the course was found and cannot be added ot the array of classes
      {
        //      cout << crn << " was not added because " << fN << " has " << crn << " already" <<  endl;
        return 0;
      }
    }
}
/*

*/
void student::viewAllCourses()
{
  //  cout <<"----- " << fN << " is taking " << " -----" << endl;
   print(numClasses,classes);
}
bool student::dropCourse(int crn)
{
  if(remove(numClasses,classes,crn))
    {
      //  cout << crn << " has been dropped successfully from " << fN << endl;
      numClasses--;
      return true;
    }
  else
    {
      // cout << crn << " Wasnt dropped from " << fN << endl;
      //cout << crn << " wasnt dropped from " << fN << " because " << crn << " doesn't exist" << endl;
      return false;
    }
}  