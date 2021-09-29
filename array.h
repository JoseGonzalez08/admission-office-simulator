#include<iomanip>
#include <iostream>
using namespace std;
/********************************************
This function fills the array with data entered from the keyboard.

ar is an array of any data type
n is the number of items entered into ar
********************************************/
template <class T>
void fill(int n , T ar[])
{
  for(int i = 0; i < n; i++ )
    {
      cout << "Enter an item: ";
      cin >> ar[i];
    }
}

/********************************************
This function prints the array.

ar is an array of any data type
n is the number of items in ar
********************************************/
template <class T>
void print(int n, T ar[])
{
  for(int i = 0; i < n; i++ )
    {

      cout << ar[i] << " ";
    }
  cout << endl;
}

/*******************************************
This function returns the index of the highest value.

ar is an array of any data type.
n is the number of items in ar
*******************************************/
template <class T>
int getHighest(int n, T ar[])
{
  int  highIndex = 0;
  for(int i = 0; i < n; i++)
    {
      if(ar[i] > ar[highIndex])
        {
          highIndex = i;

        }

    }
  return highIndex;
  //  cout << "The highest is " << ar[highIndex] << " at " << highIndex << endl;
}



/*******************************************
This function returns the index of the lowest value.

ar is an array of any data type.
n is the number of items in array
*******************************************/
template <class T>
int getLowest(int n, T ar[])
{
  int lowIndex = 0;
  for(int i = 0; i < n; i++)
         {
      if(ar[i] < ar[lowIndex])
        {
          lowIndex = i;

        }

    }
  return lowIndex;
  //cout << "The lowest is " << ar[lowIndex] << " at " << lowIndex << endl;
}

/********************************************
This function returns the average.

ar is an array of any data type.
n is the number of items in ar
********************************************/
template <class T>
double getAvg(int n, T  ar[])
{
  T sum = 0;
  double avg;
  for(int i = 0; i < n; i++)
    {
      sum = sum + ar[i];

    }
     avg = (double)sum/n;
  return avg;
}



/*******************************************
This function stores unique items into an array
and returns the number of the unique items.
  e.g.  If ar contains  9 3 5 3 9 1 9
        uniqAr gets 9 3 5 1
        The function returns 4

ar is the original array of any data type
uniqAr is the array that will have only unique items
n is the number of items in ar and uniqAr
*******************************************/
template <class T>
int unique(const T ar[], T uniqAr[],int n)
{

//uniqAr in the caller will be filled with only unique numbers
  int Num = 0;//this is because we know forsure there will be one unique number
  uniqAr[Num++] = ar[0];
  T temp;//this variable is just to hold a temporary value
  bool f = true;//this is to check if it is true or false

  for(int i = 1; i < n;i++)//this for loop goes through the array and checks each element
    {
      temp = ar[i];//temp is place holder
      for(int u = 0; u < Num && f != false; u++)//this will check the slots in uniqueAr to find the unique numbers
        {
          if(temp == uniqAr[u])// if the number is not unique it will exit and go to else
            {
              f = false;
            }
        }
      if(f == true)// this is stating if the number is unique it will add it into the unique Ar in the next open location
        {
          uniqAr[Num] = temp;
          Num++;// this number will incremenet the number of elements if b == true
        }
      f = true;
    }
  return Num;// this will return the number of elements in the uniqAr
}


/***********************************************
This function sorts the items in ascending order: smallest to largest

array is an array of any data type
N is the number of items in the array
**********************************************/

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//The following function sorts an integer array in ascending order
//using the selection sort algorithm.
//You need to change this code so it works with an array of any data type.
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
template <class T>
void sort(T array[], int N)
{
  int lrgIndx; //the index of the largest value                                                                           \

  T temp; //temporary variable that holds the largest value                                                               \


  //last is the last index in unsorted portion                                                                            \

  for(int last = N-1; last >= 1; last--)
    {
      lrgIndx = 0; //assume the first item is the largest                                                                 \

      //find the largest in unsorted portion ([0..last])                                                                  \

      for(int i = 1; i <= last; i++)
        {
          if(array[i] > array[lrgIndx]) //The current item is larger                                                      \

            lrgIndx = i;
        }

      //swap the largest with the last item in the unsorted portion

      
      temp = array[lrgIndx];
      array[lrgIndx] = array[last];
      array[last] = temp;
    }
}
/*
template <class T>
int find(T ar[],T n, T key)
{
  for(int i = 0; i < n;i++)
    {
      if(ar[i] == key)
        return key;
    }
  return -1;

  }*/
/**********************************************
this function will find a specific element inside of the array or the key of the array and if it finds it then it will ret\
urn that specific key inside of the array if it does not find it then it will return a -1
**********************************************/
template <class T1, class T2>
int find(const T1 ar[],int n, const T2& key)
{
  for(int i = 0; i < n;i++)
    {
      if(ar[i] == key)
        return i;
    }
  return -1;

}
/***********************************************
this function will first find the key of the class or crn number of the student you want to remove their class and if it f\
inds the crn number then it found the key and it will return true  procede to remove that specific key if it odes not it r\
eturns false or error message saying you cannot remove that key because it is not in the array
***********************************************/
template <class T, class T2 >
bool remove(int n, T ar[],const T2& rmKey)
{
  int key = find(ar,n,rmKey);//getting the key of the function or if the id is the same
  if(key != -1)// if the key was not found then we get false
    {
      for(int i = 0; i < n; i++)//this will go through the array and see the class counter
        {
          if(ar[i] == rmKey)//this is saying if the key was found in the array th
            {
              for(int r = key; r < (n-1); r++ )// this will get the index of where the key was found and subtract by one a\
nd start looking from there through array
                ar[r] = ar[r+1];//this will finally shift the index where the key was found
              return true;
            }

        }

    }
  else
    return false;
}
/************************************
this function is a bubblesort so it will check the array in iteratioons basically two pairs of numbers and order them
in decseding order so from largest from the left to the smallest on the right
and it will check to see which number is larger and swap it and order it in deceding order and once the sorting when done \
is true we wioll get out of the  while loop
************************************/
template <class T>
void bubbleSort(T ar[], int n)
{
  bool done = false;//setting done equal to false
  T temp;// to hold a temporary variable
  while(!done)
    {
      done = true;
      for(int i= 0; i < n-1; i++)
        {
          if(ar[i] < ar[i+1])
            {
              temp = ar[i+1];
              ar[i+1] = ar[i];
              ar[i] = temp ;
              done = false;
            }

        }
    }
}