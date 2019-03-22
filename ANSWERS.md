**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

I don't know if we talked about all of these in class, but on Wikipedia it looks like there are Created, Waiting, Running, Blocked, and Terminated states.

Created means the process has been loaded from a (secondary storage) file into main memory.
Waiting means the process is generally active, but not the current priority according to the scheduler; it is waiting for the scheduler to give it a turn.
Blocked means the process is waiting, not just for a turn from the scheduler, but for some other resource. Like for user input or a file to open.
Running means the process is actively executing.
Terminated means the process has ended, but may not be removed entirely from existence yet (see zombie processes).

**2. What is a zombie process?**

A zombie process has ended (via exit() system call) but has not been removed from the process table because its exit status has not yet been accepted by being wait()ed for.

**3. How does a zombie process get created? How does one get destroyed?**

Any child process that ends becomes a zombie process at least instantaneously, but in many cases its exit status is immediately accepted by the parent process wait()ing and the zombie gets "reaped" very quickly. If a bug or other design makes the zombie process persist, it can eventually get reaped by the parent process wait()ing, or if the parent process eventually ends, the zombie gets "adopted" by init and immediately reaped by init.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

Compiled languages can be more efficient and performant because they are lower-level. That is, when compiled, they are translated into a binary executable, which is more efficient to run than running code through an interpreter that has to follow the code's directions every step of the way. This is especially true if the process is going to be compiled once and then run many times with an identical executable, and is especially especially true because compilers have optimizers built into them that know the hardware intimately and optimize the code so that the hardware can go from one step to the next to the next with very little delay.