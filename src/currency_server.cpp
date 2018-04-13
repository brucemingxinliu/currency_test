// Mingxin Liu (Bruce)



#include <ros/ros.h>
#include <iostream>
#include <string>

using namespace std;

int days1 = 0;
int days2 = 0;
double price = 0;
double price1 = 0.05;
double price2 = 0.10;
double price3 = 0.15;
double price4 = 0.20;
double price5 = 0.25;
int date = 0; //initializing the date for month and date.
bool check = false;
int totalcost = 0;
int cost = 0;
int i;
string months[] = {"jan", "feb", "mar", "apl"}; //unfinished...all the way till decemeber 
double month_index[4] = {31,27,31,30,31,30,31,30,31,30,31,30}; 
int whichmonth;

int callback(currency_server::ServiceMsgRequest& request, currency_server::ServiceMsgResponse& response)
{
    ROS_INFO("callback activated");
   while(check = false){

        string month(request.month);
        date = request.date; // the date of the month of the input
        days = request.days; // api getting the user requests through a service message

        for(i = 0; i < 3; i++){ // iteration for i also needs to change to 12 month
        if(month.compare(months[i] == 0)){
        ROS_INFO(i,"is the month"); // this tells us the current month of the date input
        whichmonth = i + 1;
        return whichmonth;
        }

        }

        days1 = month_index[whichmonth] - date; // this shows how many days are left in the month of input
        
        while(days1>=0){  //summing up the cost of the days left in the first month

        if(days1<=5){
          cost = days1 * price1;

        }

        if(7<=days1 && days1<= 12){
            cost = 5 * price1 + (days1 - 7) * price2;


           }

        if(14<=days1 && days1<= 19){
             cost = 5 * price1 + 5 * price2 + (days1 -14) * price3;


            }
        if(21<=days1 && days1<= 28){
           cost = 5 * price1 + 5 * price2 + 5 * price3 + (days1-21) * price4;
            }

         if(days1>=28){
            cost = 5 * price1 + 5 * price2 + 5 * price3 + 5 * price4 + (days1 - 28) * price5;

         }

          totalcost = totalcost + cost;
             


        }


        while(days>=0){ //summing up the cost of the rest of the days.

        if(days<=5){
          cost = days * price1;

        }

        if(7<=days && days<= 12){
            cost = 5 * price1 + (days - 7) * price2;


           }

        if(14<=days && days<= 19){
             cost = 5 * price1 + 5 * price2 + (days -14) * price3;


            }
        if(21<=days && days<= 28){
           cost = 5 * price1 + 5 * price2 + 5 * price3 + (days-21) * price4;
            }

         if(days>=28){
            cost = 5 * price1 + 5 * price2 + 5 * price3 + 5 * price4 + (days - 28) * price5;

         }

          totalcost = totalcost + cost;
             

        days = days - month_index[whichmonth];
        whichmonth = whichmonth + 1;
        if(whichmonth>=12){
           whichmonth = 1;
        }

        }
        return totalcost;

}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "currency_service");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("lookup_budegt", callback);
  ROS_INFO("Ready to lookup_budegt.");
  ros::spin();

  return 0;
}