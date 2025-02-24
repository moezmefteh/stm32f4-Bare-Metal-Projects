#include <sys/stat.h>
#include <unistd.h>

extern void uart2_write(int ch);
extern char uart2_read(void);

int _write(int file, char *ptr, int len) {
    (void)file;
    for (int i = 0; i < len; i++) {
        // Implement your UART send function here
        uart2_write(ptr[i]);
    }
    return len;
}

int _read(int file, char *ptr, int len) {
    (void)file;
    // Implement your UART receive function here
    for (int i = 0; i < len; i++) {
        ptr[i] = uart2_read();
    }
    return len;
}

int _close(int file) {
    (void)file;
    return -1;
}

int _fstat(int file, struct stat *st) {
    (void)file;
    st->st_mode = S_IFCHR;
    return 0;
}

int _isatty(int file) {
    (void)file;
    return 1;
}

int _lseek(int file, int ptr, int dir) {
    (void)file;
    (void)ptr;
    (void)dir;
    return 0;
}
