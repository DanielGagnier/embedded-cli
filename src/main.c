#include <stdio.h>
#include <string.h>
#include "cli.h"

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
