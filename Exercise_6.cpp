#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Time{
	private:
		int hour;
		int minute;
	public:
		
		// H�m tao mac dinh
    	Time() {
        	hour = 0;
        	minute = 0;
    	}

    	// H�m tao voi tham so
    	Time(int h, int m) {
        	hour = h;
        	minute = m;
    	}
		
		//Ham tao sao chep
    	Time(Time& other){
        hour = other.hour;
        minute = other.minute;
    	}
		
		~Time(){
			
		}
		
		// To�n tu g�n =
    	Time& operator=(const Time& other) {
        if (this != &other) {
            hour = other.hour;
            minute = other.minute;
        }
        return *this;
    	}

    	// To�n tu so s�nh ==
    	bool operator==(const Time& other) const {
        return hour == other.hour && minute == other.minute;
    	}
    	
    	friend istream &operator>>(istream &is, Time &t){ //Nap chong ham nhap
			is >> t.hour >> t.minute;
			return is;
 		}
		
		friend ostream &operator>>(ostream &os, Time &x){ //Nap chong ham Xuat
		os << x.hour << ":" << x.minute;
			return os;
 		}
 		
 		// To�n tu cong +
    	Time operator+(const Time& other) const {
        Time result;
        result.hour = hour + other.hour;
        result.minute = minute + other.minute;
        if (result.minute >= 60) {
            result.hour++;
            result.minute -= 60;
        }
        return result;
    	}

    	// To�n tu tru -
    	Time operator-(const Time& other) const {
        Time result;
        result.hour = hour - other.hour;
        result.minute = minute - other.minute;
        if (result.minute < 0) {
            result.hour--;
            result.minute += 60;
        }
        return result;
    	}

    	// H�m cong
    	void add(const Time& other) {
        hour += other.hour;
        minute += other.minute;
        if (minute >= 60) {
            hour++;
            minute -= 60;
        	}
    	}
	
    	// H�m tru
    	void subtract(const Time& other) {
        hour -= other.hour;
        minute -= other.minute;
        if (minute < 0) {
            hour--;
            minute += 60;
        	}
    	}
		
};

int main(){
	Time t1(10, 30);
    Time t2(2, 45);

    Time t3 = t1 + t2;
    Time t4 = t1 - t2;

   	cout<<"t1: "<<t1<<endl;
    cout<<"t2: "<<t2<<endl;
    cout<<"t1 + t2: "<<t3<<endl;
    cout<<"t1 - t2: "<<t4<<endl;
	return 0;
}

