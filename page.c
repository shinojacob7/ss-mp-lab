#include <stdio.h>
#include <stdlib.h>

void fifo(int n, int pages[], int frame) {
    int page_frame[frame], pagefault = 0, rear = 0;
    for (int i = 0; i < frame; i++)
        page_frame[i] = -1;
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < frame; j++) {
            if (page_frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            page_frame[rear] = pages[i];
            rear = (rear + 1) % frame;
            pagefault++;
        }
    }
    printf("FIFO Page Faults: %d\n", pagefault);
}

void lru(int n, int pages[], int frame) {
    int page_frame[frame], pagefault = 0, recent[frame];
    for (int i = 0; i < frame; i++) {
        page_frame[i] = -1;
        recent[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < frame; j++) {
            if (page_frame[j] == pages[i]) {
                found = 1;
                recent[j] = i;
                break;
            }
        }
        if (!found) {
            int lru_index = 0;
            for (int j = 1; j < frame; j++) {
                if (page_frame[j] == -1 || recent[j] < recent[lru_index])
                    lru_index = j;
            }
            page_frame[lru_index] = pages[i];
            recent[lru_index] = i;
            pagefault++;
        }
    }
    printf("LRU Page Faults: %d\n", pagefault);
}

void lfu(int n, int pages[], int frame) {
    int page_frame[frame], pagefault = 0, freq[frame];
    for (int i = 0; i < frame; i++) {
        page_frame[i] = -1;
        freq[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < frame; j++) {
            if (page_frame[j] == pages[i]) {
                found = 1;
                freq[j]++;
                break;
            }
        }
        if (!found) {
            int min_index = 0;
            for (int j = 1; j < frame; j++) {
                if (page_frame[min_index] == -1 || freq[j] < freq[min_index])
                    min_index = j;
            }
            page_frame[min_index] = pages[i];
            freq[min_index] = 1;
            pagefault++;
        }
    }
    printf("LFU Page Faults: %d\n", pagefault);
}

int main() {
    int n, frame;
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter the page reference string: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    printf("Enter the number of frames: ");
    scanf("%d", &frame);
    fifo(n, pages, frame);
    lru(n, pages, frame);
    lfu(n, pages, frame);
    return 0;
}