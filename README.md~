This is a ros_service and ros_client pair using service messages and ros as API for communication written in C++.

The algorithm set up for the task is simple.

First from the date given by the user, I check which month it is and find the corresponding days of that month. Then from the date, I deduct the remaining days left in the month and calculate the cost of theses remaining days. Then, I go through a loop for the rest of the days starting from the next month from that of the user's input until the days equal to zero.

The dynamic pricing is changed every week, and the user only purchases on the week days. Therefore, to find the cost, I use the current price times the days he purchases in that week then add the cost from the last week. This interation ends in the end of the month, and when iterate to the next month, I then set the whichmonth to one when the iteration is over. 
