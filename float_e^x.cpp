#include <stdio.h>
#include <math.h>

float blad_wzgledny(float a1, float a2){
	return abs((a1 - a2) / a1);
}

float potega(float liczba, int potega){  //funckja wyliczajaca potege liczby
	float pom = liczba;
	if (potega == 0) return 1;
	for (int i = 1; i < potega; i++){
		pom *= liczba;
	}
	return pom;
}

int silnia(int liczba){  //funkcja wyliczajaca silnie danej liczby
	int pom = 1;
	if (liczba == 0) return 1;
	for (int i = 1; i <= liczba; i++){
		pom *= i;
	}
	return pom;
}

float wzor_od_poczatku(float x, int *n, float epsilon){
	float wynik = 0;
	int i;
	for (i =0 ; exp(x)-wynik>epsilon; i++)
	wynik += potega(x, i) / silnia(i);
	*n = i;
	return wynik;
}

float wzor_od_konca(float x, int n, float epsilon){
	float wynik = 0;
	for (int i = n; exp(x)-wynik>epsilon && i>=0; i--){
		wynik += potega(x, i) / silnia(i);
	}
	return wynik;
}

float pop_od_poczatku(float x, int *n, float epsilon){
	float tmp = 1;
	float wynik = 0;
	int i;
	for (i = 1; exp(x)-wynik>epsilon; i++){	
	    wynik += tmp;
		tmp = tmp * x / i;
	}
	*n = i;
	return wynik;
}

float pop_od_konca(float x, int n, float epsilon){
	float wynik = 0;
	for (int i = n;exp(x)-wynik>epsilon && i>0; i--){
		wynik = wynik*x / i + 1;
	}
	return wynik;
}


int main(){
	float biblio ;
	float epsilon = 0.1;

	for (int j = 0; j < 3; j++){
		printf("Epsilon :%f***********************************\n", epsilon);
		for (float  i = 2; i <= 6; i+=1){
			biblio = exp(i);
			float wynik;
			int iteracje;
			printf("Liczba: %f  Funkcja biblioteczna: %.25f\n", i, biblio);
			wynik = wzor_od_poczatku(i, &iteracje, epsilon);
			printf("Wzor od poczatku                       %.25f\n", wynik);
			printf("Blad                     %.25f\n", blad_wzgledny(biblio, wynik));
			wynik = wzor_od_konca(i, iteracje, epsilon);
			printf("Wzor od konca                          %.25f\n", wynik);
			printf("Blad                     %.25f\n", blad_wzgledny(biblio, wynik));
			wynik = pop_od_poczatku(i, &iteracje, epsilon);
			printf("pop. wyraz od poczatu                  %.25f\n", wynik);
			printf("Blad                     %.25f\n", blad_wzgledny(biblio, wynik));
			wynik = pop_od_konca(i, iteracje, epsilon);
			printf("pop. wyeraz od konca                   %.25f\n", wynik);
			printf("Blad                     %.25f\n", blad_wzgledny(biblio, wynik));
		}
		epsilon /= 10;
	}
	return 0;
}