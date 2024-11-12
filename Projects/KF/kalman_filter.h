#ifndef KALMAN_FILTER_H
#define KALMAN_FILTER_H

typedef struct {
    float *x; // State vector
    float *P; // Covariance matrix
    float *A; // State transition matrix
    float *H; // Measurement matrix
    float *R; // Measurement noise covariance matrix
    float *Q; // Process noise covariance matrix
    int state_dim; // Dimension of the state vector
    int meas_dim;  // Dimension of the measurement vector
} KalmanFilter;
 

/**
 * @brief Inicializa as variaveis do filtro de kalman   
 *  com base no numero de estados e medicoes
 * 
 * @param kf Variavel estrutural com os parametros do filtro de kalman   
 * @param state_dim Dimensao dos estados 
 * @param meas_dim Dimensao das medicoes
 */
void kalman_init(KalmanFilter *kf, int state_dim, int meas_dim);

// Predict the state and covariance
void kalman_predict(KalmanFilter *kf);

// Update the state and covariance with a new measurement
void kalman_update(KalmanFilter *kf, float *z);

#endif // KALMAN_FILTER_H