## Monty File Interpreter.

`push`: pushes an element to the stack.

- Usage: `push <int>` where `<int>` is an integer.
- If `<int>` is not an integer or if there is no argument given to `push`, it prints the error message L<line_number>: usage: push integer, followed by a new line, and exits with the status `EXIT_FAILURE`
where is the line number in the file.

`pall`: prints all the values on the stack, starting from the top of the stack.

- Usage: `pall`
- Prints nothing if the stack is empty.

`pint`: prints the value at the top of the stack, followed by a new line.

- Usage: `pint`
- If the stack is empty, it prints the error message L<line_number>: can't pint, stack empty, followed by a new line, and exit with the status `EXIT_FAILURE`.
