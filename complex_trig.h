#ifndef _COMPLEX_TRIG_
#define _COMPLEX_TRIG_
class Complex_Trig{
	public:
		Complex_Trig(double R, double Fi); // создать комплексное число на основе радиуса и углa от 0 до 2*пи
		Complex_Trig();
		friend Complex_Trig operator + (const Complex_Trig& a, const Complex_Trig& b);
		friend Complex_Trig operator - (const Complex_Trig& a, const Complex_Trig& b);
		friend Complex_Trig operator * (const Complex_Trig& a, const Complex_Trig& b); 
		friend Complex_Trig operator / (const Complex_Trig& a, const Complex_Trig& b); 
		friend bool operator == (const Complex_Trig& a, const Complex_Trig& b); //пара поэлементно равна
		Complex_Trig conj(); //conj(r, fi)= (r, -fi)
		//friend Complex_Trig operator "" _tocmplx(const char* str);
		friend std::ostream &operator << (std::ostream& stream,  const Complex_Trig& a);
		double radius();
		double angle();
		void ch_radius(double R);
		void ch_angle(double Fi);	
	private:
		double _r; //radius
		double _fi; //angle
};
#endif
