# simple_shell
Team kingsley Ndonake and Emma Owa C shell

This repo contains files of program for a simple shell that reads input from the user, separates it into tokens, and searches for the command in the user's PATH and executes it if found.

The codes perform the following tasks:

A program beautiful code that passes the Betty checks.
Displays a prompt and wait for the user to type a command. A command line always ends with a new line.
The prompt is displayed again each time a command has been executed.
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
The command lines are made only of one word. No arguments will be passed to programs.
If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
handle the “end of file” condition (Ctrl+D)

Simple shell 0.1 +
Handle command lines with arguments

Simple shell 0.2 +
Handle the PATH
fork must not be called if the command doesn’t exist

Simple shell 0.3 +
Implement the exit built-in, that exits the shell
Usage: exit
You don’t have to handle any argument to the built-in exit

Simple shell 0.4 +
Implement the env built-in, that prints the current environment
