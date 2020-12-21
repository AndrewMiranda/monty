# Monty Language Interpreter

**Monty** is a scripting language that is compiled into bytecodes. It relies on a stack with instructions to manipulate it. This program is an interpreter for Monty bytecode files.

-------------------

## Monty Bytecode Commands
- `push <int>` - pushes an integer onto the top of the stack
- `pop` - removes the top element of the stack
- `swap` - swaps the top two elements of the stack
- `nop` - does nothing


- `pall` - prints all values on the stack
- `pint` - prints the value at the top of the stack
- `pchar` - prints the char at the top of the stack
- `pstr` - prints the string starting at the top of the stack


- `add` - adds the top two elements of the stack
- `sub` - subtracts the top element of the stack from the second element of the stack
- `mul` - multiplies the top two elements of the stack
- `div` - divides the second element of the stack by the top element of the stack
- `mod` - returns the remainder of dividing the second element of the stack by the top element of the stack
