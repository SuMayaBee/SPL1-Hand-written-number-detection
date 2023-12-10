#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util/img.h"
#include "neural/activations.h"
#include "neural/nn.h"
#include "matrix/matrix.h"
#include "matrix/ops.h"

#define MAX_LINE_LENGTH 1024
#define ROWS 28
#define COLS 28

int main() {
	srand(time(NULL));

	//TRAINING
	//int number_imgs = 10000;
	// Img** imgs = csv_to_imgs("./data/mnist_train.csv", number_imgs);
	// NeuralNetwork* net = network_create(784, 300, 10, 0.1);
	// network_train_batch_imgs(net, imgs, number_imgs);
	// network_save(net, "testing_net");

	 

	// PREDICTING
	 int number_imgs = 3000;
	 Img** imgs = csv_to_imgs("data/mnist_test.csv", number_imgs);

     img_print(imgs[0]);



	 NeuralNetwork* net = network_load("testing_net");
	 double score = network_predict_imgs(net, imgs, 1000);
	 printf("Score: %1.5f\n", score);

	 imgs_free(imgs, number_imgs);
	 network_free(net);


	 //=======================================================================================================
	
    int image[ROWS][COLS];
    FILE *file = fopen("image.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (!fscanf(file, "%d, ", &image[i][j])) {
               break;
            }
        }
    }

    fclose(file);

    // Print the array to verify it was read correctly
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;




}

//===============================================================================================================================

// Draw on Screen like paint.
// #include <bits/stdc++.h>
// #include <graphics.h>
// #include <stdlib.h>



// using namespace std;

// // Press Left shift and move cursor to draw on the screen.
// // release shift key to stop drawing.

// int main()
// {
//     initwindow(1000, 600);
    
//     unsigned char data[1000][600];
    
//     for(int x=0; x<1000; x++) {
//     	for(int y =0; y<600; y++) {
//     		data[x][y] = 0;
// 		}
// 	}
     	
// 	POINT P, L;    
		
// 	while(!kbhit()){
// 		L.x = P.x;
// 		L.y = P.y;
// 		if(GetCursorPos(&P) and (GetKeyState(VK_SHIFT) & 0x8000)){
		
// 			line(L.x,L.y, P.x,P.y);
// 			data[P.x][P.y] =255;
// 		}
// 	}
//     getch();
    
//     FILE* file = fopen("image.txt", "w");
//     for (int x = 0;x < 1000;x++) {
//         for (int y = 0;y < 600;y++) {
//             unsigned char pixelValue = data[x][y];
//             //fwrite(&pixelValue, sizeof(char), 1, file);
//             fprintf(file, "%d", pixelValue);
//         }
//     }
//     fclose(file);
//     // to read it back, loop through the array and use 'line' or any other graphics function to draw a pixel
//     // based on the array value
// //    file = fopen("image.txt", "r");
// //    for (int x = 0;x < 1000;x++) {
// //        for (int y = 0;y < 600;y++) {
// //            char pixelValue;
// //            fread(&pixelValue, sizeof(char), 1, file);
// //
// //            data[x][y] = pixelValue;
// //        }
// //    }
// //    fclose(file);

// //      for (int x = 0;x < 1000;x++) {
// //        for (int y = 0;y < 600;y++) {
// //            cout<<data[x][y]<<" ";
// //        }
// //    }
     
    
//     return 0;
// }





//--------------------------------------------------------------------------------------------------------------------------------

// gcc -o main matrix/*.c neural/*.c util/*.c *.c -lm
// ./main
