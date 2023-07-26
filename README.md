Simple shell group project
Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

General
Who designed and implemented the original Unix operating system
Who wrote the first version of the UNIX shell
Who invented the B programming language (the direct predecessor to the C programming language)
Who is Ken Thompson
How does a shell work
What is a pid and a ppid
How to manipulate the environment of the current process
What is the difference between a function and a system call
How to create processes
What are the three prototypes of main
How does the shell use the PATH to find the programs
How to execute another program with the execve system call
How to suspend the execution of a process until one of its children terminates
What is EOF / “end-of-file”?

our command interpreter looks like this

-> Firstly we asked a user to enter a command by printing the prompt sign($)
-> Secondly a user enters a command to our shell, then we parsed the entered command using strtok
-> Thirdly we checked the parsed command if it starts with the special characters "/"... if it is, it means it is a binary file so, we directly pass it the execve function, because it means it is executable. but if it is not starting with "/" it means we have to find it in the environment variable and we concatenate the command to the environment variable and finally pass it to the execve function.
-> Finally we handled the errors the same as the sh shell.
-> so our simple shell looks like this if you have any suggestions you can contact us in github.
