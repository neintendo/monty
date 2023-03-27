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

`pop`: removes the top element of the stack.

- Usage: `pop`
- If the stack is empty, print the error message L<line_number>: can't pop an empty stack, followed by a new line, and exit with the status `EXIT_FAILURE`.

`swap`: swaps the top two elements of the stack.

- Usage: `swap`
- If the stack contains less than two elements, print the error message L<line_number>: can't swap, stack too short, followed by a new line, and exit with the status `EXIT_FAILURE`.

`add`:  adds the top two elements of the stack.

- Usage: `add`
- If the stack contains less than two elements, print the error message L<line_number>: can't add, stack too short, followed by a new line, and exit with the status `EXIT_FAILURE`.
- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
- - The top element of the stack contains the result.
- - The stack is one element shorter.

`nop`: doesn’t do anything.

- Usage: `nop`

`sub`:  subtracts the top element of the stack from the second top element of the stack.

- Usage: `sub`
- If the stack contains less than two elements, print the error message L<line_number>: can't sub, stack too short, followed by a new line, and exit with the status `EXIT_FAILURE`.
- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
- - The top element of the stack contains the result.
- - The stack is one element shorter.

`div`:  divides the second top element of the stack by the top element of the stack.

- Usage: `div`
- If the stack contains less than two elements, print the error message L<line_number>: can't div, stack too short, followed by a new line, and exit with the status `EXIT_FAILURE`.
- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
- - The top element of the stack contains the result.
- - The stack is one element shorter.
- If the top element of the stack is 0, print the error message L<line_number>: division by zero, followed by a new line, and exit with the status `EXIT_FAILURE`.

`mul`: multiplies the second top element of the stack with the top element of the stack.

- Usage: `mul`
- If the stack contains less than two elements, print the error message L<line_number>: can't mul, stack too short, followed by a new line, and exit with the status `EXIT_FAILURE`.
- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
- - The top element of the stack contains the result.
- - The stack is one element shorter.

`mod`: computes the rest of the division of the second top element of the stack by the top element of the stack.

- Usage: `mod`
- If the stack contains less than two elements, print the error message L<line_number>: can't mod, stack too short, followed by a new line, and exit with the status `EXIT_FAILURE`.
- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
- - The top element of the stack contains the result.
- - The stack is one element shorter.
- If the top element of the stack is 0, print the error message L<line_number>: division by zero, followed by a new line, and exit with the status `EXIT_FAILURE`.
