#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
void* function1()
{
	puts ("Первая функция запустилась");
       	sleep (5);
	puts ("Первая функция завершилась");
	return NULL;
}
void* function2()
{
	puts ("Вторая функция запустилась");
       	sleep(3);
	puts ("Вторая функция завершилась");
       	return NULL;
}
int main() {
       	pthread_t t1;
	pthread_t t2;
// создадим поток для функции functionl
	pthread_create(&t1, NULL, function1, NULL);
// создадим поток для функции function2
	pthread_create(&t2, NULL, function2, NULL);
// переменная для возвращаемого результата 
	void* result;
// запускаем потоки
	pthread_join(t1, &result); 
	pthread_join (t2, &result);
	return 0;
}

