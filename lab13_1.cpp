#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}


void stat(const double A[], int N, double B[]) {
    // จัดการกรณี N <= 0
    if (N <= 0) {
        // ใช้ NaN แทนค่าที่ไม่สามารถคำนวณได้
        double nanv = numeric_limits<double>::quiet_NaN();
        for (int i = 0; i < 6; ++i) B[i] = nanv;
        return;
    }
    double sum = 0.0;
    double maxv = A[0];
    double minv = A[0];
    double sumLog = 0.0;
    double sumRecip = 0.0;
    bool gm_ok = true;
    bool hm_ok = true;
    for (int i = 0; i < N; ++i) {
        double x = A[i];
        sum += x;

        if (x > maxv) maxv = x;
        if (x < minv) minv = x;

        if (x <= 0.0) {
            gm_ok = false;
        } else {
            sumLog += std::log(x);
        }

        if (x == 0.0) {
            hm_ok = false;   
        } else {
            sumRecip += 1.0 / x;
        }
    }
    double mean = sum / N;
    double sumSqDiff = 0.0;
    for (int i = 0; i < N; ++i) {
        double d = A[i] - mean;
        sumSqDiff += d * d;
    }
    double sd = std::sqrt(sumSqDiff / N);
    double gmean = gm_ok ? std::exp(sumLog / N) : numeric_limits<double>::quiet_NaN();
    double hmean = hm_ok ? (static_cast<double>(N) / sumRecip) : numeric_limits<double>::quiet_NaN();
    B[0] = mean;    // Arithmetic Mean
    B[1] = sd;      // Standard Deviation
    B[2] = gmean;   // Geometric Mean
    B[3] = hmean;   // Harmonic Mean
    B[4] = maxv;    // Max
    B[5] = minv;    // Min
}
