## Some insights about the question
- C does not support function overloading, so we can't have multiple functions with the same name. Hence, I renamed the third and fourth functions to `makeFuncN`
- The output `sub : -4` is not correct, it should be `sub : 4`. Because the value of mul is 20 and add is 10. Also, we can not have the value of sub as -4 as there is no (-4)th Fibonacci number.
- I have assumed that there is no dedicated enum for the Fibonacci function, but when an enum is passed with the second parameter as NULL, it will call the Fibonacci function.