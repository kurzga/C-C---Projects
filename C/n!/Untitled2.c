#include <stdio.h>
#include <conio.h>

int main() {
    int T = 0, n, f = 1, s = 1, j = 0, i = 1;

    printf("n:");
    scanf("%d", &n);

    for 
    (i; i <= n; i++) {
        f = f * i;

        for (j; j < i; j++) {
            s = s * (n - j);
        }

        T = T + (s / f);
        s = 1;
        j = 0;
    }

    printf("sonuc = %d", T);

    getch();
    return 0;
}
