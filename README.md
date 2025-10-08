## Description
Simulation of the **Dining Philosophers problem** using `pthreads` (POSIX Threads).

https://en.wikipedia.org/wiki/Dining_philosophers_problem

## How to run
`./philo 5 800 200 200 10`

This starts a simulation with:
- 5 philosophers
- Each philosophers must eat every 800ms
- Eating takes 200ms
- Sleeping takes 200ms
- Each philosopher must eat 10 times

`./philo 3 1000 300 300`

This starts a simulation with:
- 3 philosophers
- Each philosophers must eat every 1000ms
- Eating takes 300ms
- Sleeping takes 300ms
- The number of time each philosopher should eat is not specified
