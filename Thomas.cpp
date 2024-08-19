#include <iostream>
#include <vector>

std::vector<double> thomas_algorithm(const std::vector<double>& a, 
                                    const std::vector<double>& b, 
                                    const std::vector<double>& c, 
                                    const std::vector<double>& d) {
    int n = b.size();
    
    std::vector<double> cp(n - 1);
    std::vector<double> dp(n);
    std::vector<double> x(n);

    // Modificación de los vectores a y b
    cp[0] = c[0] / b[0];
    dp[0] = d[0] / b[0];
    
    for (int i = 1; i < n - 1; ++i) {
        double denom = b[i] - a[i - 1] * cp[i - 1];
        cp[i] = c[i] / denom;
        dp[i] = (d[i] - a[i - 1] * dp[i - 1]) / denom;
    }
    
    dp[n - 1] = (d[n - 1] - a[n - 2] * dp[n - 2]) / (b[n - 1] - a[n - 2] * cp[n - 2]);
    
    // Sustitución hacia atrás
    x[n - 1] = dp[n - 1];
    
    for (int i = n - 2; i >= 0; --i) {
        x[i] = dp[i] - cp[i] * x[i + 1];
    }
    
    return x;
}

int main() {
    std::vector<double> a = {1.0, 1.0, 1.0};   // subdiagonal
    std::vector<double> b = {4.0, 4.0, 4.0, 4.0};  // diagonal principal
    std::vector<double> c = {1.0, 1.0, 1.0};   // superdiagonal
    std::vector<double> d = {5.0, 6.0, 7.0, 8.0};  // términos independientes

    std::vector<double> x = thomas_algorithm(a, b, c, d);
    
    std::cout << "La solución del sistema con el algoritmo de Thomas es: ";
    for (double xi : x) {
        std::cout << xi << " ";
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
