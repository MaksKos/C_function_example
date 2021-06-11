#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;
// массив для автоматического формирования матрицы
int mas[]={
	24, 62, 60, 89, 5, 84, 96, 12, 19, 47, 23, 20, 34, 44, 74, 62, 58, 16, 
	34, 54, 84, 70, 85, 56, 60, 4, 44, 50, 9, 6, 68, 32, 68, 27, 21, 72, 10, 16, 83,
	29, 63, 6, 49, 97, 49, 23, 58, 7, 38, 92, 60, 22, 61, 45, 77, 20, 48, 21, 70, 56,
	27, 37, 87, 94, 63, 7, 66, 73, 23, 49, 2, 86, 54, 50, 83, 3, 72, 40, 9, 10, 31, 69,
	31, 92, 13, 8, 12, 61, 29, 81, 16, 55, 17, 3, 49, 80, 10, 14, 53, 33, 62, 54, 18, 16,
	3, 100, 18, 75, 40, 27, 84, 71, 95, 15, 63, 8, 22, 74, 68, 51, 54, 83, 5, 71, 86, 53,
	51, 95, 67, 3, 27, 28, 56, 45, 44, 59, 45, 62, 33, 85, 88, 16, 55, 83, 31, 17, 90, 53,
	91, 58, 3, 44, 41, 7, 15, 26, 60, 65, 20, 26, 67, 47, 54, 23, 92, 98, 81, 36, 59, 13, 
	20, 47, 29, 75, 29, 59, 92, 19, 12, 82, 76, 14, 26, 16, 21, 41, 42, 81, 5, 62, 7, 72, 8, 
	61, 95, 100, 58, 75, 35, 16
};

//структура "студент"
struct stud {
char name[20];
int ball; // количество оценок
int *oc; // массив оценок
};

struct point {
float x,y;
};
struct line {
float k,b;
point t1,t2;
};
//структура треугольник
struct triangle
{
 point t1,t2,t3;
};

stud* student_mas(char *name, int &k);
void print(stud *a,int n);
float** int_matrix(char *name,int &n,int &m);


float rast (float x1,float y1,float x2,float y2);
int* input_mas (int);
void print_mas(int*,int);
int** form(int*,int*,int);
void print_matrix(int**,int,int);
int** do_matrix(int,int, int*);
void change (int&,int&);
int* form1 (int*,int,int&);
void simple_sort(int*,int);
int found_number(int*,int,int);
int* mass_of_naumber(int**,int,int,int);
int number_isset(int*,int,int&);

point* do_mas_point(int);
float rast (point ,point );
line form_line(point& ,point&);
line** matrix_line(point* ,int );
point sred_poin(point* ,int );
void print_mas(float*,int);
void print_matrix(line**,int,int);
float** do_matrix(int,int, float*);

void main(){

}


//функция создает массив студентов, считываея информацию из файла с именем "name" , k - количкство студентов

stud* student_mas(char *name, int &k){
	stud *a;
	int i,j,n;
	ifstream fn(name);
	fn>>n;
	a=new stud[n];
	for(i=0;i<n;i++){
		fn>>a[i].name;
		fn>>a[i].ball;
		a[i].oc=new int[a[i].ball];
		for(j=0;j<a[i].ball;j++)
			fn>>a[i].oc[j];
	}
	fn.close();
	k=n;
	return a;
}
//функция печатает массив студентов
void print(stud *a,int n){
	int i,j;
	for(i=0;i<n;i++){
		cout<<endl<<"student num "<<i+1<<endl;
		cout<<"  name: "<<a[i].name<<endl;
		cout<<"  ozenki: ";
		for(j=0;j<a[i].ball;j++)
			cout<<" "<<a[i].oc[j];
		cout<<endl;

	}
}

//функция считывыает числа из файла в матрицу

float** int_matrix(char *name,int &n,int &m){
	float **a;
	int i,j;
	ifstream fn(name);
	fn>>n;
	fn>>m;

	a=new float*[n];
	for(i=0;i<n;i++)
		a[i]=new float[m];

	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			fn>>a[i][j];

	return a;
}



// ФУНКЦИИ РАБОТЫ С МАТРИЦАМИ

// функция нахождения расстояния между двумя точками
float rast (float x1,float y1,float x2,float y2){
	float rt;
	rt=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	return rt;
}


// функция ввода массива
int* input_mas (int n){
	int *pa; int i;
	pa=new int[n];

	cout<<"input mas:"<<endl;
	for(i=0;i<n;i++)
		cin>>pa[i];
	return pa;
}

//функция печати массива
void print_mas (int *pc,int n){
	int i;
	cout<<"massive :"<<endl;
	for (i=0;i<n;i++)
		cout<<pc[i]<<"  ";
	cout<<endl;
}


//печатает матрицу

void print_matrix (int** a, int n,int m){
	int i,j;
	
	cout<<endl<<"print matrix"<<endl<<endl;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cout<<a[i][j]<<"   ";
		}
		cout<<endl;
	}
}
// функция делает матрицу из массива "massive"
int** do_matrix(int n,int m,int* massive){
	int **a;
	int i,j,k;
	a=new int*[n];
	for(i=0;i<n;i++)
		*(a+i)=new int[m];
	for(i=0,k=0;i<n;i++)
		for(j=0;j<m;j++)
			a[i][j]=massive[k++];
	return a;

}
// функция обмена
void change (int &a,int &b){
	int buf;
	buf=a;
	a=b;
	b=buf;
}
// функция выбирает в новый массив из старого все четные положительные числа
int* form1 (int* a,int n, int &k){
	int *tp,*t,i;
	t=new int[n];
	for(i=0,k=0;i<n;i++)
		if(a[i]>0 && a[i]%2==0)
			t[k++]=a[i];

	tp=new int[k];

	for(i=0;i<k;i++)
		tp[i]=t[i];
	delete [] t;
	return tp;

}
//функция простой сортировки
void simple_sort(int *a,int n){
	int i,j,flag;
	flag=1;
	while(flag==1){
		flag=0;
		for(i=0;i<n-1;i++){
			if(a[i]>a[i+1]){
				change(a[i],a[i+1]);
				flag=1;
			}
		}

	}
}
// функция находит количесиво вхождений числа "num" в массиве
int found_number(int *a,int n, int num){
	int i,k;
	for(i=0,k=0;i<n;i++)
		if(a[i]==num)
			k++;
	return k;
}
//функция создает массив из вхождений числа 'num' в строчках матрицы
int* mass_of_naumber(int **a, int n, int m, int num){
	int *y,i,j;
	y=new int[n];
	for(i=0;i<n;i++)
		y[i]=found_number(*(a+i),m,num);

	return y;
}
//функция определяет, есть ли число "k" в массиве
int number_isset(int *a,int n,int &k){
int i,flag;
flag=0;
for(i=0;i<n;i++)
	if(a[i]==k)
		flag=1;
	
return flag;
}

//  матрица расстояний между точками
float** form_rast(float *px, float *py, int n){
	float **a;
	int i,j;
	a=new float*[n];
	for(i=0;i<n;i++)
		a[i]=new float[n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			*(a[i]+j)=rast(px[i],py[i],px[j],py[j]);
	return a;
}




//функции раоты со структурой "точка"

//расстояние между точками
float rast (point &t1,point &t2){
float r;
r=sqrt((t1.x-t2.x)*(t1.x-t2.x)+(t1.y-t2.y)*(t1.y-t2.y));
return r;
}

//создает элемент "линия"
line form_line(point &t1,point &t2){
line r;
r.k=(t1.y-t2.y)/(t1.x-t2.x);
r.b=t1.y-r.k*t1.x;
return r;
}

//матрица линий
line** matrix_line(point *z,int n){
line **a;
int i,j;
a = new line*[n];

for (i=0;i<n;i++)
	a[i]=new line[n];
	
	for (i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=form_line(z[i],z[j]);
return a;
}

// средняя точка
point sred_poin(point* z,int n){
point sr; 
int i;
sr.x=0;sr.y=0;
for(i=0;i<n;i++){
sr.x+=z[i].x;
sr.y+=z[i].y;
}
sr.x=sr.x/n;
sr.y=sr.y/n;
return sr;
}
// автоматичсеки создает массив точек из массива 'mas'
point* do_mas_point(int n){
	point *r;
	r=new point[n];
	int i;
	for(i=0;i<n;i++){
		r[i].x=mas[i];
		r[i].y=mas[100-i];
	}
	return r;
}
// печатает массив
void print_mas (float *pc,int n){
	int i;
	//cout<<"massive"<<endl;
	for (i=0;i<n;i++)
		cout<<pc[i]<<"  ";
	cout<<endl;
}


// печатает матрицу

void print_matrix (line** a, int n,int m){
	int i,j;
	
	cout<<endl<<"print matrix"<<endl<<endl;
	for(i=0;i<n;i++){
		cout<<"line"<<i<<":"<<"  ";
		for(j=0;j<m;j++){
			cout<<"["<<a[i][j].k<<" "<<a[i][j].b<<"]"<<" ";
		}
		cout<<endl<<endl;
	}
}
//автоматичсеки создает матрицу из массива 'mas'
float** do_matrix(int n,int m,float* massive){
	float **a;
	int i,j,k;
	a=new float*[n];
	for(i=0;i<n;i++)
		*(a+i)=new float[m];
	for(i=0,k=0;i<n;i++)
		for(j=0;j<m;j++)
			a[i][j]=massive[k++];
	return a;

}



//ФУНКЦИИ ДЛЯ РАБОТЫ СО СТРУКТУРОЙ ТРЕУГОЛЬНИК


point do_point (){
	point a;
	cin>>a.x;
	cin>>a.y;
	return a;
}
 // создает треугольник
triangle do_tring(){
	triangle a;
	a.t1=do_point();
	a.t2=do_point();
	a.t3=do_point();
	return a;
}
// формирует матрицу вхождения точек в треугольники 
int** matrix(point *p,triangle *t,int n, int m){
	int **matr;
	int i,j,flag;
	float a,b,c;


	matr=new int*[m];
	for(i=0;i<m;i++)
		matr[i]=new int[n];
	
	for(i=0;i<m;i++)
		for(j=0;j<n;j++){
			
			matr[i][j]=point_in_triangle(t[i],p[j]);
		}


	return matr;

}

int point_in_triangle (triangle t,point p){
 int flag;
 float a,b,c;
	a=(t.t1.x-p.x)*(t.t2.y-t.t1.y)-(t.t2.x-t.t1.x)*(t.t1.y-p.y);
	b=(t.t2.x-p.x)*(t.t3.y-t.t2.y)-(t.t3.x-t.t2.x)*(t.t2.y-p.y);
	c=(t.t3.x-p.x)*(t.t1.y-t.t3.y)-(t.t1.x-t.t3.x)*(t.t3.y-p.y);


		if((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0)){
			flag=1;
		}
		else{
			flag=0;
		}
 return flag;
}


// печатает точку
void print_p (point p){
 cout<<" "<<"["<<p.x<<" "<<p.y<<"]"<<" ";
}

// печатает массив треугольников
void print_mas_t (triangle *pc,int n){
	int i;
	cout<<"massive_tringle"<<endl;
	for (i=0;i<n;i++){
	
		print_p(pc[i].t1);
		print_p(pc[i].t2);
		print_p(pc[i].t3);
		cout<<endl;

	}

	cout<<endl;
}
// возвращает массив точек в треугольниках
int* point_in_tr(int **a,int n, int m){

	int *b;
	b=new int[n];
	int i,j,k,s;
	for(i=0;i<n;i++){
		for(j=0,s=0;j<m;j++){
			s+=a[i][j];
		}
		b[i]=s;
	}
	return b;
}
// находит треугольник с максимальным колическтвом точек
int imax_tr(int *a,int n){
	int b,i,imax,max;
	for(i=0,max=a[n-1],imax=n-1;i<n-1;i++){
		if(a[i]>max){
			max=a[i];
			imax=i;
		}
	}
	return imax;
}

