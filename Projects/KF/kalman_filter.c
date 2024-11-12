#include "kalman_filter.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Multiplica matrizes
void matrix_multiply(float *result, float *A, float *B, int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i * colsB + j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i * colsB + j] += A[i * colsA + k] * B[k * colsB + j];
            }
        }
    }
}

 // Adiciona matrizes
void matrix_add(float *result, float *A, float *B, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i * cols + j] = A[i * cols + j] + B[i * cols + j];
        }
    }
}

 // Subtrai matrizes
void matrix_subtract(float *result, float *A, double *B, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i * cols + j] = A[i * cols + j] - B[i * cols + j];
        }
    }
}

// Calcula a tramposta da matriz
void matrix_transpose(float *result, float *A, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j * rows + i] = A[i * cols + j];
        }
    }
}



// Initialize the Kalman filter
void kalman_init(KalmanFilter *kf, int state_dim, int meas_dim) {
    kf->state_dim = state_dim;
    kf->meas_dim = meas_dim;
    kf->x = (float *)calloc(state_dim, sizeof(float));
    kf->P = (float *)calloc(state_dim * state_dim, sizeof(float));
        kf->A[1][1] = 
    {
        {1, dt},
        {0, 1}
    };
    //kf->A = (float *)calloc(state_dim * state_dim, sizeof(float));
    kf->H = (float *)calloc(meas_dim * state_dim, sizeof(float));
    kf->R = (float *)calloc(meas_dim * meas_dim, sizeof(float));
    kf->Q = (float *)calloc(state_dim * state_dim, sizeof(float));


// TIRAR ISSO DAQUI 
    printf("State vector (x):\n");
    for (int i = 0; i < state_dim; i++) {
        printf("%lf ", kf->x[i]);
    }
    printf("\n");

    printf("Covariance matrix (P):\n");
    for (int i = 0; i < state_dim; i++) {
        for (int j = 0; j < state_dim; j++) {
            printf("%lf ", kf->P[i * state_dim + j]);
        }
        printf("\n");
    }

    printf("State transition matrix (A):\n");
    for (int i = 0; i < state_dim; i++) {
        for (int j = 0; j < state_dim; j++) {
            printf("%lf ", kf->A[i * state_dim + j]);
        }
        printf("\n");
    }

    printf("Measurement matrix (H):\n");
    for (int i = 0; i < meas_dim; i++) {
        for (int j = 0; j < state_dim; j++) {
            printf("%lf ", kf->H[i * state_dim + j]);
        }
        printf("\n");
    }

    printf("Measurement noise covariance matrix (R):\n");
    for (int i = 0; i < meas_dim; i++) {
        for (int j = 0; j < meas_dim; j++) {
            printf("%lf ", kf->R[i * meas_dim + j]);
        }
        printf("\n");
    }

    printf("Process noise covariance matrix (Q):\n");
    for (int i = 0; i < state_dim; i++) {
        for (int j = 0; j < state_dim; j++) {
            printf("%lf ", kf->Q[i * state_dim + j]);
        }
        printf("\n");
    }
}



// Predict the state and covariance
void kalman_predict(KalmanFilter *kf) {
    float *temp = (float *)calloc(kf->state_dim * kf->state_dim, sizeof(float));
    float *Ft = (float *)calloc(kf->state_dim * kf->state_dim, sizeof(float));

    // x =  A * x + B *u
    matrix_multiply(kf->x, kf->A, kf->x, kf->state_dim, kf->state_dim, 1); // A*x


    // P = A * P * Ft + Q
    matrix_multiply(temp, kf->A, kf->P, kf->state_dim, kf->state_dim, kf->state_dim);
    matrix_transpose(Ft, kf->A, kf->state_dim, kf->state_dim);
    matrix_multiply(kf->P, temp, Ft, kf->state_dim, kf->state_dim, kf->state_dim);
    matrix_add(kf->P, kf->P, kf->Q, kf->state_dim, kf->state_dim);

    free(temp);
    free(Ft);
}

// Update the state and covariance with a new measurement
void kalman_update(KalmanFilter *kf, float *z) {
    int state_dim = kf->state_dim;
    int meas_dim = kf->meas_dim;

    float *Ht = (float *)calloc(state_dim * meas_dim, sizeof(float));
    float *PHt = (float *)calloc(state_dim * meas_dim, sizeof(float));
    float *HPHt = (float *)calloc(meas_dim * meas_dim, sizeof(float));
    float *S = (float *)calloc(meas_dim * meas_dim, sizeof(float));
    float *K = (float *)calloc(state_dim * meas_dim, sizeof(float));
    float *y = (float *)calloc(meas_dim, sizeof(float));
    float *Hx = (float *)calloc(meas_dim, sizeof(float));
    float *I = (float *)calloc(state_dim * state_dim, sizeof(float));

    // y = z - H * x
    matrix_multiply(Hx, kf->H, kf->x, meas_dim, state_dim, 1);
    matrix_subtract(y, z, Hx, meas_dim, 1);

    // S = H * P * Ht + R
    matrix_transpose(Ht, kf->H, meas_dim, state_dim);
    matrix_multiply(PHt, kf->P, Ht, state_dim, state_dim, meas_dim);
    matrix_multiply(HPHt, kf->H, PHt, meas_dim, state_dim, meas_dim);
    matrix_add(S, HPHt, kf->R, meas_dim, meas_dim);

    // K = P * Ht * S^-1
    // For simplicity, assume S is invertible and use a simple inversion method
    // In practice, you should use a more robust method for matrix inversion
    for (int i = 0; i < meas_dim; i++) {
        for (int j = 0; j < meas_dim; j++) {
            if (i == j) {
                S[i * meas_dim + j] = 1.0 / S[i * meas_dim + j];
            } else {
                S[i * meas_dim + j] = 0;
            }
        }
    }
    matrix_multiply(K, PHt, S, state_dim, meas_dim, meas_dim);

    // x = x + K * y
    float *Ky = (float *)calloc(state_dim, sizeof(float));
    matrix_multiply(Ky, K, y, state_dim, meas_dim, 1);
    matrix_add(kf->x, kf->x, Ky, state_dim, 1);

    // P = (I - K * H) * P
    for (int i = 0; i < state_dim; i++) {
        for (int j = 0; j < state_dim; j++) {
            if (i == j) {
                I[i * state_dim + j] = 1;
            } else {
                I[i * state_dim + j] = 0;
            }
        }
    }
    float *KH = (float *)calloc(state_dim * state_dim, sizeof(float));
    matrix_multiply(KH, K, kf->H, state_dim, meas_dim, state_dim);
    matrix_subtract(I, I, KH, state_dim, state_dim);
    matrix_multiply(kf->P, I, kf->P, state_dim, state_dim, state_dim);

    free(Ht);
    free(PHt);
    free(HPHt);
    free(S);
    free(K);
    free(y);
    free(Hx);
    free(I);
    free(Ky);
    free(KH);
}