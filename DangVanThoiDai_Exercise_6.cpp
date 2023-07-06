#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Time{
	private:
    	int hour;
    	int minute;

	public:
    	// Ham tao mac dinh
    	Time(){
        	hour = 0;
        	minute = 0;
    	}

    	// Ham tao voi tham so
    	Time(int h, int m){
    	    hour = h;
    	    minute = m;
    	}

    	// Ham tao sao chep
    	Time(const Time& other){
    	    hour = other.hour;
    	    minute = other.minute;
    	}

    	// Ham huy
    	~Time(){
		
		}

    	// Toan tu gan =
    	Time& operator = (Time& other){
    	    if (this != &other){
    	        hour = other.hour;
    	        minute = other.minute;
    	    }
    	    return *this;
    	}

    	// Toan tu so sanh ==
    	bool operator == (Time& other){
    	    return hour == other.hour && minute == other.minute;
    	}

    	// Toan tu nhap
    	friend istream& operator>>(istream& is, Time& t){
    	    is>>t.hour>>t.minute;
    	    return is;
    	}

    	// Toan ta xuat
    	friend ostream& operator<<(ostream& os, const Time& t){
    	    os<<t.hour<<":"<<t.minute;
    	    return os;
    	}

    	// Toan tu cong +
    	Time &operator + (Time& other){
    	    Time result;
    	    result.hour = hour + other.hour;
    	    result.minute = minute + other.minute;
    	    if(result.minute >= 60){
    	        result.hour++;
    	        result.minute -= 60;
    	    }
    	    return result;
    	}

    	// Toan tu tru -
    	Time &operator - (Time& other){
    	    Time result;
    	    result.hour = hour - other.hour;
    	    result.minute = minute - other.minute;
    	    if(result.minute < 0){
    	        result.hour--;
    	        result.minute += 60;
    	    }
    	    return result;
    	}

    	// Ham cong
    	void cong(Time& other){
    	    hour += other.hour;
    	    minute += other.minute;
    	    if (minute >= 60){
    	        hour++;
    	        minute -= 60;
    	    }
    	}

    	// Ham tru
    	void tru(Time& other){
    	    hour -= other.hour;
    	    minute -= other.minute;
    	    if(minute < 0){
    	        hour--;
    	        minute += 60;
    	    }
    	}
    	
    	//Ham nhap
    	void Nhap(){
    		cout<<"Nhap hour: "; cin>>hour;
    		cout<<"Nhap minute: "; cin>>minute;
		}
		
		//Ham Xuat
		void Xuat(){
			cout<<"Hour: "<<hour<<endl;
			cout<<"Minute: "<<minute<<endl;
		}
};

int main(){
    Time t1(11, 30);
    Time t2(2, 55);

    Time t3 = t1 + t2;
    Time t4 = t1 - t2;

    cout<<"t1: "<<t1<<endl;
    cout<<"t2: "<<t2<<endl;
    cout<<"t1 + t2: "<<t3<<endl;
    cout<<"t1 - t2: "<<t4<< endl;

    return 0;
}

