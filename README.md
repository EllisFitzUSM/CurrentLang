
# CurrentLang

CurrentLang is supposed to mean "Current Language"

The name Current is inspired by water currents and concurrency. Water is flexible in form, and so does this project intend to be.

The overall goal is to develop an easy to type language that both works intuitively to write parallel, but also compiles so that anything that can be parallel, will be parallel (inspired by Bend and HVM).

Much is yet to be decided but for now the initial part of the project consists of a calculator that brings these ideas to fruition in the simplest ways by parallelizing the left-hand-side and right-hand-side of binary operations such as:

- Add (+)
- Subtract (-)
- Multiply (*)
- Divide (/)
- Modulus (Remainder Division) (%)

The Calculator Demo was mostly a code-along to the interpreter seen in the [Crafting Interpreters](https://craftinginterpreters.com/) book by Robert Nystrom, but instead done in C++

## Calculator Demo

Build and link the project and then use the executable to run.

There are two (2) arguments to provide. They can be provided in command line arguments when running the executable *or* by formatting command line inputs.

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `-S`    | `flag` | Sequential run of calculated expression. |
| `-C`    | `flag` | Concurrent run of calculated expression. |
| `-P`    | `flag` | Parallel run of calculated expression. |
| `Expression`    | `string` | The expression to calculate (includes tokens like [0-9] and [+-*/%]) |

## Roadmap

This roadmap is not final and just an ideal path to the envisioned final product.
Time frame is 1-2 years, with the latter half expected to take the most.

- Concurrent/Parallel/Sequential Tree-Walk Calculator ✅

### V 0.1
- Basic Syntax
- Classes
- Limited Standard Library
- Interpreted
### V 0.2
- Concurrency
- Abstract Classes, Interfaces, and Inheritance
- Basic Parallelism
- LLVM Integration
### V 0.3
- Parametric/Generics
- Bitwise Operators and Operator Overriding
- Force All Statements to Expression
### V 0.4
- Advanced Memory Management/Safety Syntax
- Syntax Highlighter/Checker Environment
### V0.5
- IO/System
- Platform Interaction
- Experimental Syntax Exploration ie Extension Functions
### V 0.6
- Exchange LLVM Codegen for Manual Parallel Compilation Optimizations
- Explore JIT and VM
### V 1:
- Finalized Syntax Decisions
- Graphics Library
## License

[MIT](https://choosealicense.com/licenses/mit/)

