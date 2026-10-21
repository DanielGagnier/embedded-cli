#include <stdio.h>
#include <string.h>
#include "cli.h"
#include "led.h"

static void helpOption(void);
static void ledonOption(void);
static void ledoffOption(void);
static void statusOption(void);
static int isValidCommand(char user_cmd[]);

static const char HELP_MESSAGE[] = 
	"Available commands:\n"
	"help\n"
	"exit\n"
	"ledon\n"
	"ledoff\n"
	"status\n";

static const char * const VALID_COMMANDS[] = {
	"help",
	"exit",
	"ledon",
	"ledoff",
	"status"
};

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

static void helpOption(void) {
        	printf("%s", HELP_MESSAGE);
}

static void ledonOption(void) {
		led_on();
		printf("LED is ON\n");
}

static void ledoffOption(void) {
		led_off();
		printf("LED is OFF\n");
}

static void statusOption(void) {
		if(led_get_state() == 0) {
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

static int isValidCommand(char user_cmd[]) {
	int length = sizeof(VALID_COMMANDS) / sizeof(VALID_COMMANDS[0]);

	for(int i=0; i < length; i++) {
		if(strcmp(user_cmd, VALID_COMMANDS[i]) == 0) {
			return 1;
		}
	}
	return 0;
}
