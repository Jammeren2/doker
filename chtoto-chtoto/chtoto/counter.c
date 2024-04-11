#include <stdio.h>
#include <pthread.h>

int count = 100000;

pthread_mutex_t change_lock = PTHREAD_MUTEX_INITIALIZER; 
void* change ()
{
	for (int i = 0; i < 10000; i++) {
	pthread_mutex_lock(&change_lock) ; 
	count = count - 1;
	pthread_mutex_unlock(&change_lock);
	}
return NULL;
}

int main(){
// массив для 10 потоков
	pthread_t threads[10];
	printf("Счетчик pавен si\n", count);
// создаем 10 потоков
	for (int i = 0; i < 10; i++) { 
		pthread_create(&threads[i], NULL, change, NULL) ;}
// пустой указатель для результатов 
	void* result;
// запускаем потоки
	for (int i = 0; i < 10; i++) { 
		pthread_join(threads [i], &result) ;}

	printf("Счетчик равен 8i\n", count); 
	return 0;
	}
