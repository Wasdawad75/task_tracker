# Task Tracker CLI

A simple command-line tool to track tasks — add, update, delete, and mark them as todo, in-progress, or done. Tasks are stored in a local `tasks.json` file so they persist between runs.

This was my first full C++ project, built from scratch as a way to practice classes, file I/O, and building a real command-line tool.

## Building

Requires a C++ compiler (g++ recommended). From the project directory:

​```bash
g++ main.cpp task.cpp taskDatabase.cpp utils.cpp -o task-cli
​```

This produces an executable called `task-cli`.

## Usage

​```bash
./task-cli <command> [arguments]
​```

### Commands

| Command | Description |
|---|---|
| `add "<description>"` | Add a new task |
| `update <id> "<new description>"` | Update a task's description |
| `delete <id>` | Delete a task |
| `mark-in-progress <id>` | Mark a task as in progress |
| `mark-done <id>` | Mark a task as done |
| `list` | List all tasks |
| `list done` | List only completed tasks |
| `list todo` | List only tasks not yet started |
| `list in-progress` | List only tasks in progress |

### Examples

​```bash
./task-cli add "Buy groceries"
./task-cli list
./task-cli mark-in-progress 1
./task-cli update 1 "Buy groceries and cook dinner"
./task-cli mark-done 1
./task-cli list done
./task-cli delete 1
​```

## Data storage

Tasks are stored in `tasks.json` in the current directory. The file is created automatically on first run if it doesn't already exist. Each task has:

- `id` — unique identifier
- `description` — task description
- `status` — `todo`, `in-progress`, or `done`
- `createdAt` — timestamp when the task was created
- `updatedAt` — timestamp when the task was last modified

## Design notes

- Built without external libraries — JSON reading and writing are implemented by hand, taking advantage of the fact that every task has a fixed, flat structure (no nesting, known field names).
- `task` represents a single task; `taskDatabase` owns the collection and all operations (add/update/delete/list/persistence).

## Known limitations

- The hand-rolled JSON parser assumes descriptions never contain a literal `"` character.
- Reloading a task from disk can slightly shift its `updatedAt` timestamp, since restoring status internally reuses the same setter that normally refreshes it on a real update.

## What I learned

- Splitting a class into a header (declarations) and a `.cpp` file (definitions), and using the `ClassName::method` scope resolution pattern.
- Designing class responsibilities deliberately — separating a single `task`'s data from the `taskDatabase` collection logic that operates on many tasks.
- The Rule of Zero: not writing a destructor/copy constructor/copy assignment unless a class actually manages a resource that needs it.
- Working with `<ctime>` to generate and format timestamps.
- Parsing command-line arguments via `argc`/`argv`, including safely checking argument counts before accessing them.
- Writing and reading JSON by hand, and understanding what a real JSON library abstracts away.
- Basic `.gitignore` usage to keep build artifacts and runtime data out of version control.