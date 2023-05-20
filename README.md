# Get Next Line (GNL) 📖✨ [![slegaris's 42 get_next_line Score](https://badge42.vercel.app/api/v2/cle3f3fm900060fjx7kw7tghw/project/3055065)](https://github.com/JaeSeoKim/badge42)

This is a C function that reads any valid file and returns each line, until the end of the file or an error occurs.

## Function 📚

`get_next_line(int fd)`

- This function reads a file descriptor `fd` and returns the next line from the file. 
- Each call to this function returns the next line of the file until there are no more lines.
- If there's an error, it returns NULL.

## Helper Functions 🔧

1. `ft_read_to_left_str(int fd, char *left_str)`: Reads from the file descriptor into a buffer of size `BUFFER_SIZE`, and then appends this buffer to `left_str`. It does this until it encounters a newline character or until it has read all data from the file.

2. `ft_get_line(char *left_str)`: Extracts the next line from `left_str` (i.e., all characters up to and including the next newline character). 

3. `ft_new_left_str(char *left_str)`: Creates a new `left_str` that contains the remaining characters (if any) after the line that was just extracted.

4. `ft_strjoin(char *left_str, char *buff)`: Concatenates `left_str` and `buff` into a new string.

5. `ft_strchr(char *s, int c)`: Finds the first occurrence of the character `c` in the string `s`.

6. `ft_strlen(char *s)`: Calculates the length of the string `s`.

7. `ft_line_length(const char *str)`: Calculates the length of a line in `str` (i.e., the number of characters before the newline character or the end of the string).

## How It Works 🚀

When `get_next_line` is called:

1. It checks if the file descriptor `fd` is valid and `BUFFER_SIZE` is greater than 0.

2. It then calls `ft_read_to_left_str`, which reads data from the file and appends it to `left_str` until a newline character is encountered or all data has been read.

3. It then calls `ft_get_line` to extract the next line from `left_str`, and `ft_new_left_str` to create a new `left_str` that contains the remaining data.

4. Finally, it returns the line extracted by `ft_get_line`.

The returned line includes the newline character, if one was found.

Note: In C, you have to manually free any memory that you allocated when you're done with it. In this code, the responsibility of freeing the returned line falls on whoever calls `get_next_line`.

Enjoy! 😄
