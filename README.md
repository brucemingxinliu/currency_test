This is a ros_service and ros_client pair using service messages and ros as API for communication written in C++.

The algorithm set up for the task is simple.

First from the date given by the user, I check which month it is and find the corresponding days of that month. Then from the date, I deduct the remaining days left in the month and calculate the cost of theses remaining days. Then, I go through a loop for the rest of the days starting from the next month from that of the user's input until the days equal to zero.

The dynamic pricing is changed every week, and the user only purchases on the week days. Therefore, to find the cost, I use the current price times the days he purchases in that week then add the cost from the last week. This interation ends in the end of the month, and when iterate to the next month, I then set the whichmonth to one when the iteration is over. 

The question was done in both C++ and JavaScript.

question:

    Design and build a microservice (no need for UI or DB storage) that contains one REST API endpoint. This endpoint should:
        Receive requests containing the following inputs: startDate (in the format of MM/DD/YYYY) and numberOfDays.
        Respond with the following outputs: totalCost.
    The endpoint will determine the output by solving this “Bob’s Banana Budget” problem:
        Every day, Bob buys a banana from the same grocery store on his way to work. At this grocery store, bananas are priced in a dynamic, yet predictable way: the first 7 days of the month, bananas cost $0.05; the second 7 days of the month, bananas cost $0.10; the third 7 days of the month, bananas cost $0.15; the fourth 7 days of the month, bananas cost $0.20; and any remaining days of the month after that, bananas cost $0.25.
        Bob wants a tool built that will allow him to budget properly for any span of time. All he should need to do is provide the date for the calculation to begin and how many days to calculate (including the beginning date), and the tool should tell him how much he’ll spend during that time.
        NOTE: Bob only buys bananas on his work days. You can assume he works a typical Monday-Friday work week.


