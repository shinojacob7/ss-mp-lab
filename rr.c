#include <stdio.h>

int q[20], front = -1, rear = -1;

struct pro {
    int pid, at, bt, ct, st, flag, rbt;
} p[10];

void enqueue(int j) {
    if (front == -1)
        front = 0;
    q[++rear] = j;
}

int dequeue() {
    int out = q[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    return out;
}

void rr(int n) {
    int i, t, current = 0, completed = 0;
    float awt = 0, att = 0;

    printf("Enter arrival time and burst time:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d%d", &p[i].at, &p[i].bt);
        p[i].pid = i + 1;
        p[i].rbt = p[i].bt;
        p[i].flag = 0;
    }

    printf("Enter time quantum: ");
    scanf("%d", &t);

    enqueue(0);
    p[0].flag = 1;

    printf("\nGANTT CHART:\n");
    printf("%d", current);

    while (completed < n) {
        int idx = dequeue();
        if (p[idx].rbt == p[idx].bt)
            p[idx].st = (current > p[idx].at) ? current : p[idx].at;

        if (current < p[idx].at)
            current = p[idx].at;

        int exec = (p[idx].rbt >= t) ? t : p[idx].rbt;
        current += exec;
        p[idx].rbt -= exec;

        printf(" | P%d | %d", p[idx].pid, current);

        for (i = 0; i < n; i++) {
            if (p[i].flag == 0 && p[i].at <= current) {
                enqueue(i);
                p[i].flag = 1;
            }
        }

        if (p[idx].rbt == 0) {
            p[idx].ct = current;
            completed++;
        } else {
            enqueue(idx);
        }

        if (front == -1) {
            for (i = 0; i < n; i++) {
                if (p[i].flag == 0) {
                    enqueue(i);
                    p[i].flag = 1;
                    break;
                }
            }
        }
    }

    printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        int tat = p[i].ct - p[i].at;
        int wt = tat - p[i].bt;
        awt += wt;
        att += tat;
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, tat, wt);
    }

    printf("\nAverage Waiting Time = %.2f", awt / n);
    printf("\nAverage Turnaround Time = %.2f\n", att / n);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    rr(n);
    return 0;
}
