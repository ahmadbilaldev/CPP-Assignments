# Date Calculator Class

Implement a date and day of week calculator for the 2019 calendar year.

## Details

> Class specified in the following. The second component is a driver program that uses the date2019 class to realize the calculator.

> The date2019 class should have two private data members of the int type, d and m with m encoding the month (1 – January, 2-February, …) and d being the day in the month. For example to represent April 5, d = 5, m = 4. To represent a date not in 2019,  m=-1, d=-1.

> The default constructor date2019() should set the default date of the object to be January 1, 2019. The parameter for the constructor with 1 parameter date2019(int dd) ranges from 1 to 365 (the code should report error and exit if the parameter is not in the range) and is  day of year for the date in 2019. The constructor converts day of year to month and day of month. For example the 70th day of the year is March 11: the constructor should make m =3 and d = 11 when date2019(70) is invoked.

> For the two parameter constructor date2019(int dd, int mm), you just need to make sure that month (mm) and day (dd) are legitimate and set d = dd, and m = dd.  If either the day or the month is not legitimate, the code should report error and exit. Setdate is similar to the two parameter constructor.

> The plusday(int days) function modifies the m and d for the new date, which is days after the current date.
