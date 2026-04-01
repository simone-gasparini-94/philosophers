# philosophers

## Description
Simulation of the [Dining Philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem) using `pthreads` (POSIX Threads), which serves as an exercise for concurrency and deadlock prevention.

## How to run

Clone this repository:

```bash
git clone https://github.com/simone-gasparini-94/philosophers.git
```

Change to the project directory:

```bash
cd philosophers
```

Build:

```bash
make
```

Run:

```bash
./philo <num_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [num_times_must_eat]
```

### Examples

```bash
./philo 5 800 200 200 10
```

This starts a simulation with:
- 5 philosophers
- Each philosophers must eat every 800ms
- Eating takes 200ms
- Sleeping takes 200ms
- Each philosopher must eat 10 times

```bash
./philo 3 1000 300 300
```

This starts a simulation with:
- 3 philosophers
- Each philosophers must eat every 1000ms
- Eating takes 300ms
- Sleeping takes 300ms
- The number of time each philosopher should eat is not specified
