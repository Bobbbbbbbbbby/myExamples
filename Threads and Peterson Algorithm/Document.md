## To Explain
***one `example.c` include 3 part corresponding to 3 target of `Makefile`***

### `make easy`<br>
`EASY` branch of the `example.c` just create 2 threads to add a static variable<br>
*In order to show the incorrectness without a lock mechanism*<br><br>
### `make peterson`<br>
`PETERSON` branch of the `example.c` is to show that `peterson algorithm` can make sure the correctness.<br>
***However***, `peterson algorithm` with out a `__sync_synchronize()` is not corret because of the optimization mechanism of `x86` CPU<br><br>

### `make pass_parameter`<br>
`PASS_PARAMETER` branch of `example.c` is to practice the method of passing parameters from `main` to `thread` as well as from `thread` to `main`<br>
Although `pthread_create` can only pass a `void*` to the a thread, we can use a `long` array to store the pointers of parameters we want to pass, and use force type transmition to make it work.<br>
From `thread` to `main` is the same!
: )