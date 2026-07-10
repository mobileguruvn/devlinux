# Chat Server — P3 Project

Multi-user chat server using epoll for concurrent connection handling.

## Quick Start

```bash
make              # Build chat-server
./build/chat-server  # Run server (listens on port 5000)
```

## Project Structure

```
.
├── src/           # Source files (.c)
│   ├── main.c     # epoll event loop, client management
│   ├── auth.c     # User authentication, password hashing
│   └── message.c  # Message broadcast, persistence
├── inc/           # Header files (.h)
│   └── chat.h     # Shared definitions
├── build/         # Build artifacts (git ignored)
│   └── obj/       # Object files
├── test/          # Unit tests
├── doc/           # Documentation
├── Makefile       # Build system
└── README.md      # This file
```

## Features

- **Single-threaded**: Epoll-based event loop (NOT thread-per-client)
- **Non-blocking I/O**: Proper EAGAIN/EWOULDBLOCK handling
- **Authentication**: SHA256 password hashing with salt
- **Persistence**: Message history logging with file locking
- **Concurrent**: Supports 100+ simultaneous clients
- **Protocol**: TEXT-based (LOGIN, MSG, USERLIST, LOGOUT, HISTORY)

## Building

```bash
make              # Build
make clean        # Remove build artifacts
make rebuild      # Clean and build
make help         # Show targets
```

## Testing

Test results documented in parent directory's `test_report.md`.

All 14 tests pass:
- Server startup ✅
- Authentication ✅
- Message broadcast ✅
- Concurrent clients ✅
- Graceful disconnect ✅
- No memory leaks ✅

## Architecture

### Message Flow

```
Client → TCP socket → epoll_wait()
                ↓
         route_message()
         ├── LOGIN → authenticate_user()
         ├── MSG → broadcast_message()
         ├── USERLIST → handle_userlist()
         ├── LOGOUT → close_client()
         └── HISTORY → send_message_history()
                ↓
         output_buffer → write() → Client
```

### File Locking

- **accounts.db**: LOCK_SH (read), LOCK_EX (write)
- **messages.log**: LOCK_EX (append)

## Requirements

- GCC compiler
- OpenSSL library (libssl-dev)
- Linux with epoll support

## Compilation Flags

```bash
-Wall -Wextra -std=c99 -lcrypto
```

## Performance

- Binary size: ~27KB
- Code: 551 lines
- Supports 100 concurrent connections
- Non-blocking operation
