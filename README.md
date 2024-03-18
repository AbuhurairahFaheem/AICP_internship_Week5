AICP Internship Task Week 5


Artificial Intelligence
--Evolution to Revolution--

A frequent parking number can be entered for discounted parking. This number consists of 4
digits and a check digit that is calculated using a modulo 11 check digit calculation. A discount of
50% is available for arrival times from 16:00 to Midnight; the discount is 10% at all other arrival
times.
Write and test a program or program to simulate the car park payment system.
Your program or programs must include appropriate prompts for the entry of data; data
must be validated on entry.
Error messages and other outputs need to be set out clearly and understandably.
All variables, constants, and other identifiers must have meaningful names.
You will need to complete these three tasks. Each task must be fully tested.
__________________________________________________________________________________________
Task 1 – Calculating the price to park.
A customer inputs the day, the hour of arrival excluding minutes (for example 15:45 would be
15), the number of hours to leave their car, and a frequent parking number if available. If the
frequent parking number has an incorrect check digit, then no discount can be applied. The
price to park, based on the day, the hour of arrival, the number of hours of parking required
and any discount available, is calculated and displayed.
_______________________________________________________________________________________________
Task 2 – Keeping a total of the payments.
Extend Task 1 to keep a daily total of payments made for parking. The daily total is zeroed at the
start of the day. For the simulation, each customer inputs the amount paid, this must be greater
than or equal to the amount displayed. There is no change given so the amount input may
exceed the amount displayed. Each customer payment is added to the daily total, and this total
is displayed at the end of the day.
_____________________________________________________________________________________________________-
Task 3 – Making payments fairer.
Customers have complained that sometimes they are being charged too much if they arrive
before 16:00 and depart after 16:00. Extend Task 1 to calculate the price before 16:00, then add
the evening charge. For example, a customer arriving at 14:45 on a Sunday and parking for five
hours was previously charged 10.00 and would now be charged 6.00
