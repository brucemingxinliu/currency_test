
#include <ros/ros.h>
#include <example_ros_service/ExampleServiceMsg.h> // this message type is defined in the current package
#include <iostream>
#include <string>
using namespace std;

string month;
int date;
int days;

int main(int argc, char **argv) {
    ros::init(argc, argv, "currency_client");
    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<example_ros_service::ExampleServiceMsg>("lookup_budget");
    example_ros_service::ExampleServiceMsg srv;

    while (ros::ok()) {
        cout<<endl;
        cout << "enter a month (x to quit): ";
        cin>>month;
       
        cout<<endl;
        cout << "enter a date (x to quit): ";
        cin>>date;

        cout<<endl;
        cout << "enter how many days (x to quit): ";
        cin>>days;
        //cout<<"you entered "<<in_name<<endl;
        srv.request.month = month; 
        srv.request.date = date; 
        srv.request.days = days; 
        if (client.call(srv)) {
            

            cout << srv.request.totalcost << "$ is your totalcost" << endl;
            

      
           }
    return 0;
}
