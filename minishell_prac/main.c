#include <string.h>
#include <stdlib.h> 
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

void	run_prompt(char *prompt)
{
	if (strcmp(prompt, "exit") == 0)
		exit(EXIT_SUCCESS);
	//tokenize_prompt(prompt);
	printf("%s\n", prompt);
}

int main(void)
{
	char	*prompt;

	do
	{
		prompt = readline("zali> ");
		add_history(prompt);
		rl_redisplay();
		run_prompt(prompt);
		free(prompt);
	} while (prompt);
	rl_clear_history();
	/*
    char *word;
    char sentence[] = "My name iz zainan.\n";
	char delimit[] = " ";

    word = strtok(sentence, delimit);
	while(word)
	{
		printf("%s\n", word);
		word = strtok(NULL, delimit);
	}
	exit(EXIT_SUCCESS);
	*/
}