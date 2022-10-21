## To Explain!
***code in this coder have been verified!***
### fork.c
`fork.c` should be very easy<br>
*Just remember that the child get 0 and parent get child's pid from `fork()`*
<br><br>

### exec.c
`exec.c` tries to find out the difference between different `exec` functions
* `execl`<br>pass the parameter normally, but normal way of passing parameter has the limit of numbers. By the way, end with `NULL`
* `execv`<br>use an array to pass the parameters, array is like `char* argv[]`, the first parameter is the name of the function, end with `NULL`
* `execlp`<br>else same as execl, but path can use the name of programs rather than full path
* `execvp`<br>else same as execv, but path can use the name of programs rather than full path

*to be honest, I like `execlp` best. Easy and Fast!*<br><br>
### Makefile
I write this make file just to practice my skills of writing makefile and do a review.

At the sametime, I can avoid gcc for a long time next time I review my examples.
:)
