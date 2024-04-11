#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void diediedie(int sig)
{
	puts ("Прощай, жестокий мир...\n");
	exit(1);
}
void churka(int sig)
{
	puts ("Баха лох\n");
	exit(3);
}

int catch_signal(int sig, void (*handler)(int))
{
	struct sigaction action;
	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	return sigaction (sig, &action, NULL); 
}

int main()
{
	if (catch_signal(SIGINT, diediedie) == -1){
		fprintf(stderr, "Не могу подобрать обработчика");
		exit(2);
	}
	else (catch_signal(SIGINT, churka) == -1);
	char name [30];
	printf("Введите своё имя: ");
	fgetw (name, 30, stdin);
	printf("Привет, %s\n", name);
	return 0;

}
