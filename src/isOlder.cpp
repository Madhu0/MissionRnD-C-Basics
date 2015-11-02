/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int extractYear(char *d1){
	int i,y = 0, dec = 1;
	for (i = 9; i > 5; i--){
		if (d1[i] > 47 && d1[i] < 58){
			y += dec*(d1[i]-'0');
			dec *= 10;
		}
		else
			return -1;
	}
	return y;
}
int monthExtracter(char *d){
	int i, m = 0, dec = 1;
	for (i = 4; i > 2; i--){
		if (d[i] > 47 && d[i] < 58){
			m += dec*(d[i] - '0');
			dec *= 10;
		}
		else
			return -1;
	}
	return m;
}
int dateExtracter(char *d){
	int i, day = 0, dec = 1;
	for (i = 1; i > -1; i--){
		if (d[i] > 47 && d[i] < 58){
			day += dec*(d[i] - '0');
			dec *= 10;
		}
		else
			return -1;
	}
	return day;
}
int validate(int dd, int mm, int yy){
	if (yy < 0 || mm <= 0 || dd <= 0)
		return 0;
	else if (mm>12 || dd>31 || yy>10000)
		return 0;
	else if (mm == 2){
		if (yy % 4 == 0 && yy % 100 != 0 && dd > 29)
			return 0;
		else if (yy % 100 == 0 && yy % 400 == 0 && dd > 29)
			return 0;
		else if (yy % 4 != 0 || (yy % 100 == 0 && yy % 400 != 0)){
			if (dd > 28)
				return 0;
		}
	}
	else if (mm == 4 || mm == 6 || mm == 9 || mm == 11){
		if (dd > 30)
			return 0;
	}
	return 1;
}
int isOlder(char *dob1, char *dob2) {
	int y1, y2, m1, m2, d1, d2,v1,v2;
	y1 = extractYear(dob1);
	y2 = extractYear(dob2);
	m1 = monthExtracter(dob1);
	m2 = monthExtracter(dob2);
	d1 = dateExtracter(dob1);
	d2 = dateExtracter(dob2);
	v1 = validate(d1, m1, y1);
	v2 = validate(d2, m2, y2);
	if (v1 == 0 || v2 == 0)
		return -1;
	if (y1 < y2)
		return 1;
	else if (y1 > y2)
		return 2;
	if (m1 < m2)
		return 1;
	else if (m1 > m2)
		return 2;
	if (d1 < d2)
		return 1;
	else if (d1 > d2)
		return 2;
	return 0;
}
