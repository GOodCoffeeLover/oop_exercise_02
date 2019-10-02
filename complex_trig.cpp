#include<iostream>
#include"complex_trig.h"
#include<cmath>
Complex_Trig::Complex_Trig(double R, double Fi){
	if(R>=0) _r=R; else std::cerr<<"Модлуь числа меньше нуля."<<std::endl; 
	while(Fi>=2*M_PI) Fi-=2*M_PI;
	while(Fi<0) Fi+=2*M_PI;
	if(R==0)_fi=0; else _fi=Fi;
}
Complex_Trig::Complex_Trig(){
	_r=0;
	_fi=0;

}
Complex_Trig operator + (const Complex_Trig& a, const Complex_Trig& b){
	Complex_Trig c;
	c._r=(double) sqrt((a._r*cos(a._fi)+b._r*cos(b._fi))*(a._r*cos(a._fi)+b._r*cos(b._fi)) + (a._r*sin(a._fi)+b._r*sin(b._fi))*(a._r*sin(a._fi)+b._r*sin(b._fi)));
	if(c._r>0){ 
		c._fi=acos((a._r*cos(a._fi)+b._r*cos(b._fi))/c._r);
		if(a._r*sin(a._fi)+b._r*sin(b._fi)<0) c._fi=2*M_PI-c._fi;
	}else{ c._r=0; c._fi=0; }
	return c;
}
Complex_Trig operator - (const Complex_Trig& a, const Complex_Trig& b){
	Complex_Trig c;
	c._r=(double) sqrt((a._r*cos(a._fi)-b._r*cos(b._fi))*(a._r*cos(a._fi)-b._r*cos(b._fi)) + (a._r*sin(a._fi)-b._r*sin(b._fi))*(a._r*sin(a._fi)-b._r*sin(b._fi)));
	if(c._r>0){	
		c._fi=acos((a._r*cos(a._fi)-b._r*cos(b._fi))/c._r);
		if(a._r*sin(a._fi)-b._r*sin(b._fi)<0) c._fi=2*M_PI-c._fi;
	}else{c._r=0; c._fi=0;}
	return c;
}

Complex_Trig operator * (const Complex_Trig& a, const Complex_Trig& b){
	Complex_Trig c;
	c._r=a._r*b._r;
	if(a._fi+b._fi>2*M_PI){
		c._fi=a._fi+b._fi-2*M_PI;
	}else{
		c._fi=a._fi+b._fi;	   
	}
	if(c._r==0) c._fi=0;
	return c;
}
 
Complex_Trig operator / (const Complex_Trig & a, const Complex_Trig& b){
	Complex_Trig c(0, 0);
	if(b._r==0){
		std::cout<<"Деление на ноль. Деление не произведенно."<<std::endl;
		return c;
	}
	c._r=a._r/b._r;
	if(a._fi-b._fi>=0) c._fi=a._fi-b._fi; else c._fi=2*M_PI+(a._fi-b._fi);
	if(c._r==0) c._fi=0;
	return c;
}
double Complex_Trig::radius(){
	return _r;
} 
double Complex_Trig::angle(){
	return _fi;
}
void Complex_Trig::ch_radius(double R){
	if(R>0) _r=R; else{ 
		if(R<0) std::cerr<<"Модлуь числа меньше нуля."<<std::endl; 
		_r=0; _fi=0;
		}
	return;
}

void Complex_Trig::ch_angle(double Fi){
	if(_r==0) return;
	while(Fi>=2*M_PI) Fi-=2*M_PI; 
	while(Fi<0) Fi+=2*M_PI; 
	_fi=Fi;
	return;
}
bool operator == (const Complex_Trig& a, const Complex_Trig& b){
	return a._fi==b._fi && a._r==b._r;
}
std::ostream& operator << (std::ostream& stream, const Complex_Trig& a){
	stream << "( "<< a._r<<" , "<<a._fi<<" )";
	return stream;
}
Complex_Trig Complex_Trig::conj(){
	Complex_Trig a; 
	a._r=_r;
	if(_fi!=0) a._fi=2*M_PI-_fi; else a._fi=0;
	return a;
}
