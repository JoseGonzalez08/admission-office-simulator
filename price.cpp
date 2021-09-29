#include"price.h"
Price::Price()
{
  dollar = 0;
  cent = 0;
}
Price::Price(int d, int c)
{
  dollar = d;
  cent = c;
}
ostream& operator<<(ostream& o, const Price& m)
{
  /*
  if(m.dollar == 0)
    o << m.cent;
  else if(m.cent > 0 )
    o << m.dollar<< "." << m.cent;
  */
  if(m.cent < 10)
    {
      o << m.dollar<< ".0" << m.cent;
    }
  else
    o << m.dollar << "." << m.cent;
  return o;

}
/************************************************
this operator overloading function adds p1
and p2 by calling the object of p1 as a reference by using this ->
the we call the class price and set new object which in this case is g
to store the addition
of the dollars and cents and return the object of g with the answer
***********************************************/
Price Price::operator+(const Price& p2)
{
  int d;
  int dolr = 0;
  //dolr = this-> dollar + p2.dollar;//this would p1 and p2 the dollars
  int cnt = this-> cent + p2.cent;// this adds p1 and p2 but the cents
  if(cnt >= 100)
    {
      dolr += 1;
      cnt -= 100;
    }
  d = this-> dollar + p2.dollar + dolr;//this would p1 and p2 the dollars and adding the dolr because the cents went over \
100
  Price g(d,cnt);//new object if g holds whatever the two added numbers were for dollars and cents
  return g;
}
/************************************************
this operator overloading function subtracts p1
and p2 by calling the object of p1 as a reference by using this ->
the we call the class price and set new object which in this case is g
to store the subtraction
of the dollars and cents and return the object of g with the answer
***********************************************/
Price Price::operator-(const Price& p2)
{
  int d;//this will hold the value of dollar
  int dolr = 0;//this is setting dollar equal to zero for when we add the dollars together
  int cnt = this-> cent - p2.cent;
  if(cnt < 0)
    {
      cnt += 100;//adding 100 to cent because the cent is negative
      dolr += 1;//extra dollar that will be added to the dollars
    }
  d = this-> dollar - p2.dollar - dolr;//this would p1 and p2 the dollars subtracting the dollar because it went under 0
  Price g(d,cnt);//new object if g holds whatever the two added numbers were for do\llars and cents
  return g;
}