// #include <sys/types.h>
// #include <stdio.h>
// #include <unistd.h>

// int main() {
//     pid_t pid;
//     /* fork a child process */
//     pid = fork();
//     if (pid < 0)
//     { /* error occurred */
//         fprintf(stderr, "Fork Failed");
//         return 1;
//     }
//     else if (pid == 0)
//     { /* child process */
//         execlp("/bin/ls", "ls", NULL);
//     }
//     else
//     { /* parent process */
//         /* parent will wait for the child to complete */
//         wait(NULL);
//         printf("Child Complete");
//     }
//     return 0;
// }

#include <stdio.h>
#include <windows.h>

int main(void) {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    /* Allocate memory */
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    /* Create child process (Equivalent of fork + execlp) */
    if (!CreateProcess(NULL, "cmd.exe /c dir", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        DWORD error = GetLastError();
        fprintf(stderr, "Create Process Failed. Error Code: %ld\n", error);
        return -1;
    }

    /* Parent waits for the child process */
    WaitForSingleObject(pi.hProcess, INFINITE);
    printf("Child Complete\n");

    /* Close handles */
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
