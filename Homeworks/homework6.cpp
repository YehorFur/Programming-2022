#include <iostream>

using namespace std;

enum Month {
	NONE,
	JANUARY,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
};

string firstlet(string str){
	string fp;
	for(int i=0; i<3; i++){
		fp+=tolower(str[i]);
	}
	return fp;
}

Month strTMonth(string str){
	string first=firstlet(str);
	if (first=="jan") return JANUARY;
	else if(first=="feb") return FEBRUARY;
	else if(first=="mar") return MARCH;
	else if(first=="apr") return APRIL;
	else if(first=="may") return MAY;
	else if(first=="jun") return JUNE;
	else if(first=="jul") return JULY;
	else if(first=="aug") return AUGUST;
	else if(first=="sep") return SEPTEMBER;
	else if(first=="oct") return OCTOBER;
	else if(first=="nov") return NOVEMBER;
	else if(first=="dec") return DECEMBER;
}

string monthTStr(Month month){
	if(month==JANUARY) return "January";
	else if(month==FEBRUARY) return "February";
	else if(month==MARCH) return "March";
	else if(month==APRIL) return "April";
	else if(month==MAY) return "May";
	else if(month==JUNE) return "June";
	else if(month==JULY) return "July";
	else if(month==AUGUST) return "August";
	else if(month==SEPTEMBER) return "September";
	else if(month==OCTOBER) return "October";
	else if(month==NOVEMBER) return "November";
	else if(month==DECEMBER) return "December";
}

void printPairs(Month* mon, int n)
{
	Month* ar=new Month[n];
	int t=0;
	bool flag=true;
	int k=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(mon[i]==ar[j]){
				flag=false;
			}
		}
		if(flag){
			ar[k]=mon[i];
			k++;
		}
		flag=true;

	}

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(ar[i]==mon[j]){
				t++;
			}
		}
		if(t!=0){
			cout<<monthTStr(ar[i])<<"-"<<t<<endl;
		}
		t=0;
	}
}


struct Date {
	unsigned int day;
	Month month;
	unsigned int year;

	void df(){
		if(day>31){
			day=31;
		}
		else if(day<1){
			day=1;
		}
	}
	int cmp(Date q){
		long long sum1=(year-1)*365+(month-1)*31+day;
		long long sum2=(q.year-1)*365+(q.month-1)*31+q.day;
		return abs(sum1-sum2);
	}

};

int main()
{
	int n;
	cin>>n;

	Date* qwe=new Date[n];

	for (int i=0; i<n; i++){
		Date date;
		string input;
		int day;
		cout<<"Enter date"<<endl;
		cin>>date.day>>input>>date.year;
		date.month=strTMonth(input);
		date.df();
		qwe[i]=date;
	}

	Date date;
	string input;
	int day;
	cout<<"Enter current date"<<endl;
	cin>>date.day>>input>>date.year;
	date.month=strTMonth(input);
	date.df();
	Date mind=qwe[0];
	for (int i=0; i<n; i++){
		if (mind.cmp(date)>date.cmp(qwe[i])){
			mind=qwe[i];
		}
	}
	cout<<mind.day<<' '<<monthTStr(mind.month)<<' '<<mind.year;

	return 0;
}
