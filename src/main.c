#include <stdio.h>
#include <string.h>

void validCheck(char user_cmd[]);
void helpOption();
void ledonOption();
void ledoffOption();
void statusOption();
int isValidCommand(char user_cmd[]);
void handleCommand(char user_cmd[]);

const char HELP_MESSAGE[] = 
	"Available commands:\n"
	"help\n"
	"exit\n"
	"ledon\n"
	"ledoff\n"
	"status\n";

const char * const VALID_COMMANDS[] = {
	"help",
	"exit",
	"ledon",
	"ledoff",
	"status"
};

int led = 0;

int main() {
	printf("Embedded CLI Simulator\n");

	char user_cmd[32] = "";

	while(strcmp(user_cmd, "exit") != 0) {
		printf("> ");
		if(fgets(user_cmd, sizeof(user_cmd), stdin) == NULL) {
			break;
		}

		user_cmd[strcspn(user_cmd, "\n")] = '\0';
		
		validCheck(user_cmd);
		handleCommand(user_cmd);
	}
	return 0;
}

void handleCommand(char user_cmd[]) {
	if(strcmp(user_cmd, "help") == 0) {
		helpOption();
	} else if(strcmp(user_cmd, "ledon") == 0) {
		ledonOption();
	} else if(strcmp(user_cmd, "ledoff") == 0) {
		ledoffOption();
	} else if(strcmp(user_cmd, "status") == 0) {
		statusOption();
	}
}

void helpOption() {
        	printf("%s", HELP_MESSAGE);
}

void ledonOption() {
		printf("LED is ON\n");
		led = 1;
}

void ledoffOption() {
		printf("LED is OFF\n");
		led = 0;
}

void statusOption() {
		if(led == 0) {
			printf("Status of LED is Off\n");
		} else {
			printf("Status of LED is On\n");
		}
}

void validCheck(char user_cmd[]) {
	if(!isValidCommand(user_cmd)) {
		printf("%s", HELP_MESSAGE);
	}
}

int isValidCommand(char user_cmd[]) {
	int length = sizeof(VALID_COMMANDS) / sizeof(VALID_COMMANDS[0]);

	for(int i=0; i < length; i++) {
		if(strcmp(user_cmd, VALID_COMMANDS[i]) == 0) {
			return 1;
		}
	}
	return 0;
}
