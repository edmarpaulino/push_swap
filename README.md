<h1 align=center>
	<b>Push_swap</b>
</h1>

<h4 align=center>
	Because Swap_push isn’t as natural.
</h4>

<p align=center>
	In this repo you will find all the codes developed during the <i>push_swap</i> project, both <b>mandatory</b>'s part and <b>bonus</b>.
</p>

---

<div align=center>
<h2>
	Final score
</h2>
<img src=https://github.com/edmarpaulino/42projects_pics/blob/master/score_125.png alt=edpaulin's 42Project Score/>
<h4>Completed + Bonus</h4>
<img src=https://github.com/edmarpaulino/42projects_pics/blob/master/push_swapm.png alt=edpaulin's 42Project Badge/>
</div>

---

### Mandatory

* The Push_swap project is a very simple and highly effective algorithm project: data will need to be sorted.

* We have at our disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks.

* Our goal? Write a program in C called push_swap which calculates and displays on the standard output the smallest program using Push_swap instruction language that sorts the integer arguments received.


#### Push_swap instruction language:

| Instruction | Description|
|:-:|-|
| **sa** | swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements). |
| **sb** | swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements). |
| **ss** | sa and sb at the same time. |
| **pa** | push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty. |
| **pb** | push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty. |
| **ra** | rotate a - shift up all elements of stack a by 1. The first element becomes the last one. |
| **rb** | rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
| **rr** | ra and rb at the same time. |
| **rra** | reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one. |
| **rrb** | reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one. |
| **rrr** | rra and rrb at the same time. |

### Bonus

* Write a program named checker, which will get as an argument the stack a formatted as a list of integers.

* The first argument should be at the top of the stack (be careful about the order). If no argument is given checker stops and displays nothing.

* checker will then wait and read instructions on the standard input, each instruction will be followed by ’\n’. Once all the instructions have been read, checker will execute them on the stack received as an argument.

* If after executing those instructions, stack a is actually sorted and b is empty, then checker must display "OK" followed by a ’\n’ on the standard output. In every other case, checker must display "KO" followed by a ’\n’ on the standard output.

* In case of error, you must display Error followed by a ’\n’ on the standard error.
Errors include for example: some arguments are not integers, some arguments are bigger than an integer, there are duplicates, an instruction don’t exist and/or is incorrectly formatted.


---
<h2>
Usage
</h2>

### Requirements

This project requires *gcc* compiler.

### Instructions

Clone this repository in your local computer:

```sh
git clone https://github.com/edmarpaulino/push_swap.git
```

In your local repository, run `make`

```sh
make 
```

> `make` supports 6 flags: 
> - `make all` or simply `make` compiles the project mandatory's part
> - `make bonus` compiles the bonus part
> - `make clean` deletes the `.o` files generated during compilation
> - `make fclean` deletes the `.o` and the `libft.a` executable file
> - `make re` executes `fclean` and `all` in sequence
> - `make rebonus` executes `fclean` and `bonus` in sequence

#### push_swap
```sh
./push_swap 1 5 2 4 3
```
or
```sh
./push_swap "1 5 2 4 3"
```

You can use ruby to generate unsorted numbers in a range **(Make sure you have ruby installed in your system)**\
Range  from 0 to 100
```sh
./push_swap `ruby -e "puts (0..100).to_a.shuffle.join(' ')"`
```
You can also use negative numbers\
Range  from -50 to 49
```sh
./push_swap `ruby -e "puts (-50..49).to_a.shuffle.join(' ')"`
```

#### checker (bonus)
```sh
ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker $ARG
```
or
```sh
ARG=$(ruby -e "puts (-50..49).to_a.shuffle.join(' ')"); ./push_swap $ARG | ./checker $ARG
```

You can also run the checker with only the numbers and next write the instructions on prompt:
```sh
./checker 1 5 2 4 3
```
When you finish the instructions you can stop the program read with `ctrl+d`

---
To make this project more fun you can use two amazing repositories that I recommend, one for testing and the other to visualize what happens when you run the program:\
1. Tester: https://github.com/laisarena/push_swap_tester
2. Visualizer: https://github.com/o-reo/push_swap_visualizer
