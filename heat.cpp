#include <iostream>
#include <vector>
#include <cmath>


void thomas_algorithm(const std::vector<double>& a, const std::vector<double>& b, 
                      const std::vector<double>& c, const std::vector<double>& d, 
                      std::vector<double>& x) {
    int n = b.size();
    std::vector<double> cp(n-1);
    std::vector<double> dp(n);

    
    cp[0] = c[0] / b[0];
    dp[0] = d[0] / b[0];

    for (int i = 1; i < n-1; ++i) {
        double denom = b[i] - a[i-1] * cp[i-1];
        cp[i] = c[i] / denom;
        dp[i] = (d[i] - a[i-1] * dp[i-1]) / denom;
    }
    dp[n-1] = (d[n-1] - a[n-2] * dp[n-2]) / (b[n-1] - a[n-2] * cp[n-2]);

    
    x[n-1] = dp[n-1];
    for (int i = n-2; i >= 0; --i) {
        x[i] = dp[i] - cp[i] * x[i+1];
    }
}

int main() {
    // Parámetros
    double L = 10.0;        // Longitud del dominio
    double T = 2.0;         // Tiempo total
    int Nx = 100;           // Número de puntos espaciales
    int Nt = 200;           // Número de pasos temporales
    double α = 0.01;        // Coeficiente de difusión

    // Discretización
    double dx = L / (Nx - 1);
    double dt = T / Nt;
    std::vector<double> x(Nx);
    std::vector<double> u(Nx, 0.0);
    std::vector<double> u_new(Nx, 0.0);

    // Inicialización del vector x y condición inicial
    for (int i = 0; i < Nx; ++i) {
        x[i] = i * dx;
    }
    u[Nx / 2] = 1.0;

    // Parámetros para el sistema tridiagonal
    double r = α * dt / (dx * dx);
    std::vector<double> a(Nx - 1, -r);
    std::vector<double> b(Nx, 1 + 2 * r);
    std::vector<double> c(Nx - 1, -r);

    // Solución
    std::vector<double> times;
    std::vector<std::vector<double>> temperature_profiles;

    for (int n = 0; n < Nt; ++n) {
        std::vector<double> d(Nx - 2);
        for (int i = 0; i < Nx - 2; ++i) {
            d[i] = u[i + 1];
        }
        d[0] += r * u[0];
        d[Nx - 3] += r * u[Nx - 1];

        thomas_algorithm(a, std::vector<double>(b.begin() + 1, b.end() - 1), c, d, u_new);
        
        // Condiciones de frontera
        u_new[0] = 0;
        u_new[Nx - 1] = 0;

        u = u_new;
    }
    return 0;
}
