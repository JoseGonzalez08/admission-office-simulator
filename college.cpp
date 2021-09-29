
#include <iostream>
#include <cstdlib> //for atoi() <-- you might not use this
using namespace std;
#include"checkInput.h"
#include"student.h"
#include"array.h"
#include"price.h"
#include<fstream>
const int SIZE = 100; //size of the array
const int START = 100000;//student id starts at 100000
const int PASSWORD = 123; //password for admission's office
const int PRIME1 = 31; //used to calculate a student's password
const int PRIME2 = 5;
//PROTOTYPES
int showMenu();
int showAdmMenu();
int showStuMenu();
void showStuInfo(const student& g);
void addStu(student ar[],int& count,int& curID);
void allStuInfo(const student ar[], int c);
bool operator==(const student& s, int id);
void removeStu(student ar[],int& c);
void addStuFromFile(student ar[],int& c, int& curID);
void addCourse(student& s);
void dropCourse(student& s);
void makePayment(student& s);
int main()
{
  int count = 0; //the number of students in the array
  int curID = START; //curID is the student id used for the next student you are creating
  student stuAR[SIZE];//creating an object array for students class and setting the array size to SIZE
  int index = 0;//this wil hold the index of the student we want to find
  int choice;//this will hold the choice of what we want to check either admin or the student or end the program
  int password;//this will hold the password answer which should be 123 but the user eneters what they think it is
  int findId;//this variable will be used to find the student ID

  do{//this do while loop will keep going until choice is 3
    choice = showMenu();//this will show the menu and choice will hold the value of showmenu choicse
    if(choice == 1)//if choice is 1
     {
        cout << "Enter your password: ";
        cin>>password;//ask user to enter the admin password which is 123

        if(password == 123)//if they enter the correct passwor which is 123
          {

            int adminC;//admins choice                                                                                 \

            while(adminC != 6)//keep showing the admin menu until we click quit which is 6
              {
                adminC = showAdmMenu();//storing the choice of show menu into adminc or admin choice
                //this switch statement is used to call seperate functions from the showAdmMenu()
                switch(adminC)
                  {
                  case 1:
                    addStu(stuAR,count,curID);//adding a student to class
                    break;
                  case 2:
                    addStuFromFile(stuAR,count,curID);//adding the students from the file college.dat
                    break;
                  case 3:
                    removeStu(stuAR,count);//removing a student from the class
                    break;
                  case 4:
                    cout << "Enter the student ID: ";
                    cin >> index;
                    findId = find(stuAR,count,index);//finding the student with that ID in the stuAR
                    if(findId == -1)
                      cout << "The student ID doesn't exist" << endl << endl;
                    else
                      showStuInfo(stuAR[findId]);//this function will show the specific students info that the id is assoc\
iated with
                    break;
                  case 5:
                    allStuInfo(stuAR,count);//displaying all of the students that are in the array
                    break;
                  default:
                    cout << endl;
                  }
              }
          }
        else
          {
            cout << "Wrong password. " << endl << endl;//display message if the password was incorrect
          }

      }
    else if(choice == 2)//IF choice is 2
      {
        int studentID;//this variable will hold the students ID
        int password2;//this is holding the password for the student
        int studentC;//choice for the student
        cout << "Enter the student id: ";
        cin >> studentID;//asking user to enter the students id they want to see or go into
        int found = find(stuAR,count,studentID);//setting found to this find function because it will return the index of \
that student
        if(found == -1)//if the student id does not exist
          cout << "The student ID doesnt exist. " << endl << endl;
        else
          {//if the student id does exist
            cout << "Enter the password: ";
            cin >> password2;//asking user to enter the password for the student depending on what their id is
            int student_ID = stuAR[found].getStuID();//student_ID will hold the students id
            student_ID = student_ID % (PRIME1 *PRIME2);//here we will get the students password and store it inside of stu\
dent_ID
            if(password2 == student_ID)//if the password  is not equal to student_id then we show an error message
              {
                cout << "The password is wrong. " << endl << endl;
              }


            else//(password2 == student_ID) if the password and student_id match then we do the following
              {
                int crn;//the crn that we wan to add
                int crnD;//the crn that we wanna drop
                cout << "Welcome " << stuAR[found].getFirstName() << endl;//welcoming the student with that ID and welcomi\
ng him with output of his first name
                while(studentC != 5)//we cant exit this while loop till the menu option 5 is chosen
                  {
                    studentC = showStuMenu();//storing the value from showStuMenu into studentC or student Choice
                    //this switch statement is used to call seperate functions from the showStuMenu()
                    switch(studentC)
                      {
                      case 1:
                        addCourse(stuAR[found]);//this function will add a course to the student
                        break;
                      case 2:
                        dropCourse(stuAR[found]);//this function will droop a course to the student that is modifying his \
schedule
                        break;
                      case 3:
                        makePayment(stuAR[found]);//this function allows the student to make a payment on his account depe\
nding on how many classes he is taing
                        break;
                      case 4:
                        showStuInfo(stuAR[found]);//this will show all of the students information about that specific stu\
dent
                        break;
                      }
                  }
              }
          }
      }
  }while(choice != 3);//if the choice is 3 the program ends

        return 0;
}
/******************************************************************
this function will show the menu and ask user to enter their choice
choice - integer that will be returned to main
*********************************************************************/
int showMenu()
{
  int choice;
  cout << "========================================================" << endl;
  cout << "1: Admission's Office" << endl;
  cout << "2: Student" << endl;
  cout << "3: End program" << endl;
  cout << "========================================================" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 3, "\tInvalid choice. Enter only 1, 2 or 3: ");

  return choice;
}

/**********************************************************************
this function will show the menu for the students to pick and it returns their choice
choice - integer that will be returned to main
*************************************************************************/
int showStuMenu()
{
  int choice;

  cout << endl;
  cout << "***************************" << endl;
  cout << "1: Add a course" << endl;
  cout << "2: drop a course" << endl;
  cout << "3: Make a payment" << endl;
  cout << "4: View my information" << endl;
  cout << "5: Quit" << endl;
  cout << "***************************" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 5, "\tInvalid choice. Enter only 1 through 5: ");

  return choice;
}
/**********************************************************************
this function shows the admin menu and asks them to enter a choice and it returns
their choice
choice - integer that will be returned to main
**********************************************************************/
int showAdmMenu()
{
  int choice;

  cout << endl;
  cout << "***************************" << endl;
  cout << "1: Add a new student" << endl;
  cout << "2: Add new students from a file" << endl;
  cout << "3: drop a student" << endl;
  cout << "4: View one student info" << endl;
  cout << "5: View all students' info" << endl;
  cout << "6: Quit" << endl;
  cout << "***************************" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 6, "\tInvalid choice. Enter only 1 through 6: ");

  return choice;
}
/***********************************************************************
this function will add a student into the student array by asking the user
to enter the students first name last name and gender and it will give them
an their curID number and be added into the array

firstN-this string holds the users input for their first name
lastN-this string holds the users input for the users last name
gender-this char holds the users gender inputted from user
**********************************************************************/
void addStu(student ar[],int& count,int& curID)
{
  string firstN;//variable for first name
  string lastN;//variable for last name
  char gender;//variable for gender
  if(count == SIZE)
    cout << "the max amount of students enrolled "<< endl;
  else
    {
      cout << "Enter the first name: ";
      cin >> firstN;
      cout << "enter the last name: ";
      cin >> lastN;
      cout << "enter the gender: ";
      cin >> gender;

      //create a student object
      student s(firstN,lastN,gender,curID);

      //copy the info from the stu obj into the array at the appropriate slot
      ar[count] = s;
      count++;//incrementing count
      curID++;//incrementing curID

    }

}
/*********************************************************************
DO NOT send the entire array to this function. BIG deduction if you do.
SEND only ONE student object as a parameter. If you don't know how, check
lab1-struct.cpp.
**********************************************************************/
/***********************************************************************
this function will print or show one of the students information onto the screen
depending on what student you pick from the array
**********************************************************************/
void showStuInfo(const student& g)
{
  //ouput all of students information
  cout << "--------------------" << endl;                                                                                 \

  cout << "first name: " << g.getFirstName()  << endl;
  cout << "last name: " << g.getLastName()  << endl;
  cout << "gender: " << g.getGender() << endl;
  cout << "stu id: " << g.getStuID() << endl;
  cout << "num classes: " << g.getNumClasses()  << endl;
  cout << "Courses: ";                                                                                                    \


  for(int i = 0; i < g.getNumClasses(); i++)  //Don't use showAllCourses() but show each course at a time. Which memeber f\
unction shows one course?
    {
      cout << g.getClassOf(i)  << ", ";//this will output the number of classes
    }
  cout << "\nAmount owed $" << g.getBalance()  << endl;  //You have an operator overloading function to show a price objec\
t at once
  cout << endl;                                                                                                           \


}
/**********************************************************************
this function will output all of the students information
depending on how many students are inside of the  array

**********************************************************************/
void allStuInfo(const student ar[], int c)                                                                                \

{                                                                                                                         \

  //Case 5 of Admission and case 4 of student                                                                             \

  //Call showStuInfo()                                                                                                    \

  //******************************************                                                                            \

  //YOU MUST call showStuInfo() to show each student.                                                                     \

  for(int i = 0; i < c; i++)//this will go through array and print all of the students infor inside of the student array
    {
      showStuInfo(ar[i]);
    }

  //*******************************************                                                                           \

                                                                                                                          \

}
/**********************************************************************
this function will remove a student from the student array depending on the
student id we enter if the student id exists the we this function will find
that id and once it does it will remove that student from the student array
and confirm what student was removed successfully from the array

deleteID - this int hold the spot in the array that has that id that we want to delete
found - this will store the number or the id that was found and store it in variable found
**********************************************************************/
void removeStu(student ar[],int& c)
{
  int deleteID;//the spot that will be remove
  int found;//int that will hold if id was found

  cout << "Enter the student id: ";//ask for user to enter id
  cin >> deleteID;
  found = find(ar,c,deleteID);//seeing if that id exist

  if(found == -1)//if id was not found we will give a message
    cout << "student with id doesn't exist " <<  endl;
  else//if the id was found we will remove that student from the array
    {
      cout << ar[found].getFirstName() << " " << ar[found].getLastName() << " has been removed: " << endl;
      remove(c,ar,deleteID);
      c--;//decrementing the counter because a student was removed
    }
}
/**********************************************************************
this function will read a file that has a certain amount of students and
we would add them into the student array and output them to see if they got added successfully
 **********************************************************************/
void addStuFromFile(student ar[],int& c, int& curID)                                                                      \

{
  //Case 2 of admission

  ifstream fin;
  string filename;
  string firstN;//variable for first name                                                                                 \

  string lastN;//variable for last name                                                                                   \

  char gender;//variable for gender
  cout << "Enter a file name: ";
  cin >> filename;

  fin.open(filename.c_str());

  if(!fin)
    {
      cout << filename << " input file does not exist" << endl;
    }
  else
    {
      fin >>  firstN;
      fin >> lastN;
      fin >> gender;
      while(fin)
        {
          if(c == SIZE)
            {
              cout << "the student array is full";
            }
           else
            {

              //create a student object                                                                                   \

              student s(firstN,lastN,gender,curID);

              //copy the info from the stu obj into the array at the appropriate slot                                     \

              ar[c] = s;
              c++;//incrementing count                                                                                    \

              curID++;//incrementing curID
              fin >>  firstN;
              fin >> lastN;
              fin >> gender;
            }
        }
    }
  fin.close();
}
bool operator==(const student& s, int id )
{
  if(s.getStuID() == id)
    return true;
  else
    return false;
}
/*********************************************
This function will add a course to a specific student that we choose in the main and
charge the student the fee of the class if it was added successfully to the student
it will also give an error message if the student tries to add a class he already has
or if he tries to add a class even though he already has the maximum amount of classes
a student can have

int crn - this holds the value of the course number user inputs
int add - is equal to what is returned from the addcourse()function in student.cpp
 *******************************************/
void addCourse(student& s)
{                                                                                                                         \
                            //case 1 of student
  int crn;//this holds the value of the course number user inputs
  cout << "Enter a crn: ";
  cin >> crn;

  //  s.addCourse(crn);
  int add = s.addCourse(crn);//is equal to what is returned from the addcourse()function in student.cpp

  if(add == 1)//if from the function add is equal to one we add a class to the student
    {
      s.addFee(50,14);//add a fee because the class was successfully added to the student
      cout << crn <<  " has been added successfully" << endl;
    }
  else if(add == 0)//this means that the student already has this class and could not be added agian
    cout << crn << " was not added because you have " << crn << " already." <<  endl;
  else
    cout << crn << " was not added because your schedule is full." << endl;//student already has the limit to how many cla\
sses he can have

}
/**********************************************
this function will drop a course from a student depending on the specified course
number the user inputs and we will drop the course if the user is taking that course
and we will give a message saying it was successful and reduce the fee of the class to the student
but if the user is not taking the coursewe will give an error message to the user
saying that class could not be dropped because the student is not taking that specified class

int crn - this holds the value of the course number user inputs
int remove - is equal to what is returned from the dropCourse()function in student.cpp
**********************************************/
void dropCourse(student& s)
{                                                                                                                         \

  //case 2 of admission                                                                                                   \

  int crn;//this holds the value of the course number user inputs
  cout << "Enter a crn: ";
  cin >> crn;

  int remove = s.dropCourse(crn);//is equal to what is returned from the dropCourse()function in student.cpp

   if(remove == false)//if remove is false we will give an error message saying we could not drop the course
    cout << crn << " wasn't dropped from " << s.getFirstName() << " because " << crn << " doesn't exist" << endl;
  else//we could drop the course and so we give message saying we drop the course and reduce the students fee by $50.14
    {
      s.reduceFee(50,14);//reduce the fee because the class was successfully dropped from
      cout << crn << " has been dropped successfully." << endl;
    }
  }
/***********************************************
this function will allow the students to make a payment towards their fee or,
 how much they owe depending on how many classes they are taking and lets them
make a payment to reduce the amount they owe

int d - variable for dollars                                                                                              \

int c - variable for cents
***********************************************/
void makePayment(student& s)                                                    
{                                          
  int d;//variable for dollars
  int c;//variable for cents
  //case 3 of student                                                                                                     \

  cout << "you owe $" << s.getBalance() << endl;//shows how much student owes
  cout << "Enter your payment: ";
  cin >> d >> c;//user input how much he would like to pay

   s.reduceFee(d,c);//we reduce the fee of the student depending on how much he wants to pay
}