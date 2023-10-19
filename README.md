# OBOShell - A Simple Shell Implementation

**Author:** Babatunde Ojomu 

## Description

OBOShell is a simple shell implementation written in C. It provides a basic command-line interface for executing commands, managing processes, and handling built-in shell commands.

## Table of Contents

- [Usage](#usage)
- [Features](#features)
- [How It Works](#how-it-works)

## Usage
Once you have OBOShell up and running, you can use it like any other shell. Here are some basic commands you can try:

$ ls
$ cd /path/to/directory
$ env
$ exit

## Features
- Basic shell functionality, including process execution.
- Support for built-in commands like cd, env, and exit.
- Handles command-line arguments and environment variables.
- Interactive and non-interactive modes.
- Signal handling for Ctrl+C (SIGINT).

## How It Works
OBOShell is structured as a collection of C functions that provide various shell functionalities. Here's a brief overview of some key components:

- atoi_obo: Converts a string to an integer.
- get_obo_func: Gets a function pointer for a given command.

###Built-in commands:
- exit_obo: Exits the shell.
- env_obo: Prints the current environment.
- cd_obo: Changes the current working directory.

###Execution functions:
- execute_mode: Executes a command in interactive mode.
- execute_obo: Executes a command in non-interactive mode.
- Path handling: handle_path finds the full path of a command.
- Signal handling: signal_handle handles signals, like SIGINT.
- Interactive mode: interact_mode handles interactive shell behavior.
- Tokenization: tokenize_line splits command lines into tokens.

# YOU ARE WELCOME
