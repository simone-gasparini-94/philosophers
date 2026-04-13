# philosophers

![C](https://img.shields.io/badge/C-00599C?logo=c&logoColor=white)

Simulation of the **Dining Philosophers problem** using POSIX threads (`pthreads`) and mutexes:

> N philosophers sit at a round table. Each one alternates between thinking, eating, and sleeping. Between each pair of philosophers lies a single fork, but eating requires two forks. Ensure no philosopher starves, without causing a deadlock.

The program logs any state change of a philosopher in the format: `timestamp_in_ms <philosopher id> <state>`

The simulation stops when either a philosopher die or the optional meal count is reached by all philosophers.

## How to run

Clone this repository:

```bash
git clone https://github.com/s-gas/philosophers.git
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
