#include <stdio.h>
#include <string.h>

// FACA SIMPLES ESSA PORRA
#define dt 0.1

typedef struct {
    int state_dim;
    int meas_dim;
    float x[2];
    float P[2][2];
    float A[2][2];
    float H[2];
    float R;
    float Q[2][2];
} KalmanFilter;

void kalman_init(KalmanFilter *kf, int state_dim, int meas_dim) {
    kf->state_dim = state_dim;
    kf->meas_dim = meas_dim;

    // Vetor de estados x
    kf->x[0] = 1.0; // Initial value
    kf->x[1] = 0.0;

    // Initialize covariance matrix P
    kf->P[0][0] = 1.0; kf->P[0][1] = 0.0;
    kf->P[1][0] = 0.0; kf->P[1][1] = 1.0;

    // Initialize state transition matrix A
    kf->A[0][0] = 1.0; kf->A[0][1] = dt;
    kf->A[1][0] = 0.0; kf->A[1][1] = 1.0;

    // Initialize measurement matrix H
    kf->H[0] = 1.0;
    kf->H[1] = 0.0;

    // Initialize measurement noise covariance R
    kf->R = 1.0;

    // Initialize process noise covariance Q
    kf->Q[0][0] = 0.1; kf->Q[0][1] = 0.0;
    kf->Q[1][0] = 0.0; kf->Q[1][1] = 0.1;
}

// Function to multiply matrices
void multiplicar_matriz(float *result, float *A, float *B, int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i * colsB + j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i * colsB + j] += A[i * colsA + k] * B[k * colsB + j];
            }
        }
    }
}

// Function to predict the state and covariance
void prever_estado(float *xk, float *Pk, float *A, float *Q, float *x_k_1, float *P_k_1) {
    // xk = A * x_k_1
    multiplicar_matriz(xk, A, x_k_1, 2, 2, 1);

    // Pk = A * P_k_1 * A' + Q
    float temp[2][2];
    multiplicar_matriz((float *)temp, A, P_k_1, 2, 2, 2);
    multiplicar_matriz(Pk, (float *)temp, A, 2, 2, 2);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            Pk[i * 2 + j] += Q[i * 2 + j];
        }
    }
}

int main() {
    KalmanFilter kf;
    kalman_init(&kf, 2, 1);

    float xk[2];
    float Pk[2][2];
    float x_k_1[2] = {1.0, 0.0};
    float P_k_1[2][2] = {{1.0, 0.0}, {0.0, 1.0}};
    float yk;
    float dx[10] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};

    for (int i = 0; i < 10; i++) {
        // Predict the state and covariance
        prever_estado((float *)xk, (float *)Pk, (float *)kf.A, (float *)kf.Q, (float *)x_k_1, (float *)P_k_1);

        // Update the state and covariance
        yk = dx[i] + kf.H[0] * xk[0];

        // Print the predicted state
        printf("Predicted state at step %d: [%f, %f]\n", i, xk[0], xk[1]);

        // Update x_k_1 and P_k_1 for the next iteration
        x_k_1[0] = xk[0];
        x_k_1[1] = xk[1];
        P_k_1[0][0] = Pk[0][0];
        P_k_1[0][1] = Pk[0][1];
        P_k_1[1][0] = Pk[1][0];
        P_k_1[1][1] = Pk[1][1];
    }

    return 0;
}