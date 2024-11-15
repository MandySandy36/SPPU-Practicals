#include<stdio.h>

void main() {
    int data[20];  // Array size is increased to hold 7 data bits + 4 parity bits
    int dataatrec[20], c, c1, c2, c3, c4, i;

    printf("Enter 7 bits of data one by one\n");
    scanf("%d", &data[0]);
    scanf("%d", &data[1]);
    scanf("%d", &data[2]);
    scanf("%d", &data[4]);
    scanf("%d", &data[5]);
    scanf("%d", &data[6]);
    scanf("%d", &data[8]);

    // Calculation of even parity bits
    data[10] = data[0] ^ data[2] ^ data[4] ^ data[6] ^ data[8];  // Parity P4
    data[9] = data[0] ^ data[1] ^ data[4] ^ data[5] ^ data[8];   // Parity P3
    data[7] = data[4] ^ data[5] ^ data[6];   // Parity P2
    data[3] = data[0] ^ data[1] ^ data[2];   // Parity P1

    printf("\nEncoded data is\n");
    for(i = 0; i < 11; i++)
        printf("%d", data[i]);

    printf("\n\nEnter received data bits one by one\n");
    for(i = 0; i < 11; i++)
        scanf("%d", &dataatrec[i]);

    // Parity checking to find the error position
    c1 = dataatrec[10] ^ dataatrec[8] ^ dataatrec[6] ^ dataatrec[4] ^ dataatrec[2] ^ dataatrec[0];
    c2 = dataatrec[9] ^ dataatrec[8] ^ dataatrec[5] ^ dataatrec[4] ^ dataatrec[1] ^ dataatrec[0];
    c3 = dataatrec[7] ^ dataatrec[6] ^ dataatrec[5] ^ dataatrec[4];
    c4 = dataatrec[3] ^ dataatrec[2] ^ dataatrec[1]^ dataatrec[0];

    c = c4*8 + c3*4 + c2*2 + c1;

    if(c == 0) {
        printf("\nNo error while transmission of data\n");
    }
    else {
        printf("\nError on position %d\n", c);
        
        printf("Data sent : ");
        for(i = 0; i < 11; i++)
            printf("%d", data[i]);
        
        printf("\nData received : ");
        for(i = 0; i < 11; i++)
            printf("%d", dataatrec[i]);
        
        printf("\nCorrect message is\n");

        // Correct the error bit
        if(dataatrec[11-c] == 0)
            dataatrec[11-c] = 1;
        else
            dataatrec[11-c] = 0;
        
        for (i = 0; i < 11; i++) {
            printf("%d", dataatrec[i]);
        }
    }
}

