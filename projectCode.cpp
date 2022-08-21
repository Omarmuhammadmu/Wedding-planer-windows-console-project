/*
Authors: 
        - Omar Muhammad Mustafa AbdelLatif
        - Omar Amr Mahmoud Hafez
*/


#include <iostream>
#include <sstream> //Header providing string stream classes, included so we can use stringstream.
#include <cmath> //Header included to use round function.

using namespace std;

char inp[99]; // universal array for receiving inputs and checking them

class Event
{
 private:
 char EventName[100], CustomerName[100];
 int NumberOfWaiters;
 float FoodCost,EventDuration,GuestCount;
 double CostPerWaiter, TotalCost,DepositAmount;
 public:
 Event ()
 {
 GuestCount=0;
 EventDuration=0;
 NumberOfWaiters=0;
 CostPerWaiter=0;
 FoodCost=0;
 TotalCost=0;
 DepositAmount=0;
 }
 void getEventName();
 void getCustomerName();
 void getGuestCount();
 void getEventDuration();
 void CalcualteCost();
 void PrintInfo();
};
void Event::getEventName()
{
 cout<<"Enter the name of the event\n";
 cin.getline(EventName,100);
}
void Event::getCustomerName()
{
 int x=0; //This var.is used then to check the existence of letters in their ASCII values intervals
 bool terminator=false;//This bool. is used to terminate the loop that checks whether all the input data are characters or not.
 cout<<"Enter the customer's first and last name\n";
 while(true)
 {
 cin.getline(CustomerName,100);
 for(int i=0; CustomerName[i];i++)
 {
 x= CustomerName[i];
 if((x>=65 && x<=90) || (x>=97 && x<=122) || (x==32))
 {
 terminator= false;
 continue;
 }
 else
 {
 terminator= true;
 break;
 }
 }
 if(terminator==true)
 {
 cout<<"Please enter your first and last name separated with a space with no numbers or special characters\n";
 }
 else
 break;
 }
}
void num_check(char line [99],const char disp[50],float &i);
void Event::getGuestCount()
{
 cout<<"Enter the number of guests\n";
 num_check(inp,"Enter the number of guests\n",GuestCount);
 while(GuestCount-(int)(GuestCount)){ // allows only integer inputs
 cout<<"\nPlease enter an integer only\nEnter the number of guests\n";
 cin>>GuestCount;
 num_check(inp,"Enter the number of guests\n",GuestCount);
 }
}
void Event::getEventDuration()
{
 cout<<"Enter the number of minutes in the event\n";
 num_check(inp,"Enter the number of minutes in the event\n",EventDuration);
 EventDuration = round(EventDuration); //the round function is used to ceil or floor the number according to the float.
}
void Event::CalcualteCost()
{ FoodCost= (GuestCount*54.5);
 while (GuestCount>20)
 {
 GuestCount-=20;
 NumberOfWaiters++;
 }
 if(GuestCount>0)
 NumberOfWaiters++;
 if(EventDuration>60)
 while((EventDuration-60)>=0)
 { EventDuration -=60;
 CostPerWaiter+=46.5;
 }
 if(EventDuration<60&&EventDuration>46)
 CostPerWaiter+=46.5;
 else
 CostPerWaiter+=EventDuration;
 TotalCost=(NumberOfWaiters*CostPerWaiter)+FoodCost;
 DepositAmount=TotalCost*0.25;
}
void Event::PrintInfo()
{
 cout<<"\n---------------------------------------------\n";
 cout<< EventName <<" Event\n"<<"Event estimate for "<<CustomerName<<endl;
 cout<<"---------------------------------------------\n";
 cout<<"Number of Waiters: "<<NumberOfWaiters<<endl;
 cout<<"The cost per waiter: "<<CostPerWaiter<<endl;
 cout<<"The cost for Food is: "<<FoodCost<<endl;
 cout<<"Total cost is: "<<TotalCost<<endl;
 cout<<"Please provide a 25% deposit to reserve the event\n"<<"The deposit need is: "<<DepositAmount<<endl;
}
void num_check(char line [99],const char disp[50],float &i) //Checks whether the input is only numbers or not and is greater than zero or not
{
 double d;
 while (cin.getline(line,99)) //The loop is broken once the entire the input(line) could be converted to double and being greater than zero.
 {
 stringstream ss(line); //Using the stringstream so to use eof.
 if (ss >> d) //Extraction Operator(>>) used to display the stringstream data
 {
 if (ss.eof() && atof(line) >0) //eof() End of file:The input sequence has no more characters available
 { i = atof(line); //atof converts a C-type string, passed as an argument to function call, to double.
 break;
 }
 }
 cout << "Please enter a number greater than zero \n";
 for (int j=0;disp[j];j++)
 cout<<disp[j];
 }
 }
int main()
{
 Event E1;
 E1.getEventName();
 E1.getCustomerName();
 E1.getGuestCount();
 E1.getEventDuration();
 E1.CalcualteCost();
 E1.PrintInfo();
 return 0;
 }
