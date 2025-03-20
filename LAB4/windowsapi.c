// #include <stdio.h>
// #include <windows.h>

// int main(void) {
//     STARTUPINFO si;
//     PROCESS_INFORMATION pi;

//     /* Allocate memory */
//     ZeroMemory(&si, sizeof(si));
//     si.cb = sizeof(si);
//     ZeroMemory(&pi, sizeof(pi));

//     /* Create child process */
//     if (!CreateProcess(NULL, "\"C:\\Windows\\System32\\mspaint.exe\"", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
//         DWORD error = GetLastError();
//         fprintf(stderr, "Create Process Failed. Error Code: %ld\n", error);
//         return -1;
//     }

//     /* Wait for child process to complete */
//     WaitForSingleObject(pi.hProcess, INFINITE);
//     printf("Child Complete\n");

//     /* Close handles */
//     CloseHandle(pi.hProcess);
//     CloseHandle(pi.hThread);

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

    /* Create child process */
    if (!CreateProcess(NULL, "\"C:\\Windows\\System32\\mspaint.exe\"", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
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
