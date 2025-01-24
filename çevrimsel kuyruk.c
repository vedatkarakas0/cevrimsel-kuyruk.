#include <stdio.h>
#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

int dolu() {
    if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) {
        return 1;
    }
    return 0;
}

int bos() {
    if (front == -1) {
        return 1;
    }
    return 0;
}

void elemanEkle(int element) {
    if (dolu()) 
        printf("\nKuyruk dolu.\n");
    else {
        if (front == -1) front = 0;
    s    rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("\nEklendi -> %d", element);
    }
}

int elemanCikart() {
    int element;
    if (bos()) {
        printf("\nKuyruk bos.\n");
        return -1;
    } else {
        element = items[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        printf("\nSilinen eleman -> %d\n", element);
        return element;
    }
}

void goruntule() {
    int i;
    if (bos()) {
        printf("\nKuyruk bos.\n");
    } else {
        printf("\nOn -> %d", front);
        printf("\nElemanlar -> ");
        for (i = front; i != rear; i = (i + 1) % SIZE) {
            printf("%d ", items[i]);
        }
        printf("%d ", items[i]);
        printf("\nArka -> %d\n", rear);
    }
}

int main() {
    int secim, element;
    
    while(1) {
        printf("\nKuyruk Islemleri:\n");
        printf("1. Eleman Ekle\n");
        printf("2. Eleman Cikar\n");
        printf("3. Goruntule\n");
        printf("4. Cikis\n");
        printf("Seciminizi girin: ");
        scanf("%d", &secim);

        switch(secim) {
            case 1:
                printf("\nEklenecek elemani girin: ");
                scanf("%d", &element);
                elemanEkle(element);
                break;
            case 2:
                elemanCikart();
                break;
            case 3:
                goruntule();
                break;
            case 4:
                printf("\nProgramdan cikiliyor...\n");
                return 0;
            default:
                printf("\nGecersiz secim! Lutfen tekrar deneyin.\n");
        }
    }

    return 0;
}

