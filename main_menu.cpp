#include<iostream>
#include<cmath>
#include"complex_trig.h"
#include<cstdlib>
/*
Трофимво Максим М8О-201б-18
---------------------------
вариант номер 2:
создать класс для хранения и работы комплексных чисел в комплексной форме.
Реализовать сложениие, вычитание, умножение, деление, проверку на равенство и нахождение споряжённого.
*/
Complex_Trig operator ""_tocmplx(const char* str, size_t size){
	char* buffer = new char[15];
	int key=0;
	int j=0;
	double r, fi;
	//std::string str(str_1);
	for(size_t i=0; i<size; ++i){ 
		if(((str[i]>='0' && str[i]<='9') || str[i]=='-'|| str[i]=='.') && j<14) 
			buffer[j++]=str[i];	
		if(str[i]==',' ){
			key=1;
			buffer[j]='\0';
			j=0;
			r=std::atof(buffer);
			for(int k=0; k<15; ++k) buffer[k]='\0';
		}
		
	}
	fi= std::atof(buffer);
	if(r<0) r=0; 
	while(fi>=2*M_PI) fi-=2*M_PI;
	while(fi<0) fi+=2*M_PI;
	if(r==0) fi=0;
	delete [] buffer;
	return Complex_Trig(r, fi);
}

void print_menu(){
	std::cout<<"1. Печать меню.\n"
		<<"2. Печать двух комплексных чисел.\n"
		<<"3. Изменение первого комплексного числа.\n"
		<<"4. Изменение второго комплексного числа.\n"
		<<"5. Проверка их на равенство.\n"
		<<"6. Сумма двух комплексных чисел.\n"
		<<"7. Вычитание второого из первого.\n"
		<<"8. Вычитание первого из второго.\n"
		<<"9. Произведение двух комплексных чисел.\n"
		<<"10. Деление первого комплексного числа на второе.\n"
		<<"11. Деление второго комплексного числа на первое.\n"
		<<"12. Сопряжённое первого числа.\n"
		<<"13. Сопряжённое второго числа.\n"
		<<"0.Выход.\n";
	return;
}

int main(){
	Complex_Trig lhs="1, 0"_tocmplx, rhs="1,1.5708 "_tocmplx, ans= "0,0"_tocmplx;
	int status=1;
	std::cout<<"Программа для работы с комплексными числами в тригонометрической форме"<<std::endl;
	std::cout<<"Первое= "<<lhs<<"\n";
	std::cout<<"Второе= "<<rhs<<std::endl;
	while(1){
		switch(status){
			case 0 : 
				return 0;
				break;
			case 1 :
				print_menu();
				break;
			case 2 :
				std::cout<<"Первое= "<<lhs<<"\n";
				std::cout<<"Второе= "<<rhs<<"\n";
				break;
			case 3 :{
				double r, fi;
				std::cout<<"Введите модуль комплексного числа."<<std::endl;
				std::cin>>r;
				lhs.ch_radius(r);
				if(r<0) break;
				std::cout<<"Введите угол комлексного числа."<< std::endl;
				std::cin>>fi;
				lhs.ch_angle(fi);
				break;
			}
			case 4 :{
				double r, fi;
				std::cout<<"Введите модуль комплексного числа."<<std::endl;
				std::cin>>r;
				rhs.ch_radius(r);
				if(r<0) break;
				std::cout<<"Введите угол комлексного числа."<< std::endl;
				std::cin>>fi;
				rhs.ch_angle(fi);
				break;
			}
			case 5 :
				if(lhs == rhs){
					std::cout<<"Числа равны."<<std::endl;
				}else{
					std::cout<<"Числа различны."<<std::endl;
				}
				break;
			
			case 6 :
				ans= lhs + rhs;
				std::cout<<lhs<<" + "<<rhs<<" = "<<ans<<std::endl;  
				break;
			case 7 :
				ans=lhs - rhs;
				std::cout<<lhs<<" - "<<rhs<<" = "<<ans<<std::endl;  
				break;
			
			case 8 :
				ans= rhs - lhs;
				std::cout<<lhs<<" - "<<rhs<<" = "<<ans<<std::endl;  
				break;
			case 9 :
				ans=lhs * rhs;
				std::cout<<lhs<<" * "<<rhs<<" = "<<ans<<std::endl;  
				break;
			
			case 10 :
				ans=lhs / rhs;
				if(rhs.radius()!=0) std::cout<<lhs<<" / "<<rhs<<" = "<<ans<<std::endl;  
				break;
			case 11 :
				ans=rhs / lhs;
				if(lhs.radius()!=0) std::cout<<lhs<<" / "<<rhs<<" = "<<ans<<std::endl;  
				break;
			case 12 :
				ans=lhs.conj();
				std::cout<<ans<<std::endl;
				break;
			case 13 :
				ans=rhs.conj();
				std::cout<<ans<<std::endl;
				break;
			default:
			std::cout<<"Неверно введено действие."<<std::endl;
		}
		std::cout<<"ПрИгЛаШеНиЕ>>";
		std::cin>>status;
	}
}

