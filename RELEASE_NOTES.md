## v0.1: Activity and Session, console only

**What it does**
- Creates an Activity with a non-empty name.
- Creates a Session for an Activity from a start time to an end time, in whole seconds, and reports its duration.
- main() reads the activity name, start and end from the console, prints the activity name and duration, and exits with code 1 on any invalid input.
- Invalid input is rejected: empty name, negative start, end before start, and a start or end that is not a number.

**Design decisions**
- Objects are built through a static create() function that returns std::optional, not through the constructor, because a constructor cannot report failure. The constructors are private.
- A Session keeps a non-owning pointer to its Activity. The Activity must outlive every Session that points to it, and Session never deletes it.
- Times are long long. A negative value can be detected and rejected, which an unsigned type would hide.
- Core classes do no printing. All console input and output is in main().

**What it does not do yet**
- No saving or loading (v0.2).
- No weekly plan or study status (v0.3).
- No presence detection, no hardware.

**Known limits**
- Names are not trimmed: "Reading " keeps its trailing space.
- Input such as 12abc is read as 12, and the rest of the line is ignored.

**What I learned**
- Pointers and references: when each is needed, how const protects data, and the lifetime rule for pointers.
- create() with std::optional instead of constructors for error handling.
- Testing with assert and a non-fatal check, and proving a test can fail.
- Keeping core logic separate from console code