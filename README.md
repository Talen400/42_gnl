# Get Next Line

A C implementation of the `get_next_line` function that reads a file line by line, including the bonus version that supports multiple file descriptors.

## 📋 Description

The **Get Next Line** project consists of creating a function that reads a file line by line, returning one line at a time with each call. It's a fundamental project from École 42 that teaches memory management, string manipulation, and file reading.

## ✨ Features

### Basic Version
- Reads files line by line
- Dynamic memory management
- Supports different buffer sizes (configurable via `BUFFER_SIZE`)
- Works with files of any size

### Bonus Version
- **Multiple File Descriptors**: Supports simultaneous reading from multiple files
- **Linked List**: Uses a linked list structure to manage different file descriptors
- **Memory Efficiency**: Maintains the state of each file separately

## 🏗️ Project Structure

```
📁 get_next_line/
├── 📄 get_next_line.c          # Main implementation
├── 📄 get_next_line.h          # Basic version header
├── 📄 get_next_line_utils.c    # Utility functions
├── 📄 get_next_line_bonus.c    # Bonus implementation
├── 📄 get_next_line_bonus.h    # Bonus version header
├── 📄 get_next_line_utils_bonus.c  # Bonus utility functions
└── 📄 README.md               # This file
```

## 🔧 Implementation

### Function Prototype
```c
char *get_next_line(int fd);
```

### Bonus Version Structure
```c
typedef struct s_fd_list
{
    int             fd;      // File descriptor
    char            *rest;   // Remaining buffer after reading a line
    struct s_fd_list *next; // Next node in the list
} t_fd_list;
```

### Utility Functions
- `ft_strlen`: Calculates the length of a string
- `ft_strdup`: Duplicates a string
- `ft_strjoin`: Concatenates two strings
- `ft_strchr`: Searches for a character in a string
- `ft_substr`: Extracts a substring

## 🚀 How to Use

### Compilation

#### Basic Version
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

#### Bonus Version
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c
```

### Usage Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;
    
    fd = open("file.txt", O_RDONLY);
    if (fd == -1)
        return (1);
        
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    
    close(fd);
    return (0);
}
```

### Multiple Files Example (Bonus)

```c
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd1, fd2;
    char *line;
    
    fd1 = open("file1.txt", O_RDONLY);
    fd2 = open("file2.txt", O_RDONLY);
    
    // Read alternately from both files
    line = get_next_line(fd1);
    printf("File 1: %s", line);
    free(line);
    
    line = get_next_line(fd2);
    printf("File 2: %s", line);
    free(line);
    
    close(fd1);
    close(fd2);
    return (0);
}
```

## ⚙️ Configuration

### BUFFER_SIZE
The buffer size can be defined during compilation:

```bash
gcc -D BUFFER_SIZE=1024 ...    # 1024 bytes buffer
gcc -D BUFFER_SIZE=1 ...       # 1 byte buffer (stress test)
```

If not defined, the default value is 42.

## 🧪 Test Cases

The function should work correctly with:
- Empty files
- Files with a single line
- Files without newline at the end
- Very large files
- Different buffer sizes
- Invalid file descriptors
- Multiple simultaneous files (bonus)

## 📊 Complexity

- **Time**: O(n) where n is the number of characters read
- **Space**: O(BUFFER_SIZE + current line length)
- **Bonus**: O(k × BUFFER_SIZE) where k is the number of open file descriptors

## 🔍 Implementation Details

### Basic Version
Uses a static variable to maintain the buffer between function calls.

### Bonus Version
Implements a linked list to manage multiple file descriptors:
- Each node stores an fd and its corresponding buffer
- Searches for or creates nodes as needed
- Removes nodes when the file is completely read

## 🛠️ Technical Specifications

### Return Values
- **Valid line**: Returns a string containing the line including `\n` (if present)
- **End of file**: Returns `NULL`
- **Error**: Returns `NULL`

### Memory Management
- Each returned line must be freed by the caller
- No memory leaks allowed
- Efficient buffer management

### Edge Cases Handled
- Files ending without newline
- Empty lines
- Very long lines
- Binary files (though not recommended)
- Multiple consecutive newlines

## 🧩 Algorithm Overview

1. **Read**: Read BUFFER_SIZE bytes from file descriptor
2. **Store**: Append to static/linked buffer
3. **Search**: Look for newline character
4. **Extract**: If found, extract line and update buffer
5. **Return**: Return extracted line or continue reading

## 👤 Author

**tlavared** - 42 São Paulo
---

*Made with ❤️ at 42 São Paulo*
